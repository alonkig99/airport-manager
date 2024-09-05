#pragma once
#include <string>
class CFlightInfo
{
public:

	CFlightInfo(std::string destination,int flightNum, int flightDuration, int flightDistance);
	CFlightInfo(const CFlightInfo& other);
	std::string GetDest()const;
	void SetDest(std::string newDest);
	int GetFlightNum()const;
	void SetFlightNum(int newFlightNum);
	int GetFlightDuration()const;
	void SetFlightDuration(int newFlightDur);
	int GetFlightDistance()const;
	void SetFlightDistance(int newFlightDist);
	bool IsEqual(const CFlightInfo& other)const;
	void Print()const;
	~CFlightInfo();


private:
	std::string destination;
	int flightNum; 
	int flightDuration; // minutes
	int flightDistance; //km



};

