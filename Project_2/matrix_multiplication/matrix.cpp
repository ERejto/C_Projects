#include <cstdlib>
#include <iostream>
#include <execution>
#include <bits/stdc++.h>

using namespace std;


class matrix {
    private:
        vector<vector<int>> data; 
    public:
        matrix(int l, int w){
            data.resize(l);
            for (int i = 0; i < l; i++){
                for (int j = 0; j < w; j++) { 
                    data[i].push_back(0);
                }
            }
        }
        matrix(int l, int w, int def){
            data.resize(l);
            for (int i = 0; i < l; i++){
                for (int j = 0; j < w; j++) { 
                    data[i].push_back(def);
                }
            }
        }
        matrix(initializer_list<vector <int>> list) {
            data = list;
            int length = data[0].size();
            for (int i = 0; i < data.size(); i++) {
                if (data[i].size() != length) {
                    throw std::length_error("Row sizes do not match.");
                }
            }
        }

        ~matrix(){

        }

        size_t length() {
            return data.size();
        }
        size_t width() {
            return data[0].size();
        }

        vector<int>& operator[](size_t i) {
            return data[i];
        }

        matrix operator+(int val) {
            matrix buff(length(), width());
            for (size_t r = 0; r < length(); ++r) {
                // transform each element in row r
                transform(
                    execution::par,
                    data[r].begin(), data[r].end(),   // input range
                    buff.data[r].begin(),             // output range
                    [val](int a) { return a + val; }    // add the constant
                );
            }
            return buff;  // return the new matrix, not *this
        }
        
        matrix operator+(matrix m){
            matrix buff(length(), width());
            for (size_t r = 0; r < length(); ++r) {
                transform(
                    data[r].begin(), data[r].end(),
                    m.data[r].begin(),
                    [val](int a) { return a + val;
                    }
                )
            }


        }

        void print(){
            for (int i = 0; i < data.size(); i++) {
                for (int j = 0; j < data[i].size(); j++) {
                    cout << data[i][j] << " ";
                }
                cout << "\n";
            }
        }
};

int main() {
    matrix m(4,4);
    m = m+1;
    m.print();
    return 0;
}