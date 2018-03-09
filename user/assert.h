#define assert(x)\
	if(!(x))\
	printf(2, "Assertion failed on line %d in file %s\n", __LINE__, __FILE__), exit();
