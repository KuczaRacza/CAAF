#include "caaf.hpp"
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
CAAF::CAAF() {}
CAAF::~CAAF() {}
auto CAAF::load_file(u32 sampling_rate, u32 channels) -> std::vector<u16> & {
  sampling = sampling_rate;
  this->channels = channels;
  return raw_file;
}
auto CAAF::encode() -> void {
  u32 multi = 256;
  u32 last_sample = 0;
  for (auto i : raw_file) {
    if (i > last_sample - rle_tolerance && i < last_sample + rle_tolerance) {
      output_buffer += "POWTÓRZENIE\n";
    } else {

      if (i / multi > max_len) {
        multi = i / target_len;
        std::stringstream a;
        a << multi;
        output_buffer += "MNOŻNIK " + a.str() + '\n';
      } else if (i / multi < min_len) {
        multi = i / target_len;
        std::stringstream a;
        a << multi;
        output_buffer += "MNOŻNIK " + a.str() + '\n';
      }
      multi = std::max<u32>(multi, 1);
      for (u32 j = 0; j < i / multi; j++) {
        output_buffer.push_back('=');
      }
      last_sample = i;
      output_buffer.push_back('\n');
    }
  }
}
auto CAAF::get_file() -> std::string & { return output_buffer; }