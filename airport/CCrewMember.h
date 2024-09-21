#pragma once
#include "CAddress.h"
#include <string>
#include <iostream>

class CCrewMember
{
public:
	static constexpr int START_ID = 1000;

	//constructors&destructor
	CCrewMember(const std::string& name,int totalAirTime = 0,const CAddress* address=nullptr);
	CCrewMember(const CCrewMember& other);
	CCrewMember() = delete;
	~CCrewMember();

	//getters&setters
	const std::string& GetName()const;
	void SetName(const std::string& newName);
	const CAddress* GetAddress()const;
	void SetAddress(const CAddress* newAddress);
    int GetID()const;
	int GetAirTime()const;
	
	//operator overloading
	bool operator+=(int minutes);
	bool operator==(const CCrewMember& other) const;
	bool operator!=(const CCrewMember& other) const;
	const CCrewMember& operator=(const CCrewMember& other);
    friend std::ostream& operator<<(std::ostream& os, const CCrewMember& member);
	


private:
	std::string name;
	CAddress* address;
	int totalAirTime;
	static int idCounter;
	int memberID;

};

