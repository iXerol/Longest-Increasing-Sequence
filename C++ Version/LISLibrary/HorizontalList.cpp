#include "HorizontalList.h"

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
