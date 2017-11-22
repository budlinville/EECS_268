#include "Executive.h"
#include <string>

Executive::Executive(std::string flnm){
  fileName = flnm;
  numDrivers = getNumDrivers();      
}

Executive::~Executive(){
  delete[] this;
}

void Executive::run(){
  DriversLicenseRecord DLR[numDrivers];
  std::string firstName = "";
  std::string lastName = "";
  int age = 0;
  char rToVote = ' ';
  std::string licenseNumber = "";
  bool validInput = false;
  bool endProgram = false;
  int decision = 0;

  std::ifstream inp(fileName);

  int i = 0;

  inp.ignore(20, '\n');
  while (inp >> firstName >> lastName >> age >> rToVote >> licenseNumber){
    DLR[i].setFirstName(firstName);

    DLR[i].setLastName(lastName);

    DLR[i].setAge(age);

    DLR[i].setRegistered(rToVote);

    DLR[i].setLicenseNumber(licenseNumber);

    i++;
  }

  inp.close();    //close stream now that I'm done with it.

  while  (endProgram == false) {
    std::cout << std::endl << std::endl;
    std::cout << "1: Query last name" << std::endl;
    std::cout << "2: Query age range" << std::endl;
    std::cout << "3: Query registered voters" << std::endl;
    std::cout << "4: Quit" << std::endl;
    while (validInput == false){
      std::cin >> decision;
      if (decision == 1){
        queryLastName(DLR);
        validInput = true;
      } else if (decision == 2){
        queryAgeRange(DLR);
        validInput = true;
      } else if (decision == 3){
        queryRegisteredVoters(DLR);
        validInput = true;
      } else if (decision == 4){
        endProgram = true;
        validInput = true;
      } else {
        validInput = false;
        std::cout << "Please enter valid input: ";
      }
    }
    validInput = false;   //reset
  }
}

int Executive::getNumDrivers(){
  std::ifstream inp(fileName);
  int num = 0;
  inp >> num;
  inp.clear();
  return num;
}

void Executive::queryLastName(DriversLicenseRecord x[]){
  std::string searchName = "";

  std::cout << std::endl << "Enter last name: ";
  std::cin >> searchName;
  bool validName = false;

  for (int i = 0; i < numDrivers; i++){
    if (x[i].getLastName() == searchName){
      printInformation(x[i]);
      validName = true;
    }
  }

  if (validName == false){
    std::cout << "Sorry. There is nobody on record with that name.";
  }
}

void Executive::queryAgeRange(DriversLicenseRecord x[]){
  int minAge = 0;
  int maxAge = 0;
  bool validInput = false;
  bool validAge = false;

  std::cout << std::endl << "Please enter minimum age: ";
  while (validInput == false){
    std::cin >> minAge;

    if (minAge < 0){
      std::cout << "Please enter a number above 0: ";
      validInput = false;
    } else {
      validInput = true;
    }
  }
  validInput = false;

  std::cout << "Please enter maximum age: ";
  while (validInput == false){
    std::cin >> maxAge;

    if (maxAge < minAge){
      std::cout << "Please enter a number greater than the minimum age: ";
      validInput = false;
    } else {
      validInput = true;
    }
  }

  for (int i = 0; i < numDrivers; i++){
    if (x[i].getAge() >= minAge && x[i].getAge() <= maxAge){
      printInformation(x[i]);
      validAge = true;
    }
  }

  if (validAge == false){
    std::cout << "Sorry. There is nobody on record in that age range.";
  }
}

void Executive::queryRegisteredVoters(DriversLicenseRecord x[]){
  std::cout << std::endl;

  for (int i = 0; i < numDrivers; i++){
    if (x[i].getRegistered() == 'Y'){
      printInformation(x[i]);
    }
  }
}

void Executive::printInformation(DriversLicenseRecord &x){
  std::cout << "Record: "<< x.getFirstName() << " ";
  std::cout << x.getLastName() << ";  ";
  std::cout << "Age: " << x.getAge() << ";  ";
  if (x.getRegistered() == 'Y'){
    std::cout << "registered to vote;  ";
  } else {
    std::cout << "not registered to vote;  ";
  }
  std::cout << "License number: " << x.getLicenseNumber() << std::endl;
}
