//%%writefile ClassAssignment2.cpp

//Histogram
//'Process followed :'
	//Made an array from the file
	//Maximum and Minimum found
	//Partition size or class width is determined
	//Histogram is printed
	//Memory is freed

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

//File is converted into an Array & no. of elements are found here
void writeintoArray(string filename, int*& fullarr, int& flen) {
	ifstream myFile;
	myFile.open(filename);
	if (!myFile.is_open()) {
		cout << "Could not read file!" << endl;
		//return -1;
	}
	int num;
	while (myFile >> num) {
		++flen;
	}
	myFile.close();

	myFile.open(filename);
	fullarr = new int[flen];
	delete[] fullarr;
	int i = 0;
	while (myFile >> num) {
		fullarr[i] = num;
		++i;
	}
	myFile.close();

}


//Maximum and Minimum is found here
void minMaxArr(int* farr, int len, int& max, int& min) {
	//Maximum element in the array and class width are found here
	max = -1000000;
	min = 1000000;
	for (int i = 0; i < len; ++i) {
		if (farr[i] > max) {
			max = farr[i];
		}
		if (farr[i] < min) {
			min = farr[i];
		}
	}
}


//Partition Size is determined herer
int partition(int max, int min, int bin) {
	float a = max - min;
	float partitionSize = ceil(a / bin);
	return partitionSize;
}


//No. of elements between a range are found and written on a 1D array
void printRange(int* fullarr, int flen, int*& smallArr, int& slen, int b, int start, int end, int partitionSize, int min, int bin) {
	for (int i = 0; i < flen; ++i) {
		if ((fullarr[i] >= start) && (fullarr[i] <= end)) {
			++slen;
		}
	}
	smallArr = new int[slen];

	int j = 0;
	for (int i = 0; i < flen; ++i) {
		if ((fullarr[i] >= start) && (fullarr[i] <= end)) {
			smallArr[j] = fullarr[i];
			++j;
		}
	}
}


//The elements in the 1D array is written in a 2D array
void allocateSpace(int** hist, int* numOfElem, int*& smallArr, int bin, int slen) {
	hist[bin] = new int[slen];
	numOfElem[bin] = slen;
	for (int j = 0; j < slen; ++j) {
		hist[bin][j] = smallArr[j];
	}
}





//Histogram is printed here
void printHistogram(int* fullarr, int flen, int*& smallArr, int** hist, int* numOfElem, int bin, int partitionSize, int min, int max) {
	cout << "Histogram with bin size " << bin << endl;
	int slen = 0;
	int start = min; int end = min + partitionSize;
	for (int i = 0; i < bin; ++i) {
		if (bin == 1) {
			end = max;
		}
		if (end < 10) {
			cout << start << " - " << end << "  :";
		}
		else {
			cout << start << " - " << end << " :";
		}

		printRange(fullarr, flen, smallArr, slen, i, start, end, partitionSize, min, bin);
		allocateSpace(hist, numOfElem, smallArr, i, slen);
        for (int j = 0; j < numOfElem[i]; ++j) {
					cout << hist[i][j] << " ";
        }


		cout << endl;
		delete[] hist[i];
		slen = 0;
		start = end + 1;
		end = start + partitionSize;

	}
}


//Memory is deleted or freed
void freeMemory(int* numOfElem, int* fullarr, int* smallArr, int bin) {
	delete[] numOfElem;
	delete[] fullarr;
	delete[] smallArr;
}

int main() {
	string filename = "input.txt";
	int bin = 3;
	int** hist = new int* [bin];
	int* numOfElem = new int[bin];
	//int* fullarr = nullptr; int flen = 0;
	int* smallArr = nullptr;
	int min = 0; int max = 0;

	int* fullarr = nullptr; int flen = 19;
	fullarr = new int[flen] {1, 2, 2, 3, 3, 4, 3, 4, 4, 5, 6, 7, 8, 7, 8, 3, 7, 1, 9};
	//writeintoArray(filename, fullarr, flen);
	minMaxArr(fullarr, flen, max, min);
	int partitionSize = partition(max, min, bin);
	printHistogram(fullarr, flen, smallArr, hist, numOfElem, bin, partitionSize, min, max);
	freeMemory(numOfElem, fullarr, smallArr, bin);

	return 0;
}
