#pragma once
using namespace std;
#include <iostream>
#include "Cargos.h"
#include "LinkedQueue.h"
#include"PriorityQueue.h"

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
	PriorityQueue<Cargos*>* List_Cargos;
	int count_cargos;
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
	bool AddCargoToList(Cargos* c);
	bool RemoveCargoFromList(Cargos*& c);
	void set_count_cargos(int c);
	int get_count_cargos();

	void PrintCargosList();
};


