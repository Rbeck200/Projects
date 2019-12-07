#pragma once

#include <vector>
#include "ListNode.hpp"

using namespace std;

template<typename DATA_TYPE>
class LinkedList {
public:

	ListNode* _front = nullptr;

	int deleteNode(ListNode* front, int value) {
		int counter = 0;

		if (front != nullptr && front->value == value) {
			ListNode* new_front = front->next;
			delete front;
			front = new_front;
			return counter;
		}

		ListNode* current = front;
		ListNode* before = nullptr;
		while (current != nullptr && current->value != value) {
			before = current;
			current = current->next;
			counter++;
		}

		if (current != nullptr) {
			before->next = current->next;
			delete current;
			return counter;
		}
		else {
			return -1;
		}
	}

	vector<int> toArray(ListNode *front) {
		vector<int> result{};
		while (front != nullptr) {
			result.push_back(front->value);
			ListNode* new_front = front->next;
			front = new_front;
			delete new_front;
		}
		return result;
	}



	

};