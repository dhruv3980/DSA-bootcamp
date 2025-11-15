#include<iostream>
#include<list>
#include<queue>
#include<vector>
using namespace std;

class Graph{
    int V; // total no. of vertices
    list <int>* l; // pointer to an array of lists

    public:
    Graph(int v){
        this->V=v;
        l = new list<int>[v];
    }

    void addedge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void printGraph(){
        for(int i=0; i<V; i++){
            cout<<i<<" -> ";

            list<int>p = l[i];
            for(int node : p){
                cout<<node<<", ";
            }
            cout<<endl;
        }
    }


    void BfsHelper(int src, vector<bool> &visited){
        queue<int> q;
        q.push(src);
        visited[src]=true;

        while(!q.empty()){
            int f = q.front();
            cout<<f<<", ";
            q.pop();

            for(int nbr : l[f]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr]=true;
                }
            }
        }
    }

    void Bfs(){
        vector<bool> visited(V, false);

        BfsHelper(0, visited);

        // for(int i=0; i<V; i++){
        //     if(!visited[i]){
        //         BfsHelper(i, visited);
        //     }
        // }
    }



    void DfsHelper(int src, vector<bool> &visited){
        cout<<src<<", ";
        visited[src]=true;

        for(int nbr : l[src]){
            if(!visited[nbr]){
                DfsHelper(nbr, visited);
            }
        }
    }

    void Dfs(){
        vector<bool> visited(V, false);

        DfsHelper(0, visited);

        // for(int i=0; i<V; i++){
        //     if(!visited[i]){
        //         DfsHelper(i, visited);
        //     }
        // }
    }


    bool hasPathHelper(int src, int dest, vector<bool> &visited){
        if(src==dest){
            return true;
        }

        visited[src]=true;

        for(int nbr : l[src]){
            if(!visited[nbr]){
                bool hasNbrPath = hasPathHelper(nbr, dest, visited);
                if(hasNbrPath){
                    return true;
                }
            }
        }
        return false;
    }

    bool hasPath(int src, int dest){
        vector<bool> visited(V, false);
        return hasPathHelper(src, dest, visited);
    }
};
int main(){

    Graph g(7);
    g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(1,3);
    
    g.addedge(2,4);
    g.addedge(3,4);
    g.addedge(3,5);
    g.addedge(4,5);
    g.addedge(5,6);


    g.printGraph();
    g.Bfs();

    cout<<endl;
    g.Dfs();

    cout<<endl;


    g.hasPath(0,8)? cout<<"Path exists"<<endl : cout<<"Path doesn't exist"<<endl;

}