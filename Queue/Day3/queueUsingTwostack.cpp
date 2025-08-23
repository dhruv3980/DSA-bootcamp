#include<iostream>
#include<stack>
using namespace std;
class queue{
    stack<int>s1;
    stack<int>s2;

    public:
        void push(int data){
            // for pushing first copy all the element of s1 into s2
            // then push the current element you want to push
            // now again push the element in the s2 into s1

            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }

            s1.push(data);

            while(s2.size()>0){
                s1.push(s2.top());
                s2.pop();
            }


        }
        void pop(){
            if(isEmpty()){
                cout<<"Stack is empty ";
            }
            s1.pop();

        }
        int top(){
             if(isEmpty()){
                cout<<endl<<"empty ha stack"<<endl;
                return -1;
            }
            
            return s1.top();

        }

        bool isEmpty(){
            return s1.empty();

        }


};
int main(){

    queue q;

    q.push(1);
    q.push(2);
    q.push(3);

    while(!q.isEmpty()){
        cout<<q.top()<<" ";
        q.pop();
    }
    


}