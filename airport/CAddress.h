#pragma once
#include <string>

class CAddress
{
public:
    CAddress(int HouseNumber, const std::string& StreetName,const std::string& CityName = "Tel Aviv");
    CAddress(const CAddress& other);

    std::string GetCityName() const;
    std::string GetStreetName() const;
    int GetHouseNumber() const;
    void Print() const;
    void UpdateAddress(const std::string& NewCity, const std::string& NewStreet, int NewHouseNum);
    ~CAddress();


private:
	std::string cityName;
	std::string streetName;
	int houseNumber;

};

