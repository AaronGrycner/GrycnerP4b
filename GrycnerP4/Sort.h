#ifndef SORTER_H
#define SORTER_H

class Sort
{
public:
	Sort() = default;

	// Sort H is the red herring!!
	static void BubbleSort(int a[], int size); // Sort A
	static void InsertionSort(int a[], int size); // Sort B
	static void SelectionSort(int a[], int size); // Sort G
	static void Comb11Sort(int a[], int size); // Sort I
	static void ShakerSort(int a[], int size); // Sort C
	static void Shell(int a[], int size); // Sort D

	static void RecursiveInPlaceMerge(int a[], int lo, int hi); 
	static void InPlaceMerge(int a[], int size); // Sort F

	static void RecursiveQuickSort(int a[], int lo, int hi); 
	static void QuickSort(int a[], int size); // Sort E

	static void GoofySort(int a[], int size); // Sort J
};

#endif