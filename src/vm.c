#include "vm.h"
#include "vm_conf.h"
#include "impl.h"

#include <stdio.h>
#include <stdlib.h>

void
vm_init(vm_p vm) {
	/* Clear memory */
	for(vm->ip=0;;vm->ip++) {
		vm->mem[vm->ip] = 0;
		if(vm->ip==MEM_END) break;
	}

	/* Clear stacks */
	for(vm->ip=0;;vm->ip++) {
		vm->ds[vm->ip] = 0;
		vm->rs[vm->ip] = 0;
		if(vm->ip==STACK_END) break;
	}

	/* Clear pointers */
	vm->ip = vm->dp = vm->rp = 0;
}

int
vm_ended(vm_p vm) {
	if(vm->ip==MEM_END) return -1;
	return 0;
}

void
vm_exec(vm_p vm) {
	instr[vm->mem[vm->ip]](vm);
}

void
vm_stat(vm_p vm) {
	/* Print Memory */
	printf("mem:\n");
	for(int i=0;i<MEM_SIZE;i++) {
		int count = 1;
		printf("%02X ", vm->mem[i]);
		if((i+1) % 16 == 0) {
			printf("\n");
		}
		while(vm->mem[i] == vm->mem[i+1] && i<MEM_END) {
			count++;
			i++;
		}
		if(count>1) printf("(%d) ", count);
	}
	printf("\n");

	/* Print Data Stack */
	printf("ds:\n");
	for (int i=0;i<STACK_SIZE;i++) {
		int count = 1;
		printf("%02X ", vm->ds[i]);
		if ((i + 1) % 16 == 0) {
			printf("\n");
		}
		while(vm->ds[i] == vm->ds[i+1] && i<STACK_END) {
			count++;
			i++;
		}
		if(count>1) printf("(%d) ", count);
	}
	printf("\n");

	/* Print Return Stack */
	printf("rs:\n");
	for (int i=0; i<STACK_SIZE;i++) {
		int count = 1;
		printf("%02X ", vm->rs[i]);
		if ((i + 1) % 16 == 0) {
			printf("\n");
		}
		while(vm->rs[i] == vm->rs[i+1] && i<STACK_END) {
			count++;
			i++;
		}
		if(count>1) printf("(%d) ", count);
	}
	printf("\n");

	/* Print 'Pointers' */
	printf("ip: 0x%04X\n", vm->ip);
	printf("dp: 0x%02X\n", vm->dp);
	printf("rp: 0x%02X\n", vm->rp);
	printf("\n");
}
