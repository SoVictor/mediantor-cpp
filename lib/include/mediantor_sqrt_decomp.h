#pragma once

#include <vector>
#include <list>

#include "i_mediantor.h"

class MediantorSqrtDecomp : public IMediantor {
public:
	explicit MediantorSqrtDecomp(int max_n);

	~MediantorSqrtDecomp() override = default;

	void insert(int x) override;

	int take() override;

	const size_t size() override {
		return size_;
	}

private:
	int size_;
	int list_size_;
	std::vector<std::list<int>> elements_;
};
