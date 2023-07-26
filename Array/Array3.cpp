// question 2 we have to sum all the elements of an array
#include<bits/stdc++.h>
using namespace std;

int sumarr(int arr[],int size){
    int sum=0;
    for (int i = 0; i < size; i++)
    {
        sum=sum+arr[i];
    }
    return sum;
    
}
int main(){
    int one[9]={2,3,4,2,1,4,4,2,3};
    cout<<"the sum of the entire one array is: "<<sumarr(one,9)<<endl;

return 0;
}