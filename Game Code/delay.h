#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <time.h>
#endif

void setTimeout(void func(), unsigned int delay)
{
#ifdef _WIN32
	Sleep(delay);
	func();
#else
	struct timespec delayStruct = 
	{
		0, //start time
		delay*1000000  //amount of nanoseconds to sleep for (1ms = 1000000ns)
	};
	nanosleep(delayStruct, NULL);
	func();
#endif
}