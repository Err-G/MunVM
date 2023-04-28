#ifndef IMPL_H
#define IMPL_H

/* This is the header of the VM implementation.You can and
should modify and extend the functionalities and instructions
of the VM according to your specific use case. This will allow 
you to tailor the VM to your specific needs. */

/* Includes */

#include "vm.h"

/* Types */

typedef void (*impl_fn)(vm_p);

enum impl_opcode {
	/* Control flow */
	OP_NOP, OP_HLT,// OP_JMP, OP_JCN, OP_JSR, OP_STH, OP_RET,
	/* Stack modification */
	OP_LIT, OP_POP,// OP_NIP, OP_DUP, OP_SWP, OP_ROT, OP_OVR,
	/* Arithmetic */
//	OP_ADD, OP_SUB, OP_MUL, OP_DIV, OP_MOD, OP_INC, OP_DEC,
	/* Logic */
//	OP_AND, OP_ORA, OP_NOT, OP_XOR, OP_SFT,
	/* Memory */
//	OP_LDD, OP_STR,
	/* I/O */
//	OP_DEI, OP_DEO,
	/* Instruction count */
	OP_COUNT
};

/* Prototypes */

/* Control flow */
void impl_nop(vm_p vm);
void impl_hlt(vm_p vm);
void impl_jmp(vm_p vm);
void impl_jsr(vm_p vm);
void impl_sth(vm_p vm);
void impl_ret(vm_p vm);

/* Stack modification */
void impl_lit(vm_p vm);
void impl_pop(vm_p vm);
void impl_nip(vm_p vm);
void impl_dup(vm_p vm);
void impl_swp(vm_p vm);
void impl_rot(vm_p vm);
void impl_ovr(vm_p vm);

/* Arithmetic */
void impl_add(vm_p vm);
void impl_sub(vm_p vm);
void impl_mul(vm_p vm);
void impl_div(vm_p vm);
void impl_mod(vm_p vm);

/* Logic */
void impl_and(vm_p vm);
void impl_ora(vm_p vm);
void impl_not(vm_p vm);
void impl_xor(vm_p vm);
void impl_sft(vm_p vm);

/* Memory */
void impl_ldd(vm_p vm);
void impl_str(vm_p vm);

/* Input/Output */
void impl_dei(vm_p vm);
void impl_deo(vm_p vm);

/* List of all functions for execution in
 * vm_exec(&vm) */

extern impl_fn instr[OP_COUNT];

#endif
