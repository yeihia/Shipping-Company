#pragma once                            //////////////////temp//////////////////////////////////
#include"UIClass.h"
#include "Queue.h"
#include "VIPTruck.h"
#include "NormalTruck.h"
#include "SpecialTruck.h"
#include "PriorityQueue.h"
#include "Cargo.h"
#include "Truck.h"
#include"PreparationEvent.h"
#include"PromotionEvent.h"
#include"CancellationEvent.h"
#include"Event.h"
#include"Time.h"
#include"List.h"  //temp
#include<fstream>
class Company 
{
	// Input file variables 
	
	int N; // Count of normal trucks 
	int S;	//Count of special trucks
	int V;	//Count of VIP trucks 
	int NTruckSpeed;
	int VTruckSpeed;
	int STruckSpeed;
	int NTruckCapacity;
	int VTruckCapacity;
	int STruckCapacity;
	int NTruckCheckupDuration;
	int STruckCheckupDuration; 
	int VTruckCheckupDuration; 
	int NumberofCheckupsforMaintenence;
	int NMaintenceneD;
	int VMaintenenceD;
	int SMaintenenceD;
	int MaxW;
	int AutoP; // time for automatic promotion 
	int EventCount;
	int JourneyCount;
	int TruckCount; 
	int NumberOfAutoPromotedCargos;//ismail
	int N_Cargo_Count;
	int S_Cargo_Count;
	int VIP_Cargo_Count;
	int TSM; // total simulationTime

	int VTrucks = 0;
	int NTrucks = 0;
	int STrucks = 0;
	// Cargos for Display
	//PriorityQueue<Cargo*> WaitingCargos;
	//Queue<Cargo*> DeliveredCargos;

	// Trucks loading
	Queue<Truck*> LoadingTrucks;

	//Incheckuptrucks
	Queue<Truck*> NInCheckupTrucks;
	Queue<Truck*> SInCheckupTrucks;
	Queue<Truck*> VInCheckupTrucks;

	Queue<Truck*>NMaintenenceTrucks;
	Queue<Truck*>VMaintenenceTrucks;
	Queue<Truck*>SMaintenenceTrucks;

	//Queue<Truck*> EmptyTrucks;
	PriorityQueue<Truck*> VIPEmptyTrucks;
    PriorityQueue<Truck*> NormalEmptyTrucks;
	PriorityQueue<Truck*> SpecialEmptyTrucks;
	//moving  may be edited under assignment criteria	Queue<Cargo*> MovingCargos;

	//Trucks
	Queue<Truck*>NormalTrucks;
	Queue<Truck*>SpecialTrucks;
	Queue<Truck*>VIPTrucks;

	PriorityQueue<Truck* > MovingTrucks;
	//=================================
	//Cargos Waiting   
	List<Cargo*>WaitingNormalCargos;
	Queue<Cargo*>WaitingSpecialCargos;
	PriorityQueue<Cargo*>WaitingVIPCargos;
	
	Queue<Cargo* > NCargosExceededMaxW;
	Queue<Cargo* > SCargosExceededMaxW;
	Queue<Cargo* > VCargosExceededMaxW;


	//Cargos delivered /////////////////
	Queue<Cargo*>DeliveredCargos;//will make them one q later
	//Queue<Cargo*>DeliveredSpCargo;//
	//Queue<Cargo*>DeliveredVIPCargo;//

	//Events
	PriorityQueue<Event*> EventsPQ;   //need editing
	
	
	Time CurrentTime;
	UIClass* pUI;

	//Queues for trucks data
	Queue<int>VTCs;
	Queue<int>VSpeeds;
	Queue<int>SSpeeds;
	Queue<int>NTCs;
	Queue<int>NSpeeds;
	Queue<int>STCs;
	Queue<bool> N_Night;
	Queue<bool> S_Night;
	Queue<bool> V_Night;
	Queue<Truck*>TRKsWhenClosed;
	Queue<Event*>PreEventswhenClosed;
	//Utility functions
	void StepbyStepSimulation();
	void PrintConsole();
	void InteractiveSimulation();
	void checkforAutop();
	void incrementWHs();
public:
	int Check_UP_Cnt = 0;
	int Returned_From_Checkup = 0;
	Company();
	void LoadCargos();
	//void IncrementHour();
	void setMaxW(int);
	void setcurtime(Time time);
	Time getcurtime();
	bool isClosed();
	/*bool AddtoVIPTruck(Cargo*);
	bool AddtoNormalTruck(Cargo*);
	bool AddtoSpecialTruck(Cargo*);*/
//	void Update_UI_Interface(Time T);
	void Loading_File();
	void GeneralSimulate();
	void OutputFile();
	Time AverageWaitingTime();
	void ExecuteEvents();
	void AddCargotoVIPWaiting(Cargo* C);
	void AddCargotoNormalWaiting(Cargo* n);
	void AddCargotoSpWaiting(Cargo* n);
	void PrintEvents();
	bool CancellationID(int id);
	void ExceededCancellation(int ID);
	Cargo* PromotionExceeded(int ID);
	Cargo* GetNormalCargo(int id);
	void printWaitingVIP(UIClass *);
	void AddToVIPexceeded(Cargo* c);
	void printWaitingNormal(UIClass* pUI);
	void printWaitingSP(UIClass* pUI);
	int GetnumMoving();
	void PrintMoving(UIClass* pUI);
	void PrintNInCheckupTRKs(UIClass* pUI);
	void PrintSInCheckupTRKs(UIClass* pUI);
	void PrintVInCheckupTRKs(UIClass* pUI);
	void PrintNMaintenenceTRKs(UIClass* pUI);
	void PrintVMaintenenceTRKs(UIClass* pUI);
	void PrintSMaintenenceTRKs(UIClass* pUI);
	int GetNumOfLaoding();
	void PrintLoading(UIClass* pUI);
	int GetCountTRUCKSincheckup();
	int GetCountTRKsMaintence();
	int Getcountall_waiting();
	int GetnumOfDeliv();
	void printDelivered(UIClass* pUI);
	//void printDeliveredVIP(UIClass* pUI);
	//void printDeliveredNormal(UIClass* pUI);
	//void printDeliveredSP(UIClass* pUI);
	void printEmptyTrucks(UIClass* pUI);
	int GetNumOfEmptyTrcs();
	void CheckforCargosExceededMaxW();
	bool AssignNormal();
	bool AssignSpecial();
	bool AssignVIP();
	void AssignExceeded();
	void AssignSpecialTruck(int T); // 0 for VIP Cargos 1 for special Cargos 2 for VExceededCargos 3 for SExceededCargos
	void AssignNormalTruck(int T); // 0 for VIP Cargos 1 for Normal Cargos 2 for VExceededCargos 3 for NExceededCargos 
	void AssignVIPTruck(int T); // 0 for VIP Cargos 1 for Normal Cargos 2 for VExceededCargos 3 for NExceededCargos
	void CreateTrucks();
	void Checkformaintenence();


	//void CheckforCheckupTrucks();
	void CheckforTrucks(); // Check for moving , loading , checkup 
    void CheckFailure();
	void Deliver(Truck* &);
	void Assign_Ignore_Loading_Rule();
	void AddtoLoading(Truck*);
	void Organize_Loading();
	void AddtoEmpty(Truck*);
	double Trucks_ActiveTime();
	void AddtoMoving(Truck* T);
		
	Time AverageWaitingTime_DeliveredNormalCargos();	//ismail
	Time AverageWaitingTime_DeliveredSpecialCargos();	//ismail
	Time AverageWaitingTime_DeliveredVIPCargos();	//ismail

	void set_NumberOfAutoPromotedCargos(int i);		//ismail
	int get_NumberOfAutoPromotedCargos();		//ismail

	int get_numOf_N_Truck();		//ismail
	int get_numOf_S_Truck();		//ismail
	int get_numOf_VIP_Truck();		//ismail

	Time NormalTrucks_ActiveTime();		//ismail
	Time SpecialTrucks_ActiveTime();		//ismail
	Time VIPTrucks_ActiveTime();		//ismail

	double NormalTrucks_Utilization();		//ismail
	double SpecialTrucks_Utilization();		//ismail
	double VIPTrucks_Utilization();		//ismail	
	
	double ALL_Utilization();		

	int Get_JourneyCount();
	void Calc_Delivered_Cargos_count();
	int get_N_Cargo_Count();
	int get_S_Cargo_Count();
	int get_VIP_Cargo_Count();
	void TestAll();
	void UpdateLoadingCnt(int& N, int& V, int& S);
	//void AddCargotoVIPWaiting(Cargo* C);
	//void CancellationIDint id);
   //	void PrintDelivered(UIClass* pUI);
	//void AddCargotoWaiting(Cargo*);
//	bool UpdatetoVIP(int ID);
};

