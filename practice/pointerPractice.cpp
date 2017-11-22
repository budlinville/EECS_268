#include <iostream>
#include <string>

void someFunction(std::string &pv) {
  pv = "BIG DOG";
}

int main(int argc, char* argv[]) {
  std::string pointerVar = "HELLO POINTER!";

  std::cout << "Please enter some kind of word: ";
  std::cin >> pointerVar;

  std::cout << "POINTER VAR IS " << pointerVar << std::endl;
  someFunction(pointerVar);

  std::cout << "POINTER VAR IS NOW " << pointerVar << std::endl;
}
