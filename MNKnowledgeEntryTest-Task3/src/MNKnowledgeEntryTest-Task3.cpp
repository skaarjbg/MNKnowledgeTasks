//============================================================================
// Name        : MNKnowledgeEntryTest-Task3.cpp
// Author      : Petar Petrov
// Version     : 0.1
// Description : MNKnowledge Entry Test Task 3
//============================================================================

#include <iostream>
using namespace std;

int main() {

	int numbers_count = 0;
	cin >> numbers_count;
	int *numbers;
	numbers = new int[numbers_count];
	int j = 0;

	//fill an array of numbers from the input
	do {
		cin >> numbers[j++];
	} while (j < numbers_count);

	//iterate over the array to find the point where the rotation has started
	//in sorted arrays that would be the first element, that is smaller than the previous one
	int last = 0;
	int step = 0;
	for (int k = 0; k < numbers_count; k++) {

		//the current element is larger than the previous, we've reached the end of the rotation
		//no need to iterate further
		if (numbers[k] < last) {
			cout << step;
			break;
		}
		last = numbers[k];
		step++;
	}
	return 0;
}
