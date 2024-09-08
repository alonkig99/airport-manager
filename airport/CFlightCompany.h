#pragma once
#include <string>


class CFlightCompany
{
public:
	CFlightCompany(const std::string& name);
	CFlightCompany(const CFlightCompany& other);

	std::string GetName()const;
	void SetName(const std::string& newName);
	void Print()const;
	~CFlightCompany();


private:
	std::string name;
};

