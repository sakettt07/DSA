// creating a jagged array.
// it is a array of irregular shape
#include<bits/stdc++.h>
using namespace std;

int main(){
    int row,col;
    row=3;
    int** arr=new int*[row];
    int sizes[]={4,2,3};
    for(int i=0;i<row;i++){
        cin>>col;
        sizes[i]=col;
        *(arr+i)=new int[sizes[i]];
    }
    int num=1;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            cin>>arr[i][j];
            arr[i][j] = num++;
        }
    }
  
    cout << "elements in matrix form as follow" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

return 0;
}