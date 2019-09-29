#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;
typedef __uint64_t uint64_t;

struct obj_version {
  uint64_t ver;
  uint32_t tag_len;
  char *tag;
};

enum VersionCond {
  VER_COND_NONE =      0,
  VER_COND_EQ,  /* equal */
  VER_COND_GT,  /* greater than */
  VER_COND_GE,  /* greater or equal */
  VER_COND_LT,  /* less than */
  VER_COND_LE,  /* less or equal */
  VER_COND_TAG_EQ,
  VER_COND_TAG_NE,
};

struct obj_version_cond {
  uint8_t cond_len;
  char cond;
  uint32_t ver_size;
  struct obj_version ver;
};

int main()
{
  FILE *fp = fopen("key", "r");
  if(fp == NULL)return -1;
  
  struct obj_version_cond data;
  
  fscanf(fp,"%c", &data.cond_len);

  fscanf(fp,"%c", &data.cond);

  char *s = (char*)&data.ver_size;
  for(int i = 0; i < 4; i++)
    fscanf(fp,"%c", s+i);

  s = (char*)&data.ver;
  for(int i = 0; i < 12; i++)
    fscanf(fp,"%c", s+i);

  data.ver.tag = (char*)malloc(data.ver.tag_len+1);
  data.ver.tag[data.ver.tag_len]='\0';
  for(int i = 0; i < data.ver.tag_len; i++)
  {
    fscanf(fp,"%c", data.ver.tag+i);
  }
  
  printf("cond:%d\n",data.cond);
  printf("var_len:%d\n", data.ver_size);
  printf("tag_len:%d\n", data.ver.tag_len);
  printf("obj_version ver=%ld tag=%s\n", data.ver.ver, data.ver.tag);

//  char a[42];
//  for(int i = 0; i < 42; i++)
//  {
//    fscanf(fp,"%c", a+i);
//  }
//  for(int i = 18; i < 42; i++)
//  {
//    printf("%c",a[i]);
//  }
//  printf("\n");
//  for(int i = 0; i < 18; i++)
//  {
//    printf("%d:%d\n",i+1,a[i]);
//  }
  return 0;
}
