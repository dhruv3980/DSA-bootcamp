#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
void printIternary(unordered_map<string, string>tickets){
    unordered_set<string>m;

    for(auto el:tickets){
        m.insert(el.second);
    }

   

    string start="";

    for(auto el:tickets){
        if(m.find(el.first)==m.end()){
            start = el.first;

            

        }
    }

    // now print 

    cout<<start<<"->";

    while(tickets.count(start)){
        cout<<tickets[start]<<"->";
        start=tickets[start];
    }
    cout<<"Destination\n";
}
int main(){
    unordered_map<string , string>tickets;

    tickets["Chennai"] = "Bangluru";
    tickets["Mumbai"]="Delhi";
    tickets["Goa"] = "Chennai";
    tickets["Delhi"]="Goa";

    printIternary(tickets);


}