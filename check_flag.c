#include "pushswap.h"

int     check_flag(char **argv, int argc)
{
        int     	i;
        int     	j;
	int	algo;

	algo = 0;
	i = 0;
        j = 1;
        while (j < argc)
        {
                        if (strcmp(argv[j], "--bench") == 0)
				algo += 10;
                        else if (strcmp(argv[j], "--simple") == 0)
				algo += 1;
                        else if (strcmp(argv[j], "--medium") == 0)
				algo += 2;
                        else if (strcmp(argv[j], "--complex") == 0)
				algo += 3;
		j++;
        }
	return (algo);
}
