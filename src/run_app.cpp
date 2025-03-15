#include "rdtsc.h"
#include <iostream>

using namespace std;

int run_app(int argc, char **argv) {
  if (argc < 0) {
    return -1;
  }

  if (argv != nullptr) {
    for (int i = 0; i < argc; i++) {
      std::cout << argv[i] << std::endl;
    }
  }

  run_rdtsc();

  return 0;
}