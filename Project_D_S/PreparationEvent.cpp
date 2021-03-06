#include "PreparationEvent.h"
#include "Company.h"


PreparationEvent::PreparationEvent(char typ, int dist, double lt, int cost, Time ET,int ID,Company * C):Event(ET,ID, C) {
	setType(typ);
	setDistance(dist);
	setLoadTime(lt);
	setCost(cost);
}
void PreparationEvent::setType(char t)
{
	this->TYP = t;
}

void PreparationEvent::setDistance(int d)
{
	this->DIST = d;
}

void PreparationEvent::setLoadTime(int lt)
{
	this->LT = lt;
}

void PreparationEvent::setCost(int c)
{
	this->Cost = c;
}

char PreparationEvent::getType()
{
	return this->TYP;
}

int PreparationEvent::getDistance()
{
	return this->DIST;
}

int PreparationEvent::getLoadTime()
{
	return this->LT;
}

int PreparationEvent::getCost()
{
	return this->Cost;
}

void PreparationEvent::Execute()
{
	int D = getEventTime().getDAY();
	int H = getEventTime().gethour();
	Time T = Cptr->getcurtime();
	//if (D != T.getDAY() || H != T.gethour()) return;
		int ID = getID();
		switch (TYP)
		{
		case 'N': {
			NormalCargo* NC = new NormalCargo(Cost, LT, DIST, ID, H, D);
			Cptr->AddCargotoNormalWaiting(NC);
			break; 
		}
		case 'V': {
			VIPCargo* VC = new VIPCargo(Cost, LT, DIST, ID, H, D);
			Cptr->AddCargotoVIPWaiting(VC);
			break; }
		case 'S': {
			SpecialCargo* SC = new SpecialCargo(Cost, LT, DIST, ID, H, D);
			Cptr->AddCargotoSpWaiting(SC);
			break; }
		default: {
			Cargo* Cargoptr = new Cargo(Cost, LT, DIST, ID, H, D);
			Cptr->AddCargotoNormalWaiting(Cargoptr);
			break; }
		}
		}
	

