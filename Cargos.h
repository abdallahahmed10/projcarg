#pragma once
using namespace std;
#include <iostream>
class Cargos
{
	char type;
	int loadtime;
	int delivery_dist;
	int cost;
	int id;
	int prepartionday;
	int prepartionhour;
public:
	friend ostream & operator <<(ostream& ,const Cargos*);
	Cargos(char type, int loadtime, int delivery_dist, int cost, int id, int prepartionday, int prepartionhour);
	Cargos(Cargos* c);
	char gettype();
	int getloadtime();
	int getdelivery_dist();
	int getcost();
	int getid();
	int getprepartionday();
	int getprepartionhour();
	void settype(char T);
	void setloadtime(int LOAD);
	void setdelivery_dist(int DD);
	void setcost(int COST);
	void setid(int ID);
	void setprepartionday(int PD);
	void setprepartionhour(int PH);
	bool operator== (const int x);

};

