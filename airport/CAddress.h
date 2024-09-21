#pragma once
#include <string>
#include <iostream>

class CAddress
{
public:
    //constructors&destructor
    CAddress(int HouseNumber, const std::string& StreetName,const std::string& CityName = "Tel Aviv");
    CAddress(const CAddress& other);
    CAddress() = delete;
    ~CAddress();

    //getters&setters
   const std::string& GetCityName() const;
   const std::string& GetStreetName() const;
   void SetCityName(const std::string& cityName);
   void SetStreetName(const std::string& streetName);
   void SetHouseNumber(int houseNumber);
   int GetHouseNumber() const;
   std::string getCurrentAddress() const;
   void UpdateAddress(const std::string& NewCity, const std::string& NewStreet, int NewHouseNum);

   //operator overloading
  const CAddress& operator=(const CAddress& other);
  bool operator ==(const CAddress& other)const;
  bool operator !=(const CAddress& other)const;
  friend std::ostream& operator<<(std::ostream & os, const CAddress& adr);
  friend std::istream& operator>> (std::istream & in, CAddress& adr);

  
private:
	std::string cityName;
	std::string streetName;
	int houseNumber;

};

