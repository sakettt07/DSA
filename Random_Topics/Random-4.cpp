// understanding the concept of gcd.
#include <bits/stdc++.h>
using namespace std;

int main() {
    string str1 = "ABCABC";
    string str2 = "ABC";

    // Using std::gcd to find the GCD of string lengths
    size_t len1 = str1.length();
    size_t len2 = str2.length();
    
    size_t result = gcd(len1, len2);

    // Displaying the result
    cout << "GCD of the lengths of \"" << str1 << "\" and \"" << str2 << "\" is: " << result <<endl;

    return 0;
}
