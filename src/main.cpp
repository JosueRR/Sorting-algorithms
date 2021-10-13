// Author: Josue Retana Rodriguez
// Tests for several sort algorithms

#include <Windows.h> // Change if unix
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <string.h>
#include "Sort.h"
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

void test_sort(int arr[], int size)
{
	for (int i = 1; i < size; i++)
	{
		if (arr[i] < arr[i - 1])
			cout << "Test failed, " << arr[i-1] << " is less than " << arr[i] << endl;
			break;
	}
}

int main()
{
	// Change for preferred size
	int const size = 10000;
	int A[size];

	Sort call;

	// Print array before and after sort
	bool print_array_bool = 0;

	// Tests
	bool test_selection = 1;
	bool test_insertion = 1;
	bool test_mergesort = 1;
	bool test_heapsort = 1;
	bool test_quicksort = 1;
	bool test_radixsort = 1;

	if (test_selection)
	{
		cout << "----------------TEST SELECTION----------------" << endl;
		if (print_array_bool)
		{
			cout << "Original array: ";
			printArray(A, size);
		}
		auto start = chrono::steady_clock::now();
		call.selection(A, size);
		auto end = chrono::steady_clock::now();
		auto diff = end - start;
		if (print_array_bool)
		{
			cout << "Sorted array:";
			printArray(A, size);
		}
		cout << "Array size: " << size << " , took time: ";
		cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;
		test_sort(A, size);
		cout << "----------------------------------------------" << endl << endl;
	}

	if (test_insertion)
	{
		setArray(A, size);
		cout << "----------------TEST INSERTION----------------" << endl;
		if (print_array_bool)
		{
			cout << "Original array: ";
			printArray(A, size);
		}
		auto start = chrono::steady_clock::now();
		call.insertion(A, size);
		auto end = chrono::steady_clock::now();
		auto diff = end - start;
		if (print_array_bool)
		{
			cout << "Sorted array: ";
			printArray(A, size);
		}
		cout << "Array size: " << size << " , took time: ";
		cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;
		test_sort(A, size);
		cout << "----------------------------------------------" << endl << endl;
	}

	if (test_mergesort)
	{
		setArray(A, size);
		cout << "----------------TEST MERGESORT----------------" << endl;
		if (print_array_bool)
		{
			cout << "Original array: ";
			printArray(A, size);
		}
		auto start = chrono::steady_clock::now();
		call.mergesort(A, size);
		auto end = chrono::steady_clock::now();
		auto diff = end - start;
		if (print_array_bool)
		{
			cout << "Sorted array: ";
			printArray(A, size);
		}
		cout << "Array size: " << size << " , took time: ";
		cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;
		test_sort(A, size);
		cout << "----------------------------------------------" << endl << endl;
	}

	if (test_heapsort)
	{
		setArray(A, size);
		cout << "----------------TEST HEAPSORT----------------" << endl;
		if (print_array_bool)
		{
			cout << "Original array: ";
			printArray(A, size);
		}
		auto start = chrono::steady_clock::now();
		call.heapsort(A, size);
		auto end = chrono::steady_clock::now();
		auto diff = end - start;
		if (print_array_bool)
		{
			cout << "Sorted array: ";
			printArray(A, size);
		}
		cout << "Array size: " << size << " , took time: ";
		cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;
		test_sort(A, size);
		cout << "----------------------------------------------" << endl << endl;
	}

	if (test_quicksort)
	{
		setArray(A, size);
		cout << "----------------TEST QUICKSORT----------------" << endl;
		if (print_array_bool)
		{
			cout << "Original array: ";
			printArray(A, size);
		}
		auto start = chrono::steady_clock::now();
		call.quicksort(A, size);
		auto end = chrono::steady_clock::now();
		auto diff = end - start;
		if (print_array_bool)
		{
			cout << "Sorted array: ";
			printArray(A, size);
		}
		cout << "Array size: " << size << " , took time: ";
		cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;
		test_sort(A, size);
		cout << "----------------------------------------------" << endl << endl;
	}

	if (test_radixsort)
	{
		setArray(A, size);
		cout << "----------------TEST RADIXSORT----------------" << endl;
		if (print_array_bool)
		{
			cout << "Original array: ";
			printArray(A, size);
		}
		auto start = chrono::steady_clock::now();
		call.radixsort(A, size);
		auto end = chrono::steady_clock::now();
		auto diff = end - start;
		if (print_array_bool)
		{
			cout << "Sorted array: ";
			printArray(A, size);
		}
		cout << "Array size: " << size << " , took time: ";
		cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;
		test_sort(A, size);
		cout << "----------------------------------------------" << endl << endl;
	}

	printf("Press ENTER...");
	fgetc(stdin);
	return 0;
}