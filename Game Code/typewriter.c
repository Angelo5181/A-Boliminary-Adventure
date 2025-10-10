#include <string.h>
#ifdef _Win32
	#include <windows.h>
#else
	#include <unistd.h>
	#include <time.h>
void Sleep(int ms)
{
	//printf("Sleeping for %d ms...\n", ms);
	ms %= 1000; // prevent picking a value that is too large
	struct timespec timeStruct = {0, ms * 1000000};
	// sleep for the amount of time specified in timeStruct and dont store the amount of time remaining if interrupted
	nanosleep(&timeStruct, NULL);
}
#endif
#include <stdio.h>

const unsigned int delay = 17; // in milliseconds

void typeWriter(char* text, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%c", *(text + i));
		Sleep(delay);
	}
	printf("\n");
}

/**
 * *text is just a string, can be like: "Sample Text"
 * removeNewLine determines whether to remove the final '\n' from fgets()
 */
void typeWriterPointer(char *text, int length, int removeNewLine)
{
	printf("text:%s\n", text);
	for (int i = 0; i < length; i++)
	{
		if (removeNewLine)
		{
			if ((i + 1) == length && *(text + i) == '\n')
			{
				printf(" ");
			}
			else
			{
				printf("%c", *(text + i));
			}
		}
		else
		{
			printf("%c", *(text + i));
		}
		Sleep(delay);
	}
	//printf("\n");
	// printf("%d %s\n", length, text);
}