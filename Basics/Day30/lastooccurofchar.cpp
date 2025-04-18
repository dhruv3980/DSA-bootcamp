#include<iostream>
#include<vector>
#include<string>
#include <cstring>
using namespace std;
void ltr(string str , int& ans, int i, char& ch){
    if(i>=str.length()){
        return;
    }

    if(str[i]==ch){
        ans=i;
    }
    ltr(str, ans, i+1, ch);



}

void rtl(string& str, int i, int& ans , char&ch){
    if(i<0){
        return;
    }

    if(str[i]==ch){
        ans=i;
        return;
    }

    rtl(str,i-1, ans, ch);
}

int main(){
    string s ="abcddefdg";
    char ch = 'd';

    // here we find char using two function rtl and ltr;
    int ans = -1;
    int i=0;
    ltr(s, ans, i, ch);
    cout<<ans;

    int ans1=-2;
    rtl(s, s.size()-1, ans1,ch);

    cout<<"rtl ans "<<ans1;



    // built in function to find last occurence of char

    char* pos;
    
    pos = strrchr("abcddefdg", 'd');

    cout<<"last occurence is "<< (pos-"abcddefdg");

    





    
}