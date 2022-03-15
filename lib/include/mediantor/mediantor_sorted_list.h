#pragma once

#include <list>

#include "i_mediantor.h"

class MediantorSortedList : public IMediantor {
 public:
  MediantorSortedList() = default;

  ~MediantorSortedList() override = default;

  // O(N).
  void Insert(int x) override;

  // O(N).
  int Take() override;

  // O(1).
  const size_t size() override { return elements_.size(); }

 private:
  std::list<int> elements_;
};  // class MediantorSortedList
