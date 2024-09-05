#include "CFlightCompany.h"
#include <string>
#include <iostream>

using namespace std;


CFlightCompany::CFlightCompany(std::string name) {
	SetName(name);

}
CFlightCompany::CFlightCompany(const CFlightCompany& other)
{
	SetName(other.name);
}
std::string CFlightCompany::GetName()const {
	return name;
}

void CFlightCompany::SetName(const string& newName) {
	name = newName;
}
void CFlightCompany::Print()const {
	cout << "Company's name: " << name << endl;
}

CFlightCompany::~CFlightCompany()
{
}
