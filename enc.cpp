#include "src/caaf.hpp"
#include "src/types.hpp"
#include <fstream>
#include <ios>
#include <string>
#include <vector>

int main(int argc, char **argv) {
  CAAF encoder;
  read_file(encoder.load_file(48000, 1), argv[1]);
  encoder.encode();
  write_file("test.caaf", encoder.get_file());
  return 0;
}