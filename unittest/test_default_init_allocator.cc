//
// Created by grakra on 2020/10/30.
//

#include <gtest/gtest.h>
#include <default_init_allocator.hh>
#include <iostream>
namespace test {
class TestDefaultInitAllocator : public testing::Test {
};
TEST_F(TestDefaultInitAllocator, testSwapVectorAndRawVector) {
  raw::raw_string a;
  a.resize(10);
  for (int i = 0; i < 10; ++i) {
    a[i] = 'a' + i;
  }
  std::string b(std::move(reinterpret_cast<std::string &>(a)));
  std::cout << a.size() << std::endl;
  std::cout << b.size() << std::endl;
}
TEST_F(TestDefaultInitAllocator, testSwapStringAndRawString) {
  raw::raw_vector<uint8_t> a;
  a.resize(10);
  for (int i = 0; i < 10; ++i) {
    a[i] = i;
  }
  std::vector<uint8_t> b(std::move(reinterpret_cast<std::vector<uint8_t> &>(a)));
  std::cout << a.size() << std::endl;
  std::cout << b.size() << std::endl;
}
} // namespace test;
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}