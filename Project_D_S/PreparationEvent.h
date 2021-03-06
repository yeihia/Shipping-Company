#pragma once
#include"Event.h"
#include"Cargo.h"
#include"NormalCargo.h"
class Company;
class PreparationEvent :public Event
{
	char TYP;
	int DIST;
	double LT;
	int Cost;
public:
	PreparationEvent(char typ,	int dist, double lt, int cost, Time ET, int ID, Company * C);
	void setType(char t);
	void setDistance(int d);
	void setLoadTime(int lt);
	void setCost(int c);
	char getType();
	int getDistance();
	int getLoadTime();
	int getCost();
	virtual void  Execute();
};

