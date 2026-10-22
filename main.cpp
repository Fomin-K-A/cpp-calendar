#include <iostream>
#include <cstdlib>

#include "calendar.h"

int main(int argc, char* argv[]) {
  if (argc == 2) {
    printYear(std::atoi(argv[1]));
  } else if (argc == 3) {
    printMonth(std::atoi(argv[1]), std::atoi(argv[2]));
  } else {
    std::cerr << "Wrong arguments !";
    return 0;
  }
}