// Minimum time to burn the entire tree-->
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        unordered_map<Node *,Node *>mp;
        queue<Node *>q;
        q.push(root);
        while(!q.empty())
        {
            
                Node * temp=q.front();
                q.pop();
                if(temp->left)
                {
                    mp[temp->left]=temp;
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    mp[temp->right]=temp;
                    q.push(temp->right);
                }
        }
        Node * targetnode;
        while(!q.empty())
        {
            q.pop();
        }
        q.push(root);
        while(!q.empty())
        {
            Node * temp=q.front();
            q.pop();
            if(temp->data==target)
            {
                targetnode=temp;
                break;
            }
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
        while(!q.empty())
        {
            q.pop();
        }
        q.push(targetnode);
        int sec=0;
        unordered_map<Node *,bool>vis;
        vis[targetnode]=true;
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                Node * temp=q.front();
                q.pop();
                if(temp->left && !vis[temp->left])
                {
                    q.push(temp->left);
                    vis[temp->left]=true;
                    
                }
                if(temp->right && !vis[temp->right])
                {
                    q.push(temp->right);
                    vis[temp->right]=true;
                    
                }
                
                if(mp[temp] && !vis[mp[temp]])
                {   
                    q.push(mp[temp]);
                    vis[mp[temp]]=true;
                    
                }
                
            }
            ++sec;
        }
        return sec-1;
    }
};
int main(){

return 0;
}