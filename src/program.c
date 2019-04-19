// Solomon Yakubov, 2019
// GPLv3

#include "lvmlib.h"

// Default program
const int program[] =
{
 EXIT
};


/* Sample 1
const int program[] =
{
  ADD, 5,
  RMOV, AX, AR,
  MUL, 15,
  PRINTR, AX,
  PRINTR, AR,
  EXIT
};
*/

 /* Sample 2
const int program[] =
{
  SUB, 17,
  MUL, 40, 
  RMOV, CX, AR,
  PRINTR, CX,
  EXIT
};
*/

/* Sample 3
const int program[] =
{
  MOV, AR, 1,
  PRINTR, AR,
  MOV, BX, 5,
  RMOV, AX, BX,
  RMUL, AX,
  PRINTR, AR, 
  PRINTLIT, 10, 
  RDIV, AX,
  PRINTR, AR,
  EXIT
};
*/
 
