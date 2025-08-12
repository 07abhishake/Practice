#include<iostream>
using namespace std;

int main(){

    int a=3;
    int*b=&a;
    cout<<b<<endl;
    cout<<"the value at address b is "<<*b<<endl; 
    return 0;

}