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

static void	swap(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

static int	Mo3(int *arr, const int low, const int high)
{
	const int	mid = low + ((high - low) / 2);

	if (arr[high] < arr[low])
		swap(arr + low, arr + high);
	if (arr[mid] < arr[low])
		swap(arr + low, arr + mid);
	if (arr[high] < arr[mid])
		swap(arr + mid, arr + high);
	return (arr[high]);
}

static int	partition(int *arr, const int low, const int high)
{
	int	i = -1;
	int	j = low - 1;
	int	pivot = Mo3(arr, low, high);

	while (++j < high)
	{
		if (arr[j] < pivot)
			swap(arr + (++i), arr + j);
	}
	swap(arr + (++i), arr + high);
	return (i);
}

/**
 * Best case performance:	O(n log(n))
 * Average performance:		O(n log(n))
 * Worst case performance:	O(log(n))
 */
void		ft_quicksort(int *arr, const size_t len)
{
	int pivot;
	int	low	= 0;
	int high = len - 1;

	if (low < high)
	{
		if (len > 16)
		{
			pivot = partition(arr, low, high);
			ft_quicksort(arr, pivot);
			ft_quicksort(arr + pivot, len - pivot);
		}
		else
			ft_insertion_sort(arr, len);
	}
}
