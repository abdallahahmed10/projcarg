#pragma once
#include "Events.h"

class Events;
class CancellationEvents : public Events
{
public:
    CancellationEvents();
    ~CancellationEvents();
    CancellationEvents(int etd, int ethr, int id);
    void execute(Company* pcompany);
};

