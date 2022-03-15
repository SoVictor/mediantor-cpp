#pragma once

class IMediantor {
public:
	virtual ~IMediantor() = default;

	virtual void insert(int x) = 0;
	virtual int take() = 0;

	virtual const size_t size() = 0;
};
