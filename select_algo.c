#include "pushswap.h"

void select_strategy(t_stack *a, t_stack *b, char **argv)
{
	
		if (strcmp(argv[1], "--simple") == 0)
                        simple(a);
                if (strcmp(argv[1], "--medium") == 0)
                        medium(a, b);
                if (strcmp(argv[1], "--complex") == 0)
                        complex_sort(a, b);
                else
                        adaptive(a, b);
}
