#include<iostream>
#include<vector>
using namespace std;
void printallsubseq(string str, string ans , int i, vector<string>& v){
    if(i== str.length()){
       v.push_back(ans);
        return;
    }


    // include
    ans = ans+str[i];
    cout<<ans <<endl;
    printallsubseq(str,ans, i+1,v);
    
    // exclude

    printallsubseq(str,ans,i+1,v);

}
int main(){
    string input="abc";
    string ans ="";
    int i=0;
    vector<string>v;
    printallsubseq(input, ans,i,v);
    
    for(string val:v){
        cout<<val<<" ";
    }
    cout<<endl;
    cout<<"Size of the array " << v.size();

}