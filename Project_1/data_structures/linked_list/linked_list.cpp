#include <iostream>
#include <initializer_list>
//#include <cstdlib>

using std::cout;
using std::cin;

template <typename T>
struct node {
    T data;
    node* next;    
    node (T val) : data(val), next(NULL) {}
};

template <typename T>
class linked_list {
    private:
        node<T>* head;
    public:
        linked_list(T data){
            head = new node<T> (data);
        }
        void push_front(T data){
            node<T>* new_node = new node<T>(data); 
            new_node->next = head; 
            head = new_node;
        }
        void push_back(T data) {
            node<T>* new_node = new node<T>(data);
            node<T>* pointer = head;
            while(pointer->next != NULL){
                pointer = pointer->next;
            }
            pointer->next = new_node;
        }
        void print(){
            node<T>* node = head;
            while(node != NULL){
                cout << node->data << "->";
                node = node->next;
            }
            cout << "\n";
        }
        ~linked_list(){

        };
};


int main() {
    linked_list<int> ll(3);
    std::initializer_list<int> list = {4,5,6,7,3,8,9,9};
    for(int value: list){
        ll.push_front(value);
    }
    ll.print();
    return 0;
}
