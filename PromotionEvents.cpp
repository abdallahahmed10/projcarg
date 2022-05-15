#include "PromotionEvents.h"
#include "Company.h"

PromotionEvents::PromotionEvents()
{
}

PromotionEvents::~PromotionEvents()
{
}

PromotionEvents::PromotionEvents(int etd, int ethr, int id, int money)
{
	setetday(etd);
	setethour(ethr);
	setid(id);
	cost = money;
}

void PromotionEvents::execute(Company* pcompany)
{
	pcompany->promotion(getid());
}

int PromotionEvents::getCost()
{
	return cost;
}