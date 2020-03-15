#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <algorithm>    // std::swap

using namespace std;

typedef pair<int,int> P;
const int INF = 1000000000; //1e9
struct edge {
    int to, cost;
};
int V = 916428;
int E = 5105039; //頂點數、邊數

vector<edge> G[916428];
int d[916428];
bool vis[916428];
priority_queue<P, vector<P>, greater<P> > Q;

void dijkstra(int s) {
    priority_queue<P, vector<P>, greater<P> > empty;

    swap(Q,empty);
    // while(!Q.empty()){
    //     Q.pop(); //在不只做一次的情況下需要先清空heap
    // }
        
    for(int i = 0; i < V; i++) 
        d[i] = INF;
    d[s] = 0;
    Q.push(make_pair(0, s));

    for(int i = 0; i < V; i++) {
        int x = Q.top().second; 
        Q.pop();
        if(vis[x]) 
            continue;
        vis[x] = true;
        for(edge &e : G[x]) {
            if(d[e.to] > d[x]+e.cost) {
                d[e.to] = d[x]+e.cost;
                Q.push(make_pair(d[e.to], e.to));
            }
        }
    }
}
//demo
int main() {

    ifstream infile("dataset/web.csv");
    int cost = 1;
    int from, to;
    int count = 0;
    while(infile >> from >> to){
        G[from].push_back((edge){to, cost});
        // G[to].push_back((edge){from,cost});
    }

    dijkstra(0);

    int longest = 0;
    for(int i = 0; i < V; i++){
        if(d[i] > longest && d[i] != INF){
            longest = d[i];
            cout << "to node : " << i << " distance : " << longest << endl;
        }
    }

    // int lsp = 0;
    // for(int i = 0; i < V; ++i){
    //     dijkstra(i);
    //     int longest = 0;
    //     int endnode = 0;
    //     for (int j = 0; j < V ; j++){
    //         if( d[j] > longest && d[j] != INF){
    //             longest = d[j];
    //             endnode = j;
    //         }
    //         d[j] = 0;
    //         vis[j] = false;
    //     }
    //     if(longest > lsp){
    //         lsp = longest;
    //         cout << "Source node : " << i <<  " to end node : " << endnode << " , longest shortest path is : " << lsp << endl;
    //     }
    // }
    
    return 0;
}