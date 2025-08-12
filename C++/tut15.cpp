#include<iostream>
using namespace std;


class Employee
{
    private:
    int a, b ,c;
    public:
    int d,e;
    void setData(int a1, int b1, int c1);
    void getData(){
        cout<<"the value of a is "<<a<<endl;
        cout<<"the value of b is "<<b<<endl;
        cout<<"the value of c is "<<c<<endl;
        cout<<"the value of d is "<<d<<endl;
        cout<<"the value of e is "<<e<<endl;}
   
};

void Employee :: setData(int a1, int b1, int c1){
    a =a1;
    b=b1;
    c=c1;
}
int main(){
    Employee abhishek;
   // abhishek.a=134;
    abhishek.d=34;
    abhishek.e=89;
    abhishek.setData(1,2,4);
    abhishek.getData();


    return 0;
}