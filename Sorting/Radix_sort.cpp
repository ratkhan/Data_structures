
/*
Simple implementation of Radix sort made for exercise purposes. 
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
#define DECIMAL 10
int get_number(int* array, int size);
void CountingSort(int* array, int size, int exp);

void RadixSort(int* array, int size) {
	int max_number = 0;
	max_number = get_number(array, size);

	for (int exp = 1; max_number / exp > 0; exp *= 10) 
	{
		CountingSort(array, size, exp);
	}

}

void CountingSort(int* array, int size, int exp) {
	
	int* count_array = new int[DECIMAL];

	for (int i = 0; i < DECIMAL; i++)
	{
		count_array[i] = 0;
	}


	int* sorted_array = new int[size];
	for (int i = 0; i < size; i++)
	{
		count_array[array[i] / exp % 10] += 1;
	}

	for (int i = 1; i < DECIMAL; i++)
	{
		count_array[i] += count_array[i - 1];
	}

	

	for (int i = size - 1; i >= 0; i--)
	{
		sorted_array[count_array[(array[i] / exp) % 10] - 1] = array[i];
		count_array[(array[i] / exp) % 10]--;
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
	
	int array[] = { 35, 40, 896, 1241, 2155, 1234, 52153, 2152152, 123211, 1235, 123216 };
	std::cout << "Original array: ";
	for (int i = 0; i < 11; i++)
	{
		std::cout << array[i] << ' ';
	}
	RadixSort(array, 11);
	std::cout << '\n' << "Sorted array: ";
	for (int i = 0; i < 11; i++)
	{
		std::cout << array[i] << ' ';
	}
	//std::cout<< minimumDays(5, 5, grid);

	system("pause");
 	return 0;
 }

