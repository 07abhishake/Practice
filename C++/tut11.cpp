#include<iostream>
using namespace std;

typedef struct employee
{
    int eid;
    char favchar;
    float salary;
}ep;

int main(){
    ep abhishek;
    abhishek.eid=34;
    abhishek.favchar='A';
    abhishek.salary=500000;
    cout<<"the value of : "<<abhishek.eid<<endl;
    cout<<"the value of : "<<abhishek.favchar<<endl;
    cout<<"the value of : "<<abhishek.salary<<endl;
    
    return 0;
}