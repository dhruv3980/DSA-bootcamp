#include<iostream>
#include<string>
using namespace std;
int findstr(string s,string part){
    for(int i=0; i<=s.length()-part.length(); i++){
        int j;
        for( j=0; j<part.length();j++){
            if(s[i+j]!=part[j]){
                break;
            }
        }
        if(j==part.length()){
            return i;
        }
        
        
    }
    return -1;

}

int main(){
    string s="daabcbaabcbc";
    string part="abc";




    int n =findstr(s,part);

    

    cout<<n;
}