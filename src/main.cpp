#include <bits/stdc++.h>

using namespace std;

#include "sorting/sorting.h"
#include "utils/utils.h"
int main() {
    vector<int> vec = {4, 3, 2, 1, 10, 9, 18, 0};
    print(vec);
    bubble_sort(vec);
    print(vec);
}
