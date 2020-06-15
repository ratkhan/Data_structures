#pragma once
//Implementation of Binary search on sorted array

#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H
int binarySearch(int* array, int beginning, int end, int data);

int search(int* array, int size, int data) {
	return binarySearch(array, 0, size, data);
}

int binarySearch(int* array, int beginning, int end, int data)
{
	if (beginning == end) return -1;
	if (data > array[(end + beginning) / 2]) {
		binarySearch(array, ((end + beginning) / 2 + 1), end, data);
	}
	else if (data < array[(end + beginning) / 2]) {
		binarySearch(array, beginning, ((end + beginning) / 2), data);
	}
	else return data;
		
}

#endif