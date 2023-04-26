#include "impl.h"
#include "vm.h"
#include "mem.h"

void
impl_nop(vm_p vm) {
	vm->ip++;
}

void
impl_lit(vm_p vm) {
	vm->ip++;
	vm->dstack[vm->sp++] = vm->mem[vm->ip++];
}

void
impl_pop(vm_p vm) {
	vm->ip++;
	vm->dstack[--vm->sp] = 0;
}

void
impl_end(vm_p vm) {
	vm->ip = MEM_END;
}

impl_fn instr[OP_COUNT] = {
	impl_nop, impl_lit, impl_pop, impl_end
};
