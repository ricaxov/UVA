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

vector<ii>adj[50001];
int dijkstra(int o, int d){
    vector<int>dist(50001, inf);
    priority_queue<ii, vector<ii>, greater<ii>>pq;
    dist[o]=0;
    pq.push({0,o});
    while(!pq.empty()){
        int u=pq.top().s; pq.pop();
        for(ii i : adj[u]){
            int v=i.f;
            int peso=i.s;
            if(dist[v]>dist[u]+peso){
                dist[v]=dist[u]+peso;
                pq.push({dist[v],v});
            }
        }
    }
    return dist[d];
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t,n,m,x,y,a,b,p,v=0; cin>>t;
    while(t--){
        v++;
        cin>>n>>m>>x>>y;
        for(int i=0; i<m; i++){
            cin>>a>>b>>p;
            adj[a].pb({b,p});
            adj[b].pb({a,p});
        }
        int ans=dijkstra(x,y);
        cout<<"Case #"<<v<<": ";
        if(ans==inf){
            cout<<"unreachable"<<endl;
        }
        else{
            cout<<ans<<endl;
        }
        for(int i=0; i<50001; i++){
            adj[i].clear();
        }
    }
}
