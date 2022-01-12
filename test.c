#include <stdio.h>
#include <unistd.h>

void	hello(void)
{
	printf("hey");
}

int	main(void)
{
	hello();
	sleep(1);
	printf("hello");
	sleep(1);
}
