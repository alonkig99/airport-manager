#pragma once
#include "CPlane.h"
#include <string>
#include <iostream>
class CCargo : public CPlane
{

public:

	CCargo(int numSeats, const std::string& ModelName, float maxWeight, float maxVol);
	CCargo(const CCargo& other);
	~CCargo();

	bool Load(float weight, float vol);
	void TakeOff(int minutes);
	virtual void ToOs(std::ostream& os) const;
	virtual void TakeOff(int minutes) const override;



private:
	float maxWeight;
	float maxVol;
	float currWeight;
	float currVol;


};

