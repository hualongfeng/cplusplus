#include<iostream>

#define STR1 "Hello"
#define STR2 "World"
#define STR3 STR1 STR2 "!"

int main(){
  std::cout << STR3 << '\n';
  return 0;
}
