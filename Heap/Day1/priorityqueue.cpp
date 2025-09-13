#include<iostream>
#include<queue>
using namespace std;

class student{
    public:
    string name;
    int marks;

    student(int marks, string name){
        this->marks= marks;
        this->name=name;
    }

    bool operator < (const student &obj) const{
        return this->marks<obj.marks;

    }
};
int main(){

    priority_queue<student> pq;
    pq.push(student(11,"neha"));
    pq.push(student(18,"papaya"));
    pq.push(student(5,"gita"));
    pq.push(student(31,"sia"));
    pq.push(student(41,"hia"));

    while(!pq.empty()){
        cout<<pq.top().marks<<"-"<<pq.top().name<<" ";
        pq.pop();
    }
}