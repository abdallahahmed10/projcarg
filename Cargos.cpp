#include "Cargos.h"
Cargos::Cargos(char T, int LOAD, int DD, int COST, int ID, int PD, int PH)
{
	type = T;
	loadtime = LOAD;
	delivery_dist = DD;
	cost = COST;
	id = ID;
	prepartionday = PD;
	prepartionhour = PH;
}

char Cargos::gettype()
{
	return type;
}

int Cargos::getloadtime()
{
	return loadtime;
}


int Cargos::getdelivery_dist()
{
	return delivery_dist;
}

int Cargos::getcost()
{
	return cost;
}

int Cargos::getid()
{
	return id;
}

int Cargos::getprepartionday()
{
	return prepartionday;
}

int Cargos::getprepartionhour()
{
	return prepartionhour;
}

void Cargos::settype(char T)
{
	type = T;
}

void Cargos::setloadtime(int LOAD)
{
	loadtime = LOAD;
}



void Cargos::setdelivery_dist(int DD)
{
	delivery_dist = DD;
}

void Cargos::setcost(int COST)
{
	cost = COST;
}

void Cargos::setid(int ID)
{
	id = ID;
}

void Cargos::setprepartionday(int PD)
{
	prepartionday = PD;
}

void Cargos::setprepartionhour(int PH)
{
	prepartionhour = PH ;
}
bool  Cargos::operator== (const int x)
{
	if (id == x)
		return true;
	return false;
}
