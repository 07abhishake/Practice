# include<iostream>
using namespace std;

int main(){
    int arr [7]={1,2,3,4,5,1,3};
     for ( int i = 0; i <6; i++)
     {
        /* code */
        if(  arr[i + 1]  > arr[i]  ){
         cout<<"True"<<endl;
        }else{cout<<"false"<<endl;}}

        return 0;
     


}