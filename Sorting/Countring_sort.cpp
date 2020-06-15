
/*
Simple implementation of counting sort made for exercise purposes. 
Takes array of integers and its size as an input
*/
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <chrono> 
#include <map>
#include <list>

#define MINIMAL_INTEGER INT_MIN
int get_number(int* array, int size);

void CountingSort(int* array, int size) {
	int max_number = 0;
	max_number = get_number(array, size);
	int* count_array = new int[max_number + 1];

	for (int i = 0; i <= max_number; i++)
	{
		count_array[i] = 0;
	}


	int* sorted_array = new int[size];
	for (int i = 0; i < size; i++)
	{
		count_array[array[i]] += 1;
	}
	

	for (int i = 0, j = 0; i <= max_number; i++)
	{
		if (count_array[i] != 0)
		{
			while (count_array[i] != 0)
			{
				sorted_array[j++] = i;
				count_array[i]--;
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		array[i] = sorted_array[i];
	}
}

int get_number(int* array, int size) {
	int max_number = MINIMAL_INTEGER;
	for (int i = 0; i < size; i++)
	{
		if (array[i] > max_number)
		{
			max_number = array[i];
		}
	}
	return max_number;
}


int main(int argc, char* argv)
{
	int array[] = { 35, 40, 896, 1, 5, 4, 3, 2, 1, 5, 6 };
	
	std::cout << "Original array: ";
	for (int i = 0; i < 8; i++)
	{
		std::cout << array[i] << ' ';
	}
	
	CountingSort(array, 8);
	std::cout << '\n' << "Sorted array: ";
	for (int i = 0; i < 8; i++)
	{
		std::cout << array[i] << ' ';
	}

	system("pause");
 	return 0;
 }