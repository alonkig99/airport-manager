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
   void SetCityName(const std::string& cityName);
   void SetStreetName(const std::string& streetName);
   void SetHouseNumber(int houseNumber);
   std::string getCurrentAddress() const;
  const CAddress& operator=(const CAddress& other);
  bool operator ==(const CAddress& other)const;
  bool operator !=(const CAddress& other)const;
  int GetHouseNumber() const;
    friend std::ostream& operator<<(std::ostream & os, const CAddress& adr);
   
    friend std::istream& operator>> (std::istream & in, CAddress& adr);

    void UpdateAddress(const std::string& NewCity, const std::string& NewStreet, int NewHouseNum);
    ~CAddress();


private:
	std::string cityName;
	std::string streetName;
	int houseNumber;

};

