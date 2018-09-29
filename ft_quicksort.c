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

static int	partition(int *arr, const int low, const int high)
{
	int	i = -1;
	int	j = low - 1;
	int	pivot = arr[high];

	while (++j < high)
	{
		if (arr[j] < pivot)
			swap(arr + (++i), arr + j);
	}
	swap(arr + (++i), arr + high);
	return (i);
}

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
			quicksort(arr, pivot);
			quicksort(arr + pivot, len - pivot);
		}
		else
			ft_insertion_sort(arr, len);
	}
}
