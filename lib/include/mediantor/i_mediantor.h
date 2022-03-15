#pragma once

namespace sovictor {
namespace mediantor {

class IMediantor {
 public:
  virtual ~IMediantor() = default;

  virtual void Insert(int x) = 0;
  virtual int Take()         = 0;

  virtual const size_t size() = 0;
};  // class IMediantor

}  // namespace mediantor
}  // namespace sovictor
