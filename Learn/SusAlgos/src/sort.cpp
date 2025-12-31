#include "sort.h"
#include <iostream>
#include <vector>

using namespace std;

namespace susalgos {

    void quick_sort(vector<int>& a, int left, int right) {
        if (left >= right) return;

        int pivot = a[left + (right - left) / 2];
        int i = left, j = right;

        while (i <= j) {
            while (a[i] < pivot) ++i;
            while (a[j] > pivot) --j;
            if (i <= j) {
                swap(a[i], a[j]);
                ++i;
                --j;
            }
        }
        
        if (left < j) quick_sort(a, left, j);
        if (i < right) quick_sort(a, i, right);
    }

}
