//
//  quadruple list.h
//  LIS
//
//  Created by Xerol Wong on 4/28/18.
//  Copyright © 2018 Xerol Wong. All rights reserved.
//

#pragma once

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
