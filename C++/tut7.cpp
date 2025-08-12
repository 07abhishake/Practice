# include<iostream>

using namespace std;


int main(){
    int age;
   /*cout<<"hello world"<<endl;
   int age;
   cout<<"tell me your age"<<endl;
   cin>>age;
   if(age<18){
    cout<<"You can not come to party"<<endl;
    
   }else if(age==18){
    cout<<"u are a kid you can get kid pass"<<endl;
   }else{ 
    cout<<"u can come to the party"<<endl;
   }*/
cout<<"tell me your age"<<endl;
   cin>>age;
  switch (age)
  {
  case 18:
    /* code */
    cout<<"your are 18"<<endl;
    break;
    case 22:
    /* code */
    cout<<"your are 22"<<endl;
    break;

    case 12:
    /* code */
    cout<<"your are 12";
    break;
  
  default:
  cout<<"you are 2 "<<endl; 
    break;
  }
   
    return 0 ;
}
