// its a greedy type of question i tried using two pointer but the edge cases got failed.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
      if (n == 0) {
            return true;
        }
        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && (i == flowerbed.size()-1 || flowerbed[i+1] == 0)) {
                flowerbed[i] = 1;
                n--;
                if (n == 0) {
                    return true;
                }
            }
        }
        return false;
    }
};
int main(){

return 0;
}