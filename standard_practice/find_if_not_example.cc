// find_if_not example
#include<vector>
#include<iostream>  //std::cout
#include<algorithm> //std::find_if_not
#include<array>     //std::array

using namespace std;

bool has_four(int i);

int main(){
  array<int, 5> foo = {1,2,3,4,5};

  array<int, 5>::iterator it =
  find_if_not(foo.begin(), foo.end(), [](int i){return i%2;});

  cout << "The first even value is " << *it << '\n';

  vector<int> vec(5, 4);
  vec[3] = 5;
  auto vit = find_if_not(vec.begin(), vec.end(), has_four);
  cout << "The value not four is " << *vit << endl;

  return 0;
}

bool has_four(int i){
  return i == 4;
}
