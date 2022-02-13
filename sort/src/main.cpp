#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>
#include "../includes/tree.h"

#define __TEST__
//#define _STR_(X) #X"="
//#define _CONCAT_(X, Y) X##Y
using namespace std;
///
/// \author wking Wstorm

template<typename compare_type>
[[maybe_unused]] void bubble_sort(std::vector<compare_type> &vec) {
    for (int i = 0; i < vec.size(); ++i) {
        bool flag = false;
        cout << "meta[" << i + 1 << "]: ";
        for_each(vec.cbegin(), vec.cend(), [](int val) { cout << val << " "; });
        cout << endl;
        for (int j = 0; j < vec.size() - i - 1; ++j) {
            if (vec[j] > vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
                cout << "swap[" << "(" << j << "," << j + 1 << ")" << "]: ";
                for_each(vec.cbegin(), vec.cend(), [](int val) { cout << val << " "; });
                cout << endl;
                flag = true;
            }
        }
        if (!flag) return;
    }
}//!
//! \tparam comparable
//! \param vec
template<typename comparable>
[[maybe_unused]]
void insert_sort(vector<comparable> &vec) {
    // [sorted:un_sorting]
    for (int i = 1; i < vec.size(); ++i) {
#ifdef __TEST__
        [&]() {
            cout << "sorted:";
            for (int k = 0; k < i; ++k) {
                cout << vec[k] << " ";
            }
            cout << endl;
            cout << "un_sorting:";
            for (int k = i; k < vec.size(); ++k) {
                cout << vec[k] << " ";
            }
            cout << endl;
        }();
#endif
        auto value = vec[i];
        // move
        int j;
        for (j = i - 1; j >= 0; --j) {
            if (vec[j] > value) {
                vec[j + 1] = vec[j];
            } else {
                break;
            }
        }
        vec[j + 1] = value;
    }
}

template<typename Comparable, typename Comparor = less<Comparable>>
[[maybe_unused]]void select_sort(vector<Comparable> &vec, Comparor comparor = less<Comparable>()) {
    for (int i = 0; i < vec.size(); ++i) {
        int min_index = vec[i];
        for (int j = i; j < vec.size(); ++j) {
            if (comparor(vec[j], vec[min_index])) {
                min_index = j;
            }
        }
        swap(vec[i], vec[min_index]);
    }
}

// TODO: MERGE-SORT https://en.wikipedia.org/wiki/Merge_sort#Merge_sort_with_parallel_recursion
// TODO: WAITING FOR COMPREHENSION RECURSION
[[maybe_unused]]
void Merge(vector<int> &Array, int front, int mid, int end) {
    // preconditions:
    // Array[front...mid] is sorted
    // Array[mid+1 ... end] is sorted
    // Copy Array[front ... mid] to LeftSubArray
    // Copy Array[mid+1 ... end] to RightSubArray
    vector<int> LeftSubArray(Array.begin() + front, Array.begin() + mid + 1);
    vector<int> RightSubArray(Array.begin() + mid + 1, Array.begin() + end + 1);
    // SET BORDER
    LeftSubArray.insert(LeftSubArray.end(), numeric_limits<int>::max());
    RightSubArray.insert(RightSubArray.end(), numeric_limits<int>::max());
#ifdef __TEST__
    cout << "LeftSubArray: ";
    for_each(LeftSubArray.cbegin(), LeftSubArray.cend() - 1, [](int val) { cout << val << " "; });
    cout << endl;
    cout << "RightSubArray: ";
    for_each(RightSubArray.cbegin(), RightSubArray.cend() - 1, [](int val) { cout << val << " "; });
    cout << endl;
#endif
    int idxLeft = 0, idxRight = 0;
    // Pick min of LeftSubArray[idxLeft] and RightSubArray[idxRight], and put into Array[i]
    for (int i = front; i <= end; i++) {
        if (LeftSubArray[idxLeft] < RightSubArray[idxRight]) {
            Array[i] = LeftSubArray[idxLeft++];
        } else {
            Array[i] = RightSubArray[idxRight++];
        }
    }
#ifdef __TEST__
    cout << "SortedPartOfArray: ";
    for_each(Array.cbegin() + front, Array.cbegin() + end + 1, [](int val) { cout << val << " "; });
    cout << endl;
    cout << "MetaArray: ";
    for_each(Array.cbegin(), Array.cend(), [](int val) { cout << val << " "; });
    cout << endl;
#endif
}

[[maybe_unused]]
void MergeSort(vector<int> &Array, int front, int end) {
    if (front >= end)
        return;
    int mid = front + (end - front) / 2;
    MergeSort(Array, front, mid);
    MergeSort(Array, mid + 1, end);
    Merge(Array, front, mid, end);
}

// TODO: WAITING FOR COMPREHENSION NON- RECURSION
template<typename T>
// 整數或浮點數皆可使用,若要使用物件(class)時必須設定"小於"(<)的運算子功能
[[maybe_unused]]void merge_sort(T arr[], int len) {
    T *a = arr;
    T *b = new T[len];
    // seg divide in array
    for (int seg = 1; seg < len; seg += seg) {
        for (int start = 0; start < len; start += seg + seg/**/) {
            int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;
            while (start1 < end1 && start2 < end2)
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            while (start1 < end1)
                b[k++] = a[start1++];
            while (start2 < end2)
                b[k++] = a[start2++];
        }
        T *temp = a;
        a = b;
        b = temp;
    }
    if (a != arr) {
        for (int i = 0; i < len; i++)
            b[i] = a[i];
        b = a;
    }
    delete[] b;
}

//TODO: May be use three area optimization [less,equal,more] Dutch Flag Problems
[[maybe_unused]]
int partition(std::vector<int> &vec, int L, int R) {
    int pivot = vec[R];
    int i = L;
    for (int j = L; j <= R - 1; ++j) {
        if (vec[j] < pivot) {
            swap(vec[i++], vec[j]);
        }
    }
    swap(vec[i], vec[R]);
    return i;
}

void quick_sort(vector<int> &vec, int L, int R) {
    if (L >= R) return;
    int q = partition(vec, L, R);
    quick_sort(vec, L, q - 1);
    quick_sort(vec, q + 1, R);
}

/*
 * ------------------------------------------
 * | T(N)       | S(N) |Stable| Sort Name   |
 * | O(N^2)     | O(1) |true  | insert_sort |
 * | O(N^2)     | O(1) |true  | bubble_sort |
 * | O(N^2)     | O(1) |false | select_sort |
 * | O(Nlog(N)) | O(N) |true  | merge_sort  |
 * | O(Nlog(N)) | O(1) |false  | quick_sort  |
 * ------------------------------------------
 * */
// TODO: count_sort bucket_sort
void count_sort(vector<int> &vec) {
    if (vec.size() <= 1) return;
    int max = vec[0];
    for (const auto &x: vec) {
        if (max < x) {
            max = x;
        }
    }
    std::vector<int> counter(max + 1, 0);
    for (auto &x: vec) {
        counter[x]++;
    }
    for (int i = 1; i <= max; ++i) {
        counter[i] = counter[i - 1] + counter[i];
    }
    vector<int> result(vec.size());
    for (int i = static_cast<int>(vec.size()) - 1; i >= 0; --i) {
        int index = counter[vec[i]] - 1;
        result[index] = vec[i];
        counter[vec[i]]--;
    }
    for (int i = 0; i < vec.size(); ++i) {
        vec[i] = result[i];
    }
}

// TODO:un-comprehension
// binary ways to sqrt
double Sqrt(double target) {
    double base = 0;
    int l = 0, r = 9;
    double step = 10;
    for (int i = 0; i < 7; i++) {
        step *= 0.1;
        while (l <= r) {
            int middle = l + (r - l) / 2;
            if (pow((base + middle * step), 2) == target) {
                return middle;
            }
            if (pow((base + middle * step), 2) < target) {
                l = middle + 1;
            }
            if (pow((base + middle * step), 2) > target) {
                r = middle - 1;
            }
        }
        base += (r) * step;
        l = 0;
        r = 9;
    }
    return base;
}

void printPermutations(int data[], int n, int k) {
    if (k == 1) {
        for (int i = 0; i < n; ++i) {
            cout << data[i] <<  " ";
        }
        cout << endl;
    }
    for (int i = 0; i < k; ++i) {
        swap(data[i],data[k - 1]);
        printPermutations(data, n, k - 1);
        swap(data[i],data[k - 1]);
    }
}


int main() {
//    std::cout << "Hello, World!" << std::endl;
//    int a = 3;
//    int ab = 4;
//    cout << _STR_(a) << a << endl;
//    cout << _CONCAT_(a, b) << endl;
    vector<int> as{4, 5, 6, 1, 3, 2, 11, 10, 9, 7};
//    insert_sort<int>(as);
//    select_sort(as);
//    MergeSort(as, 0, static_cast<int>(as.size() - 1));
//    quick_sort(as, 0, static_cast<int>(as.size() - 1));
    count_sort(as);
    for_each(as.begin(), as.end(), [](int a) { cout << a << " "; });
    auto *fp{new auto{[]() {
        return 1;
    }}};
    fp->operator()();
    cout << '\n' << Sqrt(2.5) << endl;
    cout << '\n' << sqrtf(2.5) << endl;
    delete fp;
    tree::BinaryTree tree{};
    tree.add(1);
    tree.add(2);
    tree.add(3);
    tree.add(4);
    tree.add(5);
    tree.add(6);
    tree.print();
    tree.levelorder();
    cout << endl;
    int n[]{1,2,3};
    printPermutations(n,3,3);
    return 0;
}

#undef __TEST__
#pragma clang diagnostic pop