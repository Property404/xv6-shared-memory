#include "assert.h"
int main()
{
	int n;

	n = shmem_count(-1);
	if (n != -1) test_failed();
	n = shmem_count(-100);
	if (n != -1) test_failed();
	n = shmem_count(4);
	if (n != -1) test_failed();
	n = shmem_count(100);
	if (n != -1) test_failed();
	test_passed();
	exit();
}
