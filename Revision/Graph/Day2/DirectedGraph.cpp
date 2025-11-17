#include<iostream>
#include<vector>
#include<list>
using namespace std;
class Graph{
    int V;
    list<int>*l;
    bool isUndirected;
    public:

    Graph(int V, bool isUndirected=true){
        this->V=V;
        l=new list<int>[V];
        this->isUndirected=isUndirected;
    }

    void addEdge(int U, int V){
        l[U].push_back(V);
        if(isUndirected){
            l[V].push_back(U);  
        }

    }


    bool checkCycleHelper(int src, vector<bool>& visited,  vector<bool>&path){
        visited[src]=true;

        path[src]=true;

        for(int nbr:l[src]){
            if(path[nbr]==true){
                return true;
            }else{
                if(!visited[nbr]){
                    bool cycleMila = checkCycleHelper(nbr, visited, path);

                    if(cycleMila){
                        return true;
                    }
                }
            }
        }

        path[src]=false;

        return false;
    }


    bool checkCycle(){
        vector<bool>visited(V, false);
        vector<bool>path(V, false);

        for(int i=0; i<V; i++){
            if(!visited[i]){
                bool cycleMila= checkCycleHelper(i, visited, path);
                if(cycleMila){
                    return true;
                }
            }
        }

        return false;
    }


};

int main(){

    Graph g(4, false);
    g.addEdge(1,0);
    g.addEdge(2,0);
    g.addEdge(3,2);
    g.addEdge(0,3);


    if(g.checkCycle()){
        cout<<"Cycle Present"<<endl;
    }
    else{
        cout<<"No Cycle Present"<<endl;
    }   


   

}