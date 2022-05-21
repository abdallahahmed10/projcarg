#include "CancellationEvents.h"
#include "Company.h"

CancellationEvents::CancellationEvents()
{
}

CancellationEvents::~CancellationEvents()
{
}

CancellationEvents::CancellationEvents(int etd, int ethr, int id)
{
	setetday(etd);
	setethour(ethr);
	setid(id);
}

void CancellationEvents::execute(Company* pcompany)
{
	pcompany->cancellationcargo(getid());
}
