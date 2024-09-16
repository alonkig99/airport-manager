#pragma once
#include <string>
class CPlane
{
public:

	CPlane(int NumSeats, const std::string& ModelName);
	CPlane(const CPlane& other);
	CPlane() = delete;
	int GetSerialNum() const;
	const std::string& GetModelName() const;
	int GetNumSeats() const;
	friend std::ostream& operator<<(std::ostream& os, const CPlane& plane);
	bool operator ==(const CPlane& other)const;
	bool operator !=(const CPlane& other)const; 
	const CPlane& operator++();
	 CPlane operator++(int);

	~CPlane();

private:
	static int serialNum;
	int mySerialNum;
	std::string modelName;
	int numSeats;




};

