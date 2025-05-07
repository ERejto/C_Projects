#include <iostream>
#include <initializer_list>
#include <cstdlib>
#include <x86intrin.h>
#include <thread>
#include <chrono>

using std::cout;
using std::cin;
using namespace std::this_thread;
using namespace std::chrono_literals;

class timer {
    private:
        unsigned long long start;
        unsigned long long end;
        unsigned long long out;
        unsigned long long const udiv = 180000;
        unsigned long long const mdiv = 31700000;
        unsigned long long const div  = 3000000000;
    public:
        timer() {
            start = __rdtsc();
        }
        ~timer() {

        }
        unsigned long long get() {
            end = __rdtsc();
            out = end-start;
            return out;
        }
        unsigned long long reset() {
            end = __rdtsc();
            out = end-start;
            start = __rdtsc();
            return out;
        }
        int micro() {
           return get()/udiv;
        }
        int milli() {
            return get()/mdiv;
        }
        int sec() {
            return get()/div;
        }
};

int main() {
    timer time;
    while (1) {
        cout << time.sec() << "\n";
        sleep_for(1s);
        cout << time.milli() << "\n";
        sleep_for(1ms);
    }
}