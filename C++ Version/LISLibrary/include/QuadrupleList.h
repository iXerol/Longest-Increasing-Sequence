//
//  quadruple list.h
//  LIS
//
//  Created by Xerol Wong on 4/28/18.
//  Copyright © 2018 Xerol Wong. All rights reserved.
//

#ifndef quadruple_list_h
#define quadruple_list_h

#include "HorizontalList.h"
#include <vector>
#include <iostream>

class QuadrupleList {
private:
	std::vector<HorizontalList> lists;
	int maxLength = 0;
	
	void longestIncreasingSequence(std::vector<int>& v, node* n);
	
	void pop_top();
	
	void push_back(int* sequence, int i);
public:
	QuadrupleList(int* sequence, int num);
	
	void printLongestIncreasingSequence();

	void update(int* sequence, int i);
};

void QuadrupleList::push_back(int *sequence, int i) {
	int data = sequence[i];
	node* n;
	if (lists.size() == 0 || data > lists.back().tail->data) {
		++maxLength;
		lists.emplace_back(maxLength);
		n = lists.back().emplace_back(i, data);
	} else {
		// binary search
		size_t start = 0;
		size_t end = lists.size();	// range is [start, end)
		while (end - start > 1) {
			size_t middle = start + (end - start) / 2;
			if (data < lists[middle].tail->data) {
				end = middle;
			} else {
				start = middle;
			}
		}
		n = lists[start].emplace_back(i, data);
	}
	if (n->risingLength > 1) {
		n->upNeighbor = lists[n->risingLength - 2].tail;
	}
	if (n->risingLength < maxLength) {
		n->downNeighbor = lists[n->risingLength].tail;
	}
}

QuadrupleList::QuadrupleList(int *sequence, int num) {
	for (int i = 0; i < num; ++i) {
		push_back(sequence, i);
	}
}

void QuadrupleList::longestIncreasingSequence(std::vector<int> &v, node *n) {
	v.push_back(n->data);
	if (n->risingLength == 1) {
		for (auto i = v.size(); i > 0; --i) {
			std::cout << v[i - 1] << ' ';
		}
		std::cout << std::endl;
	} else {
		longestIncreasingSequence(v, n->upNeighbor);
	}
	v.pop_back();
	if (n->leftNeighbor != nullptr && (v.empty() || n->leftNeighbor->data < v.back())) {
		longestIncreasingSequence(v, n->leftNeighbor);
	}
}

void QuadrupleList::printLongestIncreasingSequence() {
	std::vector<int> v;
	if (maxLength != 0) {
		longestIncreasingSequence(v, lists.back().tail);
	}
}

void QuadrupleList::pop_top() {
	//divide
	std::vector<HorizontalList> left, right;
	left.emplace_back(1);
	left[0].head = left[0].tail = lists[0].head;
	right.emplace_back(1);
	right[0].head = left[0].tail->rightNeighbor;
	if (right[0].head != nullptr) {
		right[0].tail = lists[0].tail;
	}
	for (int i = 1; i < maxLength; ++i) {
		left.emplace_back(i);
		right.emplace_back(i);
		if (right[i - 1].empty() || right[i - 1].head->downNeighbor == lists[i].tail) {
			left[i].head = lists[i].head;
			left[i].tail = lists[i].tail;
		} else if (left[i - 1].empty() || right[i - 1].head->downNeighbor == nullptr) {
			right[i].head = lists[i].head;
			right[i].tail = lists[i].tail;
		} else {
			left[i].head = lists[i].head;
			left[i].tail = right[i - 1].head->downNeighbor;
			right[i].head = right[i - 1].head->downNeighbor->rightNeighbor;
			right[i].tail = lists[i].tail;
		}
	}
	//horizontal update
	delete left[0].head;
	for (int i = 0; i < maxLength - 1; ++i) {
		if (left[i + 1].empty()) {
			right[i].head->leftNeighbor = nullptr;
		} else if (right[i].empty()) {
			left[i + 1].tail->rightNeighbor = nullptr;
		} else {
			left[i + 1].tail->rightNeighbor = right[i].head;
			right[i].head->leftNeighbor = left[i + 1].tail;
		}
		if (!left[i + 1].empty()){
			lists[i].head = left[i + 1].head;
		} else {
			lists[i].head = right[i].head;
		}
		if (right[i].empty()) {
			lists[i].tail = left[i + 1].tail;
		}
	}
	right[maxLength - 1].head->leftNeighbor = nullptr;
	lists[maxLength - 1].head = right[maxLength - 1].head;
	lists[maxLength - 1].tail = right[maxLength - 1].tail;
	if (lists[maxLength - 1].empty()) {
		lists.pop_back();
	}
	//vertical update
	//change LEFT's up neighbors
	for (int i = 1; i < maxLength && !left[i].empty(); ++i) {
		node* n1 = left[i].tail;
		node* n2 = left[i - 1].tail;
		while(n1 != nullptr && n1->leftNeighbor != nullptr && n1->leftNeighbor->upNeighbor == n2){
			n1 = n1->leftNeighbor;
		}
		while (n1 != nullptr && n1->leftNeighbor != left[i].tail) {
			while(n2->rightNeighbor != nullptr && n2->rightNeighbor->index < n1->index) {
				n2 = n2->rightNeighbor;
			}
			n1->upNeighbor = n2;
			n1 = n1->rightNeighbor;
		}
	}
	for (node* n = left[1].head; n != nullptr && n->leftNeighbor != left[1].tail; n = n->rightNeighbor) {
		n->upNeighbor = nullptr;
	}
	//change RIGHT's down neighbors
	for (int i = 0; i < maxLength - 2 && !right[i].empty() && !left[i + 1].empty(); ++i) {
		node* n1 = right[i].head;
		node* n2 = left[i + 2].tail;
		while(n1 != nullptr && n1->rightNeighbor != nullptr && n1->rightNeighbor->downNeighbor == left[i + 1].tail){
			n1 = n1->rightNeighbor;
		}
		while (n1 != nullptr && n1->rightNeighbor != right[i].head) {
			while(n2 != nullptr && n2->index > n1->index) {
				n2 = n2->leftNeighbor;
			}
			n1->downNeighbor = n2;
			n1 = n1->leftNeighbor;
		}
	}
	for (node* n = right[maxLength - 2].head; n != nullptr && n->downNeighbor == left[maxLength - 1].tail; n = n->rightNeighbor) {
		n->downNeighbor = nullptr;
	}
}

void QuadrupleList::update(int *sequence, int i) {
	pop_top();
	push_back(sequence, i);
}


#endif /* quadruple_list_h */
