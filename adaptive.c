#include "pushswap.h"

void	adaptive(t_stack *a, t_stack *b)
{
	double	dis;

	dis = disorder(a);
	if (dis < 0.2)
		simple(a);
	else if (dis >= 0.2 && dis < 0.5)
		medium(a, b);
	else
		complex_sort(a, b);
}
