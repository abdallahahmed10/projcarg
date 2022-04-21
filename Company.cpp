#include "Company.h"

Company::Company()
{
	N_cargos = new WaitingList;
	S_cargos = new LinkedQueue<Cargos*>;
	V_cargos = new PriorityQueue<Cargos*>;

	N_truckslist = new LinkedQueue<Truck*>;  //normal trucks list
	S_truckslist = new LinkedQueue<Truck*>;  //special trucks list
	V_truckslist = new LinkedQueue<Truck*>;  //VIP trucks list
	
	ListofEvents = new LinkedQueue<Events*>; // List of events
	
	//int curr_Day = 0;         //Time of current day and hour to take actions in
	//int curr_Hour = 0;
	//int NoWaitingCargos = 0;     //Total number of cargos
	//int NoLoadingTrucks = 0;
	//int NoEmptyTrucks = 0;
	//int NoMovingCargos = 0;
	//int NoInCheckupTrucks = 0;
	//int NoDeliveredCargos = 0;
}
/*void Company::AutoPromotion()
{
	Cargos* prom;
	N_cargos->peek(prom);
	if (curr_Hour == (AutoP + prom->)
	{

	}
}*/
int Company::GetAutoP()
{
	return AutoP;
}
int Company::Getcurr_Day()
{
	return curr_Day;
}
int Company::GetNoDeliveredCargos()
{
	return NoDeliveredCargos;
}
int  Company::Getcurr_Hour()
{
	return curr_Hour;
}
int Company::GetNoWaitingCargos()
{
	return NoWaitingCargos;
}
int Company::GetNoLoadingTrucks()
{
	return NoLoadingTrucks;
}
int Company::GetNoEmptyTrucks()
{
	return NoEmptyTrucks;
}
int Company::GetNoMovingCargos()
{
	return NoMovingCargos;
}
int Company::GetNoInCheckupTrucks()
{
	return NoInCheckupTrucks;
}
void Company::Run()
{
	UI ui;
	pUI = &ui;
	fileInput = pUI->setMode(this);
	readFile();
	curr_Day = 0;
	curr_Hour = 5;
	while (1)
	{
		ExecuteEvents();
		pUI->Interactive_StepByStep(this);

		curr_Hour++;
		if (curr_Hour == 24)
		{
			curr_Day++;
			curr_Hour = 0;
		}
		if (NoWaitingCargos == 0 && NoLoadingTrucks == 0 && NoMovingCargos == 0 
			&& NoInCheckupTrucks == 0 && ListofEvents->getcount() == 0)
		{
			return;
		}
	}
}
void Company::setFileInput(string file)
{
	fileInput = file;
}
void Company::readFile()
{
	int N, S, V, NS, SS, VS, NTC, STC, VTC, J, CN, CS, CV, E, ETDay, ETHours, 
		ID, DIST, LT, Cost,
		EDDay, EDHours, ExtraMoney;
	char TYP, evnt;
	ifstream file(fileInput, ios::in); 
		file >> N;  // number of normal trucks
		file >> S;  // number of special trucks
		file >> V;  // number of VIP trucks
		file >> NS;  //speed of normal trucks
		file >> SS;  //speed of special trucks
		file >> VS;  //speed of VIP trucks
		file >> NTC;  //normal truck capacity
		file >> STC;  //normal special capacity
		file >> VTC;  //normal VIP capacity
		file >> J;  //number of journeys the truck completes before performing a checkup
		file >> CN;  //check up duration for normal trucks
		file >> CS;  //check up duration for special trucks
		file >> CV;  //check up duration for VIP trucks
		for (int i = 0; i < N; i++)
		{
			Truck* a= new Truck ('N',NS,NTC,J,CN); 
			N_truckslist->enqueue(a);
		}
		for (int i = 0; i < S; i++)
		{
			Truck* b = new Truck('S', SS, STC, J, CS);
			S_truckslist->enqueue(b);
		}
		for (int i = 0; i < V; i++)
		{
			Truck* c =new Truck('V', VS, VTC, J, CV);
			V_truckslist->enqueue(c);
		}
		file >> AutoP;

		file >> MaxW;

		file >> E;  //number of events
		for (int i = 0; i < E; i++)
		{
			file >> evnt; 
			if (evnt == 'R')
			{
				file >> TYP;  
				file >> ETDay;
				file.ignore();
				file >> ETHours;
				file >> ID;
				file >> DIST;
				file >> LT;
				file >> Cost;
				ReadyEvents* ready = new ReadyEvents(TYP, ETDay, ETHours, ID, DIST, LT, Cost); 
				ListofEvents->enqueue(ready);
			}
			else if (evnt == 'X')
			{
				file >> EDDay;
				file.ignore();
				file >> EDHours;
				file >> ID;
				CancellationEvents* cancel =new CancellationEvents(EDDay, EDHours, ID);
				ListofEvents->enqueue(cancel);
			}
			else if (evnt == 'P')
			{
				file >> EDDay;
				file.ignore();
				file >> EDHours;
				file >> ID;
				file >> ExtraMoney;
				PromotionEvents* promotion= new PromotionEvents(EDDay, EDHours, ID, ExtraMoney);
				ListofEvents->enqueue(promotion);
			}
		}
}

void Company::addtoline(Cargos* c, int prio)
{
	char x;
	x = c->gettype();
	NoOfTotalCargos++;
	if (x == 'N')
	{
		N_cargos->InsertBeg(c);
		N_cargos_count++;
	}
	else if (x == 'S')
	{
		S_cargos->enqueue(c);
		S_Cargos_count++;
	}
	else if (x == 'V')
	{
		V_cargos->enqueue(c,prio);
		V_cargos_count++;
	}
}

int Company::calcprio(Cargos* c)
{
	return 0;
}

void Company::cancellationcargo(int id)
{
	N_cargos->DeleteNode(id);
	N_cargos_count--;
}

void Company::promotion(int id)
{
	Cargos* pc = N_cargos->Find(id);
	pc->settype('V');
	int prio=calcprio(pc);
	cancellationcargo(id);
	V_cargos->enqueue(pc, prio);
	V_cargos_count++;
}

void Company::ExecuteEvents()
{
	Events* ptrEvent;
	while (ListofEvents->peek(ptrEvent))
	{
		if ((ptrEvent->getetday() == curr_Day) && (ptrEvent->getethour() == curr_Hour))
		{
			ptrEvent->execute(this);
			ListofEvents->dequeue(ptrEvent);
			delete ptrEvent;
			ptrEvent = NULL;
		}
		else return;
	}
}

Company::~Company()
{

}
