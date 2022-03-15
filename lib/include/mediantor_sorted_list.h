#pragma once

#include <list>

#include "i_mediantor.h"

class MediantorSortedList : public IMediantor {
public:
	MediantorSortedList() = default;

	~MediantorSortedList() override = default;

	void insert(int x) override;

	int take() override;

	const size_t size() override {
		return elements_.size();
	}

private:
	std::list<int> elements_;
};
