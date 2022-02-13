#define CATCH_CONFIG_MAIN

#include <iostream>
#include <vector>
#include <algorithm>
#include <type_traits>
#include "time_complex_and_sort.h"
#include<catch2/catch.hpp>
//int main() {
////    std::vector<int>::iterator::iterator_concept ::random_access_iterator_tag
//    if constexpr (std::is_same<std::__detail::__iter_concept<std::vector<int>>,
//            std::__detail::__iter_concept<std::vector<float>>>()) {
//        std::cout << "true" << std::endl;
//    }
//    std::vector<int> vec{1, 3, 2, 5, 4, 8, 7};
//    auto out{[&]() {
//        for_each(vec.begin(), vec.end(), [](int value) { std::cout << value << " "; });
//        std::cout << std::endl;
//    }
//    };
//    out();
//    OneWeekLeetCode::sort::selection_sort(vec.begin() + 4, vec.end());
//    out();
//    OneWeekLeetCode::sort::bubble_sort(vec.begin(), vec.end());
//    out();
//    auto iter = vec.begin();
//    iter = std::next(iter);
//    std::next_permutation(vec.begin(), vec.end());
//    std::cout << *iter << std::endl;
//    std::cout << OneWeekLeetCode::problem_sets::question_01() << std::endl;
//    auto ans = OneWeekLeetCode::problem_sets::question_02();
//    std::for_each(ans.cbegin(), ans.cend(), [](int value) { std::cout << value << " "; });
//    return 0;
//}
TEST_CASE("ProblemSets") {
    SECTION("QUESTION#1") {
        REQUIRE(OneWeekLeetCode::problem_sets::question_01({1, 2, 3, 1, 2, 3, 4, 5, 4}) == 5);
        REQUIRE(OneWeekLeetCode::problem_sets::question_01({1, 2, 3, 1, 2, 3, 4, 5, 4, 5}) == 0);
    }SECTION("QUESTION#2") {
        auto test = OneWeekLeetCode::problem_sets::question_02({1, 2, 3, 1, 2, 3, 4, 5, 4, 4});
        REQUIRE((test.begin().operator*() == 4 || test.begin().operator*() == 5) ==
                (*(test.end() - 1) == 4 || *(test.end() - 1) == 5));
    }
}

TEST_CASE("sort") {
    std::vector<int> test{1, 4, 3, 2, 11, 10, 9, 8, 5, 6, 7};
    SECTION("select_sort") {
        auto testCopy = test;
        auto sort = test;
        OneWeekLeetCode::sort::selection_sort(testCopy.begin(), testCopy.end());
        std::sort(sort.begin(), sort.end());
        REQUIRE(std::equal(testCopy.begin(), testCopy.end(), sort.begin()));
    }SECTION("bubble_sort") {
        auto testCopy = test;
        auto sort = test;
        OneWeekLeetCode::sort::bubble_sort(testCopy.begin(), testCopy.end());
        std::sort(sort.begin(), sort.end());
        REQUIRE(std::equal(testCopy.begin(), testCopy.end(), sort.begin()));
    }
}