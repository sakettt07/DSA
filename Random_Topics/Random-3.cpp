// In this file i have studied about modulo which is used in the division of the large data values.
#include <iostream>
using namespace std;

int main() {
    const int MOD = 1e9 + 7;  // Define a modulo value

    int a = 1000000001;
    int b = 123456789;

    // Calculate (a + b) % MOD
    int result = (a + b) % MOD;

    cout << "Result of (" << a << " + " << b << ") % " << MOD << " is: " << result <<endl;
    return 0;
}
