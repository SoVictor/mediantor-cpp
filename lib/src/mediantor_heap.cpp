#include "mediantor/mediantor_heap.h"

void MediantorHeap::Insert(int x) {
  if (lower_half_.empty()) {
    lower_half_.push(x);
    return;
  }

  if (x < lower_half_.top()) {
    lower_half_.push(x);
  } else {
    upper_half_.push(x);
  }

  MaybeBalance();
}

int MediantorHeap::Take() {
  const int ans = lower_half_.top();
  lower_half_.pop();

  MaybeBalance();

  return ans;
}

void MediantorHeap::MaybeBalance() {
  if (lower_half_.size() < upper_half_.size()) {
    lower_half_.push(upper_half_.top());
    upper_half_.pop();
  } else if (lower_half_.size() > upper_half_.size() + 1) {
    upper_half_.push(lower_half_.top());
    lower_half_.pop();
  }
}
