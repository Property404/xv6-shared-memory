#include "types.h"
#include "user.h"
#include "assert.h"
int main()
{
	char* ptr;

	for(int i=0; i < 4; i++)
	{
		ptr = shmem_access(i);
		assert(ptr != NULL);

		char c = 'c';
		ptr[100] = c;

		char d = *(ptr+100);

		assert(c == d);
	}

	printf(1, "TEST PASSED\n");
	exit();
}
