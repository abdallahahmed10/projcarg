#pragma once
#include "Events.h"
#include "Cargos.h"
class Events;
class ReadyEvents : public Events
{
    char Cargotype;
    int Dist;
    int loadtime;
    //int unloadtime;
    int cost;
public:
    ReadyEvents();
    ~ReadyEvents();
    ReadyEvents(char type,int etd,int ethr,int ID,int dist ,int lt,int c);
    void execute(Company * pcompany);
};

