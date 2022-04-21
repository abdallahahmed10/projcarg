#include "UI.h"

void UI::setMode()
{
	string in;
	cout << "Enter file input name: (.txt)" << endl;
	cin >> in;
	pcompany->setFileInput(in);
	cout << "Choose Mode enter number: (1-Interactive, 2-Step By Step, 3-Silent)" << endl;
	cin >> Mode;
	while (Mode != 1 && Mode != 2 && Mode != 3)
	{
		cout << "Wrong Input" << endl << "Choose Mode: (1-Interactive, 2-Step By Step, 3-Silent)" << endl;
		cin >> Mode;
	}
	if (Mode == 1 || Mode == 2)
		Interactive_StepByStep();
	else if (Mode == 3)
		Silent();
}

void UI::Silent()
{
	cout << "Slient Mode" << endl << "Simulation Starts..." << endl << "Simulation ends, Output file created" << endl;
}
int UI::getMode()
{
	return Mode;
}
void UI::Interactive_StepByStep()
{
	cout << "Current Time (Day:Hours):" << endl;
	cout << "Waiting Cargos: " << endl;
	cout << "Loading Trucks: " << endl;
	cout << "Empty Trucks: " << endl;
	cout << "Moving Cargos: " << endl;
	cout << "InCheckup Trucks: " << endl;
	cout << "Delivered Cargos: " << endl;
	
}
