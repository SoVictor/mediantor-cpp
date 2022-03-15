#pragma once

#include <vector>
#include <list>

#include "i_mediantor.h"

namespace sovictor {
namespace mediantor {

class MediantorSqrtDecomp : public IMediantor {
 public:
  explicit MediantorSqrtDecomp(int max_size);

  ~MediantorSqrtDecomp() override = default;

  // O(sqrt(N)).
  void Insert(int x) override;

  // O(sqrt(N)).
  int Take() override;

  // O(1).
  const size_t size() override { return size_; }

 private:
  int size_;
  int list_size_;
  std::vector<std::list<int>> elements_;
};  // class MediantorSqrtDecomp

}  // namespace mediantor
}  // namespace sovictor
