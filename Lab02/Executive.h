//need a destructor... probz need a copy constructor too
//~Executive();
//delete[] jkadjlsf;
#include <string>

class Executive {
  private:
    void printLastName(lName);    //prints all people with last name: lName
    void printAges(int low, int high);  //prints all people between two ages
    void printRegistered(); //prints al people registered to vote

  public:
    void run();
}
