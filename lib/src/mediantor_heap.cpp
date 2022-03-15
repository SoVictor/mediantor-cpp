#include "mediantor_heap.h"

void MediantorHeap::insert(int x) {
	if (lower_half_.empty()) {
		lower_half_.push(x);
		return;
	}

	if (x < lower_half_.top())
	{
		lower_half_.push(x);
	}
	else
	{
		upper_half_.push(x);
	}

	balance();
}

int MediantorHeap::take() {
	const int ans = lower_half_.top();
	lower_half_.pop();

	balance();

	return ans;
}

void MediantorHeap::balance() {
	if (lower_half_.size() < upper_half_.size())
	{
		lower_half_.push(upper_half_.top());
		upper_half_.pop();
	}
	else if (lower_half_.size() > upper_half_.size() + 1)
	{
		upper_half_.push(lower_half_.top());
		lower_half_.pop();
	}
}
