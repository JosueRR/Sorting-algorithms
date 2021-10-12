// Autor: Josue Retana Rodriguez - C06440
// Implementa algoritmos de ordenamiento

#ifndef Ordenador_h
#define Ordenador_h
#include <iostream>
using namespace std;

class Ordenador
{
private:

	/* Merge sort */
	void merge(int* A, int const p, int const q, int const r);
	void merge_sort(int* A, int const p, int const r);

	/* Heap sort */
	void max_heapify(int* a, int i, int n);
	void build_max_heap(int* a, int n);

	/* Quick sort */
	int partition(int* A, int low, int high);
	void quickSort(int* A, int low, int high);

public:

	Ordenador();
	~Ordenador();
	void seleccion(int *A, int n);
	void insercion(int *A, int n);
	void mergesort(int *A, int n);
	void heapsort(int *A, int n);
	void quicksort(int *A, int n);
	void radixsort(int *A, int n);
};

/* PUBLIC FUNCTION DEFINITION */

Ordenador::Ordenador() 
{}

Ordenador::~Ordenador()
{}

void Ordenador::seleccion(int* A, int n)
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

void Ordenador::insercion(int* A, int n)
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

void Ordenador::mergesort(int* A, int n)
{
	merge_sort(A, 0, n - 1);
}

void Ordenador::heapsort(int* A, int n)
{
	build_max_heap(A, n);
	int i, temp, heap_size;
	heap_size = n - 1;
	for (i = n - 1; i >= 1; --i)
	{
		temp = A[i];
		A[i] = A[0];
		A[0] = temp;
		heap_size = heap_size - 1;
		max_heapify(A, 0, heap_size);
	}
}

void Ordenador::quicksort(int* A, int n)
{
	quickSort(A, 0, n);
}

void Ordenador::radixsort(int* A, int n)
{
	// Base decimal, k = 19, -9 a 9
	const int base = 10, rango = base * 2 - 1;
    auto salida = new int[n];

	// Ordenamiento por residuos
    for (int pos = 1; ; pos *= base) 
	{
		// Ordenamiento por conteo
        int contador[rango]{};
        bool done = true;

		// Construye histograma
        for (int i = 0; i < n; i++) 
		{
            int d = A[i] / pos;
            ++contador[d % base + rango / 2];
            done &= (d == 0);
        }
        if (done)
            break;
		// Construye histograma acumulativo
        for (int i = 1; i < rango; i++)
            contador[i] += contador[i - 1];
		// Paso m�gico
        for (int i = n; i-- > 0; )
            salida[--contador[A[i] / pos % base + rango / 2]] = A[i];
        for (int i = 0; i < n; i++)
            A[i] = salida[i];
    }
    delete[] salida;
}

/* PRIVATE FUNCTION DEFINITION */


/* Merge sort */

void Ordenador::merge(int* A, int p, int q, int r)
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

void Ordenador::merge_sort(int* A, int const p, int const r)
{
	if (p < r) 
	{
		int q = (p + r) / 2;
		merge_sort(A, p, q);
		merge_sort(A, q + 1, r);
		merge(A, p, q, r);
	}
}
#endif

/* Heap sort*/

void Ordenador::max_heapify(int* A, int i, int n)
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
		max_heapify(A, largest, n);
	}
}

void Ordenador::build_max_heap(int* A, int n)
{
	for (int k = n / 2 - 1; k >= 0; k--)
	{
		max_heapify(A, k, n);
	}
}

/* Quick sort*/

int  Ordenador::partition(int* A, int low, int high) 
{
	int temp;
  	int pivot = A[high];
  	int i = (low - 1);

	for (int j = low; j < high; j++) 
	{
		if (A[j] <= pivot) 
		{
			i++;
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	temp = A[i + 1];
	A[i + 1] = A[high];
	A[high] = temp;
	return (i + 1);
}

void Ordenador::quickSort(int* A,int low,int high)
{
	if (high > low) 
	{
		int pi = partition(A, low, high);
		quickSort(A, low, pi - 1);
		quickSort(A, pi + 1, high);
  	}
}