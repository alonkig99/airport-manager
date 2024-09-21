#pragma once

#include <iostream>
#include <string>

class CFlightInfo
{
public:
	//constructors&destructor
	CFlightInfo(const std::string& destination,int flightNum, int flightDuration, int flightDistance);
	CFlightInfo(const CFlightInfo& other);
	CFlightInfo() = delete;
	~CFlightInfo();
	
	//getters&setters
	const std::string& GetDest()const;
	void SetDest(const std::string& newDest);
	int GetFNum()const;
	void SetFNum(int newFlightNum);
	int GetFDuration()const;
	void SetFDuration(int newFlightDur);
	int GetFDistance()const;
	void SetFDistance(int newFlightDist);

	//operator overloading
	friend std::ostream& operator<<(std::ostream& os, const CFlightInfo& flightInfo);
	operator int() const;
	bool operator ==(const CFlightInfo& other)const;
	bool operator !=(const CFlightInfo& other)const;
	const CFlightInfo& operator=(const CFlightInfo& other);
	


private:
	std::string destination;
	int flightNum; 
	int flightDuration; // minutes
	int flightDistance; //km



};

