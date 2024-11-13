#pragma once
#include "CCrewMember.h"
class CPilot : public CCrewMember
{

public:
	

	CPilot(const std::string name, bool isCaptain, const CAddress* address = nullptr);
	CPilot(const CPilot& other);
	~CPilot();
	virtual void GetUniform() const override;
	void SetAddress(const CAddress* newAddress);
	virtual void ToOs(std::ostream& os) const;
	virtual bool operator+=(int minutes);
	virtual bool operator==(const CCrewMember& other) const override;
	void ToSimulator() const;
	

private:
	bool isCaptain;
	CAddress* address;
};

