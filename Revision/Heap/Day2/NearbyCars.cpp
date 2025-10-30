#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class cars{ // here we stored distance and the idx
public:
int dist;
int idx;

    cars(int x, int y, int idx){
        dist = x*x+y*y;
        this->idx = idx;
    }

    bool operator< (const cars &p) const{
        return this->dist>p.dist;

    }

};

void NearestCars(vector<pair<int, int>>v, int k){
    vector<cars>a;

    for(int i=0; i<v.size(); i++){
        a.emplace_back(v[i].first,v[i].second, i);
    }

    priority_queue<cars>pq(a.begin(), a.end());

    for(int i=0; i<k; i++){
        cout<<"Car at "<<pq.top().idx<<" th pos"<<endl;
        pq.pop();
    }

}
int main(){
    vector<pair<int, int>>v={ // first is the x cordinate and second is the y cordinate
        {3,3}, {5,-1}, {-2,4}

    };

    NearestCars(v, 2);

}