#include <iostream>
#include <vector>
#include "sort.h"
#include "print.h"

using namespace std;

int main() {
    vector<int> a{13, 49, 23, 87, 90, 9, 63, 2};
    susalgos::quick_sort(a, 0, a.size() - 1);
    susprint::print_numeric_array(a);
    cin.get();
}