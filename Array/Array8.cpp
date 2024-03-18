// Three array based question its a type of 2d array but not exactly like that .
// Q1 - Insert Intervals.
// Q2- Merge Intervals.
// Q3- Minimum Number of Arrows to Burst Balloons.
#include <bits/stdc++.h>
using namespace std;


// solution to the 1st
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        for(auto&& i:intervals){
            if(i[1]<newInterval[0]) ans.push_back(i);
            else if(newInterval[1]<i[0]){
                ans.push_back(newInterval);
                newInterval=i;//updating the new interval
            }
    // the new interval is in the range of the other interval
            else{
                newInterval[0]=min(newInterval[0],i[0]);
                newInterval[1]=max(newInterval[1],i[1]);
            }    
        }
    //At the end after the loop just add the updated newIntervals
        ans.push_back(newInterval);
        return ans;
        
    }
};


// Solution to the 2nd
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            int start=intervals[i][0];
            int end=intervals[i][1];
            if(!ans.empty() && end<=ans.back()[1]){
                continue;
            }
            for(int j=i+1;j<n;j++){
                if(intervals[j][0]<=end){
                    end=max(end,intervals[j][1]);
                }
                else{
                    break;
                }
            }
            ans.push_back({start,end});
        }  
        return ans; 
    }
};

// solution to the-3rd
bool cmp ( vector<int> &a, vector<int>&b ){
        return a[1]<b[1];
    }
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        int ans=1;
        int mid=points[0][1];
        for(int i=1;i<points.size();i++){
            if(mid<points[i][0]){
                ans++;
                mid=points[i][1];
            }
        }
        return ans;
    }
};
int main(){

return 0;
}