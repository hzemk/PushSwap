#include "pushswap.h"

int	count_numbers(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i])
		{
			count++;
			while (str[i] && str[i] != ' ')
				i++;
		}
	}
	return (count);
}

int	has_duplicate(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	fill_numbers(int *nums, char *str, int size)
{
	int		i;
	int		j;
	long	val;
	char	*start;

	i = 0;
	j = 0;
	while (str[i] && j < size)
	{
		while (str[i] == ' ')
			i++;
		start = &str[i];
		while (str[i] && str[i] != ' ')
			i++;
		if (!is_number(start))
			return (0);
		val = ft_atoi(start);
		if (val > INT_MAX || val < INT_MIN)
			return (0);
		nums[j++] = (int)val;
	}
	return (1);
}

int	*split_numbers(char *str, int *size)
{
	int	*nums;

	*size = count_numbers(str);
	nums = malloc(sizeof(int) * (*size));
	if (!nums)
		return (NULL);
	if (!fill_numbers(nums, str, *size))
		return (NULL);
	if (has_duplicate(nums, *size))
		return (NULL);
	return (nums);
}
