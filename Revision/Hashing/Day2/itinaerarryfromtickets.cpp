#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;

void printTrip(unordered_map<string, string>city){
    unordered_set<string>a;

    for(auto it:city){
        a.insert(it.second);
    }

    string start;

    for(auto it : city){
        if(a.find(it.first)==a.end()){
            start = it.first;

        }

    }

    // now print city

    cout<<start<<" -> ";

    while(city.find(start)!=city.end()){
        cout<<city[start]<<" -> ";

        start = city[start];




    }

}
int main(){
    unordered_map<string, string>city;

    city["Chennai"]="Bengluru";

    city["Mumbai"]="Delhi";

    city["Goa"]="Chennai";

    city["Delhi"] = "Goa";

    printTrip(city);
}