#ifndef IMPL_H
#define IMPL_H

/* Includes */

#include "vm.h"

/* Types */

typedef void (*impl_fn)(vm_p);

enum impl_opcode {
	OP_NOP, OP_LIT, OP_POP, OP_END,
	OP_COUNT
};

/* Prototypes */

void impl_nop(vm_p vm);
void impl_lit(vm_p vm);
void impl_pop(vm_p vm);
void impl_end(vm_p vm);

extern impl_fn instr[OP_COUNT];

#endif
