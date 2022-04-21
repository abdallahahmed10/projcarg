#pragma once
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
public:
	Truck(char type, int speed , int capacity , int noOfJourenrys, int checkupDuration);
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

};

