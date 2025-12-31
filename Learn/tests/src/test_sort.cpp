#include <iostream>
#include <vector>
#include "sort.h"
#include "print.h"

using namespace std;

template <typename T>
bool is_sorted(const vector<T>& a) {
    for (size_t i = 1; i < a.size(); ++i)
        if (a[i - 1] > a[i]) return false;
    return true;
}

int main() {
    cout << "+++Testing quick_sort:" << endl;

    cout << "Test 1:" << endl;
    vector<int> a{13, 49, 23, 87, 90, 9, 63, 2};
    susalgos::quick_sort(a, 0, a.size() - 1);
    susprint::print_numeric_array(a);
    if (is_sorted(a)) cout << "Test 1 Passed!" << endl;
    else cout << "Test 1 FAILED!" << endl;

    cout << "Test 2:" << endl;
    vector<int> b{};
    susalgos::quick_sort(b, 0, b.size() - 1);
    susprint::print_numeric_array(b);
    if (is_sorted(b)) cout << "Test 2 Passed!" << endl;
    else cout << "Test 2 FAILED!" << endl;

    cout << "Test 3:" << endl;
    vector<int> c{1, 2, 3, 3, 4, 4, 5};
    susalgos::quick_sort(c, 0, c.size() - 1);
    susprint::print_numeric_array(c);
    if (is_sorted(c)) cout << "Test 3 Passed!" << endl;
    else cout << "Test 3 FAILED!" << endl;

    return 0;
}
