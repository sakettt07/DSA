// questions on heappsss

// Two of the most popular questions on heaps are 
// Find the kth largest and the smallest element in the array
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // For the largest element we have used min heap
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i=0;i<k;i++)
        {
            pq.push(nums[i]);
        }

        for(int i=k;i<nums.size();i++)
        {
            if(nums[i]>pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }

        int ans=pq.top();
        return ans;
        
    }
    int kthSmallest(int arr[], int l, int r, int k) {
        //fotr the smallest element we have used max heap 
        priority_queue<int>pq;
        for(int i=0;i<k;i++){
            pq.push(arr[i]);
        }
        for(int i=k;i<=r;i++){
            if(arr[i]<pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        int ans=pq.top();
        return ans;
        
    }
};
int main(){

return 0;
}