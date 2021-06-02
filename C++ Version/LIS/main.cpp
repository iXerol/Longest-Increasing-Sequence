//
//  main.cpp
//  LIS
//
//  Created by Xerol Wong on 4/28/18.
//  Copyright © 2018 Xerol Wong. All rights reserved.
//

#include <iostream>
#include "QuadrupleList.h"
using namespace std;

int main(int argc, const char * argv[]) {
	int t[10] = {3, 9, 6, 2, 8, 5, 7, 10};
	QuadrupleList q(t, 7);
	q.printLongestIncreasingSequence();
	q.update(t, 7);
	cout << endl;
	q.printLongestIncreasingSequence();
}
