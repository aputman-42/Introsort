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
#include <stdio.h>
#include <windows.h>

// static void	printArray(int *arr, int n)
// {
// 	for (int i=0; i < n; i++)
// 		printf("%d ", arr[i]);
// 	printf("\n");
// }

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

/* ************************************************************************** */

double get_time()
{
	LARGE_INTEGER t, f;
	QueryPerformanceCounter(&t);
	QueryPerformanceFrequency(&f);
	return (double)t.QuadPart/(double)f.QuadPart;
}

int	is_sorted(int *arr, size_t len)
{
	size_t i = 0;

	while (++i < len)
	{
		if (arr[i] < arr[i - 1])
		{
			printf("Index: %ld & %ld\nValue: %d & %d\n", i - 1, i, arr[i - 1], arr[i]);
			return (0);
		}
	}
	return (1);
}

int	main(void)
{
	size_t	size = 10000;
	int		*arr;
	double	start, end;

	if (!(arr = (int *)malloc(sizeof(int) * size)))
		return (1);

	for(size_t i = 0; i < size; i++)
		arr[i] = random() % 100000;

	start = get_time();
	ft_introsort(arr, size);
	end = get_time();

	// printArray(arr, size);
	if (is_sorted(arr, size))
		printf("Array is sorted\n");
	else
		printf("Array is not sorted\n");
	printf("Time: %f\n ", end - start);

	free(arr);
	arr = NULL;

	return (0);
}
