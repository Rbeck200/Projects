#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <sstream>
#include "BianaryNode.h";
#include "LinkedList.h";

using namespace std;

// O(N) where N is the size of your LinkedList
LinkedList* reverseLinkedList(LinkedList* root) {
	LinkedList* prev = nullptr;
	LinkedList* current = root;
	LinkedList* next;
	while (current != nullptr) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return prev;
}

// O(N + M) based on the size of both LinkedLists
LinkedList* mergedSortedLinkedLists(LinkedList* first, LinkedList* second) {
	LinkedList* result = nullptr;
	if (first == nullptr) {
		return(second);
	}
	else if (second == nullptr) {
		return(first);
	}
	if (first->value <= second->value){
		result = first;
		result->next = mergedSortedLinkedLists(first->next, second);
	}
	else{
		result = second;
		result->next = mergedSortedLinkedLists(first, second->next);
	}
	return(result);
}

// O(LogN) because we, roughly, cut out search pool in half 
// by choosing which child to search
bool exists_iter(BinaryNode* root, int value) {
	while (root->left != nullptr || root->right != nullptr) {
		if (value == root->value) {
			return true;
		}
		else {
			if (value >= root->value) {
				root = root->right;
			}
			else {
				root = root->left;
			}
		}
	}
	return false;
}

// O(LogN) because we, roughly, cut out search pool in half 
// by choosing which child to search
bool exists_rec(BinaryNode* root, int value) {
	if (value == root->value) {
		return true;
	}
	else {
		if (value >= root->value) {
			if (exists_rec(root->right, value)) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			if (exists_iter(root->left, value)) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}

vector<int> bstToVector_helper(BinaryNode* root, vector<int>* result) {
	if (root->left != nullptr) bstToVector_helper(root->left, result);
	result->push_back(root->value);
	if (root->right != nullptr) bstToVector_helper(root->right, result);
}

// O(N) where N is the number of Nodes in the Binary Treebecause we have to visit every node.
vector<int> bstToVector(BinaryNode* root) {
	vector<int> result{};
	if (root->left != nullptr) bstToVector_helper(root->left, &result);
	result.push_back(root->value);
	if (root->right != nullptr) bstToVector_helper(root->right, &result);
	return result;
}

// O(N) where N is the number of Nodes in the Binary Treebecause we have to visit every node.
int getHeight(BinaryNode* root) {
	if (root == nullptr) {
		return 0;
	}
	int left = getHeight(root->left);
	int right = getHeight(root->right);
	if (left < right) {
		return (right + 1);
	}
	else {
		return (left + 1);
	}
}

// O(N) calling the getHeight function twice.
bool isAVL(BinaryNode* root) {
	if (root == nullptr) {
		return false;
	}
	int left = getHeight(root->left);
	int right = getHeight(root->right);
	int result = left - right;
	if (result >= -1 && result <= 1) {
		return true;
	}
	else {
		return false;
	}
}

// O(N + M) where N is text.size() and M is number of kvp's in pairs unordered_map
bool isBalanced(string text) {
	bool result = true;
	unordered_map<char, char> pairs{
		{'(',')'},
		{'[',']'},
		{'{','}'},
		{'<','>'}
	};
	unordered_map<char, int> singles;
	for (int i = 0; i < text.size(); i++) {
		singles[text[i]] += 1;
	}
	for (auto pair : pairs) {
		if (singles[pair.first] != singles[pair.second]) {
			result = false;
			break;
		}
	}
	return result;
}

// O(N + M) where N is text.size() and M is the number of kvp's in Chars
bool has_unique_chars(string text) {
	bool result = true;
	unordered_map<char, int> Chars;
	for (int i = 0; i < text.size(); i++) {
		Chars[text[i]] += 1;
	}
	for (auto pair : Chars) {
		if (pair.second > 1) {
			result = false;
			break;
		}
	}
	return result;
}

// O(N) where N is the number of words in wordBank
string most_common_word(string text) {
	unordered_map<string, int> words;
	istringstream wordBank{ text };
	int commonNum = 0;
	string commonWord = "";
	while (wordBank.eof() == false) {
		string temp;
		wordBank >> temp;
		int thisWord = words[temp];
		thisWord++;
		words[temp] = thisWord;
		if (thisWord > commonNum) {
			commonNum = thisWord;
			commonWord = temp;
		}
	}
	return commonWord;
}
