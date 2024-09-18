#pragma once
#include "CAddress.h"
#include <string>
#include <iostream>

class CCrewMember
{
public:
	static constexpr int START_ID = 1000;

	CCrewMember(const std::string& name,/* const CAddress& address,*/ int totalAirTime = 0);
	CCrewMember(const CCrewMember& other);
	CCrewMember() = delete;
	//+= operator updates total air time
	bool operator+=(int minutes);
	const std::string& GetName()const;
	void SetName(const std::string& newName);
	//const CAddress& GetAddress()const;
    int GetID()const;
	//void SetAddress(const CAddress& newAddress);
	int GetAirTime()const;
	bool operator==(const CCrewMember& other) const;
	bool operator!=(const CCrewMember& other) const;
    friend std::ostream& operator<<(std::ostream& os, const CCrewMember& member);
	~CCrewMember();


private:
	std::string name;
	//CAddress address;
	int totalAirTime;
	static int idCounter;
	int memberID;

};

