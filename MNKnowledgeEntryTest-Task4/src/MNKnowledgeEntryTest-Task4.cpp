//============================================================================
// Name        : MNKnowledgeEntryTest-Task4.cpp
// Author      : Petar Petrov
// Version     :
// Copyright   : Your copyright notice
// Description : MN Knowledge Entry Test Task 4
//============================================================================

#include <iostream>
#include <map>
#include <set>

using namespace std;

typedef struct num {
	int occurence_index;
	int occurence_count;
} num;

int main() {
	int tests_count = 0;
	cin >> tests_count;

	for (int i = 0; i < tests_count; i++) {

		int numbers_count = 0;
		cin >> numbers_count;
		std::map<int, int> numbers;
		std::set<int> duplicates;
		int k = 0;
		//insert all elements and their indices of occurrence into a map
		//if an element already exists in the map, insert it's index of occurrence into a set
		//later we'll use the set's property that it's always sorted
		do {
			int tmp = 0;
			cin >> tmp;
			auto search = numbers.find(tmp);
			if (search != numbers.end()) {
				duplicates.insert(search->second);
			} else {
				//insert the number and index of occurrence,
				//increment as our read is zero-based, but the output expects answer with base 1
				numbers.insert(pair<int, int>(tmp, k + 1));
			}
			k++;
		} while (k < numbers_count);

		set<int>::iterator it = duplicates.begin();

		// if the set is not empty print it's first element that contains the index of the element's occurrence
		// as the set is always sorted that guarantees that the smallest index will be printed
		if(it == duplicates.end()) {
			cout << 0 << endl;
		} else {
			cout << *it << endl;
		}
	}

	return 0;
}
