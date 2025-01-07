//
//  horizontal list.h
//  LIS
//
//  Created by Xerol Wong on 4/28/18.
//  Copyright © 2018 Xerol Wong. All rights reserved.
//

#pragma once

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
