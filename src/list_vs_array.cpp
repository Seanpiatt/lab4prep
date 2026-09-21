#include <cstddef>   
#include <cstdint>   
#include <iostream>  
#include <list>      
#include <random>    
#include <vector>    

#include "timer.h"

constexpr size_t SIZE = 16000000;

int main() {
    Timer timer;
    std::mt19937_64 rng(0);

    std::list<uint64_t> list;
    rng.seed(0);
    timer.restart();
    for (size_t i = 0; i < SIZE; ++i) {
        list.push_back(rng());
    }
    std::cout << "list insert:              " << timer.click<Timer::Micros>() << " us\n";

    std::vector<uint64_t> vec;
    rng.seed(0);
    timer.restart();
    for (size_t i = 0; i < SIZE; ++i) {
        vec.push_back(rng());
    }
    std::cout << "vector insert (no reserve): " << timer.click<Timer::Micros>() << " us\n";

    std::vector<uint64_t> vecReserved;
    vecReserved.reserve(SIZE);
    rng.seed(0);
    timer.restart();
    for (size_t i = 0; i < SIZE; ++i) {
        vecReserved.push_back(rng());
    }
    std::cout << "vector insert (reserve):    " << timer.click<Timer::Micros>() << " us\n";

    uint64_t listSum = 0;
    timer.restart();
    for (uint64_t x : list) {
        listSum += x;
    }
    std::cout << "list sum:   " << listSum << ", " << timer.click<Timer::Micros>() << " us\n";

    uint64_t vecSum = 0;
    timer.restart();
    for (uint64_t x : vecReserved) {
        vecSum += x;
    }
    std::cout << "vector sum: " << vecSum << ", " << timer.click<Timer::Micros>() << " us\n";

    return 0;
}
