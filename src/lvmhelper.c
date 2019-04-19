// Solomon Yakubov, 2019
// GPLv3

#include "lvmlib.h"

char* register_name(int regnum)
{
  char* name = (char *) malloc(100); 
  switch(regnum)
  {
  case 0:
    ;
    strcpy(name, "AR");
    break;
  case 1:
    ;
    strcpy(name, "AX");
    break;
  case 2:
    ;
    strcpy(name, "BX");
    break;
  case 3:
    ;
    strcpy(name, "CX");
    break;
  case 4:
    ;
    strcpy(name, "IP");
    break;
  }
  return name;
}

int fetch()
{
  return program[registers[IP]];
}

void eval(int instruction)
{
  switch(instruction)
  {
    
  case EXIT:
  {
    running = false;
    printf("Program exit.\n");
    break;
  }
  
  case RMOV:
  {
    registers[IP]++;
    int reg = program[registers[IP]];
    registers[IP]++;
    registers[reg] = registers[program[registers[IP]]];
    break;
  }

  case MOV:
  {
    registers[IP]++;
    int reg = program[registers[IP]];
    registers[IP]++;
    registers[reg] = program[registers[IP]];
    break;
  }
  
  case ADD:
  {
    registers[IP]++;
    registers[AR] += program[registers[IP]];
    break;
  }

  case RADD:
  {
    registers[IP]++;
    registers[AR] += registers[program[registers[IP]]];
    break;
  }  
  
  case SUB:
  {
    registers[IP]++;
    registers[AR] -= program[registers[IP]];
    break;
  }

  case RSUB:
  {
    registers[IP]++;
    registers[AR] -= registers[program[registers[IP]]];
    break;
  }

  case MUL:
  {
    registers[IP]++;
    registers[AR] *= program[registers[IP]];
    break;
  }

  case RMUL:
  {
    registers[IP]++;
    registers[AR] *= registers[program[registers[IP]]];
    break;
  }

  case DIV:
  {
    registers[IP]++;
    registers[AR] /= program[registers[IP]];
    break;
  }

  case RDIV:
  {
    registers[IP]++;
    registers[AR]  /= registers[program[registers[IP]]];
    break;
  }

  case PRINTLIT:
  {
    registers[IP]++;
    printf("Literal value: %d\n", program[registers[IP]]);
    break;
  }
  
  case PRINTR:
  {
    registers[IP]++;
    char* reg = register_name(program[registers[IP]]);
    char insp[100] = "Inspecting register ";
    strcat(reg, "\n");
    strcat(insp, reg);
    printf(insp);
    printf("Value: %d\n", registers[program[registers[IP]]]);
    break;
  }
  
  default:
    perror("Instruction not recognized.");
    break;
  }
}
