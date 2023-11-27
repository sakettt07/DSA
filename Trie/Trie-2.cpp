// in this file i have find the longest common prefix from the array of strings
// for eg{coding,coder,codingninja} so here cod is same in all the three strings so the ans is cod
#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
        char data;
    TrieNode *children[26];
    int childcount;
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};
class Trie{
    public:
    TrieNode *root;
    Trie(char ch){
        root=new TrieNode(ch);
    }
    void insertutil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->childcount++;
            root->children[index] = child;
        }

        insertutil(child, word.substr(1));
    }
    void insertword(string word)
    {
        insertutil(root, word);
    }
    void lcp(string str,string ans){
        for(int i=0;i<str.length();i++){
            char ch=str[i];
            if(root->childcount==1){
                ans.push_back(ch);
                int index=ch-'a';
                root=root->children[index];
            }
            else{
                break;
            }
            if(root->isTerminal){
                break;
            }
        }

    }
};



string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    Trie *t=new Trie('\0');
    for(int i=0;i<n;i++){
        t->insertword(arr[i]);
    }
    string first=arr[0];
    string ans="";
    t->lcp(first,ans);
}



int main(){

return 0;
}