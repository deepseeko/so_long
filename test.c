#include <stdio.h>
#include <sys/ioctl.h>
int main()
{
	struct winsize w;

	printf("lines %d\n", w.ws_row);
	printf("columns %d\n", w.ws_col);
	return 0;
}
