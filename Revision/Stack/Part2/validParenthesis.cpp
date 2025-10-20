#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool validParenthesis(string a){
    stack<char>s;

    for(int i=0; i<a.size(); i++){
        char current = a[i];

        if(current=='(' || current=='{' || current=='['){ // for opening brackets
            s.push(current);
        }
        else{ // for closing brackets
            if(s.empty()){
                return false;
            }

            char top = s.top();

            

            if(current==')' && top=='('  || current=='}' && top=='{' || current==']' && top=='['){
                s.pop();
            }
            else{
                return false;
            }


        }
    }



    return s.empty();

}
int main(){
    string ans = "()[]{}";

    string a = "([}])";

    cout<<validParenthesis(ans);
}