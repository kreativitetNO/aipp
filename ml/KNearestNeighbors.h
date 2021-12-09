#ifndef KNEAREST_NEIGHBORS_H
#define KNEAREST_NEIGHBORS_H

#include <algorithm>
#include <cassert>
#include <cmath>
#include <exception>
#include <functional>
#include <map>
#include <tuple>
#include <vector>

template <typename... DataFields>
class KNearestNeighbors
{
    public:
    explicit KNearestNeighbors(unsigned long kValue = 1);

    unsigned long kValue() const;

    template <template <typename...> typename Data, template <typename...> typename Labels>
    unsigned long train(Data<std::tuple<DataFields...>> const& data, Labels<int> const& labels);

    std::vector<bool> predict(std::vector<std::tuple<DataFields...>> inputs);

    private:
    unsigned long const kValue_;
    std::vector<std::tuple<DataFields...>> data_;
    std::vector<int> labels_;
};

template <typename... Fields>
KNearestNeighbors<Fields...>::KNearestNeighbors(unsigned long kValue)
    : kValue_ { kValue }
{
    assert(kValue % 2 == 1);
}

template <typename... DataFields>
unsigned long
KNearestNeighbors<DataFields...>::kValue() const
{
    return kValue_;
}

template <typename... DataFields>
template <template <typename...> typename Data, template <typename...> typename Labels>
unsigned long KNearestNeighbors<DataFields...>::train(Data<std::tuple<DataFields...>> const& data, Labels<int> const& labels)
{
    if (data.size() != labels.size()) throw std::logic_error("Data and labels contain different number of rows");
    data_.clear();
    for (auto const& sourceRow : data)
    {
        data_.push_back(sourceRow);
    }
    for (auto const& label : labels)
    {
        labels_.push_back(label);
    }
    return data_.size();
}

template <typename T1, typename T2, int... Is>
double squareOfDifference(T1 tuple1, T2 tuple2, std::integer_sequence<int, Is...>)
{
    return (((std::get<Is>(tuple1) - std::get<Is>(tuple2)) *
             (std::get<Is>(tuple1) - std::get<Is>(tuple2))) + ...);
}

template <typename... DataFields>
std::vector<bool> KNearestNeighbors<DataFields...>::predict(std::vector<std::tuple<DataFields...>> inputs)
{
    std::vector<bool> results;
    for (auto const& input : inputs)
    {
        std::vector<std::tuple<double, bool>> nearest;
        for (auto i = 0UL; i < data_.size(); ++i)
        {
            double distance = squareOfDifference(data_[i], input, std::make_integer_sequence<int, sizeof...(DataFields)>());
            if (nearest.size() < kValue_)
            {
                nearest.push_back(std::tuple { distance, labels_[i] });
                std::sort(nearest.begin(), nearest.end(), [](auto n1, auto n2) {
                    return std::get<0>(n1) < std::get<0>(n2);
                });
            }
            else if (distance < std::get<0>(nearest[kValue_ - 1]))
            {
                nearest[kValue_ - 1] = std::tuple { distance, labels_[i] };
                std::sort(nearest.begin(), nearest.end(), [](auto n1, auto n2) {
                    return std::get<0>(n1) < std::get<0>(n2);
                });
            }
        }
        std::map<int, unsigned long> labelCount;
        for (auto const& [distance, label] : nearest)
        {
            labelCount[label]++;
        }
        results.push_back(std::max_element(labelCount.begin(), labelCount.end())->first);
    }

    return results;
}

#endif