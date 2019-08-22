// rgw_rest_s3.h:714
// looks_like_ip_address

#include <iostream>

bool looks_like_ip_address(const char *bucket);

int main(){
  char *ip = "10.239.47.81";
  char *like_ip = "10.1.345.";
  bool stat = looks_like_ip_address(ip);
  std::cout << stat << '\n';
  return 0;
}

bool looks_like_ip_address(const char *bucket){
  int num_periods = 0;
  bool expect_period = false;
  const char *b = bucket;
  for(b = bucket; *b; ++b){
    if (*b == '.'){
      if(!expect_period)
        return false;
      ++num_periods;
      if(num_periods > 3)
        return false;
      expect_period = false;
    }
    else if(isdigit(*b)){
      expect_period = true;
    }
    else{
      return false;
    }
  }
  return (num_periods == 3) && *(--b) != '.';
}
