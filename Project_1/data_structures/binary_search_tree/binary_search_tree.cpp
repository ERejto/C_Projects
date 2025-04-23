#include <iostream>
#include <initializer_list>
#include <cstdlib>

using std::cout;
using std::cin;

template <typename T>
struct node {
    int key;
    T data;
    node* left;
    node* right;
    node(int key_val,T val): key(key_val), data(val), left(NULL), right(NULL) {}
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
        void insert(int key, T data){
            node<T>* new_node = new node<T>(key, data);
            node<T>* pointer = head;
            while(pointer->left != NULL && pointer->right != NULL){
                if(pointer->key > new_node->key){
                    pointer = pointer->left;
                }
                else if(pointer->key < new_node->key){
                    pointer = pointer->right;
                }
            }
            if(pointer->key > new_node->key){
                pointer->left = new_node;
            }
            if(pointer->key < new_node->key){
                pointer->right = new_node;
            }
        }
        T get(int key){
            node<T>* pointer = head;
            while(pointer != NULL){
                if(pointer->key > key){
                    pointer = pointer->left;
                }
                else if(pointer->key < key){
                    pointer = pointer->right;
                }
                else if(pointer->key == key){
                    return pointer->data;
                }
            }
            cout << "NOT FOUND" << "\n";
            return (T)NULL;
        }

        void print_help(node<T>* p,int start){
            start++;
            if (p->right != NULL)
            {
                print_help(p->right,start);
            }
            for (int i = 0; i <= start; i++)
            {
                cout<<"    ";
            } 
            cout << p->key << "  ,  " << p->data<<"\n";
            if (p->left != NULL)
            {
                print_help(p->left, start);
            }
        }
            

        void print(){
            node<T>* pointer = head;
            print_help(pointer, 0);    
        }
};

int main() {
    binary_search_tree<float> bst(4,1.2);
    bst.insert(6,4.555);
    bst.insert(2,3.3333);
    bst.insert(1,4.56666);
    bst.insert(8,1.222);

    bst.insert(7,4.44444);
    bst.insert(1,4.4444);
    bst.print();
    cout << bst.get(8) << "\n";
    return 0;
}