#pragma once

#include "mediantor/i_mediantor.h"
#include "mediantor/mediantor_heap.h"
#include "mediantor/mediantor_sorted_list.h"
#include "mediantor/mediantor_sqrt_decomp.h"

namespace sovictor {
namespace mediantor {

enum class Mediantors {
  kHeap,
  kSqrtDecomp,
  kSortedList,
  kMediantorsNumber,
};

std::unique_ptr<IMediantor> MakeMediantor(Mediantors mediantor_type,
                                          int max_size) {
  switch (mediantor_type) {
    case Mediantors::kHeap:
      return std::make_unique<MediantorHeap>();
    case Mediantors::kSqrtDecomp:
      return std::make_unique<MediantorSqrtDecomp>(max_size);
    case Mediantors::kSortedList:
      return std::make_unique<MediantorSortedList>();
    case Mediantors::kMediantorsNumber:
      exit(1);
  }

  // Can't be reached.
  return std::unique_ptr<IMediantor>();
}

std::string to_string(Mediantors mediantor_type) {
  switch (mediantor_type) {
    case Mediantors::kHeap:
      return "MediantorHeap";
    case Mediantors::kSqrtDecomp:
      return "MediantorSqrtDecomp";
    case Mediantors::kSortedList:
      return "MediantorSortedList";
    case Mediantors::kMediantorsNumber:
      return "kMediantorsNumber";
  }

  // Can't be reached.
  return "";
}

}  // namespace mediantor
}  // namespace sovictor
