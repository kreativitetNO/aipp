#include <gtest/gtest.h>
#include "../KNearestNeighbors.h"

class KNearestNeighborTestFixture : public ::testing::Test
{
    public:
    KNearestNeighborTestFixture()
    {}
};

TEST_F(KNearestNeighborTestFixture, ConstructorSetsKValue)
{
    KNearestNeighbors instance { 3ul };
    auto expected = 3ul;

    ASSERT_EQ(instance.kValue(), expected);
}

TEST_F(KNearestNeighborTestFixture, ConstructorWithoutArgumentSetsKValueTo1)
{
    KNearestNeighbors instance;
    auto expected = 1ul;

    ASSERT_EQ(instance.kValue(), expected);
}

TEST_F(KNearestNeighborTestFixture, ConstructorWitEvenArgumentFailsAssertion)
{
    ASSERT_DEATH({
        KNearestNeighbors instance { 2 };
    },
        "kValue % 2 == 1"
    );
}

TEST_F(KNearestNeighborTestFixture, SimpleClassification)
{
    int arr1[] { 1, 2 };
    int arr2[] { 1, 2 };
    bool b[] { true, false };

    int value1 = 0;
    int value2 = 0;

    bool expected = true;
    
    KNearestNeighbors instance;

    int actual = instance.binaryClassification(arr1, arr2, b, 2, value1, value2);

    ASSERT_EQ(actual, expected);
}