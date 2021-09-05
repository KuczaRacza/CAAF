#include "types.hpp"
#include <cstdlib>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <fstream>
void dstoffsetcopy(void *dst, void *src, u32 *offset, u32 size) {
  memcpy((u8 *)dst + *offset, src, size);
  *offset += size;
}
void srcoffsetcopy(void *dst, void *src, u32 *offset, u32 size) {
  memcpy(dst, (u8 *)src + *offset, size);
  *offset += size;
}

Stream::Stream() {}
Stream::Stream(u64 buffer_size) {
  ptr = (u8 *)malloc(buffer_size);
  size = buffer_size;
}
Stream::~Stream() { free(ptr); }
auto read_file(std::vector<u16> &file, const char *path) -> void {
  std::ifstream f;
  f.open(std::string(path), std::ios::binary | std::ios::in);
  if (!f.good()) {
    printf("cannot find file %s\n", path);
  }
  f.seekg(0, std::ios::seekdir::_S_end);
  u64 size = f.tellg();
  f.seekg(0, std::ios::seekdir::_S_beg);
  file.resize(size / 2);
  f.read((char *)file.data(), size);
}
auto write_file(std::string name, std::string &file) -> void{
  std::ofstream f;
  f.open(name, std::ios::out | std::ios::binary);
  f.write(file.data(), file.size());
  f.close();
}