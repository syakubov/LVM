// Solomon Yakubov, 2019
// GPLv3

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

extern char* register_name(int);
extern int fetch();
extern void eval(int);
extern const int program[];
extern int registers[];
extern bool running;

typedef enum
{
	      AR,
	      AX, 
	      BX,
	      CX,
	      IP,
	      NUM_OF_REGISTERS
}
Registers;

typedef enum
{
	      MOV,
	      RMOV,
	      
	      ADD,
	      RADD,
	      
	      SUB,
	      RSUB,
	      
	      MUL,
	      RMUL,
	      
	      DIV,
	      RDIV,
	      
	      PRINTLIT,
	      PRINTR,
	      
	      EXIT
}
Instructions;
