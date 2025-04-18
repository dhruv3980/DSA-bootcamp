#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    string s="abcd";
    vector<string>v;
    for(int i=0; i<s.length(); i++){
        string ans="";
        for(int j=i; j<s.length(); j++){
            ans+=s[j];
            v.push_back(ans);
            
           

        }
        
    }
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<endl;
    }
}