#include <iostream>
using namespace std;

void primeFactors(int n) {
    if (n % 2 == 0) {
        cout << 2 << " ";
        while (n % 2 == 0)
            n /= 2;
    }

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            cout << i << " ";
            while (n % i == 0)
                n /= i;
        }
    }

    if (n > 2)
        cout << n << " ";
}

int main() {
    int n = 315; 
    primeFactors(n);
    return 0;
}
