# AIPP

Artificial Intelligence Library written in C++. Although it is mainly an exercise to improve my knowledge and skills in c++ and AI, it is also a portable alternative to enable the usage of AI in environments where Python may not be the best fit such as embedded environments.

By AI, I am referring to the definition where AI contains the subset Machine Learning, and Machine Learning contains the subset Deep Learning. (And Deep Learning is used to implement AI if you want to get philosophical.)

Note that much of the Python AI stuff is already written in fast and efficient languages such as C, C++ (and Rust?) and most of the gruntwork is done in an enviroment where the scripty, loosely and dynamically typed nature of Python doesn't significantly impact performance. Most of this stuff is written by highly knowledgeable individuals and teams who have done a way better job than myself. If you're under the impression that my C++ implementation of some of these algorithms will improve performance, you will probably be disappointed. If you're looking for portability and joining me in my learning journey (and perhaps contributing a bit), you've come to the right place.

## Testing

Unit tests are implemented using Google Test which is therefore a prerequisite if you want to run tests.

## Current release notes - v0.0.0 Alpha

This is barely a placeholder for future work as per now. My main goal in the near future is to establish interfaces for models, data and the relationships between them. Ideally, I want it to be simple to switch between models of the same type (eg. binary classification models) and data source types (arrays, std::vector, std::array etc).

For the first genuine release (v0.1 or the likes) I will try to add:

- Makefiles for building libraries and tests
- Tests (that will hopefully serve as documentation)
- A minimum set of typical ML/DL algorithms
