#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<string, int>m;
    m["china"] = 189;
    m["india"] = 25;
    m["Us"] = 85;

    for(pair<string , int> a:m){
        cout<<a.first<<" ,"<<a.second<<endl;
    }

    // cout function return 1 if value exist otherwise give 0

    if(m.count("chi a")){
        cout<<"exist";
    }

    // if eraseany vaue then use erase method


     m.erase("india");
    if(m.count("india")){
        cout<<"exist";
    }

}

// map and unordered map in map element store in the ordered form while in unordered map there will no order
