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
	
	delivaryday = 0;
	delivaryhour = 0;
	TID = 0;
	waitingtimehour = 0;
	waitingtimeday = 0;
}
Cargos::Cargos(Cargos* c)
{
	type = c->gettype();
	loadtime = c->getloadtime();
	delivery_dist = c->getdelivery_dist();
	cost = c->getcost();
	id = c->getid();
	prepartionday = c->getprepartionday();
	prepartionhour = c->getprepartionhour();
	delivaryday = c->getdelivaryday();
	delivaryhour = c->getdelivaryhour();
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

ostream& operator<<(ostream &output ,const Cargos* c)
{
	output << (c->id);
	return output;
}

void Cargos::setdelivaryday(int x)
{
	delivaryday = x;
}
int Cargos::getdelivaryday()
{
	return delivaryday;
}
void Cargos::setdelivaryhour(int x)
{
	delivaryhour = x;
}
int Cargos::getdelivaryhour()
{
	return delivaryhour;
}
void Cargos::setwaitingtimeday(int x)
{
	waitingtimeday = x;
}
int Cargos::getwaitingtimeday()
{
	return waitingtimeday;
}
void Cargos::setwaitingtimehour(int x)
{
	waitingtimehour = x;
}
int Cargos::getwaitingtimehour()
{
	return waitingtimehour;
}
void Cargos::setTID(int x)
{
	TID = x;
}
int Cargos::getTID()
{
	return TID;
}
