#include "assert.h"
#include "types.h"
#include "user.h"
#include "fcntl.h"
int
main(int argc, char *argv[])
{
	int fd = open("tmp", O_WRONLY | O_CREATE);
	assert(fd != -1);

	// at zero 
	char* arg = (char*) 0x0;
	assert(write(fd, arg, 10) == -1);

	// within null page
	arg = (char*) 0x400;
	assert(write(fd, arg, 1024) == -1);

	// Spanning null page and code 
	arg = (char*) 0xfff;
	assert(write(fd, arg, 2) == -1);

	printf(1, "TEST PASSED\n");
	exit();
}
