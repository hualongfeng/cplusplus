/// distance example
#include <iostream>
#include <iterator>
#include <list>

int main(){
  std::list<int> mylist;
  for(int i=0; i < 10; i++) mylist.push_back(i*10);

  std::list<int>::iterator first = mylist.begin();
  auto last = mylist.end();

  std::cout << "The distance is: " << std::distance(first, last) << std::endl;

  return 0;
}
