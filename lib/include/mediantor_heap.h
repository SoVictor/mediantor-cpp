#pragma once

#include <vector>
#include <queue>

#include "i_mediantor.h"

class MediantorHeap : public IMediantor {
public:
	MediantorHeap() = default;

	~MediantorHeap() override = default;

	void insert(int x) override;

	int take() override;

	const size_t size() override {
		return lower_half_.size() + upper_half_.size();
	}

private:
	void balance();

	std::priority_queue<int> lower_half_;
	std::priority_queue<int, std::vector<int>, std::greater<int>> upper_half_;
};
