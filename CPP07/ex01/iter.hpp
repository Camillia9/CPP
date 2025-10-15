#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

// Version pour tableaux non-const
template <typename T, typename F>
void iter(T* array, size_t length, F func) {
    for (size_t i = 0; i < length; i++) {
        func(array[i]);
    }
}

// Version pour tableaux const
template <typename T, typename F>
void iter(const T* array, size_t length, F func) {
    for (size_t i = 0; i < length; i++) {
        func(array[i]);
    }
}

#endif
