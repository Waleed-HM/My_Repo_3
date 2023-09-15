#include "Test.h"

int main()
{
#ifdef ENALBE_DEBUG
	print_debug_message();
#else
	print_release_message();
#endif

	return 0;
}