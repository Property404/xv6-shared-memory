#include "assert.h"
#include "types.h"
#include "user.h"

int main()
{
	int* x = shmem_access(0);
	*x = 42;
	printf(1, "%p:", x);
	printf(1, "%d\n", *x);
	assert(*x == 42);
	assert(shmem_count(0) == 1);
	exit();
}
