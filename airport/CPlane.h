#pragma once
#include <string>
class CPlane
{
public:
	//constructors&destructor
	CPlane(int NumSeats, const std::string& ModelName);
	CPlane(const CPlane& other);
	CPlane() = delete;
	~CPlane();

	//getters
	int GetSerialNum() const;
	const std::string& GetModelName() const;
	int GetNumSeats() const;

	//operator overloading
	friend std::ostream& operator<<(std::ostream& os, const CPlane& plane);
	bool operator ==(const CPlane& other)const;
	bool operator !=(const CPlane& other)const; 
	const CPlane& operator++();
	 CPlane operator++(int);
	 CPlane& operator=(const CPlane& other);
	

private:
	static int serialNumCounter;
	int serialNum;
	std::string modelName;
	int numSeats;

};

