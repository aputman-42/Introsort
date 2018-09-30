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
#include <math.h>

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

static void	ft_introsort_util(int *arr, const size_t len, const size_t depth_limit)
{
	int pivot;
	int	low	= 0;
	int high = len - 1;

	if (len < 16)
		return ft_insertion_sort(arr, len);
	if (depth_limit == 0)
		return ft_heapsort(arr, len);

	pivot = partition(arr, low, high);
	ft_introsort_util(arr, pivot, depth_limit - 1);
	ft_introsort_util(arr + pivot, len - pivot, depth_limit - 1);
}

void	ft_introsort(int *arr, const size_t len)
{
	size_t	depth_limit;

	depth_limit = 2 * log(len);
	ft_introsort_util(arr, len, depth_limit);
}
