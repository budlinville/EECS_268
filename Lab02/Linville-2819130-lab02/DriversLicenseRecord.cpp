#include "DriversLicenseRecord.h"
#include <string>

DriversLicenseRecord::DriversLicenseRecord(){
  firstName = "";
  lastName = "";
  age = 0;
  registeredToVote = ' ';
  licenseNumber = "";
}

DriversLicenseRecord::~DriversLicenseRecord(){
  delete[] this;
}

void DriversLicenseRecord::setFirstName(std::string &fName){
  firstName = fName;
}

std::string DriversLicenseRecord::getFirstName() const{
  return firstName;
}

void DriversLicenseRecord::setLastName(std::string &lName){
  lastName = lName;
}

std::string DriversLicenseRecord::getLastName() const{
  return lastName;
}

void DriversLicenseRecord::setAge(int &a){
  age = a;
}

int DriversLicenseRecord::getAge() const{
  return age;
}

void DriversLicenseRecord::setRegistered(char &r){
  registeredToVote = r;
}

char DriversLicenseRecord::getRegistered() const{
  return registeredToVote;
}

void DriversLicenseRecord::setLicenseNumber(std::string &lNumber){
  licenseNumber =lNumber;
}

std::string DriversLicenseRecord::getLicenseNumber() const{
  return licenseNumber;
}
