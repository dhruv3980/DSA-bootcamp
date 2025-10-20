#include<iostream>
#include<queue>
using namespace std;
void NonRepeatingLetter(string a){
    int arr[26]={0};
    queue<char>q;

    for(int i=0; i<a.size(); i++){
        arr[a[i]-'a']++;
        q.push(a[i]);

        while(!q.empty() && arr[q.front()-'a']>1){
            q.pop();
        }

        if(q.empty()){
            cout<<-1<<endl;
        }
        else{
            cout<<q.front()<<endl;
        }
    }
}
int main(){
    string a = "aabccxb";

    NonRepeatingLetter(a);

}