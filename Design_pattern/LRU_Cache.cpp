#include<bits/stdc++.h>
using namespace std;
class LRUCache {
public:
// optimal method using Doubly linked list
// list address is written as iterator
list<int>dll;
map<int,pair<list<int>::iterator,int>>mp;
int n;
    LRUCache(int capacity) {
        n=capacity;
    }
    void makeRecentlyUsed(int key){
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first=dll.begin();
    }
    int get(int key) {
        // if key is not present inside the map
        if(mp.find(key)==mp.end()){
            return -1;
        }
        // if we find the kind return the value and make is recently used
        makeRecentlyUsed(key);
        return mp[key].second;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            mp[key].second=value;
            makeRecentlyUsed(key);
            return ;
        }
        dll.push_front(key);
        mp[key]={dll.begin(),value};
        n--;
        if(n<0){
            int key_to_deleted=dll.back();
            mp.erase(key_to_deleted);
            dll.pop_back();
            n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main(){
    LRUCache* obj = new LRUCache(2);
    obj->put(1, 1);
    obj->put(2, 2);
    cout << obj->get(1) << endl; // returns 1
    obj->put(3, 3);              // evicts key 2
    cout << obj->get(2) << endl; // returns -1 (not found)
    obj->put(4, 4);              // evicts key 1
    cout << obj->get(1) << endl; // returns -1 (not found)
    cout << obj->get(3) << endl; // returns 3
    cout << obj->get(4) << endl; // returns 4

    
return 0;
}