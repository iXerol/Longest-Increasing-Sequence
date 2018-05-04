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

class horizontalList {
public:
	int risingLength;
	node* head = NULL;
	node* tail = NULL;
	
	horizontalList(int length) {
		risingLength = length;
	}
	
	node* push_back(node* item);
	
	node* emplace_back(int index, int data);

	bool empty();
};

node *horizontalList::push_back(node *item) {
	if (!empty()) {
		tail->rightNeighbor = item;
		item->leftNeighbor = tail;
		tail = item;
	} else {
		head = tail = item;
	}
	return tail;
}

node *horizontalList::emplace_back(int index, int data) {
	node* item = new node(index, data, risingLength);
	push_back(item);
	return tail;
}

bool horizontalList::empty() {
	if (tail == NULL) {
		return true;
	}
	else {
		return false;
	}
}

#endif /* horizontal_list_h */
