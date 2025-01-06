#include "node.h"

node *node::un(int t) {
	if (t < 0 || t >= risingLength) {
		return nullptr;
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
