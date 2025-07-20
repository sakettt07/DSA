// Bus_Route -  
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target){
            return 0;
        }
        // adjacency list
        unordered_map<int,vector<int>>adj;
        for(int route=0;route<routes.size();route++){
            for(auto& stop:routes[route]){
                adj[stop].push_back(route);
            }
        }
        // BFE code
        queue<int>q;
        vector<bool>visited(501,false);
        // push all the source routes in queue
        for(auto& route:adj[source]){
            q.push(route);
            visited[route]=true;
        }
        int busUsed=1;   // initially we will be taking atleast one bus

        while(!q.empty()){
            int size=q.size();
            while(size--){
                int top=q.front();
                q.pop();

                // now check at top route which all stops are there
                for(auto& stop :routes[top]){
                    if(stop==target){
                        return busUsed;
                    }
                    for(auto&nextRoute:adj[stop]){
                        if(visited[nextRoute]==false){
                            visited[nextRoute]=true;
                            q.push(nextRoute);
                        }
                    }
                }
            }
            busUsed++;
        }
        return -1;
    }
};
int main(){
    Solution s1;
    vector<vector<int>> routes = {{1, 2, 7}, {3, 6, 7}};
    int source = 1, target = 6;
    int result = s1.numBusesToDestination(routes, source, target);
    cout << "Number of buses needed: " << result << endl; // Output the result

return 0;
}