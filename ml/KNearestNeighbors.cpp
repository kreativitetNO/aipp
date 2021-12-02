#include <cassert>
#include "KNearestNeighbors.h"

KNearestNeighbors::KNearestNeighbors(unsigned long kValue)
    : kValue_ { kValue }
{
    assert(kValue % 2 == 1);
}

unsigned long
KNearestNeighbors::kValue() const
{
    return kValue_;
}