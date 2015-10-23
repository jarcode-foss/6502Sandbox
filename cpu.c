#include "cpu.h"

//Example opcode implementation, what do you think?
inline void op_lda(cpu_t *cpu){
    int val = cpu->memory[cpu->pc];
    cpu->pc++;
    cpu->reg_A = cpu->irq ? val & 255 : val;
}