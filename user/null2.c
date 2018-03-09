// Test:
// Any dereference fromf irst page should fault
#include "types.h"
#include "user.h"
int main(int argc, char* argv[])
{
	int ppid = getpid();
	int pid = fork();
	if (pid < 0){
		printf(1, "TEST_FAILED\n");
		exit();
	}
	else if (pid == 0){
		uint * badp = (uint*)4095;
		printf(1, "bad dereference (0x0fff): "
				"%x %x\n", badp, *badp);
		// this process should be killed
		printf(1, "TEST FAILED");
		kill(ppid);
		exit();
	}
	else{
		wait();
		printf(1, "TEST_PASSED\n");
		exit();
	}
}
