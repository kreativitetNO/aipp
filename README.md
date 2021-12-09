# Introduction

Artificial Intelligence Library written in C++. Although it is mainly an exercise to improve my knowledge and skills in c++ and AI, it is also a portable alternative to enable the usage of AI in environments where Python may not be the best fit such as embedded environments.

By AI, I am referring to the definition where AI encompasses the subset Machine Learning, and Machine Learning encompasses the subset Deep Learning. (And Deep Learning is used to implement AI if you want to get all recursive and philosophical.)

Note that much of the Python AI stuff is already written in fast and efficient languages such as C, C++ (and Rust?) and most of the gruntwork is done in an enviroment where the scripty, loosely and dynamically typed nature of Python doesn't significantly impact performance. Most of this stuff is written by highly knowledgeable individuals and teams who have done a way better job than myself. If you're under the impression that my C++ implementation of some of these algorithms will improve performance, you will probably be disappointed. If you're looking for portability and joining me in my learning journey (and perhaps contributing a bit), you've come to the right place.

## Note on complexity

My development philosophy follows this list of priorities in descending order:
1. Correctness - Does what it should
2. Maintainability - Code is legible, understandable and therefore maintainable
3. Flexibility - Doesn't force the use of specific containers/types unnecessarily
4. Efficiency - Runs fast

Most of my prototyping will be done using specific types or very basic template usage and mirror the description of the actual algorithms. From there, I will add flexibility through abstractions (more aggressive templating) and local optimizations to remove obvious bottlenecks. If the code looks too advanced, try looking through the commit history for an earlier version of the specific file(s). Although maintainability has high priority, some degree of complexity is unavoidable in areas where performance matters.

# Prequisites and build environment

Unit tests are implemented using Google Test which is therefore a prerequisite if you want to run tests. Code is built using gcc 9.3.0.

# Todo

* Improve tests for KNN

## Adventurous todo

* Multithreaded version of KNN

# Release History

# v0.1 - 9.12.21

Implemented KNN and added simple makefile.

# Initial release

This is barely a placeholder for future work as per now. My main goal in the near future is to establish interfaces for models, data and the relationship between the two. Ideally, I want it to be simple to switch between models of the same type (eg. binary classification models) and data source types (arrays, std::vector, std::array etc).

For the first genuine release (v0.1 or the likes) I will try to add:

- Makefiles for building libraries and tests
- Tests (that will hopefully serve as documentation)
- A minimum set of typical useful ML algorithms

Deep learning is probably still a way off.
