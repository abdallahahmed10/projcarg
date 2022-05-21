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

	WaitingList* temp_N_waiting;
	LinkedQueue<Cargos*>* temp_S_waiting;
	PriorityQueue<Cargos*>* temp_V_waiting;

	//LinkedQueue<Cargos*>* N_cargos_delivered;
	//LinkedQueue<Cargos*>* S_cargos_delivered;
	//LinkedQueue<Cargos*>* V_cargos_delivered;
	LinkedQueue<Cargos*>* cargos_delivered;

	LinkedQueue<Truck*>* N_truckslist_empty;
	LinkedQueue<Truck*>* S_truckslist_empty;
	LinkedQueue<Truck*>* V_truckslist_empty;

	//LinkedQueue<Truck*>* N_truckslist_loading;
	//LinkedQueue<Truck*>* S_truckslist_loading;
	//LinkedQueue<Truck*>* V_truckslist_loading;
	Truck* N_truck_Loading;
	Truck* S_truck_Loading;
	Truck* V_truck_Loading;

	LinkedQueue<Truck*>* N_truckslist_inCheckup;
	LinkedQueue<Truck*>* S_truckslist_inCheckup;
	LinkedQueue<Truck*>* V_truckslist_inCheckup;

	PriorityQueue<Truck*>* Moving_TruckList;

	LinkedQueue<Events*>* ListofEvents;

	int N_cargos_count;      //count for the number of waiting normal cargos
	int V_cargos_count;      //count for the number of waiting VIP cargos
	int S_Cargos_count;      //count for the number of waiting special cargos
	//int NoOfTotalCargos;     //Total number of cargos
	
	int AutoP;  //Auto promotion limit (Day) 
	int MaxW;   //Maximum wait (Hours)
	
	UI* pUI; // pointer to UI class
	
	int NoWaitingCargos;     //Total number of cargos
	int NoLoadingTrucks;
	int NoEmptyTrucks;
	int NoMovingCargos;
	int NoInCheckupTrucks;
	int NoDeliveredCargos;
	int NoN_Trucks;
	int NoS_Trucks;
	int NoV_Trucks;
	int NoAutoProm;
	int counter_for_unloading;
	//int Flag_Unloading;

	int NoDeliveredNormalCargos , NoDeliveredSpecialCargos , NoDeliveredVIPCargos;

	
	int NoMovingTrucks;

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
	void Run();
	int GetNoWaitingCargos();
	int GetNoLoadingTrucks();
	int GetNoEmptyTrucks();
	int GetNoMovingCargos();
	int GetNoInCheckupTrucks();
	int Getcurr_Day();
	int Getcurr_Hour();
	int GetNoDeliveredCargos();
	void print_waiting_cargos();
	void print_delivered_cargos();
	void print_loading_truck();   //p2
	void print_empty_truck();
	void FiveSteps();

	void AvailToLoading();
	void LoadCargos();     //p2
	void DeliverCargos();
	void OutputFile();
	int AvgActiveTime();
	int	AvgUtilization();

	void MovingToAvailable();
	void CheckupToAvailable();

	void print_moving_truck();
	void moveatruck();
	bool OffHours();
};
