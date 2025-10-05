#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class weakRow{
    public:
    int idx;
    int solider;

    weakRow(int a, int b){
        this->idx = a;
        this->solider=b;
    }

    bool operator < (const weakRow & obj) const{
        if(this->solider==obj.solider){
            return this->idx>obj.idx;
        }

        return this->solider>obj.solider;
    }
};

void printweakestrow(vector<vector<int>>m, int k){
    vector<weakRow>q;

    for(int i=0; i<m.size(); i++){
        int count=0;
        for(int j=0; j<m[i].size(); j++){
            if(m[i][j]==1){
                count++;
            }

        }
        q.push_back(weakRow(i, count));
    }

    priority_queue<weakRow>pq(q.begin(), q.end());

    for(int i=0; i<k; i++){
        cout<<"Row No is "<<pq.top().idx<<" and total no of soldier "<<pq.top().solider<<"\n";
        pq.pop();
    }


}
int main(){
    vector<vector<int>>m={ // here 1 for soldier and 2 for civilian 
        {1,0,0,0},
        {1,1,1,1},
        {1,0,0,0},
        {1,0,0,0}

        

    };
    printweakestrow(m,4);


}