#pragma once
#include<iostream>
#include<fstream>
#include <Windows.h>
#include "Company.h"
using namespace std;

class Company;

class UI
{
private:
	int Mode;
public:
	UI();
	string setMode(Company* pcompany);
	int getMode();
	void Interactive_StepByStep(Company* pcompany);
	void Silent();
};
