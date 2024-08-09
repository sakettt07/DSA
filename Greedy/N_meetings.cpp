#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    bool static comp(pair<int, int> &el1, pair<int, int> &el2){
        return el1.second < el2.second || ( el1.second == el2.second && el1.first <= el2.first);
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        // writing the greedy appraoch
        vector<pair<int,int>>vpp;  // we will be storing the strt and the end time 
        // and on the basis of end time we will distribute the meetings.
        for(int i=0;i<n;i++){
            vpp.push_back({start[i],end[i]});
        }
        sort(vpp.begin(),vpp.end(),comp);
        int totalMeet=1;  //one will always be there
        int endtime=vpp[0].second;
        for(int i=1;i<n;i++){
            if(vpp[i].first>endtime){
                totalMeet++;
                endtime=vpp[i].second;
            }
        }
        return totalMeet;
        
    }
};
int main(){

return 0;
}