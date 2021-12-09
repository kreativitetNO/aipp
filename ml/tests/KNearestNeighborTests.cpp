#include <functional>
#include <gtest/gtest.h>
#include <tuple>
#include "../KNearestNeighbors.h"

class KNearestNeighborTestFixture : public ::testing::Test
{
    public:
    KNearestNeighborTestFixture()
    {}
};

TEST_F(KNearestNeighborTestFixture, ConstructorSetsKValue)
{
    KNearestNeighbors<int> instance { 3ul };
    auto expected = 3ul;

    ASSERT_EQ(instance.kValue(), expected);
}

TEST_F(KNearestNeighborTestFixture, ConstructorWithoutArgumentSetsKValueTo1)
{
    KNearestNeighbors<int> instance;
    auto expected = 1ul;

    ASSERT_EQ(instance.kValue(), expected);
}

TEST_F(KNearestNeighborTestFixture, ConstructorWitEvenArgumentFailsAssertion)
{
    ASSERT_DEATH({
        KNearestNeighbors<int> instance { 2 };
    },
        "kValue % 2 == 1"
    );
}

TEST_F(KNearestNeighborTestFixture, SimpleClassification)
{
    KNearestNeighbors<int, int> instance { 1 };

    std::vector<std::tuple<int, int>> trainingData {
        { 1, 1 },
        { 2, 2 },
        { 3, 3 },
        { 4, 4 },
        { 5, 5 },
        { 6, 6 }
    };

    std::vector<int> labels {
        false, false, false, true, true, true
    };

    instance.train(trainingData, labels);

    std::vector<std::tuple<int, int>> test { { 1, 1 }, { 2, 2 }, { 4, 4 }, { 5, 5}, { 3, 3 }, { 5, 3 }, { 1, 1 }};

    auto results = instance.predict(test);

    for (int i = 0; i < test.size(); ++i)
    {
        std::cout << std::get<0>(test[i]) << ", " << std::get<1>(test[i]) << ": " << results[i] << std::endl;
    }

    ASSERT_EQ(1, 2);
}