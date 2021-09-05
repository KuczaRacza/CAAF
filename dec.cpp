#include "src/caaf.hpp"
#include "src/types.hpp"
#include <fstream>
#include <ios>
#include <string>
#include <string_view>
#include <vector>
auto read_file_string(std::string &out, std::string path) -> void {
  std::ifstream f;
  f.open(path, std::ios::binary | std::ios::in);
  if (!f.good()) {
    printf("cannot find file %s\n", path.c_str());
  }
  f.seekg(0, std::ios::seekdir::_S_end);
  u64 size = f.tellg();
  f.seekg(0, std::ios::seekdir::_S_beg);
}
int main(int argc, char **argv) {
  std::string file;
  std::vector<u16> pcm;
  read_file_string(file, argv[1]);
  u64 index = 0;
  u64 second_index = 0;
  while (true) {
    index = file.find_first_of('\n');
	if(index ==std::string::npos){
		break;
	}

	second_index = index;
  }

  return 0;
}