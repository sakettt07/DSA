// Even&Odd.
#include<bits/stdc++.h>
using namespace std;


// the below code is giving the memory limit exceeded

long long findKthNumber(long long n, long long k) {
    long long oddCount = (n + 1) / 2; // Count of odd numbers from 1 to n
    if (k <= oddCount) {
        return 2 * (k - 1) + 1; // If kth number is odd
    } else {
        return 2 * (k - oddCount); // If kth number is even
    }
}

int main() {
    long long n, k;
    cin >> n >> k;

    cout << findKthNumber(n, k) << endl;

    return 0;
}
// int main(){
//     int n,k;
//     cin>>n>>k;
//     cout<<endl;
//     vector<int>ans;
//     // add the odd numbers in the ans array.
//     for (int i = 1; i <= n; i++) {
//         if (i % 2 != 0) {
//             ans.push_back(i);
//         }
//     }

//     // Add even numbers
//     for (int i = 2; i <= n; i += 2) {
//         ans.push_back(i);
//     }
//     cout<<ans[k-1]<<endl;

// return 0;
// }