#include <iostream>
#include <initializer_list>
#include <cstdlib>
using std::cout;
using std::cin;
template <typename T>
class vector {
    private:
        T* data;
        size_t size = 0;
        size_t capacity = 10;
        size_t data_size = sizeof(T);
    public:
        vector() {
            data = (T*)malloc(capacity*data_size);
        }
        vector(size_t sz) {
            size = sz;
            capacity=sz;
            data = (T*)malloc(size*data_size);
        }
        vector(std::initializer_list<T> list) {
            data = (T*)malloc(capacity*data_size);
            for(T value : list){
                push_back(value);
            }
        }
        ~vector(){
            free(data);
        }
        void push_back(T value) {
            if (size >= capacity){
                capacity *=  2;
                data = (T*)realloc(data, capacity*data_size);
            }
            data[size++] = value;
        }
        T& operator [](size_t index) {
            return data[index]; 
        }
        void operator +=(T value){
            push_back(value);
        }
        void operator +=(std::initializer_list<T> list){
            for(T value : list) {
                push_back(value);
            }
        }
        size_t get_size(){
            return size;            
        }
        T& begin(){
            return data[0];
        }
        T& end(){
            return data[size-1];
        }
        void print() {
            cout << "[ ";
            for(int i=0; i<size; i++){
                cout << data[i] << " ";
            }
            cout << "]" << "\n";
        } 
};

int main() {
    vector<int> vec = {1,2,3,4,5,6,7,8,9,10};
    return 0;
}