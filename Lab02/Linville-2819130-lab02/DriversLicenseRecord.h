#include <string>

class DriversLicenseRecord {
  private:
    std::string firstName;
    std::string lastName;
    int age;
    char registeredToVote;  //will be a value of Y or N
    std::string licenseNumber;

  public:
    DriversLicenseRecord();

    ~DriversLicenseRecord();

    //get and set methods for drivers' first name
    void setFirstName(std::string &fName);
    std::string getFirstName() const;

    //get and set methods for drivers' last name
    void setLastName(std::string &lName);
    std::string getLastName() const;

    //get and set methods for drivers' age
    void setAge(int &a);
    int getAge() const;

    /*get and set methods for whether or not the driver is registered to vote
      uses a char value of 'Y" for yes and 'N' for no
    */
    void setRegistered(char &r);
    char getRegistered() const;

    //get and set method for the drivers' license number
    void setLicenseNumber(std::string &lNumber);
    std::string getLicenseNumber() const;
};
