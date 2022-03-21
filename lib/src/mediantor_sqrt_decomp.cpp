#include "mediantor/mediantor_sqrt_decomp.h"

#include <cmath>

namespace {

size_t size_t_sqrt(size_t x) {
  return static_cast<size_t>(sqrt(static_cast<double>(x)));
}

}  // namespace

namespace sovictor::mediantor {

MediantorSqrtDecomp::MediantorSqrtDecomp(size_t max_size)
    : size_(0), bucket_size_(std::max(size_t(1), size_t_sqrt(max_size))) {}

void MediantorSqrtDecomp::Insert(int x) {
  if (size_ == 0) {
    buckets_.push_back(std::list<int>());
    buckets_.front().push_back(x);
    ++size_;
    return;
  }

  size_t bucket_idx = buckets_.size() - 1;
  while (bucket_idx > 0 && buckets_[bucket_idx].front() > x) {
    --bucket_idx;
  }
  std::list<int>& bucket = buckets_[bucket_idx];

  bool inserted = false;
  for (auto it = bucket.begin(); it != bucket.end(); ++it) {
    if (*it > x) {
      bucket.insert(it, x);
      inserted = true;
      break;
    }
  }
  if (!inserted) {
    bucket.push_back(x);
  }

  for (size_t i = bucket_idx; i + 1 < buckets_.size(); ++i) {
    const int x = buckets_[i].back();
    buckets_[i].pop_back();
    buckets_[i + 1].push_front(x);
  }
  if (buckets_.back().size() > bucket_size_) {
    const int x = buckets_.back().back();
    buckets_.back().pop_back();
    buckets_.push_back(std::list<int>());
    buckets_.back().push_back(x);
  }

  ++size_;
}

int MediantorSqrtDecomp::Take() {
  const size_t idx           = (size_ - 1) / 2;
  const size_t bucket_idx    = idx / bucket_size_;
  const size_t idx_in_bucket = idx % bucket_size_;
  std::list<int>& bucket     = buckets_[bucket_idx];

  auto it = bucket.begin();
  std::advance(it, idx_in_bucket);
  const int ans = *it;
  bucket.erase(it);

  for (size_t i = bucket_idx; i + 1 < buckets_.size(); ++i) {
    int y = buckets_[i + 1].front();
    buckets_[i + 1].pop_front();
    buckets_[i].push_back(y);
  }
  if (buckets_.back().empty()) {
    buckets_.pop_back();
  }

  --size_;
  return ans;
}

}  // namespace sovictor::mediantor
