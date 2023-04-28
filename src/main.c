/* MunVM - v0.1 */

/* Includes */

#include <stdio.h>
/*  TODO: use less, like getchar, putchar & EOF */

#include "vm.h"
#include "impl.h"

void
test(vm_p vm) {
//	vm->mem[] = ;
	vm->mem[0] = OP_NOP; 
	vm->mem[1] = OP_LIT;
	vm->mem[2] = 0x0f;
	vm->mem[3] = OP_POP;
	vm->mem[4] = OP_HLT;
}

int
main(void) {
	vm_t vm;
	vm_init(&vm);
	test(&vm);
	
	while(!vm_ended(&vm)) {
		vm_exec(&vm);
		vm_stat(&vm);
	}
	
	return 0;
}
