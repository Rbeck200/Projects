#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <exception>
using namespace std;

//#1 ALL GOOD
void FizzBuzz() {
	for (int i = 1; i <= 100; i++) {
		if ((i % 3 == 0) && (i % 5 == 0)) {
			cout << "FizzBuzz" << endl;
		}
		else if (i % 3 == 0) {
			cout << "Fizz" << endl;
		}
		else if (i % 5 == 0) {
			cout << "Buzz" << endl;
		}
		else {
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
	vector<string> line_data;
	vector<int> numbers{};
	int sum = 0;
	int avg = 0;
	if (input.is_open() == true) {
		string line;
		while (input.good() == true) {
			getline(input, line);
			if (line.length() > 0) {
				line_data.push_back(line);
			}
		}
	}
	for (int i = 0; i < line_data.size(); i++) {
		istringstream data{ line_data[i] };
		while (data.eof() == false) {
			int num = 0;
			data >> num;
			numbers.push_back(num);
		}
	}
	for (int i = 0; i < numbers.size(); i++) {
		sum += numbers[i];
	}
	avg = (sum / numbers.size());
	ofstream output{ output_file };
	output << avg;
	output.close();
}

//#4
void displayNumbers(vector<double>& data) {

}

//#7
int numberOfSentences(string text) {
	vector<string> line_data{};
	istringstream input{ text };
	while (input.good() == true) {
		string temp;
		if (input.peek() != ' ') {
			getline(input, temp, '.');
			if (temp.length() > 0) {
				line_data.push_back(temp);
			}
		}
		else {
			string _space;
			_space = input.get();
		}
	}
	cout << "(" << line_data.size() << ") sentence";
	if (line_data.size() > 1) {
		cout << "s";
	}
	cout << " " << endl << text << endl;
	return line_data.size();
}

//#8
int longestSentence(string text) {
	int position = 0;
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
		if (words[i].size() > position) {
			position = words[i].size();
		}
	}
	cout << "(" << position << ") " << endl << text << endl;
	return position;
}

int main(){

	//ALL COMMENTED OUT FUNCTIONS HAVE BEEN TESTED TO WORK.
	//readfile("tinypix.ppm");
	//computeAverage("test3.txt", "test3output.txt");
	//numberOfSentences("This has one sentence");
	//numberOfSentences("This. has. multiple. sentences.");

	return 0;
}

