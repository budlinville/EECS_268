/* Bud Linville
  2819130
  EECS 268
  TA: Surya Tej Nimmakayala
  Lab finished on 2/7/16
*/


#include "Executive.h"
#include <string>
#include <cstring>

//Initiates program.
int main(int argc, char* argv[]){
  std::string fileName = argv[1];
  Executive exec(fileName);
  exec.run();
  return 0;
};
