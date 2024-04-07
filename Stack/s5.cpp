// Stack POTD LC question---
// For continuosly 5 days we are gettting godd stack questions on LC
// Q1---Maximum nesting depth of the Parenthesis.
// Q2----Valid Parenthesis String
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
// using stack easiest apprroach.
    int maxDepth(string s) {
        stack<int>st;
        int maxii=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')st.push(s[i]);
            else if(s[i]==')')st.pop();
            maxii=max(maxii,(int)st.size());
        }
        return maxii;
    }
};

// solution for the second
class Solution {
public:
    bool checkValidString(string s) {
        stack<int>para;
        stack<int>star;
        for(int i=0;i<s.length();i++){

            // pushing the index of the element
            if(s[i]=='('){
                para.push(i);
            }
            // pushing the elements index in star stack
            else if(s[i]=='*'){
                star.push(i);
            }
            // main driver condition
            else if(s[i]==')'){
                if(para.empty()&&star.empty()){
                    return false;
                }
                else if(!para.empty()){
                    para.pop();
                }
                else{
                    star.pop();
                }
            }
        }
        // iterating in the index stack for comparing the index value if greater that means the closing bracket is after the star
        while(!para.empty())
        {
            if(star.empty()) return false;
            if(para.top() > star.top()) return false;
            para.pop();
            star.pop();
        }

        return true;

    }
};
int main(){

return 0;
}