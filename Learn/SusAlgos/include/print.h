#pragma once
#include <vector>
#include <iostream>

namespace susprint {

    template <typename T>
    inline void print_numeric_array(const std::vector<T>& a) {
        std::cout << "[";
        for (size_t i = 0; i < a.size(); ++i) {
            std::cout << a[i];
            if (i != a.size() - 1) std::cout << ",";
        }
        std::cout << "]" << std::endl;
    }
    
}