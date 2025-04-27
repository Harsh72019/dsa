#include <iostream>
#include <cmath>
using namespace std;

void printDivisors(int n) {
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            cout << i << " ";

          
            if (i != n / i) {
                cout << n / i << " "; 
            }
        }
    }
}

int main() {
    int n = 36;  // Example
    cout << "Divisors of " << n << " are: ";
    printDivisors(n);
    return 0;
}
