#pragma once
#include <string>


class CFlightCompany
{
public:
	CFlightCompany(const std::string& name);
	CFlightCompany(const CFlightCompany& other);
	CFlightCompany() = delete;

	const std::string& GetName()const;
	void SetName(std::string newName);
	void Print()const;
	~CFlightCompany();


private:
	std::string name;
};

