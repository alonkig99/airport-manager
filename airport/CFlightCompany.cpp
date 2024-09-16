#include "CFlightCompany.h"
#include <string>
#include <iostream>

using namespace std;


CFlightCompany::CFlightCompany(const string& name):name(name) {}
// copy constructor is not a must in this class
//CFlightCompany::CFlightCompany(const CFlightCompany& other):name(other.name) {}

const string& CFlightCompany::GetName()const {
	return name;
}

void CFlightCompany::SetName(string newName) {
	name = newName;
}

void CFlightCompany::Print()const {
	cout << "Company's name: " << name << endl;
}

CFlightCompany::~CFlightCompany() {}
