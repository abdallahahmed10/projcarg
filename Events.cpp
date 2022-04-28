#include "Events.h"
#include "Company.h"

Events::Events()
{
}

Events::Events(int etd, int ethr, int ID)
{
	etday = etd;
	ethour = ethr;
	id = ID;
}

void Events::setetday(int etd)
{
	etday = etd;
}

void Events::setethour(int ethr)
{
	ethour = ethr;
}

int Events::getetday()
{
	return etday;
}

int Events::getethour()
{
	return ethour;
}

void Events::setid(int ID)
{
	id = ID;
}

int Events::getid()
{
	return id;
}
