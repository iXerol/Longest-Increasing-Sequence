//
//  node.h
//  LIS
//
//  Created by Xerol Wong on 4/28/18.
//  Copyright © 2018 Xerol Wong. All rights reserved.
//

#pragma once

struct node {
public:
	int data;
	int index;
	int risingLength;
	node* leftNeighbor = nullptr;
	node* rightNeighbor = nullptr;
	node* upNeighbor = nullptr;
	node* downNeighbor = nullptr;
	
	node(int i, int d, int r) {
		index = i;
		data = d;
		risingLength = r;
	}
	
	bool operator<(node& item);
	
	bool operator>(node& item);
	
	node* un(int t);
};
