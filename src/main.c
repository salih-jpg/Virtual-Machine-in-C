#include <stdio.h> 
#include <stdbool.h>


typedef enum {
  PSH,
  ADD,
  POP,
  SET,
  HLT
}InstructionSet;

typedef enum {
  A, B, C, D, E, F,
  NUM_OF_REGISTERS
}Registers;

const int program[] = {
  PSH, 5,
  PSH, 6,
  ADD,
  POP,
  HLT
};


ip = 0;
bool running = true;
int sp= -1;
int stack [256];
int registers[NUM_OF_REGISTERS];

int fetch(){
  return program[ip];
}

 void eval(int instr){
  switch (instr) {
    case HLT:
      running = false;
      break;
    case PSH:{
      sp++;
      stack[sp] = program[++ip]; //ip is the value after argument PSH
      break;
    }
    case POP:{
      int val_popped = stack[sp--]; //store the value at the stack in val_popped 
      printf("popped &d\n, val_popped");
    }
    case ADD:{
      int a = stack[sp--];
      int b = stack[sp--];
      int result = a + b;
      sp++;
      stack[sp] = result;
      break;
    }
}

int main() {
 while (running) {
    eval(fetch());
    ip++; //increment the ip every iteration
  }
  return 0;
}


