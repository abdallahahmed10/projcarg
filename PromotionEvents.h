#pragma once
#include "Events.h"


class Events;
class PromotionEvents : public Events
{
private:
    int cost;
public:
    PromotionEvents();
    ~PromotionEvents();
    PromotionEvents(int etd, int ethr, int id , int money);
    void execute(Company* pcompany);
};

