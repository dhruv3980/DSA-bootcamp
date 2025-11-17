#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int>*l;

    public:

    Graph(int V){
        this->V=V;
        l = new list<int>[V];
    }

    void addEdge(int U, int V){
        l[U].push_back(V);
        l[V].push_back(U);
    }

    bool checkCycleHelper(int src, int parent, vector<bool>& visited){
        
        visited[src]=true;


        for(int nbh:l[src]){
            if(!visited[nbh]){
                bool cycleexist = checkCycleHelper(nbh, src, visited);
                if(cycleexist){
                    return true;
                }
            }else{
                if(nbh!=parent){
                    return true;
                }
            }

        }

        return false;

    }
    bool checkcycle(){
        vector<bool>visited(V, false);

        for(int i=0; i<V; i++){
            if(!visited[i]){
                if(checkCycleHelper(i, -1, visited)) return true;
            }
        }

        return false;
    }

};
int main(){

    Graph g(5);
    g.addEdge(1,0);
    g.addEdge(1,2); 
    g.addEdge(2,0);
    g.addEdge(0,3);
    g.addEdge(3,4);

    if(g.checkcycle()){
        cout<<"Cycle exists"<<endl; 
    }else{
        cout<<"Cycle does not exist"<<endl;
    }

}