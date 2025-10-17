#include<iostream>
using namespace std;

void printAllSubsets(string a, string ans, int i){

    if(a.size()==i){
        cout<<ans<<" ";
        cout<<1<<endl;

        return;
    }
    

    printAllSubsets(a, ans+a[i], i+1);
    printAllSubsets(a, ans, i+1);
}
int main(){
    string a="abc";

    printAllSubsets(a, "",0);
}