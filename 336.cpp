#include <bits/stdc++.h>
#define s second
#define pb push_back

using namespace std;

typedef pair<int,int> ii;

int cont;
vector<int>adj[100000];
vector<bool>vis(100000);
void bfs(int o, int distancia){
    queue<ii>q;
    q.push({o,0});
    vis[o]=true;
    while(!q.empty()){
        ii u=q.front(); q.pop();
        if(u.s>distancia){
            cont++;
        }
        for(auto i : adj[u.first]){
            if(!vis[i]){
                vis[i]=true;
                q.push({i,u.s+1});
            }
        }
    }
}
int main(){
    int n,a,b,x,y,v=1; cin>>n;
    while(n!=0){
        for(int i=0; i<n; i++){
            cin>>a>>b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        cin>>x>>y;
        while(x!=0 || y!=0){
            cont=0;
            bfs(x,y);
            for(int i=0; i<100000; i++){
                for(auto j : adj[i]){
                    if(!vis[j]){
                        vis[j]=true;
                        cont++;
                    }
                }
            }
            cout<<"Case "<<v++<<": "<<cont<<" nodes not reachable from node "<<x<<" with TTL = "<<y<<"."<<endl;
            for(int i=0; i<100000; i++){
                vis[i]=false;
            }
            cin>>x>>y;
        }
        for(int i=0; i<100000; i++){
            adj[i].clear();
            vis[i]=false;
        }
        cin>>n;
    }
}
