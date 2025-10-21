#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Job{
    public:
    int idx;
    int deadline;
    int profit;

    Job(int deadline, int profit, int idx){
        this->deadline = deadline;
        this->profit = profit;
        this->idx =idx;


    }
};

int jobsequencing(vector<pair<int, int>> pairs){
    vector<Job>jobs;

    for(int i=0; i<pairs.size(); i++){
        jobs.emplace_back(pairs[i].first, pairs[i].second, i);
    }

    sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b ){
        return a.profit>b.profit;

    });
    
    int profit=jobs[0].profit;
    cout<<"Job select"<<jobs[0].idx<<endl;
    int safedeadline = 2;

    for(int i=1; i<jobs.size(); i++){

        if(jobs[i].deadline>safedeadline){
            cout<<"job select"<<jobs[i].idx<<endl;
            profit+=jobs[i].profit;
            safedeadline++;

        }

    }

    return profit;

};
int main(){

    vector<pair<int, int>>pairs;

    pairs.push_back(make_pair(4,20));
    pairs.push_back(make_pair(1,10));

    pairs.push_back(make_pair(1,40));
    pairs.push_back(make_pair(1,30));

    int ans=jobsequencing(pairs);
    cout<<ans;
}