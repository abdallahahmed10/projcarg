#include "Truck.h"

Truck::Truck(char T, int SPEED, int CAP, int noJ, int checkD, int ID)
{
	type = T;
	capacity = CAP;
	noOfJourenrys = noJ;
	checkupDuration = checkD;
	speed = SPEED;
	id = ID;
	List_Cargos = new PriorityQueue<Cargos*>;
	count_cargos = 0;

	maintenance_EndDay = 0;
	maintenance_EndHour = 0;
	movingday = 0;
	movinghour = 0;
	dropOffDay = 0;
	dropOffHour = 0;

}
Truck::~Truck()
{
	delete List_Cargos;
}

//Truck::Truck(int m, int dild, int dilh)
//{
//	 mantince_time=m;
//	 deliveryintervelday = dild;
//	 deliveryintervelhour = dilh;
//
//}

char Truck::gettype()
{
	return type;
}

int Truck::getcapacity()
{
	return capacity;
}

int Truck::getspeed()
{
	return speed;
}


int Truck::getmovingday()
{
	return movingday;
}

int Truck::getmovinghour()
{
	return movinghour;
}

void Truck::settype(char T)
{
	type = T;
}

void Truck::setcapacity(int CAP)
{
	capacity = CAP;
}

void Truck::setspeed(int SPEED)
{
	speed = SPEED;
}

void Truck::setmovingday(int MD)
{
	this->movingday = MD;
}

//void Truck::setmovinghour(int MH)
//{
//	movinghour = MH;
//}

ostream& operator<<(ostream& output, const Truck* t)
{
	output << (t->id);
	return output;
	// TODO: insert return statement here
}

int Truck::getid()
{
	return id;
}

int Truck::GetCheckupDuration()
{
	return checkupDuration;
}

void Truck::SetCheckupDuration(int CD)
{
	checkupDuration = CD;
}

bool Truck::NeedsCheckup()
{
	if (JourneysCompleted % noOfJourenrys == 0)
	{
		return true;
	}
	return false;
}

void Truck::SetIsInCheckup(bool IC)
{
	InCheckup = IC;
}

bool Truck::GetIsInCheckup()
{
	return InCheckup;
}

int Truck::CalcDropOff()
{
	int DeliveryDistOfFurthest = 0;
	int SumOfUnload = 0;
	Cargos* cargo;
	PriorityQueue<Cargos*>* temp = new PriorityQueue<Cargos*>;
	while (List_Cargos->peekFront(cargo))
	{
		int x = cargo->getdelivery_dist();
		SumOfUnload += cargo->getloadtime();
		if (x > DeliveryDistOfFurthest)
			DeliveryDistOfFurthest = x;
		List_Cargos->dequeue(cargo);
		temp->enqueue(cargo, 1 / (cargo->getdelivery_dist()) * 100);
	}
	while (temp->dequeue(cargo))
	{
		List_Cargos->enqueue(cargo, 1 / (cargo->getdelivery_dist()) * 100);
	}
	int DIHours = 2 * (DeliveryDistOfFurthest / speed) + SumOfUnload;
	int DIDays = DIHours / 24;
	DIHours = DIHours - (24 * DIDays);

	dropOffDay = movingday + DIDays;
	dropOffHour = movinghour + DIHours;
	PrioValTruck = ((dropOffHour + (dropOffDay * 24)) * (-1));
	return PrioValTruck;
}

int Truck::GetDropOffDay()
{
	return dropOffDay;
}
void Truck::SetDropOffDay(int DD)
{
	dropOffDay = DD;
}

int Truck::GetDropOffHour()
{
	return dropOffHour;
}
void Truck::SetDropOffHour(int DH)
{
	dropOffHour = DH;
}
void Truck::SetMaintenance_TimeDay(int MTD)
{
	maintenance_timeDay = MTD;
}
int Truck::GetMaintenance_TimeDay()
{
	return maintenance_timeDay;
}

void Truck::SetMaintenance_TimeHour(int MTH)
{
	maintenance_timeHour = MTH;
}
int Truck::GetMaintenance_TimeHour()
{
	return maintenance_timeHour;
}


void Truck::SetPrioTruck(int prio)
{
	PrioValTruck = prio;
}
int Truck::GetPrioTruck()
{
	return PrioValTruck;
}



void Truck::set_count_cargos(int c)
{
	count_cargos = c;
}
int Truck::get_count_cargos()
{
	return count_cargos;
}
bool Truck::AddCargoToList(Cargos* c)
{
	if (capacity != 0)
	{
		List_Cargos->enqueue(c, (1 / c->getdelivery_dist()) * 10000);     //this so that the cargo with the least distance is placed first
		count_cargos++;
		capacity--;
		return true;
	}
	return false;

}
bool Truck::RemoveCargoFromList(Cargos*& c)
{
	if (!List_Cargos)
		return false;
	List_Cargos->dequeue(c);
	count_cargos--;
	capacity++;
	return true;
}

void Truck::PrintCargosList()
{
	List_Cargos->PrintList();
}

int Truck::getTotalLoadingTimeCargos()
{
	return totalloadtimeofcargos;
}

int Truck::calcTotalLoadingTimeCargos()
{
	Cargos* cargo1;
	LinkedQueue <Cargos*>* Q = new LinkedQueue <Cargos*>;
	while (List_Cargos->dequeue(cargo1))
	{
		Q->enqueue(cargo1);
		totalloadtimeofcargos = totalloadtimeofcargos + cargo1->getloadtime();
	}
	while (Q->dequeue(cargo1))
	{
		List_Cargos->enqueue(cargo1, 0);
	}
	return totalloadtimeofcargos;

}

void Truck::setTotalLoadingTimeCargos(int FT)
{
	totalloadtimeofcargos = FT;
}

//int Truck::getTotalLoadingTime()
//{
//	return loadingtime;
//}
//
//void Truck::setTotalLoadingTime(int FT)
//{
//	loadingtime = FT;
//}
void Truck::SetLoadingTimeDay(int LTD)
{
	LoadingTime_Day = LTD;
}
void Truck::SetLoadingTimeHour(int LTH)
{
	LoadingTime_Hour = LTH;
}
int Truck::getLoadingTimeDay()
{
	return LoadingTime_Day;
}
int Truck::getLoadingTimeHour()
{
	return LoadingTime_Hour;
}
void Truck::SetnoOfJourneys(int nOj)
{
	noOfJourenrys = nOj;
}

int Truck::GetnoOfJourneys()
{
	return noOfJourenrys;
}




void Truck::SetMaintenance_EndDay(int MTD)  //tet8ayar 3nd el ba2y
{
	maintenance_EndDay = MTD;
}
int Truck::GetMaintenance_EndDay()
{
	return maintenance_EndDay;
}

void Truck::SetMaintenance_EndHour(int MTH)
{
	maintenance_EndHour = MTH;
}
int Truck::GetMaintenance_EndHour()
{
	return maintenance_EndHour;
}

void Truck::setmovinghour(int MH)
{
	movinghour = MH;
}