#pragma once
#include <string>
class CPlane
{
public:

	CPlane(int SerialNum, int NumSeats, std::string ModelName);
	CPlane(const CPlane& other);
	int GetSerialNum() const;
	std::string GetModelName() const;
	int GetNumSeats() const;
	void Print() const;
	bool IsEqual(const CPlane& Other) const;
	~CPlane();

private:
	int serialNum;
	std::string modelName;
	int numSeats;




};

