# include <iostream>
using namespace std;

int main(){
    int marks[4]={23,45,56,89};
    int mathmarks[4];
    mathmarks[0]=23;
    mathmarks[1]=33;
    mathmarks[2]=43;
    mathmarks[3]=53;
    cout<<"this marks"<<endl;
    cout<<marks[0]<<endl;
    cout<<marks[1]<<endl;
    cout<<marks[2]<<endl;
    cout<<marks[3]<<endl;
    for(int i = 0; i<4; i++){
        cout<<"the value of marks "<<i<<" is "<<marks[i]<<endl;
    }
    


    return 0;

}