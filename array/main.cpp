#include <iostream>
#include <vector>
/**
 * Array 数组是 增删改查 offset [0...length] 表示地址的偏移
 */
template<typename DataType>
class Array {
    using size_t = std::size_t;
private:
    DataType *data;
    size_t capacity; // capacity
    size_t length;  // current length
public:
    explicit Array(size_t capacity) : capacity{capacity}, length{0}, data{new DataType[capacity]} {
        if (data == nullptr) {
            throw std::runtime_error("内存不足!");
        }
        for (size_t i = 0; i < capacity; ++i) {
            data[i] = 0;
        }
    }
    // insert
    void insert(const DataType value, size_t index) {
        if (index < 0 || index > capacity || length + 1 > capacity || index > length + 1){
            throw std::range_error("位置错误");
        }
        for(size_t i = length; i > index; --i) {
            data[i + 1] = data[i];
        }
        data[index] = value;
        ++length;
    }
    // delete
    void delete_data(size_t index){
        if (index < 0 || index > length ){
            throw std::range_error("位置错误");
        }
        for (size_t i = index; i < length; ++i) {
            data[i] = data[i + 1];
        }
        length --;
    }
    void print()const{
        for (size_t i = 0; i < length; ++i) {
            std::cout << data[i] <<" ";
        }
        std::cout << std::endl;
    }
    ~Array() {
        delete[] data;
    }
};
using namespace std;
// ask for my position

#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"
int f(int n){
    if (n == 1) return n;
    return f(n - 1) + 1;
}
#pragma clang diagnostic pop

int main() {
    Array<int> array{110};
    for (int i = 0; i < 11; ++i) {
        array.insert(i,i);
    }
    vector<int> st;
    auto push{[&st](int val)mutable {
        st.push_back(val);
    }};
    auto pop{[&](){
        int tmp = st.back();
        st.erase(st.end() - 1);
        return st.back();
    }};
    int n = 5;
    while (n != 0){
        push(n--);
    }
    st.
    int sum = 0;
    while (!st.empty()){
        sum += 1;
        pop();
    }
    cout << "My Position: " << sum << endl;
    array.delete_data(1);
    array.print();
    cout << "My Position: " << f (5) << endl;
    return 0;
}
