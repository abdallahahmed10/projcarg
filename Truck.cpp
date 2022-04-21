#include "Truck.h"

Truck::Truck(char T, int SPEED , int CAP , int noJ, int checkD)
{
	type = T;
	capacity = CAP;
	noOfJourenrys = noJ;
	checkupDuration = checkD;
	speed = SPEED;
}

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
