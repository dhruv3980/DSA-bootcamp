#include<iostream>
#include<queue>

using namespace std;

class student{
    public:
    string name;
    int marks;


    student(string name, int marks){
        this->name = name;
        this->marks=marks;
    }

    bool operator< (const student& obj1) const{
        return this->marks<obj1.marks;
    }
};


struct compare{
    bool operator()(const pair<string, int>&p1, const pair<string, int>&p2)const{
        return p1.second>p2.second;

    }
};
int main(){
    priority_queue<student, vector<student>, less<student> >pq;

  

    pq.push(student("Dhruv", 40));
    pq.push(student("Aman", 50));
    pq.push(student("Karan", 30));


    while(!pq.empty()){
        cout<<"Top "<<pq.top().name<<" "<<pq.top().marks<<endl;

        pq.pop();
    }

    cout<<endl<<"second"<<endl;


    priority_queue<pair<string, int>, vector<pair<string, int>>, compare> p;

   
    p.push({"dh", 55});
    p.push({"aman", 75});
    p.push({"karan", 45});

    while (!p.empty()) {
        cout << p.top().first << " " << p.top().second << endl;
        p.pop();
    }
}