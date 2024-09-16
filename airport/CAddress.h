#pragma once
#include <string>
#include <iostream>
class CAddress
{
public:
    CAddress(int HouseNumber, const std::string& StreetName,const std::string& CityName = "Tel Aviv");
    CAddress(const CAddress& other);
    CAddress() = delete;
   const std::string& GetCityName() const;
   const std::string& GetStreetName() const;
   std::string getCurrentAddress() const;
  const CAddress& operator=(const CAddress& other);
  bool operator ==(const CAddress& other)const;
  bool operator !=(const CAddress& other)const;
    int GetHouseNumber() const;

    //printing
    friend std::ostream& operator<<(std::ostream & os, const CAddress& adr);
    // input
    friend std::istream& operator>> (std::istream & is, CAddress& adr);

    void UpdateAddress(const std::string& NewCity, const std::string& NewStreet, int NewHouseNum);
    ~CAddress();


private:
	std::string cityName;
	std::string streetName;
	int houseNumber;

};

