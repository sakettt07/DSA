#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string check ="";
        string confirm ="";
        for(int i=0;i<word1.size();i++){
            check=check+word1[i];
        }
        for(int i=0;i<word2.size();i++){
            confirm=confirm+word2[i];
        }
        return check==confirm;
    }
};
int main(){

return 0;
}