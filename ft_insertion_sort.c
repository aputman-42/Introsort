/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* ************************************************************************** */

#include "libsort.h"

void	insertion_sort(int *arr, const size_t len)
{
	int		i;
	int		j;
	int		key;

	i = 0;
	while (++i < len)
	{
		key = arr[i];
		j = i;
		while (--j >= 0 && arr[j] > key)
			arr[j + 1] = arr[j];
		arr[j + 1] = key;
	}
}
