#include "Truck.h"

Truck::Truck(char T, int SPEED, int CAP, int noJ, int checkD,int ID)
{
	type = T;
	capacity = CAP;
	noOfJourenrys = noJ;
	checkupDuration = checkD;
	speed = SPEED ;
	id=ID;
	List_Cargos = new PriorityQueue<Cargos*>;
	count_cargos = 0;
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

int Truck::getmantince_time()
{
	return mantince_time;
}

int Truck::getspeed()
{
	return speed;
}

int Truck::getdeliveryintervelday()
{
	return deliveryintervelday;
}

int Truck::getdeliveryintervelhour()
{
	return deliveryintervelhour;
}

void Truck::settype(char T)
{
	type = T;
}

void Truck::setcapacity(int CAP)
{
	capacity = CAP;
}

void Truck::setmantince_time(int MT)
{
	mantince_time = MT;
}

void Truck::setspeed(int SPEED)
{
	speed = SPEED;
}

void Truck::setdeliveryintervelday(int DTD)
{
	deliveryintervelday = DTD;
}

void Truck::setdeliveryintervelhour(int DTH)
{
	deliveryintervelhour = DTH;
}

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

void Truck:: set_count_cargos(int c)
{
	count_cargos = c;
}
int Truck:: get_count_cargos()
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