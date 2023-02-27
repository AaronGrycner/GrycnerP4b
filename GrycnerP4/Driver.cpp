// Aaron Grycner, agrycner@cnm.edu, GrycnerP4

#include "Header.h"

int main() {

	int *data = nullptr;
	string filename;
	ofstream out;

	WriteHeader();

	cout << "\nEnter a filename for results output: ";
	getline(cin, filename);
	out.open(filename);

	// try to allocate memory for the array
	try {
		data = new int[SIZE];
	}
	catch (bad_alloc) {
		cerr << "\nMemory Allocation Error!\n";
		return -1;
	}
	
	// read data from file
	if (!ReadFile(INFILE, data)) {
		cerr << "\nFile Read Error!\n";
		return -1;
	}
	else {
		cout << "\nFile read successfully!\n\n";
	}

	// run the sorts and time them, cout the results
	try {
		if (out) {
			out << GetFormattedTimeString(data); // write data to file
			cout << "\nFile written successfully!\n";
			out.close();
		}
		else {
			cerr << "\nFile Write Error!\n";
		}
	}
	catch (bad_alloc) {
		cerr << "\nMemory Allocation Error!\n";
		return -1;
	}

	// cleanup
	out.close();
	delete[] data;

	return 0;
}
