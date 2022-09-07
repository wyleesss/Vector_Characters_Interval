#include <iostream>
#include <vector>
using namespace std;

bool isin(char character, vector<char> vector) {
	for (auto& i : vector)
		if (i == character) return true;
	return false;
}

int main(){
	vector<char>characters{ 'X', 'W', 'O', 'T', 'Z', 'Y', 'Q', 'V', 'U', 'T', 'Z', 'Y', 'X', 'W', 'O', 'T', 'Z', 'Y', 'Q',
		'V', 'U', 'T', 'S', 'X', 'W', 'V', 'N', 'Z', 'Y', 'X', 'P', 'U', 'T', 'Z', 'R', 'W', 'V', 'U', 'M', 'Y', 'X', 'W',
		'O', 'T', 'Z', 'Y', 'Q', 'V', 'U', 'T', 'S', 'X', 'W', 'V', 'N', 'Z', 'Y', 'X', 'P', 'U', 'T', 'Z', 'R', 'W', 'V',
		'U', 'M', 'Y', 'X', 'W', 'O', 'T', 'Z', 'Y', 'Q', 'V', 'U', 'T', 'S', 'X', 'W', 'V', 'N', 'Z', 'Y', 'X', 'P', 'U',
		'T', 'Z' };
	vector<char>used;
	for (auto& i : characters) {
		if (!isin(i, used)) {
			vector<int>coordinates;
			used.push_back(i);
			for (int j = 0; j < characters.size(); j++)
				if (characters[j] == i) coordinates.push_back(j);
			cout << "character info(" << i << ")'\n";
			for (int j = 0; j < coordinates.size(); j++)
				cout << i << "(" << j << ")" << ":[" << coordinates[j] << "]" << (j != coordinates.size() - 1 ? " - " : "\n");
			cout << "intervals'\n";
			for (auto j = coordinates.begin(); j != coordinates.end(); j++) {
				if (j == coordinates.begin()) continue;
				cout << "+" << *j - *(j - 1) << "; ";
			}
			cout << "\n\n";
		}
	}
}