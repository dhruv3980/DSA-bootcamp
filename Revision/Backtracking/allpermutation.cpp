#include<iostream>
#include<vector>
using namespace std;

void printAllString(string s, string ans){
    int n= s.size();

   

    if(n==0){
      
        cout<<ans<<" ";

        cout<<endl;
    }

    for(int i=0; i<n; i++){
        char current = s[i];

        string restString = s.substr(0, i)+s.substr(i+1);

        printAllString(restString, ans+current);
    }
   

    

}
int main(){
    string s = "abc";

    printAllString(s, "");
}