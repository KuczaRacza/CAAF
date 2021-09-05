#include "types.hpp"
#include <string>
#include <vector>
class CAAF {
public:
  CAAF();
  ~CAAF();
  auto load_file(u32 sampling_rate, u32 channels) -> std::vector<u16> &;
  auto encode() -> void;
  auto get_file() -> std::string &;

protected:
  std::vector<u16> raw_file;
  std::string output_buffer;
  u32 sampling;
  u32 channels;
  u32 max_len = 64;
  u32 min_len = 16;
  u32 target_len = (min_len + max_len )/2;
  u32 rle_tolerance = 32;
};