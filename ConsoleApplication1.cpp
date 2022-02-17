#include<iostream>

using namespace std;

int* initialize(int arraySize) {
	int* array = new int[arraySize]; 
	for (int i = 0; i < arraySize; i++) {
		cin >> array[i];
	}
	return array;
}

void arrPushBack(int*& array, int& arrSize, int t)
{
	int m = arrSize + 1;
	int* anew = (int*)realloc(array, m * sizeof(int));
	if (anew != NULL)
	{
		anew[arrSize] = t;
		arrSize++;
		array = anew;
	}
}

void addElementAtIndex(int*& array, int index, int data, int& arrSize) {
	arrSize ++;
	int* anew = (int*)realloc(array, arrSize * sizeof(int));
	if (anew != NULL)
	{
		anew[index] = data;
		for (int i = index+1; i < arrSize; i++) anew[i] = array[i-1];
		array = anew;
	}
}

void arrPopBack(int*& array, int& arrSize) {
	int m = arrSize - 1;
	int* anew = (int*)realloc(array, m * sizeof(int));
	if (anew != NULL)
	{
		arrSize--;
		array = anew;
	}
}

void removeElementAtIndex(int*& array, int index, int& arrSize) {
	arrSize--;
	int* anew = (int*)realloc(array, arrSize * sizeof(int));
	if (anew != NULL)
	{
		for (int i = index ; i < arrSize; i++) anew[i] = array[i + 1];
		array = anew;
	}
}

int* shrinkArray(int* array, int arrSize) {
	int* anew = (int*)realloc(array, arrSize * sizeof(int));
	return anew;
}

int searchMaxElement(int* array, int arrSize) {
	int iMax = -20120065;
	for (int i = 0; i < arrSize; i++) {
		if (array[i] > iMax) iMax = array[i];
	}
	return iMax;
}

int searchElement(int* array, int key, int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		if (array[i] == key) return i;
	}
	return -1;
}

int* merge2Arrays(int* a, int* b, int na, int nb, int& doubleSize) {
	doubleSize = na + nb;
	int* anew = (int*)realloc(a, doubleSize * sizeof(int));
	if (anew != NULL)
	{
		for (int i = 0; i < nb; i++) anew[na + i ] = b[i];
		return anew;
	}
}

void printArray(int* array, int size) {
	for (int i = 0; i < size; i++) cout << array[i] << " ";
	cout << endl;
}

int main() {

	//De code khong rac roi so voi yeu cau de bai, hau het cac du lieu deu duoc gan cung
	//Viec sua doi kha don gion va khong phai chuc nang quan trong, mong giang vien chap nhan

	int arraySize; cin >> arraySize;
	int* arr = initialize(arraySize);

	arrPushBack(arr, arraySize, 12);
	printArray(arr, arraySize);
	cout << endl;

	addElementAtIndex(arr, 3, 26, arraySize);
	printArray(arr, arraySize);
	cout << endl;

	arrPopBack(arr, arraySize);
	printArray(arr, arraySize);
	cout << endl;

	removeElementAtIndex(arr, 3, arraySize);
	printArray(arr, arraySize);
	cout << endl;

	arr = shrinkArray(arr, arraySize);
	printArray(arr, arraySize);
	cout << endl;

	int iMax = searchMaxElement(arr, arraySize);
	cout << iMax << "\n\n";

	cout << searchElement(arr, 4, arraySize) << "\n\n";
	
	int doubleSize = 0;
	int* doubleArray = merge2Arrays(arr, arr, arraySize, arraySize, doubleSize);
	printArray(doubleArray, doubleSize);
	cout << endl;
}