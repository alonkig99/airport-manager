#pragma once
#include "CCrewMember.h"
#include <string>

class CHost : public CCrewMember
{
public:
	enum HostType { eRegular, eSuper, eCalcelan};
	std::string enumArr[3] = { "Regular","Super", "Calcelan" };


	CHost(const std::string name, HostType type);
	CHost(const CHost& other);
	~CHost();
	HostType GetHostType() const;
	virtual void GetUniform() const override;
	virtual void GetPresent() const override;
	virtual void ToOs(std::ostream& os) const override;

	 

private:
	HostType type;
};

