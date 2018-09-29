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

static void	heapify(int *arr, const size_t index, const size_t len)
{
	size_t	left_child;
	size_t	right_child;
	size_t	largest;

	left_child = 2 * index + 1;
	right_child = 2 * index + 2;
	largest = index;
	if (left_child < len && arr[largest] < arr[left_child])
		largest = left_child;
	if (right_child < len && arr[largest] < arr[right_child])
		largest = right_child;
	if (largest < len)
	{
		swap(arr + index, arr + largest);
		heapify(arr, index + 1, len);
	}
}

/**
 * Best case performance:	O(n log(n)) (distinct keys) | O(n) (equal keys)
 * Average performance:		O(n log(n))
 * Worst case performance:	O(n log(n))
 */
void	ft_heapsort(int *arr, const size_t len)
{
	int	i;

	i = len / 2;
	while (--i >= 0)
		heapify(arr, i, len);
	i = len;
	while (--i >= 0)
	{
		swap(arr, arr + i);
		heapify(arr, 0, i);
	}
}
