#include <bits/stdc++.h>
#define f first
#define s second
#define pi 3.14159
#define pb push_back
#define tos to_string
#define inf 1000000000
#define inf64 1000000000000000000
#define entrada freopen("input.txt", "r", stdin);
#define saida freopen("output.txt", "w", stdout);

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

vector<ii>adj[100];
int dijkstra(int o, int d){
    priority_queue<ii, vector<ii>, greater<ii>>pq;
    vector<int>dist(100, inf);
    pq.push({0,o});
    dist[o]=0;
    while(!pq.empty()){
        ii u=pq.top(); pq.pop();
        for(ii i : adj[u.s]){
            int v=i.f;
            int peso=i.s;
            if(dist[v]>dist[u.s]+peso){
                dist[v]=dist[u.s]+peso;
                pq.push({dist[v],v});
            }
        }
    }
    return dist[d];
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t,n,m,v,x,a,b,p; cin>>t;
    while(t--){
        int cont=0;
        cin.ignore();
        string fds; getline(cin,fds);
        while(fds!="\0"){
            getline(cin,fds);
        }
        cin>>n>>m>>v>>x;
        for(int i=0; i<x; i++){
            cin>>a>>b>>p;
            a--; b--;
            adj[a].pb({b,p});
        }
        for(int i=0; i<n; i++){
            if(dijkstra(i,m-1)<=v){
                cont++;
            }
        }
        cout<<cont<<endl;
        if(t>0){
            cout<<endl;
        }
        for(int i=0; i<100; i++){
            adj[i].clear();
        }
    }
}
