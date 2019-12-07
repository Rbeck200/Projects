#include<iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <exception>

using namespace std;

string flipText(string text) {
	string result;
	vector<char> letters{};
	for (int i = 0; i < text.length(); i++) {
		letters.push_back(text[i]);
	}
	for (int j = letters.size() - 1; j >= 0; j--) {
		result += letters[j];
	}
	return result;
}

vector<int> difference(vector<int> first, vector<int> second) {
	vector<int> result{};
	for (int i = 0; i < first.size(); i++) {
		bool not_in_second = true;
		for (int j = 0; j < second.size(); j++) {
			if (first[i] == second[j]) {
				not_in_second = false;
			}
		}
		if (not_in_second == true) {
			result.push_back(first[i]);
		}
	}
	return result;
}

char toUpper(char ch) {
	if (ch < 123 && ch > 96) {
		ch = ch - 32;
	}
	return ch;
}

int findMode(string input_file) {
	int result = 0;
	ifstream input{ input_file };
	vector<int> raw_data{};
	while (input.good() == true) {
		int value = 0;
		input >> value;
		raw_data.push_back(value);
	}
	vector<vector<int>> numbers{};
	for (int i = 0; i < raw_data.size(); i++) {
		bool added = false;
		if (i == 0) {
			vector<int> temp{ raw_data[i] };
			numbers.push_back(temp);
			continue;
		}
		for (int j = 0; j < numbers.size(); j++) {
			if (raw_data[i] == numbers[j][0]) {
				numbers[j].push_back(raw_data[i]);
				bool added = true;
				break;
			}
		}
		if (added == false) {
			vector<int> temp{ raw_data[i] };
			numbers.push_back(temp);
		}
	}
	int length = 0;
	for (int k = 0; k < numbers.size(); k++) {
		if (numbers[k].size() > length) {
			result = numbers[k][0];
			length = numbers[k].size();
		}
	}
	return result;
}

void findLongSentences(string input_file, int sentence_length) {
	ifstream input{ input_file };
	vector<string> sentences{};
	vector<vector<string>> words{};
	while (input.good() == true) {
		string sentence_data;
		if (input.peek() != ' ') {
			getline(input, sentence_data);
			
			if (sentence_data.length() > 0) {
				sentences.push_back(sentence_data);
			}
		}
		else {
			string space;
			space = input.get();
		}
	}
	for (int i = 0; i < sentences.size(); i++) {
		vector<string> sentence_temp{};
		istringstream word_data{ sentences[i] };
		while (word_data.eof() == false) {
			string temp;
			getline(word_data, temp, ' ');
			sentence_temp.push_back(temp);
		}
		words.push_back(sentence_temp);
	}
	for (int i = 0; i < words.size(); i++) {
		if (words[i].size() >= sentence_length) {
			for (int j = 0; j < words[i].size(); j++) {
				cout << words[i][j] << ' ';
			}
			cout << endl;
		}
	}
	
};

int main() {

	vector<int> one{ 3,2,9 };
	vector<int> two{ 5,3 };
	vector<int> one_minus_two{};

	char a = 'a';
	char m = 'm';
	char z = 'z';

	cout << flipText("CS112") << endl;

	one_minus_two = difference(one, two);

	for (int i = 0; i < one_minus_two.size(); i++) {
		cout << one_minus_two[i] << ' ';
	}
	cout << endl;

	cout << toUpper(a) << endl
		<< toUpper(m) << endl
		<< toUpper(z) << endl;

	cout << findMode("numbers.txt");

	findLongSentences("sentences.txt",5);

	return 0;
}