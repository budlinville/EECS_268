#include "DriversLicenseRecord.h"
#include <string>

DriversLicenseRecord::DriversLicenseRecord(){
  firstName = "";
  lastName = "";
  age = 0;
  registeredToVote = '';
  licenseNumber = "";
}

void DriversLicenseRecord::setFirstName(std::string &fName){
  firstName = fName;
}

std::string DriversLicenseRecord::getFirstName(){
  return firstName;
}

void DriversLicenseRecord::setLastName(std::string &lName){
  lastName = lName;
}

std::string DriversLicenseRecord::getLastName(){
  return lastName;
}

void DriversLicenseRecord::setAge(int &a){
  age = a;
}

int DriversLicenseRecord::getAge(){
  return age;
}

void DriversLicenseRecord::setRegistered(char &r){
  registeredToVote = r;
}

char DriversLicenseRecord::getRegistered(){
  return registeredToVote;
}

void DriversLicenseRecord::setLicenseNumber(std::string &lNumber){
  licenseNumber =lNumber;
}

std::string DriversLicenseRecord::getLicenseNumber(){
  return licenseNumber;
}
