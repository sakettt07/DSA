#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int>& A) {
    sort(A.begin(), A.end());
    unordered_map<int, int> freq;

    // Populate frequency map
    for (int num : A) {
        freq[num]++;
    }

    int operations = 0;

    for (int i = 0; i < A.size(); ++i) {
        if (freq[A[i]] > 0) {
            int x = A[i];
            // Try to remove pairs (x, x+1)
            if (freq[x] > 0 && freq[x + 1] > 0) {
                freq[x]--;
                freq[x + 1]--;
                operations++;
            } 
            // Try to remove two occurrences of x
            else if (freq[x] > 1) {
                freq[x] -= 2;
                operations++;
            } 
            // Remove a single occurrence of x
            else {
                freq[x]--;
                operations++;
            }
        }
    }

    return operations;
}

int main() {
    // Test case 1
    vector<int> A1 = {2, -3, 10, 1, -1};
    int result1 = minOperations(A1);
    cout << "Test case 1 output: " << result1 << endl;

    // Test case 2
    vector<int> A2 = {5};
    int result2 = minOperations(A2);
    cout << "Test case 2 output: " << result2 << endl;

    return 0;
}
