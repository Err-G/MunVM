#include "mem.h"
#include <stdio.h>

void
mem_verify(void) {
	if(DCELL_SIZE!=(CELL_SIZE*2))
		printf("Err: size(dcell)!=size(cell)*2\n");
}
