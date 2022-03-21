#pragma once

#include <vector>
#include <list>

#include "i_mediantor.h"

namespace sovictor {
namespace mediantor {

class MediantorSqrtDecomp : public IMediantor {
 public:
  explicit MediantorSqrtDecomp(size_t max_size);

  ~MediantorSqrtDecomp() override = default;

  // O(sqrt(N)).
  void Insert(int x) override;

  // O(sqrt(N)).
  int Take() override;

  // O(1).
  const size_t size() override { return size_; }

 private:
  size_t size_;
  size_t bucket_size_;
  std::vector<std::list<int>> buckets_;
};  // class MediantorSqrtDecomp

}  // namespace mediantor
}  // namespace sovictor
