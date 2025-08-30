#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// bool compare(pair<int, int>p1, pair<int, int>p2){
//     return p1.second>p2.second;
// }

// int maxProfit (vector<pair<int, int>> &jobs){
//     int profit =0;

//     sort(jobs.begin(), jobs.end(), compare);

//     int safeDeadline = 1;
//     profit+=jobs[0].second;

//     for(int i=1; i<jobs.size(); i++){
//         if(jobs[i].first>safeDeadline){
//             profit+=jobs[i].second;
//             safeDeadline++;
//         }
//     }

//     cout<<"max profit from jobs "<<profit;

// }


class job{
    public:
    int idx;
    int profit;
    int deadline;

    job(int idx, int profit, int deadline){
        this->idx =idx;
        this->deadline=deadline;
        this->profit=profit;
    }
};

int maxProfit(vector<pair<int,  int>> & pairs){
    vector<job>Jobs;

    for(int i=0; i<pairs.size(); i++){
        Jobs.emplace_back(i, pairs[i].second, pairs[i].first);
    }

   



    sort(Jobs.begin(), Jobs.end(), [](job &a , job &b){
        return a.profit > b.profit;
    });

    int Profit =Jobs[0].profit;
    int jobdeadline = 1;
    cout<<"job "<<Jobs[0].idx <<" selected" <<endl;
    
    for(int i=1; i<Jobs.size(); i++){
        
        
        if(Jobs[i].deadline>jobdeadline){
            
            jobdeadline++;
            Profit+=Jobs[i].profit;
            cout<<"job "<<Jobs[i].idx<<" selected" <<endl;;
        }

    }


    cout<<"max profit from jobs "<<Profit<<endl;
    return Profit;


 };


int main(){
    vector<pair<int, int>> jobs;

    jobs.push_back(make_pair(2,20));
    jobs.push_back(make_pair(1,10));
    jobs.push_back(make_pair(4,40));
    jobs.push_back(make_pair(1,30));

    maxProfit(jobs);

}