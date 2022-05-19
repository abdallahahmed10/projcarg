#pragma once
using namespace std;
#include <iostream>
#include "Cargos.h"
#include"PriorityQueue.h"

class Truck
{
	char type;
	int capacity;
	int speed;
	int noOfJourenrys;
	int checkupDuration;
	int id;

	int maintenance_timeDay;
	int maintenance_timeHour;
	int movingday;
	int movinghour;
	int dropOffDay;               //WT
	int dropOffHour;              //WT
	int JourneysCompleted;
	bool InCheckup = false;



	PriorityQueue<Cargos*>* List_Cargos;
	int count_cargos;
public:
	~Truck();
	friend ostream& operator << (ostream&, const Truck*);
	Truck(char T, int SPEED, int CAP,int noJ, int checkD,int ID);
	/*Truck(int m, int dild, int dilh);*/
	char gettype();
	int getcapacity();
	int getspeed();

	int getmovingday();
	int getmovinghour();
	void setmovingday(int DTD);
	void setmovinghour(int DTH);

	void settype(char T);
	void setcapacity(int CAP);
	
	void setspeed(int SPEED);
	int getid();

	void SetMaintenance_TimeDay(int MTD);
	void SetMaintenance_TimeHour(int MTH);
	int GetMaintenance_TimeDay();
	int GetMaintenance_TimeHour();

	int GetCheckupDuration();
	void SetCheckupDuration(int CD);

	bool NeedsCheckup();
	void CalcDropOff();

	void SetIsInCheckup(bool IC);
	bool GetIsInCheckup();

	int GetDropOffDay();
	int GetDropOffHour();
	void SetDropOffDay(int DD);
	void SetDropOffHour(int DH);

	void setdeliveryintervelday(int DTD);
	void setdeliveryintervelhour(int DTH);
	void setmovingday(int MD);
	void setmovinghour(int MH);
	int getmovingday();
	int getmovinghour();

	bool AddCargoToList(Cargos* c);
	bool RemoveCargoFromList(Cargos*& c);
	void set_count_cargos(int c);
	int get_count_cargos();

	void PrintCargosList();
};


