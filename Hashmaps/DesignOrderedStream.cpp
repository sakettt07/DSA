#include<bits/stdc++.h>
using namespace std;
class OrderedStream {
    vector<string> buffered;
    int sendIdx;

public:
    OrderedStream(int n) {
        buffered.resize(n);
        sendIdx = 0; // starting from this (inclusive)
    }

    vector<string> insert(int idKey, const string& value) {
        buffered[idKey - 1] = value;

        if (buffered[sendIdx].size() == 0)
            return {}; // chunk not completed, yet

        // we have a portion of complete chunk, send it
        vector<string> sentBuffer;
        while (sendIdx < buffered.size() && buffered[sendIdx].size() > 0)
            sentBuffer.push_back(buffered[sendIdx++]);
        return sentBuffer;
    }
};
int main(){
    OrderedStream os(5);
    cout<<os.insert(3,"ccccc").size()<<endl; // Inserts (3, "ccccc"), returns [].
    cout<<os.insert(1,"aaaaa").size()<<endl; // Inserts (1, "aaaaa"), returns ["aaaaa"].
    cout<<os.insert(2,"bbbbb").size()<<endl; // Inserts (2, "bbbbb"), returns ["bbbbb", "ccccc"].
    cout<<os.insert(5,"eeeee").size()<<endl; // Inserts (5, "eeeee"), returns [].
    cout<<os.insert(4,"ddddd").size()<<endl; // Inserts (4, "ddddd"), returns ["ddddd", "eeeee"].
return 0;
}