#pragma once
#include<iostream>
#include<fstream>
#include "Company.h"
using namespace std;

class Company;

class UI
{
private:
	int Mode;
	Company* pcompany;
public:
	void setMode();
	int getMode();
	void Interactive_StepByStep();
	void Silent();
};
