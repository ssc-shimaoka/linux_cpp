#include <iostream>
#include <cstddef>

int main()
{
  std::ios str(NULL);
  std::cout << "exceptions = " << str.exceptions() << '\n';
  std::cout << "rdstate = " << str.rdstate() << '\n';
  try {
    str.exceptions(std::ios_base::failbit | std::ios_base::badbit);
  } catch (std::ios_base::failure& e) {
    std::cout << "exceptions = " << str.exceptions() << '\n';
    std::cout << "rdstate = " << str.rdstate() << '\n';
    std::cout << e.what() << '\n';
  }
  std::cout << "end\n";
}