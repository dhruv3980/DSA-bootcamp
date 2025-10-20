#include<iostream>
#include<stack>
using namespace std;

// void pushATBottom(stack<int> & s, int data){
//     if(s.empty()){
//         s.push(data);
//         return;
//     }

//     int top =s.top();
//     s.pop();

//     pushATBottom(s, data);

//     s.push(top);
// }
class queue{
    public:
    stack<int>s;

    stack<int> s2;

    void push(int data){

        // pushATBottom(s,data);

        while(!s.empty()){
            int top = s.top();
            s.pop();
            s2.push(top);
        }

        s.push(data);

        while(!s2.empty()){
            int top = s2.top();
            s2.pop();
            s.push(top);

        }



    }

    void pop(){

        if(s.empty()){
            cout<<"queue is empty";
            return;
        }
        s.pop();
    }

    int front(){
         if(s.empty()){
            cout<<"queue is empty";
            return -1;
        }

        return s.top();

    }
    bool isempty(){

        return s.empty();

    }
    
};
int main(){

    queue q;
    q.push(1);
    q.push(2);
    q.push(3);

    while(!q.isempty()){
        cout<<q.front()<<" ";
        q.pop();
    }

    q.pop();

  

}