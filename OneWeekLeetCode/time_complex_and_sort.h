//
// Created by dev on 11/2/2022.
//
#include <iterator>
#include <vector>


namespace OneWeekLeetCode {
    namespace OneWeekLeetCode::base {
        template<typename T>
        auto swap(T &t1, T &t2) -> void {
            t1 = t1 ^ t2;
            t2 = t1 ^ t2;
            t1 = t1 ^ t2;
        }
    }
    namespace sort {
        template<typename Iterator>
        auto selection_sort(Iterator begin, Iterator end) -> void {
            if (begin == end) {
                return;
            }
            for (Iterator i = begin; i != end; i++) {
                Iterator min = i;
                for (Iterator j = i; j != end; j++) {
                    if (*min > *j) {
                        min = j;
                    }
                }
                std::swap(*min, *i);
            }
        }

        template<typename Iterator>
        auto bubble_sort(Iterator begin, Iterator end) -> void {
            if (begin == end) {
                return;
            }
            for (Iterator i = end - 1; i != begin; i--) {
                for (Iterator j = begin; j != i; j++) {
                    if (*j > *(j + 1)) {
                        std::swap(*j, *(j + 1));
                    }
                }
            }
        }
    }

    namespace problem_sets {
        /**
         * Question #1: find odd times number(only take one) [找出出现奇数次的数]
         * tips:xor operation, same case 0, other case 1
         * input case: {1, 1, 2, 2, 3, 3, 5, 4, 4, 6, 6, 20, 5}
         * output case: 20
         */
        auto question_01(const std::vector<int> &vec = {1, 1, 2, 2, 3, 3, 5, 4, 4, 6, 6, 20, 5}) -> int {
            int answer = 0;
            for (const auto &val: vec) {
                answer xor_eq val;
            }
            return answer;
        }
        /**
         * Question #1: find odd times number(two numbers) [找出出现奇数次的数]
         * tips:xor operation, same case 0, other case 1
         * input case: {1, 1, 2, 2, 3, 3, 5, 4, 4, 6, 6, 20, 5, 5}
         * output case: 20,5
        */
        auto question_02(const std::vector<int> &vec = {1, 1, 2, 2, 3, 3, 5, 4, 4, 6, 6, 20, 5, 5}) -> std::vector<int>{
            int answer = 0;
            for (const auto &val: vec) {
                answer xor_eq val;
            }
            int eor = answer & ( ~answer + 1);
            int onlyOne{0};
            for (const auto &cur:vec) {
                if ((eor & cur) == 0) {
                    onlyOne xor_eq cur;
                }
            }
            return {onlyOne, onlyOne xor answer};
        }
    }
}