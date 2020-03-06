#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <functional>
#include <iomanip>
#include <sstream>
#include <unordered_map>
using namespace std;

class BinaryNode {
public:
	int value;
	BinaryNode* left = nullptr;
	BinaryNode* right = nullptr;
	BinaryNode(int v = 0)
	{
		value = v;
	}
};

class LinkedList {
public:
	int value;
	LinkedList* next = nullptr;
	LinkedList(int v)
	{
		value = v;
	}
};

LinkedList* reverseLinkedList(LinkedList* root)
{
	//add all nodes to a stack
	stack<LinkedList*>nodes;

	//track the current node we are going to work with
	LinkedList* currentNode = root;

	//loop through until list is empty pushing to stack
	while (currentNode != nullptr) {
		nodes.push(currentNode);
		
		//increment current node
		currentNode = currentNode->next;
	}

	//get the top node from the stack
	LinkedList* topNode = nullptr;

	//setup top node
	if (!nodes.empty()) {
		topNode = nodes.top();
		nodes.pop();
	}
	

	//all the nodes are now on the stack, pop them off and rewire them
	int i = 0; //index tracking loop num
	while (!nodes.empty()) {
		currentNode = nodes.top();
		nodes.pop();

		//wire the currentNode to be the next to the top node
		topNode->next = currentNode;

		if (i == 0) { //assign the new top node as the root, only on the first iteration
			root = topNode;
		}
		
		//decend down the list
		topNode = currentNode;

		i++; //increment index
	}

	//currentNode is the last item in the list, set it's next to nullptr
	currentNode->next = nullptr;

	return root;
}

/*
2. Write a recursive function that determines the height of the BST
*/
int getHeight(BinaryNode* root, int num = 0)
{
	int myHeight;

	if (root == nullptr) {
		myHeight = 0;
		return myHeight;
	}
	else {
		myHeight = 1;
	}

	//get our childrens height
	int leftHeight = 0;
	int rightHeight = 0;

	if (root->left != nullptr) {
		leftHeight = getHeight(root->left, num++);
	}

	if (root->right != nullptr) {
		//kludgey
		if (root->left != nullptr)num--;
		rightHeight = getHeight(root->right, num++);
	}

	//our height is our largest childrens height, plus myHeight
	if (leftHeight >= rightHeight) {
		myHeight += leftHeight;
	}else {
		myHeight += rightHeight;
	}

	//I coded the tree to give 1 more than height, so this fixes the first item called by decreasing height by one
	if (num == 0) myHeight--;

	return myHeight;
}

bool isBalanced(string input){
	bool returnVal = true;
	stack<char> parens;
	//loop char by char
	for (int i = 0; i < input.size(); i++) {
		char c = input[i];
		//if c is an opening type of parenthesis, add it to the stack.
		if (c == '(' || c == '[' || c == '{') {
			parens.push(c);
		}
		//if c is a closing type of parenthesis we pop a character from the stack, and make sure it is the cooresponding parenthesis.
		char first;
		if (c == ')') {
			//we are unbalanced if there are no chars to pop
			if (parens.empty()) {
				returnVal = false;
				break;
			}
			first = parens.top();
			parens.pop();
			//check if they match
			if (first != '(') {
				returnVal = false;
				break;
			}
		}else if (c == ']') {
			//we are unbalanced if there are no chars to pop
			if (parens.empty()) {
				returnVal = false;
				break;
			}
			first = parens.top();
			parens.pop();

			//check if they match
			if (first != '[') {
				returnVal = false;
				break;
			}
		}else if (c == '}') {
			//we are unbalanced if there are no chars to pop
			if (parens.empty()) {
				returnVal = false;
				break;
			}
			first = parens.top();
			parens.pop();

			//check if they match
			if (first != '{') {
				returnVal = false;
				break;
			}
		}
	}

	return returnVal;
}

//helper function to build vector
void bstToVector_helper(BinaryNode* node, vector<int>* result) {

	//an in order traversal
	if (node->left != nullptr) bstToVector_helper(node->left, result);		//add all items in the left tree
	result->push_back(node->value); //our our value
	if (node->right != nullptr) bstToVector_helper(node->right, result);	//add all items in the right tree
}


vector<int> bstToVector(BinaryNode* node)
{
		vector<int> result{};
	
		//do an in order traversal

		if (node->left != nullptr) bstToVector_helper(node->left, &result);		//add all items in the left tree
		result.push_back(node->value); //our our value
		if (node->right != nullptr) bstToVector_helper(node->right, &result);	//add all items in the right tree

		return result;
}


bool has_unique_chars(string text)
{
	bool returnVal = true; //default to true, change to false when we find first false item.

	//instantiate our map
	unordered_map<char, int> characters;
	//characters.emplace('x', 1);

	//loop through string, adding characters that don't exist, if one already exists, break and return false
	for (int i = 0; i < text.size(); i++) {
		char c = text[i];
		auto it = characters.find(c);
		int num = characters[c];
		if (num != 0) {
			returnVal = false;
			break;
		}else {
			
			//this char doesn't exist in map, lets add it for next time
			//characters.emplace(c, 1);
			//characters.insert(c, 1);
			characters[c] = 1;
		}
	}

	return returnVal;
}

string most_common_word(string text)
{
	unordered_map<string, int> words;
	istringstream wordBank{ text };
	int numCommon = 0;
	string commonWord = "";

	while (wordBank.eof() == false) {
		string temp;
		wordBank >> temp;
		int numThisWord = words[temp];
		numThisWord++;
		words[temp] = numThisWord;
		if (numThisWord > numCommon) {
			numCommon = numThisWord;
			commonWord = temp;
		}
	}
	return commonWord;
}
