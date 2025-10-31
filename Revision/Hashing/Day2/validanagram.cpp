#include<unordered_map>
#include<iostream>
using namespace std;

bool validAnagram(string s, string a){
    if(a.size()!=s.size()){
        return false;
    }

    unordered_map<char, int>m;  // first one stored the char and second one stored the freq

    for(auto  it:s){
        if(m.count(it)){
            m[it]++;

        }else{
            m[it]=1;
        }
    }

    for(auto it:a){
        if(m.find(it)==m.end()){ // not exist

            return false;

        }
        else{
            m[it]--;

            if(m[it]==0){
                m.erase(it);
            }
        }

    }

    return m.size()==0;
}
int main(){

    cout<<"Print true or false for the valid anagram ans is "<< validAnagram("tulip", "lipid");

}