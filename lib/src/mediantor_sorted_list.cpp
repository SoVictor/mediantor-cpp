#include "mediantor_sorted_list.h"

void MediantorSortedList::insert(int x) {
	for (auto it = elements_.begin(); it != elements_.end(); ++it) {
		if (*it > x) {
			elements_.insert(it, x);
			return;
		}
	}

	elements_.push_back(x);
}

int MediantorSortedList::take() {
	auto it = elements_.begin();
	std::advance(it, (elements_.size() - 1) / 2);
	const int ans = *it;
	elements_.erase(it);

	return ans;
}
