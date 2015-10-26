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
void close(cpu_t *cpu);

void inc_pc();

// Opcode Implementations
// -------------------------------------------------
//

__inline__ void op_lda(cpu_t *cpu);
__inline__ void op_ldx(cpu_t *cpu);
__inline__ void op_ldy(cpu_t *cpu);
__inline__ void op_brk(cpu_t *cpu);
__inline__ void op_bpl(cpu_t *cpu);
__inline__ void op_jsr(cpu_t *cpu);
__inline__ void op_bmi(cpu_t *cpu);
__inline__ void op_rti(cpu_t *cpu);
__inline__ void op_bvc(cpu_t *cpu);
__inline__ void op_rts(cpu_t *cpu);
__inline__ void op_bvc(cpu_t *cpu);
__inline__ void op_bcc(cpu_t *cpu);
__inline__ void op_bcs(cpu_t *cpu);
__inline__ void op_cpy(cpu_t *cpu);
__inline__ void op_bne(cpu_t *cpu);
__inline__ void op_beq(cpu_t *cpu);
__inline__ void op_ora(cpu_t *cpu);
__inline__ void op_and(cpu_t *cpu);
__inline__ void op_eor(cpu_t *cpu);
__inline__ void op_adc(cpu_t *cpu);
__inline__ void op_sta(cpu_t *cpu);
__inline__ void op_cmp(cpu_t *cpu);
__inline__ void op_sbc(cpu_t *cpu);
__inline__ void op_cpx(cpu_t *cpu);
__inline__ void op_bit(cpu_t *cpu);
__inline__ void op_asl(cpu_t *cpu);
__inline__ void op_rol(cpu_t *cpu);
__inline__ void op_lsr(cpu_t *cpu);
__inline__ void op_ror(cpu_t *cpu);
__inline__ void op_stx(cpu_t *cpu);
__inline__ void op_dec(cpu_t *cpu);
__inline__ void op_inc(cpu_t *cpu);
__inline__ void op_php(cpu_t *cpu);
__inline__ void op_clc(cpu_t *cpu);
__inline__ void op_plp(cpu_t *cpu);
__inline__ void op_sec(cpu_t *cpu);
__inline__ void op_pha(cpu_t *cpu);
__inline__ void op_cli(cpu_t *cpu);
__inline__ void op_pla(cpu_t *cpu);
__inline__ void op_sei(cpu_t *cpu);
__inline__ void op_dey(cpu_t *cpu);

#endif //CPU_H_
