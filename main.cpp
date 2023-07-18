#include <iostream>

int main()
{
  std::cout << "Elise Wendlandt, 115" << std::endl;

  int x = 5;
  int y = 7;
  int z = x + y;
  std::cout << "The sum of " << x << " and " << y << " is " << x+y<< std::endl;
  std::cout << z<< std::endl;

  int w = x * y * z;
  std::cout << "The product of " << x << " and " << y << "and " << z << " is " << w << std::endl;
  std::cout << w << std::endl;
  int v = x/y;
  std::cout << "The quotient of " << x << " and " << y << " is " << v << std::endl;
  std::cout << "This is " << v << std::endl;

  return 0;
}