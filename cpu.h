#include "sandbox.h"
#include <stdbool.h>

#ifndef CPU_H_
#define CPU_H_

#define MAX_MEM 8192

//Designed to be contained by a sandbox_inst
//Contains all the memory and is responsible for handling opcodes
typedef struct {
    unsigned char *memory; //Memory bytes. Should default to MAX_MEM

    int reg_A; //Accumulator
    int reg_X; //B register
    int reg_Y; //C register

    int pc; //Program Counter

    bool carry; //Carry flag
    bool neg; //Negative flag
    bool overflow; //Overflow flag
    bool brk; //BRK flag
    bool dec; //Decimal flag
    bool zero; //Zero flag
    bool irq; //IRQ Disable flag
} cpu_t;

void init(sandbox_inst *container, cpu_t *cpu);
void close(sandbox_inst *container, cpu_t *cpu);

// Opcode Implementations
// -------------------------------------------------
//

inline void op_lda(cpu_t *cpu);

#endif //CPU_H_
