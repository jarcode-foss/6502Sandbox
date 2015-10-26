#include "cpu.h"

void init(sandbox_inst *container, cpu_t *cpu){
    cpu->memory = malloc(MAX_MEM);
    cpu->reg_A = 0;
    cpu->reg_X = 0;
    cpu->reg_Y = 0;
    cpu.brk = false;
    cpu.carry = false;
    cpu.dec = false;
    cpu.neg = false;
    cpu->overflow = false;
    cpu->pc = 0;
    cpu->zero = false;
    cpu->irq = false;
}

void close(cpu_t *cpu){
    free(cpu->memory);
}

//Example opcode implementation, what do you think?
inline void op_lda(cpu_t *cpu){
    int val = cpu->memory[cpu->pc];
    cpu->pc++;
    cpu->reg_A = cpu->irq ? val & 255 : val;
}