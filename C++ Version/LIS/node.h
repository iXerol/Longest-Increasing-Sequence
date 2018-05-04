//
//  node.h
//  LIS
//
//  Created by Xerol Wong on 4/28/18.
//  Copyright © 2018 Xerol Wong. All rights reserved.
//

#ifndef node_h
#define node_h

struct node {
public:
	int data;
	int index;
	int risingLength;
	node* leftNeighbor = NULL;
	node* rightNeighbor = NULL;
	node* upNeighbor = NULL;
	node* downNeighbor = NULL;
	
	node(int i, int d, int r) {
		index = i;
		data = d;
		risingLength = r;
	}
	
	bool operator<(node& item);
	
	bool operator>(node& item);
	
	node* un(int t);
};

node *node::un(int t) {
	if (t < 0 || t >= risingLength) {
		return NULL;
	} else if (t == 0) {
		return this;
	} else {
		return upNeighbor->un(t - 1);
	}
}

bool node::operator>(node &item) {
	return data > item.data;
}

bool node::operator<(node &item) {
	return data < item.data;
}

#endif /* node_h */
