#include <iostream>
#include <initializer_list>
#include <cstdlib>

using std::cout;
using std::cin;

template <typename T>
struct node {
    int* key;
    T* data;
    node* left;
    node* right;
    node(int key,T data): key(key), data(data), left(NULL), right(NULL) {}
};

template <typename T>
class binary_search_tree {
    private:
        node<T>* head;
    public:
        binary_search_tree(int key, T data){
            head = new node<T>(key, data);
        }
        ~binary_search_tree(){

        }
        insert(int key, T data){
            node<T>* new_node = new node<T>(key, data);
            node<T>* pointer = head;
            if(pointer->left==NULL && pointer->right==NULL){
                
            }

        }


};

int main() {
    binary_search_tree<int> bst(1);
    return 0;
}