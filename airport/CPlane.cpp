#include "CPlane.h"
#include <string>
#include <iostream>
using namespace std;

int CPlane::serialNumCounter = 100;

CPlane::CPlane(int numSeats, const string& modelName)
    : serialNum(serialNumCounter++), numSeats(numSeats), modelName(modelName){}

CPlane::CPlane(const CPlane& other)
    : serialNum(other.serialNum), numSeats(other.numSeats), modelName(other.modelName){}

 
    int CPlane::GetSerialNum() const{
        return serialNum;
    }

    const string& CPlane::GetModelName() const {
        return modelName;
    }

    int CPlane::GetNumSeats() const {
        return numSeats;
    }

    ostream& operator<<(ostream& os, const CPlane& plane) {
        os << "Plane: " << plane.serialNum << ", Model name: " << plane.modelName << ", Number of seats: " << plane.numSeats << std::endl;

        return os;
   }

    bool  CPlane::operator ==(const CPlane& other)const {
        return serialNum == other.serialNum;
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

    CPlane::~CPlane(){}
