// Author: Josue Retana Rodriguez
// Implementation of several sort algorithms

#ifndef Sort_h
#define Sort_h
using namespace std;

class Sort
{
private:

	/* Merge sort aux */
	void merge_aux(int* A, int const p, int const q, int const r);
	void merge_sort_aux(int* A, int const p, int const r);

	/* Heap sort aux */
	void max_heapify_aux(int* a, int i, int n);
	void build_max_heap_aux(int* a, int n);

	/* Quick sort aux */
	void quick_sort_aux(int* A, int low, int high);

public:

	Sort();
	~Sort();
	void selection(int *A, int n);
	void insertion(int *A, int n);
	void mergesort(int *A, int n);
	void heapsort(int *A, int n);
	void quicksort(int *A, int n);
	void radixsort(int *A, int n);
};

/* PUBLIC FUNCTION DEFINITION */

Sort::Sort() 
{}

Sort::~Sort()
{}

void Sort::selection(int* A, int n)
{
	int i, j, min, temp;

	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
		{
			if (A[j] < A[min])
			{
				min = j;
			}
		}
		temp = A[i];
		A[i] = A[min];
		A[min] = temp;
	}
}

void Sort::insertion(int* A, int n)
{
	int i, j, key;
	for (i = 1; i < n; i++)
	{
		key = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > key)
		{
			A[j + 1] = A[j];
			j = j - 1;
		}
		A[j + 1] = key;
	}
}

void Sort::mergesort(int* A, int n)
{
	merge_sort_aux(A, 0, n - 1);
}

void Sort::heapsort(int* A, int n)
{
	build_max_heap_aux(A, n);
	int i, temp, heap_size;
	heap_size = n - 1;
	for (i = n - 1; i >= 1; --i)
	{
		temp = A[i];
		A[i] = A[0];
		A[0] = temp;
		heap_size = heap_size - 1;
		max_heapify_aux(A, 0, heap_size);
	}
}

void Sort::quicksort(int* A, int n)
{
	quick_sort_aux(A, 0, n-1);
}

void Sort::radixsort(int* A, int n)
{
	// Base decimal, range = 19, -9 a 9
	const int base = 10, range = base * 2 - 1;
    auto output = new int[n];

	// Radix Sort
    for (int pos = 1; ; pos *= base)
	{
		// Counting Sort
        int count[range]{};
        bool done = true;

		// Builds histogram
        for (int i = 0; i < n; i++) 
		{
            int d = A[i] / pos;
            ++count[d % base + range / 2];
            done &= (d == 0);
        }
        if (done)
            break;
		// Builds cumulative histogram
        for (int i = 1; i < range; i++)
            count[i] += count[i - 1];
		// Magic step
        for (int i = n; i-- > 0; )
            output[--count[A[i] / pos % base + range / 2]] = A[i];
        for (int i = 0; i < n; i++)
            A[i] = output[i];
    }
    delete[] output;
}

/* PRIVATE FUNCTION DEFINITION */

/* Merge sort aux */

void Sort::merge_aux(int* A, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	int i, j, k;
	int* L = new int[n1 + 1];
	int* R = new int[n2 + 1];

	for (i = 0; i < n1; i++)
		L[i] = A[p + i];
	for (j = 0; j < n2; j++)
		R[j] = A[q + j + 1];

	L[n1] = 2147483647; // ~inf, INT_MAX
	R[n2] = 2147483647; // ~inf, INT_MAX
	i = 0;
	j = 0;

	for (k = p; k <= r; k++) 
	{
		if (L[i] <= R[j]) 
		{
			A[k] = L[i];
			i++;
		}
		else 
		{
			A[k] = R[j];
			j++;
		}
	}

	// Frees memory
	delete[] L;
	delete[] R;
}

void Sort::merge_sort_aux(int* A, int const p, int const r)
{
	if (p < r) 
	{
		int q = (p + r) / 2;
		merge_sort_aux(A, p, q);
		merge_sort_aux(A, q + 1, r);
		merge_aux(A, p, q, r);
	}
}
#endif

/* Heap sort aux */

void Sort::max_heapify_aux(int* A, int i, int n)
{
	int l, r, largest, temp;
	l = 2 * i + 1;
	r = (2 * i + 2);

	if ((l <= n) && A[l] > A[i])
	{
		largest = l;
	}
	else 
	{
		largest = i;
	}
	if ((r <= n) && (A[r] > A[largest]))
	{
		largest = r;
	}
	if (largest != i)
	{
		temp = A[i];
		A[i] = A[largest];
		A[largest] = temp;
		max_heapify_aux(A, largest, n);
	}
}

void Sort::build_max_heap_aux(int* A, int n)
{
	for (int k = n / 2 - 1; k >= 0; k--)
	{
		max_heapify_aux(A, k, n);
	}
}

/* Quick sort aux */

void Sort::quick_sort_aux(int* A,int low,int high)
{
    int i = low;
    int j = high;
    int pivot = A[(i + j) / 2];
    int temp;

    while (i <= j)
    {
        while (A[i] < pivot)
            i++;
        while (A[j] > pivot)
            j--;
        if (i <= j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i++;
            j--;
        }
    }
    if (j > low)
        quick_sort_aux(A, low, j);
    if (i < high)
        quick_sort_aux(A, i, high);
}
