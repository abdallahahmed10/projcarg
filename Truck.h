#pragma once
using namespace std;
#include <iostream>
#include "Cargos.h"
#include "LinkedQueue.h"

class Truck
{
	char type;
	int capacity;
	int mantince_time;
	int speed;
	int deliveryintervelday;
	int deliveryintervelhour;
	int noOfJourenrys;
	int checkupDuration;
	int id;
	LinkedQueue<Cargos*>* List_Cargos;
public:
	~Truck();
	friend ostream& operator << (ostream&, const Truck*);
	Truck(char T, int SPEED, int CAP,int noJ, int checkD,int ID);
	/*Truck(int m, int dild, int dilh);*/
	char gettype();
	int getcapacity();
	int getmantince_time();
	int getspeed();
	int getdeliveryintervelday();
	int getdeliveryintervelhour();
	void settype(char T);
	void setcapacity(int CAP);
	void setmantince_time(int MT);
	void setspeed(int SPEED);
	void setdeliveryintervelday(int DTD);
	void setdeliveryintervelhour(int DTH);
	int getid();
};


