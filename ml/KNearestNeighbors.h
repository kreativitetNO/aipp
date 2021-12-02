#ifndef KNEAREST_NEIGHBORS_H
#define KNEAREST_NEIGHBORS_H

#include <cmath>
#include <climits>

class KNearestNeighbors
{
    public:
    explicit KNearestNeighbors(unsigned long kValue = 1);

    unsigned long kValue() const;

    template <typename T>
    bool binaryClassification(T[], T[], bool[], unsigned long count, T v1, T v2) const;

    private:
    unsigned long kValue_;
};

#include <iostream>

// TODO Find better way of passing count - ideally not having to pass it all
// TODO Detect and notify if lists are of different lengths...
template <typename T>
bool KNearestNeighbors::binaryClassification(T vector1[], T vector2[], bool b[], unsigned long count, T value1, T value2) const
{
    bool result = false;
    double minDistance = -1;
    for (unsigned long i = 0; i < count; ++i)
    {
        double distance = ((value1 - vector1[i]) * (value1 - vector1[i])) + ((value2 - vector2[i]) * (value2 - vector2[i]));
        if (minDistance == -1 || distance < minDistance)
        {
            result = b[i];
            minDistance = distance;
        }
    }
    return result;
}

#endif