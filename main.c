#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	a = parsing(argc, argv);
	if (!is_sorted(a))
		simple(a);
	return (0);
}
