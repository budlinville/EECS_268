#include <string>

class DriversLicenseRecord {
  private:
    std::string firstName;
    std::string lastName;
    int age;
    char registeredToVote;  //will be a value of Y or N
    string licenseNumber;

  public:
    DriversLicenseRecord();

    void setFirstName(std::string &fName);
    std::string getFirstName() const;

    void setLastName(std::string &lName);
    std::string getLastName() const;

    void setAge(int &a);
    int getAge() const;

    void setRegistered(char &r);
    char getRegistered() const;

    void setLicenseNumber(std::string &lNumber);
    std::string getLicenseNumber() const;
};
