// dynamic memory allocation in 2d array
#include<bits/stdc++.h>
using namespace std;

int main(){
    int row;
    cin>>row;
    int col;
    cin>>col;
    int** arr=new int*[row];
    for(int i=0;i<row;i++){
        arr[i]=new int[col];
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
        }
    }
    cout<<endl;
        for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }
    // when the memory has been allocated then we have to release it 
    // in stack the memory got automatically deleted.
    // if we does not do so then it will create memory leakage.
    for(int i=0;i<row;i++){
        delete []arr[i];
    }
    delete []arr;

return 0;
}