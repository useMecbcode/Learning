//
// Created by dev on 15/1/2022.
//
#include "../includes/search.h"

int binary_search(const std::vector<int> &vec, int value) {
    int high = static_cast<int>(vec.size()) - 1;
    int low = 0;
    while (low <= high) {
        int mid = low + ((high - low) >> 1);
        if (value < vec[mid]) {
            high = mid - 1;
        } else if (value > vec[mid]) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}
#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"
[[maybe_unused]]
static int bsearchInternally(const std::vector<int> &a, int low, int high, int value) {
    if (low > high) return -1;
    int mid = low + ((high - low) >> 1);
    if (a[mid] == value) { return mid; }
    else if (a[mid] < value) {
        return bsearchInternally(a, mid + 1, high, value);
    }
    else { return bsearchInternally(a, low, mid - 1, value); }
}
#pragma clang diagnostic pop
