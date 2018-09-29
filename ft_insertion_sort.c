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

/**
 * For every value the insertion sort will save the current value and compare
 * it to every previous value until it finds its final position and shifts the
 * array to insert the saved value into position
 *
 * Best case performance:	O(n)	comparisons, O(1)	swaps (array sorted)
 * Average performance:		O(n^2)	comparisons, O(n^2)	swaps
 * Worst case performance:	O(n^2)	comparisons, O(n^2)	swaps (reverse sorted)
 */
void	ft_insertion_sort(int *arr, const size_t len)
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
