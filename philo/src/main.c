#include "philosophers.h"

int	main(int argc, char *argv[])
{
	int *n;
	if ((argc != 6 && argc != 5))
	{
		perror("Invalid number of arguments");
		exit(1);
	}
	n = malloc(sizeof(int) * argc);
	parse_input(argv, n);
	return (0);
}