#include "Header.h"

void WriteHeader() {

	cout << "Aaron Grycner, GrycnerP4\nTimed Sorts!\n\n";

}

bool ReadFile(string filename, int arr[]) {

	ifstream in{ filename };

	size_t t = sizeof arr;

	if (in) {
		for (int i{}; i < SIZE; ++i) {
			in >> arr[i];
		}
	}
	else {
		return false;
	}

	in.close();
}

// Runs sort, checks that the sort was correct, couts a message with results and returns the time
double TimedSort(void sortFunc(int a[], int size), int a[]) {
	double time;
	int* copy = nullptr;

	// allocate memory for a copy of the array for sorting
	try {
		copy = new int[SIZE];
	}
	catch (bad_alloc) {
		throw bad_alloc();
	}

	ArrayCopy(a, SIZE, copy);

	// run the sort and time it
	auto begin = high_resolution_clock::now();
	sortFunc(copy, SIZE);
	auto end = high_resolution_clock::now();

	// set time to the difference between the start and end times
	time = duration_cast<nanoseconds>(end - begin).count() / 1'000'000'000.0;
	cout << setprecision(7) << fixed;

	// check that arrays were sorted correctly, catch possible bad_alloc and throw to calling function
	if (CheckSort(copy))
		cout << "Sorted successfully in " << time << " seconds\n\n";
	else
		cout << "Bad sort: final array not in order\n\n";

	delete[] copy;
	return time;
}

string GetFormattedTimeString(int arr[]) {
	stringstream st;

	st << setprecision(7) << fixed;

	try {
		st << "NAME: Aaron Grycner\n\nSize of Data: " << SIZE << " integers\n\n";

		st << "Name of sort function: 		Elapsed time in secs.msec\n";

		cout << "Starting BubbleSort...\n";
		st << "Bubble Sort:		 	    	" << TimedSort(Sort::BubbleSort, arr) << endl;

		cout << "Starting Comb11Sort...\n";
		st << "Comb Sort:			 	" << TimedSort(Sort::Comb11Sort, arr) << endl;

		cout << "Starting Goofy Sort...\n";
		st << "Goofy Sort: 			 	" << TimedSort(Sort::GoofySort, arr) << endl;

		cout << "Starting In-Place Sort...\n";
		st << "In-Place Merge Sort:			" << TimedSort(Sort::InPlaceMerge, arr) << endl;

		cout << "Starting Insertion Sort...\n";
		st << "Insertion Sort: 		   	" << TimedSort(Sort::InsertionSort, arr) << endl;

		cout << "Starting Quick Sort...\n";
		st << "Quick Sort: 			  	" << TimedSort(Sort::QuickSort, arr) << endl;

		cout << "Starting Selection Sort...\n";
		st << "Selection Sort: 			" << TimedSort(Sort::SelectionSort, arr) << endl;

		cout << "Starting Shaker Sort...\n";
		st << "Shaker Sort: 			 	" << TimedSort(Sort::ShakerSort, arr) << endl;

		cout << "Starting Shell Sort...\n";
		st << "Shell Sort: 	    			" << TimedSort(Sort::Shell, arr);
	}
	catch (bad_alloc) {
		throw bad_alloc();
	}

	return st.str();
}

// function for creating copies of arrays
void ArrayCopy(int src[], int size, int dest[]) {
	for (int i{}; i < size; ++i) {
		dest[i] = src[i];
	}
}

// uses algorithm library to check that the sorts were done correctly
bool CheckSort(int arr[]) {
	int* copy = nullptr;

	try {
		copy = new int[SIZE];
	}
	catch (bad_alloc) {
		throw bad_alloc();
	}
	
	// create sorted copy of array for comparison
	ArrayCopy(arr, SIZE, copy);
	sort(copy, copy + SIZE);

	// check that the copy sorted by the algorithm library matches the one sorted by the sort class
	for (int i{}; i < SIZE; ++i) {
		if (copy[i] != arr[i]) {
			delete[] copy;
			return false;
		}
	}

	delete[] copy;
	return true;
}