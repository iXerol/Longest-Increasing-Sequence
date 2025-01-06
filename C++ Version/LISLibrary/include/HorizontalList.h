//
//  horizontal list.h
//  LIS
//
//  Created by Xerol Wong on 4/28/18.
//  Copyright © 2018 Xerol Wong. All rights reserved.
//

#ifndef horizontal_list_h
#define horizontal_list_h

#include "node.h"

class HorizontalList {
public:
	int risingLength;
	node* head = nullptr;
	node* tail = nullptr;
	
	HorizontalList(int length) {
		risingLength = length;
	}
	
	node* push_back(node* item);
	
	node* emplace_back(int index, int data);

	bool empty();
};

node * HorizontalList::push_back(node *item) {
	if (!empty()) {
		tail->rightNeighbor = item;
		item->leftNeighbor = tail;
		tail = item;
	} else {
		head = tail = item;
	}
	return tail;
}

node * HorizontalList::emplace_back(int index, int data) {
	node* item = new node(index, data, risingLength);
	push_back(item);
	return tail;
}

bool HorizontalList::empty() {
	if (tail == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

#endif /* horizontal_list_h */
