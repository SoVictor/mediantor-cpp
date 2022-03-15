#include "mediantor/mediantor_sqrt_decomp.h"

MediantorSqrtDecomp::MediantorSqrtDecomp(int max_size)
	: size_(0), list_size_(std::max(1, static_cast<int>(sqrt(max_size)))) {}

void MediantorSqrtDecomp::insert(int x) {
	if (size_ == 0)
	{
		elements_.push_back(std::list<int>());
		elements_[0].push_back(x);
	}
	else
	{
		int idx = static_cast<int>(elements_.size()) - 1;
		while (idx > 0 && elements_[idx].front() > x) {
			idx--;
		}
		bool inserted = false;
		for (auto it = elements_[idx].begin(); it != elements_[idx].end(); ++it) {
			if (*it > x)
			{
				elements_[idx].insert(it, x);
				inserted = true;
				break;
			}
		}
		if (!inserted) {
			elements_[idx].push_back(x);
		}

		for (int i = idx + 1; i < elements_.size(); i++) {
			int y = elements_[i - 1].back();
			elements_[i - 1].pop_back();
			elements_[i].push_front(y);
		}
		if (elements_[elements_.size() - 1].size() > list_size_) {
			int y = elements_[elements_.size() - 1].back();
			elements_[elements_.size() - 1].pop_back();
			elements_.push_back(std::list<int>());
			elements_[elements_.size() - 1].push_back(y);
		}
	}
	size_++;
}

int MediantorSqrtDecomp::take() {
	int ans = 0;
	int k = (size_ - 1) / 2;

	int idx = 0;
	while (k >= list_size_) {
		idx++;
		k -= list_size_;
	}

	for (auto it = elements_[idx].begin(); it != elements_[idx].end(); ++it) {
		if (k == 0) {
			ans = *it;
			elements_[idx].erase(it);
			break;
		}
		k--;
	}

	for (int i = idx + 1; i < elements_.size(); i++) {
		int y = elements_[i].front();
		elements_[i].pop_front();
		elements_[i - 1].push_back(y);
	}
	if (elements_[elements_.size() - 1].empty()) {
		elements_.resize(elements_.size() - 1);
	}

	size_--;
	return ans;
}
