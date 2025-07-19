#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int N;
    long dp[101][101];
    const int MOD = 1e9+7;
    
    long solve(int count_Playlist_song, int count_unique_songs,int goal,int k) {
        //base cases
        
        if(count_Playlist_song == goal) {
            if(count_unique_songs == N)
                return 1;
            
            return 0;
        }
        
        if(dp[count_Playlist_song][count_unique_songs] != -1)
            return dp[count_Playlist_song][count_unique_songs];
        
        long result = 0;
        
        //Option-1 (Play a unique song)
        if(count_unique_songs < N)
            result += (N-count_unique_songs) * solve(count_Playlist_song+1, count_unique_songs+1,goal,k);
        
        //Option-2 (Replay a song)
        if(count_unique_songs > k)
            result += (count_unique_songs - k) * solve(count_Playlist_song+1, count_unique_songs,goal,k);
        
        
        return dp[count_Playlist_song][count_unique_songs] = result % MOD;

    }
    
    int numMusicPlaylists(int n, int goal, int k) {
        N= n;
        //memoize.
        memset(dp, -1, sizeof(dp));
        return solve(0, 0,goal,k); 
    }
};

int main(){
    Solution s1;
    int n = 3, goal = 3, k = 1; 
    int result = s1.numMusicPlaylists(n, goal, k);
    cout << "Number of Music Playlists: " << result << endl; // Output the result
return 0;
}