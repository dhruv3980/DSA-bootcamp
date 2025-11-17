#include<iostream>
#include<vector>
#include<string>
#include<list>
using namespace std;
class Graph{
    int V;
    list<int>* l;

    bool isUndirected;


    public:
    Graph(int V , bool isUndirected = true){
        this->V = V;
        l = new list<int>[V];
        this->isUndirected = isUndirected;
    }

    void addEdge(int U, int V){
        l[U].push_back(V);

        if(isUndirected){
            l[V].push_back(U);

        }

    }

    void pathHelper(int src, int dest, vector<bool>& visited, string &pathSoFar){

        if(src==dest){
            cout<<pathSoFar<<dest<<endl;
            return;
        }

        visited[src]=true;
        pathSoFar+=to_string(src);

        for(int nbr:l[src]){
            if(!visited[nbr]){
                pathHelper(nbr, dest, visited, pathSoFar);
            }
        }

        pathSoFar.pop_back();
        visited[src]=false;
    }
    void path(int src, int dest){
        vector<bool>visited(V, false);

        string path;

        pathHelper(src, dest, visited, path);

    }

};
int main(){

    Graph g(7, false);
    g.addEdge(5,0);
    g.addEdge(5,2);
    g.addEdge(2,3);
    g.addEdge(0,3);
    g.addEdge(3,1);
    g.addEdge(4,1);
    g.addEdge(4,0);

    g.path(5,1);

}