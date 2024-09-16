#pragma once
#include <string>
class CFlightInfo
{
public:

	CFlightInfo(const std::string& destination,int flightNum, int flightDuration, int flightDistance);
	CFlightInfo(const CFlightInfo& other);
	CFlightInfo() = delete;
	const std::string& GetDest()const;
	void SetDest(const std::string& newDest);
	int GetFlightNum()const;
	void SetFlightNum(int newFlightNum);
	int GetFlightDuration()const;
	void SetFlightDuration(int newFlightDur);
	int GetFlightDistance()const;
	void SetFlightDistance(int newFlightDist);
	friend std::ostream& operator<<(std::ostream& os, const CFlightInfo& flightInfo);
	bool operator ==(const CFlightInfo& other)const;
	bool operator !=(const CFlightInfo& other)const;
	~CFlightInfo();


private:
	std::string destination;
	int flightNum; 
	int flightDuration; // minutes
	int flightDistance; //km



};

