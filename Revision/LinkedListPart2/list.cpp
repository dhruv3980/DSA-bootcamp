#include<iostream>
#include<list>
using namespace std;
int main(){
    list<int>ll;

    list<int> :: iterator it;

    ll.push_front(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);

    it=ll.begin();
    advance(it, 5); 

    

   

   
    ll.insert(it, 2, 8);

    for( it=ll.begin(); it!=ll.end(); it++){
        cout<<*it<<"->";

    }
    cout<<"NULL";
    
    
}