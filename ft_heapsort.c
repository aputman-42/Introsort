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
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	heapify(int *arr, const size_t index, const size_t len)
{
	size_t	largest;
	size_t	left_child;
	size_t	right_child;

	left_child = index * 2 + 1;
	right_child = index * 2 + 2;
	largest = index;
	if (left_child < len && arr[left_child] > arr[largest])
		largest = left_child;
	if (right_child < len && arr[right_child] > arr[largest])
		largest = right_child;
	if (largest != index)
	{
		swap(arr + largest, arr + index);
		heapify(arr, largest, len);
	}
}

/**
 * Best case performance:	O(n log(n)) (distinct keys) | O(n) (equal keys)
 * Average performance:		O(n log(n))
 * Worst case performance:	O(n log(n))
 */
void	ft_heapsort(int *arr, const size_t len)
{
	size_t	i;

	i = len / 2 - 1;
	while (--i + 1)
		heapify(arr, i, len);
	i = len;
	while (--i + 1)
	{
		swap(arr, arr + i);
		heapify(arr, 0, i);
	}
}
