#pragma once
#include <string>

class CAddress
{
public:
    CAddress(int HouseNumber, std::string StreetName, std::string CityName = "Tel Aviv");
    CAddress(const CAddress& other);

    std::string GetCityName() const;
    std::string GetStreetName() const;
    int GetHouseNumber() const;
    void Print() const;
    void UpdateAddress(std::string NewCity, std::string NewStreet, int NewHouseNum);
    ~CAddress();


private:
	std::string cityName;
	std::string streetName;
	int houseNumber;

};

