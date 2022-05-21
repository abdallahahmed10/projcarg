#include "ReadyEvents.h"
#include "Company.h"

ReadyEvents::ReadyEvents()
{
}

ReadyEvents::~ReadyEvents()
{
}

ReadyEvents::ReadyEvents(char type, int etd, int ethr, int ID, int dist, int lt, int c)
{
	Cargotype = type;
	setetday(etd);
	setethour(ethr);
	setid(ID);
	Dist = dist;
	loadtime = lt;
	cost = c;
}

void ReadyEvents::execute(Company* pcompany)
{
	Cargos* newcargo = new Cargos(Cargotype, loadtime, Dist, cost, getid(), getetday() , getethour());
	pcompany->addtoline(newcargo, pcompany->calcprio(newcargo));
}
