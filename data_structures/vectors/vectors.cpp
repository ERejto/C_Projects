#include <iostream>
using namespace std;

template <typename T>
class vector {
        T* data;
        size_t size = 0;
        size_t capacity = 10;
    public:
        vector() {
            data = (T*)malloc(capacity);
        }
        ~vector(){
            free(data);
        }
        void push_back(T value) {
            if (size > capacity){
                capacity = capacity * 2;
                data = (T*)realloc(data, capacity);
            }
            *(data+size) = value;
            size += 1;
        }
        T& operator [](size_t index) {
            return *(data+index); 
        }
        size_t get_size(){
            return size;            
        }
};

int main() {
    vector<int> vec;
    vec.push_back(5);
    vec.push_back(10);
    int size = vec.get_size();
    cout << vec[1] << "\n";
    cout << size << "\n";
    vec.push_back(1);
    vec.push_back(2);
    size = vec.get_size();
    cout << size << "\n";
    return 0;
}