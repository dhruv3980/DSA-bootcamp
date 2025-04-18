#include<iostream>
#include<string>
using namespace std;
bool compares(string str,string str2){
    if(str.length()!=str2.length()){
        return false;

    }
    int j=0;
    int i=0;
    while(i<str.length()){
        if(str[i]==str2[j]){
            i++;
            j++;
        }
        else{
            return false;
        }
    }
    return true;
   
}
int main(){
    // string str;
    // getline(cin,str);
    // cout<<str<<endl;
    // char arr[10];
    // arr[0]='d';
    // arr[1]='p';
    
    // arr[2]='\0';
    // arr[3]='a';

    // for(int i=0 ; i<5; i++){
    //     cout<<arr[i]<<"";
    // }
    // cout<<arr[2];

    string str;
    string str2;
    getline(cin,str);
    getline(cin,str2);
    cout<<compares(str,str2);



}