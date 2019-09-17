//编译选项要加上-std=c++17
#include <optional>

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

auto get_even_random_number()
{
  int i = std::rand();
  return (i % 2 == 0) ? i : std::optional<int>{};
}
int main()
{
  std::srand(static_cast<unsigned int>(std::time(0)));
  std::optional<int> i = get_even_random_number();
  if(i)
    std::cout << std::sqrt(static_cast<float>(*i)) << '\n';
  return 0;
}
