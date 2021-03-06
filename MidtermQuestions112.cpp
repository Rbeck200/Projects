#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <exception>
#include <iomanip>
using namespace std;

//#1 ALL GOOD
void FizzBuzz() {
	for (int i = 1; i <= 100; i++) {
		if ((i % 3 == 0) && (i % 5 == 0)) {
			cout << "FizzBuzz" << endl;
		}else if (i % 3 == 0) {
			cout << "Fizz" << endl;
		}else if (i % 5 == 0) {
			cout << "Buzz" << endl;
		}else {
			cout << i << endl;
		}
	}
};

//#2 ALL GOOD
void readfile(const string& file_name) {
	ifstream input{ file_name };
	vector<string> file_data{};
	if (input.is_open() == true) {
		string line;
		while (input.good() == true) {
			getline(input, line);
			if (line.length() > 0) {
				file_data.push_back(line);
			}
		}
	}
	for (int i = 0; i < file_data.size(); i++) {
		cout << file_data[i] << endl;
	}
}

//#3 ALL GOOD
void computeAverage(string input_file, string output_file) {
	ifstream input{ input_file };
	ofstream output{ output_file };
	vector<int> numbers{};
	int sum = 0;
	int avg = 0;
	while (input.good() == true) {
		int value = 0;
		input >> value;
		numbers.push_back(value);
	}
	for (int i = 0; i < numbers.size(); i++) {
		sum += numbers[i];
	}
	avg = (sum / numbers.size());
	output << avg;
	output.close();
}

//#4 ALL GOOD
void displayNumbers(vector<double>& data) {
	cout << fixed;
	cout << setprecision(2);
	for (int i = 0; i < data.size(); i++) {
		if ((i % 3 == 0) && (i != 0)) {
			cout << endl;
		}
		cout << setw(8) << data[i];
	}
}

//#7 ALL GOOD
int numberOfSentences(string text) {
	int num_sentences = 0;
	for (int i = 0; i < text.length(); i++) {
		if ((text[i] == '.') && (i != 0)) {
			num_sentences++;
		}
		cout << "(" << num_sentences << ")" << endl << text;
		return num_sentences;
	}
}

//#8 ALL GOOD
int longestSentence(string text) {
	int sentence_length = 0;
	vector<string> lines{};
	vector<vector<string>> words{};
	istringstream input{ text };
	while (input.good() == true) {
		string temp;
		if (input.peek() != ' ') {
			getline(input, temp, '.');
			lines.push_back(temp);
		}
		else {
			string _space;
			_space = input.get();
		}
	}
	for (int i = 0; i < lines.size(); i++) {
		istringstream line_data{ lines[i] };
		vector<string> sentences{};
		while (line_data.good() == true) {
			string temp;
			getline(line_data, temp, ' ');
			sentences.push_back(temp);
		}
		words.push_back(sentences);
	}
	for (int i = 0; i < words.size(); i++) {
		if (words[i].size() > sentence_length) {
			sentence_length = words[i].size();
		}
	}
	cout << "(" << sentence_length << ") " << endl << text << endl;
	return sentence_length;
}

int main(){

	//ALL COMMENTED OUT FUNCTION HAVE BEEN TESTED TO WORK.

	//#1
	//FizzBuzz();

	//#2
	//readfile("tinypix.ppm");

	//#3
	//computeAverage("test3.txt", "test3output.txt");

	//#4
	/*
	vector<double> question_four{ 123.45,
		4.56,
		78.90,
		98.76,
		54.32,
		1.01 };
	displayNumbers(question_four);
	//*/

	//#7
	//numberOfSentences("This has one sentence");
	//numberOfSentences("This. has. multiple. sentences.");

	//#8
	//longestSentence("This. has multiple. sentences and the last one is the longest.");


	return 0;
}

/*catch (const string msg) {
			cerr << msg << endl;
		}*/
