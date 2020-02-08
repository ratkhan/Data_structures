//merge sort implementation with use of vectors instead of arrays
#include <iostream>
#include <vector>

void merge(std::vector<int>& nums, int first_begin, int first_end, int second_begin, int second_end)
{
	std::vector<int> first_array(first_end - first_begin + 1, 0);
	std::vector<int> second_array(second_end - second_begin + 1, 0);
	for (int i = 0; i < first_array.size(); i++) 
	{
		first_array[i] = nums[first_begin + i];
	}

	for (int i = 0; i < second_array.size(); i++)
	{
		second_array[i] = nums[second_begin + i];
	}

	int i = 0;
	int j = 0;
	int k = 0;
	while (i < first_array.size() && j < second_array.size())
	{
		if (first_array[i] <= second_array[j])
		{
			nums[first_begin + k] = first_array[i];
			i++;
		}
		else
		{
			nums[first_begin + k] = second_array[j];
			j++;
		}
		k++;
	}

	while (i < first_array.size())
	{
		nums[first_begin + k] = first_array[i];
		i++;
		k++;
	}
	while (j < second_array.size())
	{
		nums[first_begin + k] = second_array[j];
		j++;
		k++;
	}
	
}

void mergeSort(std::vector<int>& nums, int begin,int end) {
	if (nums.size() == 1) return;
	if (begin < end)
	{
		int middle = (begin + end - 1) / 2;
		mergeSort(nums, begin, middle);
		mergeSort(nums, (middle + 1), end);
		merge(nums,begin,middle,(middle+1),end);
	}
}


void main(int argc, char* argv) {
	std::vector<int> test_vector {1, 0, 0, 8, 6, 2, 3, 4, 5, 7};
	mergeSort(test_vector, 0, (test_vector.size() - 1));
	for (auto& it : test_vector) {
		std::cout << it << ' ';
	}
}