#include "CCargo.h"
#include <iostream>
using namespace std;

CCargo::CCargo(int numSeats, const std::string& ModelName, float maxWeight, float maxVol):CPlane(numSeats,ModelName),
maxWeight(maxWeight), maxVol(maxVol),currWeight(0),currVol(0) {}

CCargo::CCargo(const CCargo& other) :CPlane(other),
maxWeight(other.maxWeight), maxVol(other.maxVol), currWeight(other.currWeight), currVol(other.currVol) {}

CCargo::~CCargo(){}

bool CCargo::Load(float weight, float vol) {
	if (currWeight + weight > maxWeight || currVol + vol > maxVol) return false;

	currWeight += weight;
	currVol += vol;

	return true;
}
void CCargo::TakeOff(int minutes) {
	cout << "need to add <" << minutes << "> to my log book" << endl;
}

 void CCargo::ToOs(std::ostream& os) const {
	 os << "Cargo M_VOL " << maxVol << "M_Kg " << maxWeight << "C_vol " << currVol << ", C_Kg " << currWeight << endl;

}

 void CCargo::TakeOff(int minutes) const {
	 cout << "Need to add " << minutes << " minutes to my log book" << endl;
 }