#include <unistd.h>
#include <libstd.h>
#include <stdio.h>

int main(int argc, char *s[])
{
	t_stack *a;
	t_stack *b;

	if (argc >= 2)
	{
		if (strcmp(argv[1], "--simple") == 0)
			simple(a, b);
		if (strcmp(argv[1], "--medium") == 0)
                        medium(a, b);
		if (strcmp(argv[1], "--complex") == 0)
                	complex_sort(a, b);
		else
			adaptive(a, b);
	}








}
