#include "CPilot.h"
#include <iostream>

using namespace std;

CPilot::CPilot(const std::string name, bool isCaptain, const CAddress* address):CCrewMember(name), isCaptain(isCaptain) {
    SetAddress(address);
}
CPilot::CPilot(const CPilot& other):CCrewMember(other),isCaptain(other.isCaptain) {
    SetAddress(other.address);
}
CPilot::~CPilot() {
	delete address;
}
void CPilot::GetUniform() const {
    cout <<name << ": this is the fifth time I get a new uniform - this is a waste of money!" << endl;
}

void CPilot::ToOs(std::ostream& os) const {
    os << name << " minutes " << totalAirTime;

    if (address)
        os << " Home " << *address;

    os << (this->isCaptain ? " a Captain" : "Not a Captain") << endl;
 }
 bool CPilot::operator+=(int minutes) {
     return CCrewMember::operator+=(this->isCaptain ? int(minutes * 1.1f) : minutes);
 }

  bool CPilot::operator==(const CCrewMember& other) const {
      if (!CCrewMember::operator==(other)) return false;

      const CPilot* temp = dynamic_cast<const CPilot*>(&other);
      if (temp == NULL) return false;

      if (address == nullptr && temp->address == nullptr) return true; 
      if (address == nullptr || temp->address == nullptr) return false;

      return *address == *(temp->address);

 }

 void CPilot::SetAddress(const CAddress* newAddress) {

     if (newAddress != nullptr) {
         if (address != newAddress) { //self address assignment check
             delete address;
             address = new CAddress(*newAddress);
         }
     }
 }

 void CPilot::ToSimulator() const
 {
     cout << "Pilot " << this->name << " got the message will come soon" << endl;
 }
