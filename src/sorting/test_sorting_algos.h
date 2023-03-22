#include <bits/stdc++.h>

#include "../utils/utils.h"
#include "./children/check_sorted.h"
#include "./sorting.h"
using namespace std;

void test1() {
    vector<int> vec = {19, 1, 2, 3, 10, 4, 1, 8, 9, 0, 20};
    print(check_sorted(vec));
    print(vec);
    insertion_sort(vec);
    print(check_sorted(vec));

    print(vec);
}

void test2() {
    vector<int> vec = {19, 1, 2, 3, -1, 10, 4, 1, 8, 9, 0, 20, 100, -1};
    print(check_sorted(vec));
    print(vec);
    insertion_sort(vec);
    print(check_sorted(vec));
    print(vec);
}