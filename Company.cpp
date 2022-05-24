#include "Company.h"

Company::Company()
{
	N_cargos = new WaitingList;
	S_cargos = new LinkedQueue<Cargos*>;
	V_cargos = new PriorityQueue<Cargos*>;

	temp_N_waiting = new WaitingList;
	temp_S_waiting = new LinkedQueue<Cargos*>;
	temp_V_waiting = new PriorityQueue<Cargos*>;

	N_truckslist_empty = new LinkedQueue<Truck*>;  //normal trucks list
	S_truckslist_empty = new LinkedQueue<Truck*>;  //special trucks list
	V_truckslist_empty = new LinkedQueue<Truck*>;  //VIP trucks list

	//N_truckslist_loading = new LinkedQueue<Truck*>;  //normal trucks list
	//S_truckslist_loading = new LinkedQueue<Truck*>;  //special trucks list
	//V_truckslist_loading = new LinkedQueue<Truck*>;  //VIP trucks list
	Moving_TruckList = new PriorityQueue<Truck*>;

	N_truck_Loading = nullptr;
	S_truck_Loading = nullptr;
	V_truck_Loading = nullptr;


	cargos_delivered = new LinkedQueue<Cargos*>;
	/* N_cargos_delivered = new LinkedQueue<Cargos>;
	S_cargos_delivered = new LinkedQueue<Cargos*>;
	V_cargos_delivered = new LinkedQueue<Cargos*>; */

	ListofEvents = new LinkedQueue<Events*>; // List of events

	curr_Day = 0;         //Time of current day and hour to take actions in
	curr_Hour = 0;
	NoWaitingCargos = 0;     //Total number of cargos
	NoMovingTrucks = 0;
	NoDeliveredCargos = 0;
	NoMovingCargos = 0;


	NoEmptyTrucks = 0;
	NoLoadingTrucks = 0;
	NoInCheckupTrucks = 0;

	NoN_Trucks = 0;
	NoS_Trucks = 0;
	NoV_Trucks = 0;

	NoAutoProm = 0;
	counter_for_unloading = 0;
	//Flag_Unloading = 0;

	NoDeliveredNormalCargos = 0;
	NoDeliveredSpecialCargos = 0;
	NoDeliveredVIPCargos = 0;
	maxconditionN = 0;
	maxconditionS = 0;
}
void Company::AutoPromotion()
{
	Cargos* ptr = (N_cargos->GetEntry(1));
	promotion(ptr->getid());
	NoAutoProm++;
}

int Company::Getcurr_Day()
{
	return curr_Day;
}
int Company::GetNoDeliveredCargos()
{
	return NoDeliveredCargos;
}
void Company::print_waiting_cargos()
{
	cout << "[";
	N_cargos->PrintList();
	cout << "]";
	cout << "(";
	S_cargos->PrintList();
	cout << ")";
	cout << "{";
	V_cargos->PrintList();
	cout << "}" << endl;
}
void Company::print_loading_truck()
{
	/* Truck t; */
	if (N_truck_Loading)
	{
		if (N_truck_Loading->gettype() == 'N')
		{
			cout << N_truck_Loading->getid();
			cout << "[";
			N_truck_Loading->PrintCargosList();     //This line will be modified so that you can call print function in Truck to print list os cargos
			cout << "]";
		}
		if (N_truck_Loading->gettype() == 'V')
		{
			cout << N_truck_Loading->getid();
			cout << "{";
			N_truck_Loading->PrintCargosList();     //This line will be modified so that you can call print function in Truck to print list os cargos
			cout << "}";
		}
	}
	if (S_truck_Loading)
	{
		cout << " ";
		cout << S_truck_Loading->getid();
		cout << "(";
		S_truck_Loading->PrintCargosList();    //This line will be modified so that you can call print function in Truck to print list os cargos
		cout << ")";
	}
	if (V_truck_Loading)
	{
		if (V_truck_Loading->gettype() == 'V')
		{
			cout << " ";
			cout << V_truck_Loading->getid();
			cout << "{";
			V_truck_Loading->PrintCargosList();     //This line will be modified so that you can call print function in Truck to print list os cargos
			cout << "}";
		}
		if (V_truck_Loading->gettype() == 'N')
		{
			cout << " ";
			cout << V_truck_Loading->getid();
			cout << "[";
			V_truck_Loading->PrintCargosList();     //This line will be modified so that you can call print function in Truck to print list os cargos
			cout << "]";
		}
		if (V_truck_Loading->gettype() == 'S')
		{
			cout << " ";
			cout << V_truck_Loading->getid();
			cout << "(";
			V_truck_Loading->PrintCargosList();     //This line will be modified so that you can call print function in Truck to print list os cargos
			cout << ")";
		}
	}

}
void Company::print_empty_truck()
{
	cout << "[";
	N_truckslist_empty->PrintList();
	cout << "]";
	cout << "(";
	S_truckslist_empty->PrintList();
	cout << ")";
	cout << "{";
	V_truckslist_empty->PrintList();
	cout << "}" << endl;

}
void Company::print_moving_truck()
{

	if (!(Moving_TruckList->isEmpty()))
	{
		Truck* truck;
		LinkedQueue<Truck*>* temp = new LinkedQueue<Truck*>;
		while (Moving_TruckList->dequeue(truck))
		{
			if (truck->gettype() == 'N')
			{
				cout << truck->getid();
				cout << "[";
				truck->PrintCargosList();
				cout << "]";
			}
			if (truck->gettype() == 'S')
			{
				cout << " ";
				cout << truck->getid();
				cout << "(";

				truck->PrintCargosList();
				cout << ")";
			}
			if (truck->gettype() == 'V')
			{
				cout << " ";
				cout << truck->getid();
				cout << "{";

				truck->PrintCargosList();;
				cout << "}";
			}
			temp->enqueue(truck);
		}
		while (temp->dequeue(truck))
		{
			Moving_TruckList->enqueue(truck, truck->GetPrioTruck());
		}
	}

}
void Company::print_delivered_cargos()
{
	Cargos* ptrCargo;
	LinkedQueue<Cargos*>* temp;
	temp = new LinkedQueue<Cargos*>;
	NoDeliveredNormalCargos = 0;
	NoDeliveredSpecialCargos = 0;
	NoDeliveredVIPCargos = 0;
	while (cargos_delivered->peek(ptrCargo))
	{
		cargos_delivered->dequeue(ptrCargo);
		if (ptrCargo->gettype() == 'N')
		{
			cout << "[" << ptrCargo->getid() << "] ";
			temp->enqueue(ptrCargo);
			NoDeliveredNormalCargos++;
		}
		if (ptrCargo->gettype() == 'S')
		{
			cout << "(" << ptrCargo->getid() << ") ";
			temp->enqueue(ptrCargo);
			NoDeliveredSpecialCargos++;
		}
		if (ptrCargo->gettype() == 'V')
		{
			cout << "{" << ptrCargo->getid() << "} " << endl;
			temp->enqueue(ptrCargo);
			NoDeliveredVIPCargos++;
		}
	}
	while (temp->peek(ptrCargo))
	{
		temp->dequeue(ptrCargo);
		cargos_delivered->enqueue(ptrCargo);
	}
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
	while (true)
	{
		ExecuteEvents();
		NoEmptyTrucks = N_truckslist_empty->getcount() + S_truckslist_empty->getcount() + V_truckslist_empty->getcount(); //this is in phase 1 only
		MaxWaitRule();
		if (N_cargos->GetEntry(1) && ((curr_Day - N_cargos->GetEntry(1)->getprepartionday()) == AutoP) && (curr_Hour - N_cargos->GetEntry(1)->getprepartionhour() == 0))
		{
			AutoPromotion();
		}

		AvailToLoading();
		LoadCargos();
		moveatruck();
		DeliverCargos();
		if ((pUI->getMode() == 1) || (pUI->getMode() == 2))
			pUI->Interactive_StepByStep(this);
		curr_Hour++;
		if (curr_Hour == 24)
		{
			curr_Day++;
			curr_Hour = 0;
		}
		if (NoWaitingCargos == 0 && NoLoadingTrucks == 0 && NoMovingTrucks == 0
			&& NoInCheckupTrucks == 0 && ListofEvents->getcount() == 0)
		{
			if (pUI->getMode() == 3)
				pUI->Silent();
			OutputFile();
			return;
		}
		//FiveSteps();
	}

}



void Company::FiveSteps()
{
	while (true)
	{
		Cargos* test = N_cargos->GetEntry(1);
		if (test)
		{
			int h = 5 + test->getprepartionhour();
			int d = 1 + test->getprepartionday();
			if (h >= 24)
			{
				h = h - 24;
				d++;
			}
			if (d == curr_Day && h == curr_Hour)
			{
				N_cargos->DeleteNode(test->getid());
				cargos_delivered->enqueue(test);
				NoDeliveredCargos++;
				NoWaitingCargos--;
			}
			else
				break;
		}
		else
			break;
	}
	while (true)
	{
		Cargos* test;
		if (S_cargos->peek(test))
		{
			int h = 5 + test->getprepartionhour();
			int d = test->getprepartionday();
			if (h >= 24)
			{
				h = h - 24;
				d++;
			}
			if (d == curr_Day && h == curr_Hour)
			{
				S_cargos->dequeue(test);
				cargos_delivered->enqueue(test);
				NoDeliveredCargos++;
				NoWaitingCargos--;
			}
			else
				break;
		}
		else
			break;
	}
	while (true)
	{
		Cargos* test;
		if (V_cargos->peekFront(test))
		{
			int h = 5 + test->getprepartionhour();
			int d = test->getprepartionday();
			if (h >= 24)
			{
				h = h - 24;
				d++;
			}
			if (d <= curr_Day && h <= curr_Hour)
			{
				V_cargos->dequeue(test);
				cargos_delivered->enqueue(test);
				NoDeliveredCargos++;
				NoWaitingCargos--;
			}
			else
				break;
		}
		else
			break;
	}
}

void Company::moveatruck()
{
	Truck* truck;
	Cargos* cargo;
	if (N_truck_Loading != nullptr)//N_truckslist_loading->peek(truck))
	{
		truck = N_truck_Loading;
		truck->PeekCargoList(cargo);
		int movetimeDays = truck->getLoadingTimeDay();
		int movetimeHour = (/*truck->calcTotalLoadingTimeCargos()*/truck->getTotalLoadingTimeCargos()) + (truck->getLoadingTimeHour());
		while (movetimeHour > 24)
		{
			movetimeDays++;
			movetimeHour = movetimeHour - 24;
		}

		truck->setmovingday(movetimeDays);
		truck->setmovinghour(movetimeHour);

		if (curr_Hour == movetimeHour && curr_Day == movetimeDays)
		{
			//N_truckslist_loading->dequeue(x);
			Moving_TruckList->enqueue(truck, -(cargo->getdelivaryhour()+ 24*(cargo->getdelivaryhour())));
			truck->Calc_CDT_ForCargos();
			NoLoadingTrucks--;
			N_truck_Loading = nullptr;
			NoMovingCargos = NoMovingCargos + truck->getcapacity();

		}
	}
	if (V_truck_Loading != nullptr)
	{
		truck = V_truck_Loading;
		truck->PeekCargoList(cargo);
		//int movetime = (truck->getTotalLoadingTimeCargos()) + (truck->getTotalLoadingTime());
		int movetimeDays = truck->getLoadingTimeDay();
		int movetimeHour = (/*truck->calcTotalLoadingTimeCargos()*/truck->getTotalLoadingTimeCargos()) + (truck->getLoadingTimeHour());
		while (movetimeHour > 24)
		{
			movetimeDays++;
			movetimeHour = movetimeHour - 24;
		}

		truck->setmovingday(movetimeDays);
		truck->setmovinghour(movetimeHour);
		
		if (curr_Hour == movetimeHour && curr_Day == movetimeDays)
		{
			//V_truckslist_loading->dequeue(x);
			Moving_TruckList->enqueue(truck, -(cargo->getdelivaryhour() + 24 * (cargo->getdelivaryhour())));
			truck->Calc_CDT_ForCargos();
			NoLoadingTrucks--;
			V_truck_Loading = nullptr;
			NoMovingCargos = NoMovingCargos + truck->getcapacity();


		}
	}
	if (S_truck_Loading != nullptr)
	{
		truck = S_truck_Loading;
		truck->PeekCargoList(cargo);
		int movetimeDays = truck->getLoadingTimeDay();
		int movetimeHour = (/*truck->calcTotalLoadingTimeCargos()*/truck->getTotalLoadingTimeCargos()) + (truck->getLoadingTimeHour());
		while (movetimeHour > 24)
		{
			movetimeDays++;
			movetimeHour = movetimeHour - 24;
		}

		truck->setmovingday(movetimeDays);
		truck->setmovinghour(movetimeHour);

		if (curr_Hour == movetimeHour && curr_Day == movetimeDays)
		{
			//S_truckslist_loading->dequeue(x);
			Moving_TruckList->enqueue(truck, -(cargo->getdelivaryhour() + 24 * (cargo->getdelivaryhour())));
			truck->Calc_CDT_ForCargos();
			NoLoadingTrucks--;
			S_truck_Loading = nullptr;
			NoMovingTrucks++;
			NoMovingCargos = NoMovingCargos + truck->getcapacity();
		}
	}
}

void Company::setFileInput(string file)
{
	fileInput = file;
}

void Company::OutputFile()
{
	ofstream file;
	file.open("Output_File.txt", ofstream::out | ofstream::trunc);
	file << "CDT   ID   PT   WT   TID" << endl;
	Cargos* ptrCargo;
	while (cargos_delivered->peek(ptrCargo))
	{
		cargos_delivered->dequeue(ptrCargo);
		file << ptrCargo->getdelivaryday() << ":" << ptrCargo->getdelivaryhour()
			<< "   " << ptrCargo->getid() << "   " <<
			ptrCargo->getprepartionday() << ":" << ptrCargo->getprepartionhour()
			<< "   " << ptrCargo->getwaitingtimeday() << ":" << ptrCargo->getwaitingtimehour()
			<< "   " << ptrCargo->getTID() << endl;
	}
	file << "---------------------------------------------" << endl;
	file << "---------------------------------------------" << endl;
	file << "Cargos: " << NoDeliveredCargos
		<< "[ N: " << NoDeliveredNormalCargos << ", S: " << NoDeliveredSpecialCargos << ", V: " << NoDeliveredVIPCargos << " ]" << endl;
	file << "Cargo Avg Wait = " << endl;
	file << "Auto-promoted Cargos: " << ((NoAutoProm / NoWaitingCargos) * 100) << "%" << endl;
	file << "Trucks: " << NoN_Trucks + NoS_Trucks + NoV_Trucks << "[ N: " << NoN_Trucks << ", S: " << NoS_Trucks << ", V: " << NoV_Trucks << " ]" << endl;
	file << "Avg Active time = " << AvgActiveTime() << "%" << endl;
	file << "Avg utalizationS = " << AvgUtilization() << "%" << endl;
}
int Company::AvgActiveTime()
{
	return 0;
}
int	Company::AvgUtilization()
{
	return 0;
}
void Company::readFile()
{
	int NS, SS, VS, NTC, STC, VTC, J, CN, CS, CV, E, ETDay, ETHours,
		ID, DIST, LT, Cost,
		EDDay, EDHours, ExtraMoney;
	char TYP, evnt;
	ifstream file(fileInput, ios::in);
	file >> NoN_Trucks;  // number of normal trucks
	file >> NoS_Trucks;  // number of special trucks
	file >> NoV_Trucks;  // number of VIP trucks
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
	for (int i = 0; i < NoN_Trucks; i++)
	{
		Truck* a = new Truck('N', NS, NTC, J, CN, i + 1);
		N_truckslist_empty->enqueue(a);
	}
	for (int i = 0; i < NoS_Trucks; i++)
	{
		Truck* b = new Truck('S', SS, STC, J, CS, NoN_Trucks + i + 1);
		S_truckslist_empty->enqueue(b);
	}
	for (int i = 0; i < NoV_Trucks; i++)
	{
		Truck* c = new Truck('V', VS, VTC, J, CV, NoN_Trucks + NoS_Trucks + i + 1);
		V_truckslist_empty->enqueue(c);
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
			CancellationEvents* cancel = new CancellationEvents(EDDay, EDHours, ID);
			ListofEvents->enqueue(cancel);
		}
		else if (evnt == 'P')
		{
			file >> EDDay;
			file.ignore();
			file >> EDHours;
			file >> ID;
			file >> ExtraMoney;
			PromotionEvents* promotion = new PromotionEvents(EDDay, EDHours, ID, ExtraMoney);
			ListofEvents->enqueue(promotion);
		}
	}
}

void Company::addtoline(Cargos* c, int prio)
{
	char x;
	x = c->gettype();
	NoWaitingCargos++;
	if (x == 'N')
	{
		N_cargos->InsertEnd(c);
		N_cargos_count++;
		//TotalNoN_WaitingCargos++;
	}
	else if (x == 'S')
	{
		S_cargos->enqueue(c);
		S_Cargos_count++;
	}
	else if (x == 'V')
	{
		V_cargos->enqueue(c, prio);
		V_cargos_count++;
	}
}

int Company::calcprio(Cargos* c)
{
	return  (c->getcost() + c->getdelivery_dist() + c->getloadtime());
}

void Company::cancellationcargo(int id)
{
	N_cargos->DeleteNode(id);
	N_cargos_count--;
	NoWaitingCargos--;
}

void Company::promotion(int id)
{
	Cargos* pc = N_cargos->Find(id);
	pc->settype('V');
	int prio = calcprio(pc);
	cancellationcargo(id);
	// pc->setcost(pc->getcost() + ); /
	addtoline(pc, prio);
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
//void Company::AvailToLoading()
//{
//	Cargos* cargo;
//	Truck* truck;
//	// for VIP
//	if (V_truck_Loading==nullptr && V_truckslist_empty->peek(truck))
//	{
//		if (V_cargos->getcount() >= truck->getcapacity())
//		{
//			V_truckslist_empty->dequeue(truck);
//			//V_truckslist_loading->(truck);
//			V_truck_Loading = truck;
//			for (int i = 0; i < truck->getcapacity(); i++)
//			{
//				V_cargos->dequeue(cargo);
//				temp_V_waiting->enqueue(cargo, calcprio(cargo));
//			}
//			NoEmptyTrucks--;
//			NoLoadingTrucks++;
//		}
//	}
//	else if (V_truckslist_empty->isEmpty() && N_truckslist_empty->peek(truck))
//	{
//		if (V_cargos->getcount() >= truck->getcapacity())
//		{
//			N_truckslist_empty->dequeue(truck);
//			//V_truckslist_loading->enqueue(truck);
//			V_truck_Loading = truck;
//			for (int i = 0; i < truck->getcapacity(); i++)
//			{
//				V_cargos->dequeue(cargo);
//				temp_V_waiting->enqueue(cargo, calcprio(cargo));
//			}
//			NoEmptyTrucks--;
//			NoLoadingTrucks++;
//		}
//	}
//	else if (V_truckslist_empty->isEmpty() && S_truckslist_empty->peek(truck))
//	{
//		if (V_cargos->getcount() >= truck->getcapacity())
//		{
//			S_truckslist_empty->dequeue(truck);
//			//V_truckslist_loading->enqueue(truck);
//			V_truck_Loading = truck;
//			for (int i = 0; i < truck->getcapacity(); i++)
//			{
//				V_cargos->dequeue(cargo);
//				temp_V_waiting->enqueue(cargo, calcprio(cargo));
//			}
//			NoEmptyTrucks--;
//			NoLoadingTrucks++;
//		}
//	}
//	//For Special
//	if (/S_truckslist_loading->isEmpty()/S_truck_Loading==nullptr && S_truckslist_empty->peek(truck) && S_cargos->getcount() >= truck->getcapacity())
//	{
//		S_truckslist_empty->dequeue(truck);
//		//S_truckslist_loading->enqueue(truck);
//		S_truck_Loading = truck;
//		for (int i = 0; i < truck->getcapacity(); i++)
//		{
//			S_cargos->dequeue(cargo);
//			temp_S_waiting->enqueue(cargo);
//		}
//		NoEmptyTrucks--;
//		NoLoadingTrucks++;
//	}
//
//	//for Normal
//	if (/N_truckslist_loading->isEmpty()/N_truck_Loading==nullptr && N_truckslist_empty->peek(truck))
//	{
//		if (N_cargos->getcount() >= truck->getcapacity())
//		{
//			N_truckslist_empty->dequeue(truck);
//			//N_truckslist_loading->enqueue(truck);
//			N_truck_Loading = truck;
//			for (int i = 0; i < truck->getcapacity(); i++)
//			{
//				N_cargos->GetFirstItem(cargo);
//				temp_N_waiting->InsertEnd(cargo);
//				N_cargos->DeleteFirst();
//			}
//			NoEmptyTrucks--;
//			NoLoadingTrucks++;
//		}
//	}
//	else if (N_truckslist_empty->isEmpty() && V_truckslist_empty->peek(truck))
//	{
//		if (N_cargos->getcount() >= truck->getcapacity())
//		{
//			V_truckslist_empty->dequeue(truck);
//			//N_truckslist_loading->enqueue(truck);
//			N_truck_Loading = truck;
//			for (int i = 0; i < truck->getcapacity(); i++)
//			{
//				N_cargos->GetFirstItem(cargo);
//				temp_N_waiting->InsertEnd(cargo);
//				N_cargos->DeleteFirst();
//			}
//			NoEmptyTrucks--;
//			NoLoadingTrucks++;
//		}
//	}
//}
//
//void Company::LoadCargos()
//{
//	Cargos* cargo;
//	Truck* truck;
//
//	if (temp_V_waiting->peekFront(cargo))
//	{
//		if (/V_truckslist_loading->peek(truck)/V_truck_Loading!=nullptr && truck->getcapacity() != 0)
//		{
//			counter_for_loading++;
//			if (counter_for_loading == cargo->getloadtime())
//			{
//				temp_V_waiting->dequeue(cargo);
//				truck->AddCargoToList(cargo);
//				V_cargos_count--;
//				NoWaitingCargos--;
//				counter_for_loading = 0;
//			}
//
//		}
//
//	}
//
//	if (temp_S_waiting->peek(cargo))
//	{
//		if (/S_truckslist_loading->peek(truck)/S_truck_Loading != nullptr && truck->getcapacity() != 0)
//		{
//			counter_for_loading++;
//			if (counter_for_loading == cargo->getloadtime())
//			{
//				temp_S_waiting->dequeue(cargo);
//				truck->AddCargoToList(cargo);
//				S_Cargos_count--;
//				NoWaitingCargos--;
//				counter_for_loading = 0;
//			}
//
//		}
//	}
//	
//
//	if (temp_N_waiting->GetFirstItem(cargo))
//	{
//		if (/N_truckslist_loading->peek(truck)/ N_truck_Loading != nullptr && truck->getcapacity() != 0)
//		{
//			counter_for_loading++;
//			if (counter_for_loading == cargo->getloadtime())
//			{
//				temp_N_waiting->DeleteFirst();
//				truck->AddCargoToList(cargo);
//				N_cargos_count--;
//				NoWaitingCargos--;
//				counter_for_loading = 0;
//			}
//
//		}
//	}
//
//}

void Company::AvailToLoading()
{
	Cargos* cargo;
	Truck* truck;
	// for VIP
	if (V_truck_Loading == nullptr && V_truckslist_empty->peek(truck))
	{
		if (V_cargos->getcount() >= truck->getcapacity())
		{
			V_truckslist_empty->dequeue(truck);
			//V_truckslist_loading->enqueue(truck);
			V_truck_Loading = truck;
			for (int i = 0; i < truck->getcapacity(); i++)
			{
				V_cargos->dequeue(cargo);
				temp_V_waiting->enqueue(cargo, calcprio(cargo));
			}
			NoEmptyTrucks--;
			NoLoadingTrucks++;
		}
	}
	else if (V_truckslist_empty->isEmpty() && N_truckslist_empty->peek(truck))
	{
		if (V_cargos->getcount() >= truck->getcapacity())
		{
			N_truckslist_empty->dequeue(truck);
			//V_truckslist_loading->enqueue(truck);
			V_truck_Loading = truck;
			for (int i = 0; i < truck->getcapacity(); i++)
			{
				V_cargos->dequeue(cargo);
				temp_V_waiting->enqueue(cargo, calcprio(cargo));
			}
			NoEmptyTrucks--;
			NoLoadingTrucks++;
		}
	}
	else if (V_truckslist_empty->isEmpty() && S_truckslist_empty->peek(truck))
	{
		if (V_cargos->getcount() >= truck->getcapacity())
		{
			S_truckslist_empty->dequeue(truck);
			//V_truckslist_loading->enqueue(truck);
			V_truck_Loading = truck;
			for (int i = 0; i < truck->getcapacity(); i++)
			{
				V_cargos->dequeue(cargo);
				temp_V_waiting->enqueue(cargo, calcprio(cargo));
			}
			NoEmptyTrucks--;
			NoLoadingTrucks++;
		}
	}
	//For Special
	if (S_truck_Loading == nullptr && S_truckslist_empty->peek(truck) && S_cargos->getcount() >= truck->getcapacity())
	{
		S_truckslist_empty->dequeue(truck);
		//S_truckslist_loading->enqueue(truck);
		S_truck_Loading = truck;
		for (int i = 0; i < truck->getcapacity(); i++)
		{
			S_cargos->dequeue(cargo);
			temp_S_waiting->enqueue(cargo);
		}
		NoEmptyTrucks--;
		NoLoadingTrucks++;
	}

	//for Normal
	if (N_truck_Loading == nullptr && N_truckslist_empty->peek(truck))
	{
		if (N_cargos->getcount() >= truck->getcapacity())
		{
			N_truckslist_empty->dequeue(truck);
			//N_truckslist_loading->enqueue(truck);
			N_truck_Loading = truck;
			for (int i = 0; i < truck->getcapacity(); i++)
			{
				N_cargos->GetFirstItem(cargo);
				temp_N_waiting->InsertEnd(cargo);
				N_cargos->DeleteFirst();
			}
			NoEmptyTrucks--;
			NoLoadingTrucks++;
		}
	}
	else if (N_truckslist_empty->isEmpty() && V_truckslist_empty->peek(truck))
	{
		if (N_cargos->getcount() >= truck->getcapacity())
		{
			V_truckslist_empty->dequeue(truck);
			//N_truckslist_loading->enqueue(truck);
			N_truck_Loading = truck;
			for (int i = 0; i <= truck->getcapacity(); i++)
			{
				N_cargos->GetFirstItem(cargo);
				temp_N_waiting->InsertEnd(cargo);
				N_cargos->DeleteFirst();
			}
			NoEmptyTrucks--;
			NoLoadingTrucks++;
		}
	}
	if (MaxWaitRule()) //MZ
	{
		if (maxconditionN)
		{
			if (N_truck_Loading == nullptr && N_truckslist_empty->peek(truck))
			{
				if (N_cargos->getcount() < truck->getcapacity())
				{
					N_truckslist_empty->dequeue(truck);
					//N_truckslist_loading->enqueue(truck);
					N_truck_Loading = truck;
					for (int i = 0; i <= N_cargos->getcount(); i++)
					{
						N_cargos->GetFirstItem(cargo);
						temp_N_waiting->InsertEnd(cargo);
						N_cargos->DeleteFirst();
					}
					NoEmptyTrucks--;
					NoLoadingTrucks++;
				}
			}
		}
		else if (N_truckslist_empty->isEmpty() && V_truckslist_empty->peek(truck))
		{
			if (N_cargos->getcount() < truck->getcapacity())
			{
				V_truckslist_empty->dequeue(truck);
				//N_truckslist_loading->enqueue(truck);
				N_truck_Loading = truck;
				for (int i = 0; i < N_cargos->getcount(); i++)
				{
					N_cargos->GetFirstItem(cargo);
					temp_N_waiting->InsertEnd(cargo);
					N_cargos->DeleteFirst();
				}
				NoEmptyTrucks--;
				NoLoadingTrucks++;
			}
		}
		if (maxconditionS) {
			if (S_truck_Loading == nullptr && S_truckslist_empty->peek(truck) && S_cargos->getcount() < truck->getcapacity())
			{
				S_truckslist_empty->dequeue(truck);
				//S_truckslist_loading->enqueue(truck);
				S_truck_Loading = truck;
				for (int i = 0; i < S_cargos->getcount(); i++)
				{
					S_cargos->dequeue(cargo);
					temp_S_waiting->enqueue(cargo);
				}
				NoEmptyTrucks--;
				NoLoadingTrucks++;
			}
		}
	}
}

void Company::LoadCargos()
{
	Cargos* cargo;
	Truck* truck;


	if (V_truck_Loading != nullptr && (V_truck_Loading->CheckIfCargoListIsEmpty()))
	{
		truck = V_truck_Loading;
		truck->SetLoadingTimeDay(curr_Day);
		truck->SetLoadingTimeHour(curr_Hour);
		//counter_for_V_loading++;
		//truck->calc_TotalLoadTime();
		//if (counter_for_V_loading == truck->get_Total_Load_Time())
		//{
		while (!(temp_V_waiting->isEmpty()))
		{
			if (temp_V_waiting->dequeue(cargo) && truck->getcapacity() != 0)
			{
				truck->AddCargoToList(cargo);
				V_cargos_count--;
				NoWaitingCargos--;
			}
		}
		truck->setTotalLoadingTimeCargos(truck->calcTotalLoadingTimeCargos());

		//NoWaitingCargos--;
		//counter_for_V_loading = 0;
	//}
	}

	/*if (temp_V_waiting->peekFront(cargo))
	{
		if (V_truckslist_loading->peek(truck) && truck->getcapacity() != 0)
		{
			counter_for_loading++;
			if (counter_for_loading == cargo->getloadtime())
			{
				temp_V_waiting->dequeue(cargo);
				truck->AddCargoToList(cargo);
				V_cargos_count--;
				NoWaitingCargos--;
				counter_for_loading = 0;
			}

		}

	}*/
	if (S_truck_Loading != nullptr && (S_truck_Loading->CheckIfCargoListIsEmpty()))
	{
		truck = S_truck_Loading;
		truck->SetLoadingTimeDay(curr_Day);
		truck->SetLoadingTimeHour(curr_Hour);
		/*counter_for_S_loading++;
		truck->calc_TotalLoadTime();
		if (counter_for_S_loading == truck->get_Total_Load_Time())
		{*/
		while (!(temp_S_waiting->isEmpty()))
		{
			if (temp_S_waiting->dequeue(cargo) && truck->getcapacity() != 0)
			{
				truck->AddCargoToList(cargo);
				S_Cargos_count--;
				NoWaitingCargos--;
			}
		}
		truck->setTotalLoadingTimeCargos(truck->calcTotalLoadingTimeCargos());

		//NoWaitingCargos--;
		//counter_for_S_loading = 0;
	//}
	}
	/*if (temp_S_waiting->peek(cargo))
	{
		if (S_truckslist_loading->peek(truck) && truck->getcapacity() != 0)
		{
			counter_for_loading++;
			if (counter_for_loading == cargo->getloadtime())
			{
				temp_S_waiting->dequeue(cargo);
				truck->AddCargoToList(cargo);
				S_Cargos_count--;
				NoWaitingCargos--;
				counter_for_loading = 0;
			}

		}
	}*/

	if (N_truck_Loading != nullptr && (N_truck_Loading->CheckIfCargoListIsEmpty()))
	{
		truck = N_truck_Loading;
		truck->SetLoadingTimeDay(curr_Day);
		truck->SetLoadingTimeHour(curr_Hour);
		/*counter_for_N_loading++;
		truck->calc_TotalLoadTime();
		if (counter_for_N_loading == truck->get_Total_Load_Time())
		{*/
		while (!(temp_N_waiting->IsEmpty()))
		{
			if (temp_N_waiting->GetFirstItem(cargo) && truck->getcapacity() != 0)
			{
				temp_N_waiting->DeleteFirst();
				truck->AddCargoToList(cargo);
				N_cargos_count--;
				NoWaitingCargos--;
			}
		}

		truck->setTotalLoadingTimeCargos(truck->calcTotalLoadingTimeCargos());

		//counter_for_N_loading = 0;
	//}
	}

	/*if (temp_N_waiting->GetFirstItem(cargo))
	{
		if (N_truckslist_loading->peek(truck) && truck->getcapacity() != 0)
		{
			counter_for_loading++;
			if (counter_for_loading == cargo->getloadtime())
			{
				temp_N_waiting->DeleteFirst();
				truck->AddCargoToList(cargo);
				N_cargos_count--;
				NoWaitingCargos--;
				counter_for_loading = 0;
			}

		}
	}*/

}


void Company::DeliverCargos()
{
	Cargos* cargo;
	Truck* truck;
	LinkedQueue<Truck*>* temp = new LinkedQueue<Truck*>;
	while (Moving_TruckList->dequeue(truck))
	{
		if (truck->PeekCargoList(cargo))
		{
			if ((cargo->GetCDT_Day()) == curr_Day && (cargo->GetCDT_Hour()) == curr_Hour)
			{

				//if (counter_for_unloading == cargo->getloadtime())
				{
					truck->RemoveCargoFromList(cargo);
					cargos_delivered->enqueue(cargo);
					NoMovingCargos--;
					NoDeliveredCargos++;
				}
			}
			temp->enqueue(truck);
		}
	}
	while (temp->dequeue(truck))
	{
		int time = truck->GetDropOffDay() * 24 + truck->GetDropOffHour();
		Moving_TruckList->enqueue(truck, time);
	}

}



Company::~Company()
{
	delete N_cargos;
	delete S_cargos;
	delete V_cargos;

	delete temp_N_waiting;
	delete temp_S_waiting;
	delete temp_V_waiting;

	delete N_truckslist_empty;  //normal trucks list
	delete S_truckslist_empty;  //special trucks list
	delete V_truckslist_empty;  //VIP trucks list

	//delete N_truckslist_loading;  //normal trucks list
	//delete S_truckslist_loading;  //special trucks list
	//delete V_truckslist_loading;  //VIP trucks list

	//delete N_cargos_delivered;
	//delete S_cargos_delivered;
	//delete V_cargos_delivered;
	delete cargos_delivered;

	delete ListofEvents;

}
void Company::MovingToAvailable()       //Moves the truck from moving list to empty list or checkup list
{
	Truck* TruckToReturn;
	//truckToReturn iterate on all moving trucks

	while ((Moving_TruckList->peekFront(TruckToReturn)) && TruckToReturn->GetDropOffDay() == curr_Day && TruckToReturn->GetDropOffHour() == curr_Hour)
	{
		char t = TruckToReturn->gettype();
		TruckToReturn->SetnoOfJourneys(TruckToReturn->GetnoOfJourneys() + 1);
		if (!TruckToReturn->NeedsCheckup())
		{
			Moving_TruckList->dequeue(TruckToReturn);
			if (t == 'N')
			{
				N_truckslist_empty->enqueue(TruckToReturn);
			}
			else if (t == 'S')
			{
				S_truckslist_empty->enqueue(TruckToReturn);
			}
			else
			{
				V_truckslist_empty->enqueue(TruckToReturn);
			}
			NoEmptyTrucks++;



		}
		if (TruckToReturn->NeedsCheckup())
		{
			int MaintenanceEndDay = 0;
			int MaintenanceEndHour = TruckToReturn->GetCheckupDuration() + curr_Hour;
			if (MaintenanceEndHour > 24)
			{
				MaintenanceEndDay = MaintenanceEndHour / 24;
				MaintenanceEndHour = MaintenanceEndHour - (24 * MaintenanceEndDay);
			}

			TruckToReturn->SetMaintenance_EndHour(MaintenanceEndHour);
			TruckToReturn->SetMaintenance_EndDay(MaintenanceEndDay);
			TruckToReturn->SetIsInCheckup(true);
			Moving_TruckList->dequeue(TruckToReturn);
			if (t == 'N')
			{
				N_truckslist_inCheckup->enqueue(TruckToReturn);
			}
			else if (t == 'S')
			{
				S_truckslist_inCheckup->enqueue(TruckToReturn);
			}
			else
			{
				V_truckslist_inCheckup->enqueue(TruckToReturn);
			}
			NoInCheckupTrucks++;
		}
		TruckToReturn->setmovingday(0);
		TruckToReturn->setmovinghour(0);
		TruckToReturn->SetDropOffDay(0);
		TruckToReturn->SetDropOffHour(0);
		TruckToReturn->SetPrioTruck(0);
		TruckToReturn->setTotalLoadingTimeCargos(0);
	}
}
void Company::CheckupToAvailable()
{
	Truck* TruckInCheckup;


	//For Normal Trucks

	while (N_truckslist_inCheckup->peek(TruckInCheckup))
	{
		char t = TruckInCheckup->gettype();
		if (curr_Day == TruckInCheckup->GetMaintenance_EndDay() && curr_Hour == TruckInCheckup->GetMaintenance_EndHour())
		{
			N_truckslist_inCheckup->dequeue(TruckInCheckup);
			N_truckslist_empty->enqueue(TruckInCheckup);
			TruckInCheckup->SetMaintenance_EndDay(0);
			TruckInCheckup->SetMaintenance_EndHour(0);
			TruckInCheckup->SetnoOfJourneys(0);
		}

	}

	//For Special trucks

	while (S_truckslist_inCheckup->peek(TruckInCheckup))
	{
		char t = TruckInCheckup->gettype();
		if (curr_Day == TruckInCheckup->GetMaintenance_EndDay() && curr_Hour == TruckInCheckup->GetMaintenance_EndHour())
		{
			S_truckslist_inCheckup->dequeue(TruckInCheckup);
			S_truckslist_empty->enqueue(TruckInCheckup);
			TruckInCheckup->SetMaintenance_EndDay(0);
			TruckInCheckup->SetMaintenance_EndHour(0);
		}

	}

	//For VIP Trucks

	while (V_truckslist_inCheckup->peek(TruckInCheckup))
	{
		char t = TruckInCheckup->gettype();
		if (curr_Day == TruckInCheckup->GetMaintenance_EndDay() && curr_Hour == TruckInCheckup->GetMaintenance_EndHour())
		{
			V_truckslist_inCheckup->dequeue(TruckInCheckup);
			V_truckslist_empty->enqueue(TruckInCheckup);
			TruckInCheckup->SetMaintenance_EndDay(0);
			TruckInCheckup->SetMaintenance_EndHour(0);
		}

	}


}
bool Company::OffHours()
{
	if (curr_Hour >= 5 && curr_Hour <= 23)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool Company::MaxWaitRule()
{
	Cargos* cargo;
	
	if (!(N_cargos->IsEmpty()))
	{
		N_cargos->GetFirstItem(cargo);
		if ((cargo->getprepartionhour()) + MaxW + 24*(cargo->getprepartionday()) == curr_Hour + 24*curr_Day)
		{
			maxconditionN = 1;
			return true;
		}
	}

	if (!(S_cargos->isEmpty()))
	{
		while (S_cargos->peek(cargo))
		{
			if ((cargo->getprepartionhour()) + MaxW + 24 * (cargo->getprepartionday()) == curr_Hour + 24 * curr_Day)
			{
				maxconditionS = 1;
					return true;
			}
		}

	}

	return false;
}
