#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Car{

    public:
    int idx;
    int distance;

    Car(int idx, int distance){
        this->idx =idx;
        this->distance=distance;

    }

    bool operator<(const Car & obj) const{

        return this->distance>obj.distance;
    }
};



void knearsetcars(vector<pair<int, int>>p , int k){

    vector<Car> a;

    

    for(int i=0; i<p.size(); i++){
          

      int first= p[i].first*p[i].first + p[i].second*p[i].second;
      int second =i;

        Car b(second,first);
        a.push_back(b);

       


    }
    priority_queue<Car>q(a.begin(), a.end());

    for(int i=0; i<k; i++){
         cout << "Car at " <<q.top().idx<< " distance = " << q.top().distance << endl;
        q.pop();
    }
    
}
int main(){
    vector<pair<int, int>> p;

    p.push_back({3,3});
    p.push_back({5,-1});
     p.push_back({1,4});

    p.push_back({-2,4});

    knearsetcars(p, 3);
    
}