#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;
typedef __uint64_t uint64_t;

struct uid {
  uint32_t num;
  char *user;
};

int main()
{
  FILE *fp = fopen("key", "r");
  if(fp == NULL)return -1;
  struct uid users;
  char *s = (char*)&users.num;
  for(int i = 0; i < 4; i++)
  {
    fscanf(fp, "%c", s+i);
  }
  users.user = (char*)malloc(users.num+1);
  users.user[users.num]='\0';
  for(int i = 0; i < users.num; i++)
  {
    fscanf(fp,"%c", users.user+i);
  }
  printf("%d,%s\n",users.num,users.user);
  return 0;
}
