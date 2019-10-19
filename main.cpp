#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <exception>
using namespace std;

int main(){

	
return 0;
}

//#1
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

//#2
void readfile(string file_name) {
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

//#3
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

//#7
int numberOfSentences(string text) {
	vector<string> line_data{};
	istringstream input{ text };
	while (input.good() == true) {
		string temp;
		getline(input, temp, '.');
		line_data.push_back(temp);
	}
	return line_data.size();
}

//#8
int longestSentence(string text) {
	int result = 0;

	return result;
}
