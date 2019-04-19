// Solomon Yakubov, 2019
// GPLv3

#include "lvmlib.h"

bool running = true;
int registers[NUM_OF_REGISTERS] = {0};

int main()
{
  printf("Begin execution.\n");
  while(running)
  {
      eval(fetch());
      registers[IP]++;
  }
}
