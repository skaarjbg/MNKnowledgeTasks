//============================================================================
// Name        : MNKnowledgeEntryTask5.cpp
// Author      : Petar Petrov
// Version     :
// Copyright   : Your copyright notice
// Description : MNKnowledge Entry Test Task 5
//============================================================================

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <map>
#include <set>

using namespace std;

int main() {
//	int employees = 0;
	int employee_boss_pairs = 0;
	int cake_pieces = 0;
	string mnk_input;
	getline(cin, mnk_input);

	stringstream ss(mnk_input);

	vector<string> tokens;
	string buffer;

	while (ss >> buffer) {
		tokens.push_back(buffer);
	}

//	employees = atoi(tokens.at(0).c_str());
	employee_boss_pairs = atoi(tokens.at(1).c_str());
	cake_pieces = atoi(tokens.at(2).c_str());
	int total_cake_pieces = cake_pieces;

	cin.clear();
	multimap<int, int> boss_employee_relations;
	set<int> got_cake;

	//here we store boss-employee relations in a multimap
	int k = 0;
	do {
		string line;
		getline(cin, line);
		vector<string> tk;
		stringstream sts(line);
		while (sts >> line) {
			tk.push_back(line);
		}

		int boss_id = atoi(tk.at(0).c_str());
		int employee_id = atoi(tk.at(1).c_str());
		boss_employee_relations.insert(pair<int, int>(boss_id, employee_id));
		k++;

	} while (k < employee_boss_pairs);

	//iterate over the relations, and give the bosses a piece of cake first
	//this is done by putting their indices in a set
	multimap<int, int>::iterator it = boss_employee_relations.begin();
	do {

		if (it->first > 0 && got_cake.insert(it->first).second) {
			cake_pieces--;
		}

		if (it-> second > 0 && got_cake.insert(it->second).second) {
			cake_pieces--;
		}

		it++;
	} while(it != boss_employee_relations.end());

	set<int>::iterator itt = got_cake.begin();
	for (int i = 0; i < total_cake_pieces; i++) {
		if (itt == got_cake.end()) {
			cout << -1 << endl;
		} else {
			cout << *itt << endl;
			itt++;
		}
	}
	return 0;
}
