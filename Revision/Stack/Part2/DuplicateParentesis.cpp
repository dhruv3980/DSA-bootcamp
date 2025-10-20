#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool DuplicateParenthesis(string a){
    stack<char> ans;

    for(int i=0; i<a.size(); i++){
        if(a[i]!=')'){
            ans.push(a[i]);
        }else{
            if(ans.top()=='('){
                return true;
            }

            while(ans.top()!='('){
                ans.pop();

            }

            ans.pop();

            
        }
    }

    return false;

}
int main(){
    string a ="((x+y)+(z))";

    cout<<DuplicateParenthesis(a);
}