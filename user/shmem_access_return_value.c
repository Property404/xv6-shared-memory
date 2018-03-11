// shmem_access return value needs to be one of 4
// pages 
// Address space: first access needs to return
// last virtual page, second needs to return
// second to last virtual page, etc
//
#include "types.h"
#include "user.h"
#include "param.h"
#include "assert.h"
#include "../kernel/mmu.h"

int main()
{
	void *ptr;

	ptr = shmem_access(2);
	assert(ptr != NULL);
	assert((int)ptr == USERTOP-PGSIZE*1);

	ptr = shmem_access(3);
	assert(ptr != NULL);
	assert((int)ptr == USERTOP-PGSIZE*2);

	ptr = shmem_access(0);
	assert(ptr != NULL);
	assert((int)ptr == USERTOP-PGSIZE*3);

	ptr = shmem_access(1);
	assert(ptr != NULL);
	assert((int)ptr == USERTOP-PGSIZE*4);


	printf(1, "TEST PASSED\n");
	exit();
}


