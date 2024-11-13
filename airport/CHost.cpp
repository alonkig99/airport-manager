#include "CHost.h"
#include <iostream>
#include <string>


using namespace std;



CHost::CHost(const std::string name, HostType type):CCrewMember(name), type(type) {}

CHost::CHost(const CHost& other):CCrewMember(other), type(other.type) {}


CHost::~CHost(){}

CHost::HostType CHost::GetHostType() const {
	return type;
}


 void CHost::GetUniform() const  {
	 cout << name<<": I think the new uniform is very nice!" << endl;
 }

 void CHost::GetPresent() const {
	 CCrewMember::GetPresent();
		cout << "I wasn't expecting it" << endl;


}

 void CHost::ToOs(std::ostream& os) const {
	 os << enumArr[type] << " " << name << " minutes " << totalAirTime << endl;

 }

