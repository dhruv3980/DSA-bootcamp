#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
bool anagram(string s, string p){
    if(s.size()!=p.size()){
        return false;
    }

    unordered_map<char, int>m;

    for(int i=0; i<s.size(); i++){
        if(m.count(s[i])){
            m[s[i]]++;
        }
        else{
            m[s[i]]=1;
        }
    }

    for(int i=0; i<p.size(); i++){
        if(m.count(p[i])){
            m[p[i]]--;

            if(m[p[i]]==0){
                m.erase(p[i]);
            }


        }
        else{
            return false;
        }
    }

    return m.size()==0;


}
int main(){
    string s="poatto";
    string p="potato";

    cout<<anagram(s, p);
}