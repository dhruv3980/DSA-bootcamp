#include<iostream>
#include<string>
using namespace std;

void RemoveDuplicate(string s, int idx, string ans, int map[]){
    if(s.size()==idx){
        cout<<ans<<endl;
        return;
    }

    int a = (int)(s[idx]-'a');
    
    
    if(map[a]==true){
        
        RemoveDuplicate(s, idx+1, ans, map);

    }else{
        map[a]=true;
        RemoveDuplicate(s, idx+1, ans+s[idx], map);
    }


}
int main(){
    int arr[26]={false};

  
    RemoveDuplicate("apnnacollege", 0, "", arr);

}