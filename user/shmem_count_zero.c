#include "assert.h"
int main()
{
	int n;
	int i;

	for(i = 0; i < 4; i++)
	{
		n = shmem_count(i);
		if(n!=0)test_failed();
	}
	test_passed();
	exit();
}
