#include<iostream>
#include<queue>
using namespace std;
class stack{
    queue<int>q1;
    queue<int>q2;
    public:
        void push(int data){
            // first we move all the element present in q1 move to q2
            // second now push data into the front
            // thirs now push all the element of q2 into q1

            while(!q1.empty()){
                
                q2.push(q1.front());
                q1.pop();
            }
            
            q1.push(data);

            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }

        }
        void pop(){
            if(q1.empty()){
                cout<<"stack is empty";
                return;
            }

            q1.pop();

        }
        int front(){
            if(q1.empty()){
                
                return -1;
            }

            return q1.front();


        }
        bool isEmpty(){
            return q1.empty();

        }

};
int main(){
    stack s;

   s.push(1);
   s.push(2);
   s.push(3);

   while(!s.isEmpty()){
    cout<<s.front()<<" ";
    s.pop();
   }

}