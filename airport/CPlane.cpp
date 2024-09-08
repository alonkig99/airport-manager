#include "CPlane.h"
#include <string>
#include <iostream>
using namespace std;



    CPlane::CPlane(int serialNum, int numSeats, const string& modelName) {
        this->serialNum = serialNum;
        this->numSeats = numSeats;
        this->modelName = modelName;
        

    }

    CPlane::CPlane(const CPlane& other)
    {
        this->serialNum = other.serialNum;
        this->numSeats = other.numSeats;
        this->modelName = other.modelName;
    }

 
    int CPlane::GetSerialNum() const{
        return serialNum;
    }

    std::string CPlane::GetModelName() const {
        return modelName;
    }

    int CPlane::GetNumSeats() const {
        return numSeats;
    }

    void CPlane::Print() const {
        std::cout << "Serial number: "<<serialNum<< ", Model name: " << modelName << ", Number of seats: " << numSeats << std::endl;
    }

    bool CPlane::IsEqual(const CPlane& other) const {
        return this->serialNum == other.serialNum;
    }

    CPlane::~CPlane()
    {
    }
