#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include "Ordenador.h"
#include <string.h>
#include <Windows.h>
using namespace std;
using namespace std::chrono;

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void setArray(int arr[], int size)
{
	// Initialize random seed
	int randNumber;
	srand(time(NULL));
	
	for (int i = 0;  i < size;  i++)
	{
		/* generate random number between -1000 and 1000: */
		randNumber = rand() % 2000 + (-1000);
		arr[i] = randNumber;
	}
}

void test(int arr[], int size)
{
	for (int i = 1; i < size; i++)
	{
		if (arr[i] < arr[i - 1])
			cout << " Fallo, " << arr[i-1] << " ES menor que " << arr[i] << endl;
	}
}

int main()
{
	int const size = 150000;
	int A[size];
	//int A[size] = { 0, 3, -8, 8, 1, -7 };

	Ordenador llamado;

	// Print array before and after sort
	bool print_array_bool = 0;

	// Test
	bool prueba_seleccion = 1;
	bool prueba_insercion = 1;
	bool prueba_mergesort = 1;
	bool prueba_heapsort = 1;
	bool prueba_quicksort = 1;
	bool prueba_radixsort = 1;


	if (prueba_seleccion)
	{
		cout << "----------------PRUEBA SELECCION----------------" << endl;
		if (print_array_bool)
		{
			cout << "Arreglo Original: ";
			printArray(A, size);
		}
		auto start = chrono::steady_clock::now();
		llamado.seleccion(A, size);
		auto end = chrono::steady_clock::now();
		auto diff = end - start;
		if (print_array_bool)
		{
			cout << "Resultado algoritmo seleccion: ";
			printArray(A, size);
		}
		cout << "Arreglo tamanio: " << size << " , tomo tiempo: ";
		cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;
		test(A, size);
		cout << "----------------------------------------------" << endl << endl;
	}

	if (prueba_insercion)
	{
		setArray(A, size);
		cout << "----------------PRUEBA INSERCION----------------" << endl;
		if (print_array_bool)
		{
			cout << "Arreglo Original: ";
			printArray(A, size);
		}
		auto start = chrono::steady_clock::now();
		llamado.insercion(A, size);
		auto end = chrono::steady_clock::now();
		auto diff = end - start;
		if (print_array_bool)
		{
			cout << "Resultado algoritmo insercion: ";
			printArray(A, size);
		}
		cout << "Arreglo tamanio: " << size << " , tomo tiempo: ";
		cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;
		test(A, size);
		cout << "----------------------------------------------" << endl << endl;
	}

	if (prueba_mergesort)
	{
		setArray(A, size);
		cout << "----------------PRUEBA MERGESORT----------------" << endl;
		if (print_array_bool)
		{
			cout << "Arreglo Original: ";
			printArray(A, size);
		}
		auto start = chrono::steady_clock::now();
		llamado.mergesort(A, size);
		auto end = chrono::steady_clock::now();
		auto diff = end - start;
		if (print_array_bool)
		{
			cout << "Resultado algoritmo mergesort: ";
			printArray(A, size);
		}
		cout << "Arreglo tamanio: " << size << " , tomo tiempo: ";
		cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;
		test(A, size);
		cout << "----------------------------------------------" << endl << endl;
	}

	if (prueba_heapsort)
	{
		setArray(A, size);
		cout << "----------------PRUEBA HEAPSORT----------------" << endl;
		if (print_array_bool)
		{
			cout << "Arreglo Original: ";
			printArray(A, size);
		}
		auto start = chrono::steady_clock::now();
		llamado.heapsort(A, size);
		auto end = chrono::steady_clock::now();
		auto diff = end - start;
		if (print_array_bool)
		{
			cout << "Resultado algoritmo mergesort: ";
			printArray(A, size);
		}
		cout << "Arreglo tamanio: " << size << " , tomo tiempo: ";
		cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;
		test(A, size);
		cout << "----------------------------------------------" << endl << endl;
	}

	if (prueba_quicksort)
	{
		setArray(A, size);
		cout << "----------------PRUEBA QUICKSORT----------------" << endl;
		if (print_array_bool)
		{
			cout << "Arreglo Original: ";
			printArray(A, size);
		}
		auto start = chrono::steady_clock::now();
		llamado.quicksort(A, size);
		auto end = chrono::steady_clock::now();
		auto diff = end - start;
		if (print_array_bool)
		{
			cout << "Resultado algoritmo mergesort: ";
			printArray(A, size);
		}
		cout << "Arreglo tamanio: " << size << " , tomo tiempo: ";
		cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;
		test(A, size);
		cout << "----------------------------------------------" << endl << endl;
	}

	if (prueba_radixsort)
	{
		setArray(A, size);
		cout << "----------------PRUEBA RADIXSORT----------------" << endl;
		if (print_array_bool)
		{
			cout << "Arreglo Original: ";
			printArray(A, size);
		}
		auto start = chrono::steady_clock::now();
		llamado.radixsort(A, size);
		auto end = chrono::steady_clock::now();
		auto diff = end - start;
		if (print_array_bool)
		{
			cout << "Resultado algoritmo radixsort: ";
			printArray(A, size);
		}
		cout << "Arreglo tamanio: " << size << " , tomo tiempo: ";
		cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;
		test(A, size);
		cout << "----------------------------------------------" << endl << endl;
	}

	printf("Press ENTER...");
	fgetc(stdin);
	return 0;
}