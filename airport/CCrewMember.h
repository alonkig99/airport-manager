#pragma once
#include "CAddress.h"
#include <string>
#include <iostream>

class CCrewMember
{
public:


	//constructors&destructor
	CCrewMember(const std::string& name,int totalAirTime = 0);
	CCrewMember(const CCrewMember& other);
	CCrewMember() = delete;
	virtual ~CCrewMember();

	//getters&setters
	const std::string& GetName()const;
	void SetName(const std::string& newName);

	int GetAirTime()const;
	
	//operator overloading
	virtual bool operator+=(int minutes);
	virtual bool operator==(const CCrewMember& other) const;
	bool operator!=(const CCrewMember& other) const;
	const CCrewMember& operator=(const CCrewMember& other);
    friend std::ostream& operator<<(std::ostream& os, const CCrewMember& member);



	///////////////////
	virtual void GetUniform() const = 0;
	virtual void GetPresent() const;
	void TakeOff(int minutes);
	virtual void ToOs(std::ostream& os) const = 0;


//private:
protected:
	std::string name;
	int totalAirTime;

};

