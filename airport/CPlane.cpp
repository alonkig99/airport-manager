#include "CPlane.h"
#include <string>
#include <iostream>
using namespace std;

int CPlane::serialNum = 100;

CPlane::CPlane(int numSeats, const string& modelName)
    : mySerialNum(serialNum++), numSeats(numSeats), modelName(modelName){}

// when copying an object, the serial number of the newly created object stays unique.
CPlane::CPlane(const CPlane& other)
    : mySerialNum(other.mySerialNum), numSeats(other.numSeats), modelName(other.modelName){}

 
    int CPlane::GetSerialNum() const{
        return mySerialNum;
    }

    const string& CPlane::GetModelName() const {
        return modelName;
    }

    int CPlane::GetNumSeats() const {
        return numSeats;
    }

    void CPlane::Print() const {
        std::cout << "Serial number: "<<serialNum<< ", Model name: " << modelName << ", Number of seats: " << numSeats << std::endl;
    }
    ostream& operator<<(ostream& os, const CPlane& plane) {
        os << "Serial number: " << plane.serialNum << ", Model name: " << plane.modelName << ", Number of seats: " << plane.numSeats << std::endl;

        return os;
   }



    bool  CPlane::operator ==(const CPlane& other)const {
        return mySerialNum == other.mySerialNum;
    }
    bool CPlane::operator !=(const CPlane& other) const {
        return !(*this == other);
    }

    // adding a seat to the plane with either postfix or prefix
    const CPlane& CPlane::operator++() {
        ++numSeats;
        return *this;
    }
     CPlane CPlane::operator++(int) { 
         CPlane temp(*this); 
        numSeats++;
        return temp;
    }

    CPlane::~CPlane()
    {

    }
