#pragma once
//#include"Company.h"
//et is event time
class Company;

class Events
{
	int etday;
	int ethour;
	int id;
public:
	Events();
	virtual void execute(Company *pcompany) = 0;
	Events(int etd, int ethr,int ID);
	void setetday(int etd);
	void setethour(int ethr);
	int getetday();
	int getethour();
	void setid(int ID);
	int getid();
};

