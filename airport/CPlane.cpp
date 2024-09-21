#include "CPlane.h"
#include <string>
#include <iostream>
using namespace std;

int CPlane::serialNumCounter = 100;

/* =====================================
   constructors&destructor
   ===================================== */

CPlane::CPlane(int numSeats, const string& modelName)
    : serialNum(serialNumCounter++), numSeats(numSeats), modelName(modelName){}

CPlane::CPlane(const CPlane& other){
    *this = other;
}
CPlane::~CPlane() {}

/* =====================================
  getters&setters
  ===================================== */

    int CPlane::GetSerialNum() const{
        return serialNum;
    }

    const string& CPlane::GetModelName() const {
        return modelName;
    }

    int CPlane::GetNumSeats() const {
        return numSeats;
    }


  /* =====================================
     operator overloading
     ===================================== */


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

    //prefix add seat to plane
    const CPlane& CPlane::operator++() {
        ++numSeats;
        return *this;
    }
    //postfix add seat to plane
     CPlane CPlane::operator++(int) { 
         CPlane temp(*this); 
        numSeats++;
        return temp;
    }

     CPlane& CPlane::operator=(const CPlane& other) {

         if (this != &other) {

             this->serialNum = other.serialNum;
             this->modelName = other.modelName;
             this->numSeats = other.numSeats;
         }

         return *this;
     }

