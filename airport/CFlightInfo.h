#pragma once

#include <iostream>
#include <string>

class CFlightInfo
{
public:

	CFlightInfo(const std::string& destination,int flightNum, int flightDuration, int flightDistance);
	CFlightInfo(const CFlightInfo& other);
	CFlightInfo() = delete;
	const std::string& GetDest()const;
	void SetDest(const std::string& newDest);
	int GetFNum()const;
	void SetFNum(int newFlightNum);
	int GetFDuration()const;
	void SetFDuration(int newFlightDur);
	int GetFDistance()const;
	void SetFDistance(int newFlightDist);
	friend std::ostream& operator<<(std::ostream& os, const CFlightInfo& flightInfo);
	operator int() const;
	bool operator ==(const CFlightInfo& other)const;
	bool operator !=(const CFlightInfo& other)const;
	~CFlightInfo();


private:
	std::string destination;
	int flightNum; 
	int flightDuration; // minutes
	int flightDistance; //km



};

