#pragma once
template<class T>
class Queue;
#include "Queue.h"
#include "Cargo.h"
class UIClass;

//enum State  {Loading, Empty, InCheckUp};

class Truck
{
protected:
	Time ActiveTime;
	int ID; 
	int State;
	int TC; //TruckCapacity
	//State TruckState;
	int CargoCount;
	int MaintenanceTime; // In hours
	double Speed; //In Km/Hour 
	int JourneyCount;
	int TimeforGoingwithoutReturning;
	int DisofFurthestCargo;
	int LoadTimeofAllcargos;
	Queue <Cargo* > * TruckCargos;
	int DI; //Delivery Interval =(Distance of furthest cargo)/ speed + Sum of unload times of all its cargos + time to come back

public:
	int GetID();
	//void ChangeState(State S);
	Truck(int ID , int TC , int TS );
	bool AddCargo(Cargo* C);
	void updateDI();
	int getDI();
	void incrementJC();
	void resetJC();
	int getJC();
	bool RemoveCargo(Cargo* C);
	virtual void Print(UIClass*p);
	void setTruckCapacity(int);
	void setSpeed(double);
	bool isFull();
	int getTimeleftforDelivery();
	void decrementTimeleftforDelivery();
	void set_ActiveTime();		//ismail
	Time get_ActiveTime();		//ismail
	int	Truck_utilization();
};