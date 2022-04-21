#pragma once
# include "PriorityQueue.h"
#include"Events.h"
#include "LinkedQueue.h"
# include "Cargos.h"
#include "Truck.h"
#include <iostream>
#include <fstream>
#include "UI.h"
#include "ReadyEvents.h"
#include "PromotionEvents.h"
#include "CancellationEvents.h"
#include <string>
#include "WaitingList.h"

class UI;
class Events;
class Company
{
private:
	int curr_Day;         //Time of current day and hour to take actions in
	int curr_Hour;
	string fileInput;

	WaitingList* N_cargos;
	LinkedQueue<Cargos*>* S_cargos;
	PriorityQueue<Cargos*>* V_cargos;

	LinkedQueue<Truck*>* N_truckslist;
	LinkedQueue<Truck*>* S_truckslist;
	LinkedQueue<Truck*>* V_truckslist;

	LinkedQueue<Events*>* ListofEvents;

	int N_cargos_count;      //count for the number of normal cargos
	int V_cargos_count;      //count for the number of VIP cargos
	int S_Cargos_count;      //count for the number of special cargos
	int NoOfTotalCargos;     //Total number of cargos
	
	int AutoP;
	int MaxW;
public:
	Company();
	void addtoline(Cargos* c, int prio = 0);
	int calcprio(Cargos* c);
	void cancellationcargo(int id);
	void promotion(int id);
	void ExecuteEvents();
	~Company();
	void readFile();
	void setFileInput(string file);
	void AutoPromotion();
};
