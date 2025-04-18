#include<iostream>
using namespace std;
void swap1(string& str , int start, int end){
    if(start>=end){
        return;
    }
    swap(str[start], str[end]);

    swap1(str, start+1, end-1);
}
int main(){
    string s ="abcd";

    swap1 (s, 0, s.length()-1);
    cout<<s;

}