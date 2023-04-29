#include "vm.h"

void
vm_init(vm_p vm) {
	/* Clear memory */
	for(int i=0;i<MEM_END;++i) {
		vm->mem[i] = 0;
	}

	/* Clear stacks */
	for(int i=0;i<STACK_END;++i) {
		vm->ds[i] = 0;
		vm->rs[i] = 0;
	}

	/* Clear pointers */
	vm->dp = vm->rp = vm->pc = 0;
}
