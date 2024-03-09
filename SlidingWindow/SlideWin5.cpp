// Sliding window hard problem
// First negative integer in every window of size k
// Short Description of the above question ---> hume ek array given hai or ek integer k given h hume us array me window size tak first negative integer nikalna h.
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int K)
{
    vector<ll> result;
    int i = 0, j = 0;
    deque<ll> dq;
    while (j < N)
    {
        if (A[j] < 0)
        {
            dq.push_back(A[j]);
        }
        if (j - i + 1 == K)
        {
            if (!dq.empty())
            {
                result.push_back(dq.front());
            }
            else
            {
                result.push_back(0);
            }

            if (A[i] < 0 && !dq.empty())
            {
                dq.pop_front();
            }
            i++;
        }
        j++;
    }
    return result;
}




int main()
{

    return 0;
}