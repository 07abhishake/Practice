#include <iostream>
using namespace std;


 int sum(int a, int b){
    int c= a+b;
    return c;

}
void swap(int a, int b){
    int temp=a;
    a = b;
    b = temp;
} 
void swapReferenceVar(int&a, int&b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    int x =4, y=5;
    cout<<"the value of x is "<<x<<"and the value of y is "<<y<<endl;
    swapReferenceVar(x, y);
    cout<<"the value of x is "<<x<<"and the value of y is "<<y<<endl;


    return 0 ;
}