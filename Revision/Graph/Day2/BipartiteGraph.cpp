#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int V;
    list<int>* l;
    bool isUndirected;

    public:
    Graph(int V, bool isUndirected = true){
        this->V = V;
        l = new list<int>[V];
        this->isUndirected = isUndirected;
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        if(isUndirected){
            l[v].push_back(u);
        }
    }


    bool isBipartite(int src, vector<int>& colorArr){
        colorArr[src]=0;

        queue<int>q;
        q.push(src);

        while(q.size()>0){
            int front = q.front();
            q.pop();

            list<int>p = l[front];

            for(int nbr:p){
                if(colorArr[nbr]==-1){
                    colorArr[nbr]=!colorArr[front];
                    q.push(nbr);
                }else{
                    if(colorArr[nbr]==colorArr[front]){
                        return false;
                    }
                }
            }
            


        }
        return true;
    }

    bool isBipartiteHelper(){
        vector<int>colorArr(V, -1);

        for(int i=0;i<V;i++){
            if(colorArr[i]==-1){
                if(!isBipartite(i, colorArr)){
                    return false;
                }
            }
        }
        return true;
    }
};
int main(){
    Graph g(4);
    g.addEdge(1,0);
    g.addEdge(1,3);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(0,3);
   

    if(g.isBipartiteHelper()){
        cout<<"Graph is Bipartite"<<endl;
    }else{
        cout<<"Graph is not Bipartite"<<endl;
    }

}