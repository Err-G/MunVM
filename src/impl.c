#include "impl.h"
#include "vm.h"
#include "vm_conf.h"

/* Just for readability purposes */

/* Control Flow */

void
impl_nop(vm_p vm) {
	vm->ip++;
}

void
impl_hlt(vm_p vm) {
	vm->ip = MEM_END;
}

void
impl_jmp(vm_p vm) {
	if(--vm->dp==0) impl_hlt(vm);
	vm->ip = vm->ds[vm->dp];
}

/* Stack Manipulation */

void
impl_lit(vm_p vm) {
	vm->ip++;
	if(++vm->dp==STACK_END) impl_hlt(vm);
	vm->ds[vm->dp] = vm->ip++;
}

void
impl_pop(vm_p vm) {
	vm->ip++;
	if(--vm->dp==0) impl_hlt(vm);
	vm->ds[vm->dp+1] = 0;
}

/* All instructions */

impl_fn instr[OP_COUNT] = {
	/* Control flow */
	impl_nop, impl_hlt,// impl_jmp, impl_jsr, impl_sth, impl_ret,
	/* Stack modification */
	impl_lit, impl_pop,// impl_nip, impl_dup, impl_swp, impl_rot, impl_ovr,
	/* Arithmetic */
//	impl_add, impl_sub, impl_mul, impl_div, impl_mod,
	/* Logic */
//	impl_and, impl_ora, impl_not, impl_xor, impl_sft,
	/* Memory */
//	impl_ldd, impl_str,
	/* I/O */
//	impl_dei, impl_deo,
};
