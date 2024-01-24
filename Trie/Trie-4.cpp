// An Important question to get your hands on trie data structures.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

// Its a Trie Data Structure question

vector<string>result;
int m,n;
vector<pair<int, int>> directions{{-1, 0},{1, 0},{0, 1},{0, -1}};

// making the struct node
struct trieNode{
    bool endOfWord;
    string word;
    trieNode* children[26];
};

// getnode
trieNode* getNode(){
    trieNode* newNode= new trieNode();
    newNode->endOfWord=false;
    newNode->word="";
    for(int i=0;i<26;i++){
        newNode->children[i]=NULL;
    }
    return newNode;
}

// function for inserting the word in the trie
void insert(trieNode* root,string word){
    trieNode* ghoom=root;
    for(char ch:word){
        if(ghoom->children[ch-'a']==NULL){
            ghoom->children[ch-'a']=getNode();
        }
        ghoom=ghoom->children[ch-'a'];
    }
    ghoom->endOfWord=true;
    ghoom->word=word;
}
void findwords(vector<vector<char>>& board,int i,int j,trieNode* root){
    if(i<0||i>=m||j<0||j>=n||board[i][j]=='$' ||root->children[board[i][j]-'a']==NULL){
        return;
    }
    // we are good to go
    root=root->children[board[i][j]-'a'];
    if(root->endOfWord==true){
        result.push_back(root->word);
        root->endOfWord=false;
    }
    char temp=board[i][j];
    board[i][j]='$';
    for(pair<int, int> p:directions) {
            int new_i = i+p.first;
            int new_j = j+p.second;
            findwords(board, new_i, new_j, root);
        }
        board[i][j] = temp;
}
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m=board.size();
        n=board[0].size();

        // root banana h
        trieNode* root=getNode();

        // insert toh kardo
        for(string& word:words){
            insert(root,word);
        }

        // traverse karna h ab bas
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                char ch=board[i][j];
                if(root->children[ch-'a']!=NULL){
                    findwords(board,i,j,root);
                }
            }
        }
        return result;
    }
};
int main(){

return 0;
}