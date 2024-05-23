#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

double logBase(double value, double base) {
    return log(value) / log(base);
}

bool isPowerOfPrime(int value, int prime) {
    // get the maximum power that is less than INT_MAX
    int power = (int)logBase(INT_MAX, prime);
    cout << power << endl;
    return (int)pow(prime, power) % value == 0;
}

void tolower(string &s) {
    for (char &c : s) {
        c = std::tolower(c);
    }
}