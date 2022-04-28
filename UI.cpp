#include "UI.h"
UI::UI()
{
	Mode = 0;
}
string UI::setMode(Company* pcompany)
{
	string in;
	cout << "Enter file input name: (.txt)" << endl;
	cin >> in;
	cout << "Choose Mode enter number: (1-Interactive, 2-Step By Step, 3-Silent)" << endl;
	cin >> Mode;
	while (Mode != 1 && Mode != 2 && Mode != 3)
	{
		cout << "Wrong Input" << endl << "Choose Mode: (1-Interactive, 2-Step By Step, 3-Silent)" << endl;
		cin >> Mode;
	}
	return in;
}

void UI::Silent()
{
	cout << "Slient Mode" << endl << "Simulation Starts..." << endl << "Simulation ends, Output file created" << endl;
}
int UI::getMode()
{
	return Mode;
}
void UI::Interactive_StepByStep(Company* pcompany)
{
	if (Mode == 1)
	{
		system("pause");
	}
	else if (Mode == 2)
	{
		Sleep(1000);
	}
	
	cout << "Current Time (Day:Hour):" << pcompany->Getcurr_Day() << ":" 
		<< pcompany->Getcurr_Hour() << endl;
	
	cout << pcompany->GetNoWaitingCargos() << " Waiting Cargos: ";
	pcompany->print_waiting_cargos();
	cout << "-------------------------------------------------" << endl;
	cout << pcompany->GetNoLoadingTrucks()<< " Loading Trucks: " << endl;
	cout << "-------------------------------------------------" << endl;

	cout << pcompany->GetNoEmptyTrucks()<< " Empty Trucks: ";
	pcompany->print_empty_truck();
	cout << "-------------------------------------------------" << endl;
	

	cout << pcompany->GetNoMovingCargos()<< " Moving Cargos: " << endl;
	cout << "-------------------------------------------------" << endl;

	cout << pcompany->GetNoInCheckupTrucks()<< " InCheckup Trucks: " << endl;
	cout << "-------------------------------------------------" << endl;

	cout << pcompany->GetNoDeliveredCargos()<<" Delivered Cargos: " << endl;
	cout << "-------------------------------------------------" << endl << endl;

}
