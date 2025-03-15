#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include <string>

extern int run_app(int argc, char **argv);

TEST(RunAppTest, RunApp) {
  // Redirect std::cout to a stringstream
  std::stringstream buffer;
  std::streambuf *prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

  run_app(1, nullptr);

  // Restore std::cout to its previous buffer
  std::cout.rdbuf(prevcoutbuf);

  // // Check the output
  // std::string expected_output = "";
  // ASSERT_EQ(buffer.str(), expected_output);
}