#include <string>
#include <iostream>
#include <fstream>
#include "DriversLicenseRecord.h"
#pragma once

class Executive {
  private:
    //prints all people with last name: lName
    void printLastName(std::string lName);

    //prints all people between two ages
    void printAges(int low, int high);

    //prints al people registered to vote
    void printRegistered();

    std::string fileName;
    int numDrivers;

  public:
    Executive(std::string flnm);
    ~Executive();

    /* Pre: allocates input from a text file into instances of the array of
      Post: handles input from the user to decide which method to call
    */
    void run();

    //returns number of drivers in text file by looking at first line
    int getNumDrivers();

    /*following 3 methods decide which drivers' info should be displayed to the user
      in accordance with the defined parameters.
    */
    void queryLastName(DriversLicenseRecord x[]);

    void queryAgeRange(DriversLicenseRecord x[]);

    void queryRegisteredVoters(DriversLicenseRecord x[]);

    //prints info a specific instance of the array of class objects.
    void printInformation(DriversLicenseRecord &x);
};
