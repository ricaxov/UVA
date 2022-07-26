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

vector<int>adj[1000];
int low[1000],num[1000];
void dfs(int v, int p, int timer, set<int>&points, set<ii>&bridges){
    low[v]=num[v]=timer++;
    for(int i : adj[v]){
        if(!num[i]){
            dfs(i,v,timer,points,bridges);
            low[v]=min(low[v],low[i]);
            if(low[i]>=num[v]){
                points.insert(v);
            }
            if(low[i]>num[v]){
                bridges.insert({min(v,i),max(v,i)});
            }  
        }
        else{
            if(p!=i){
                low[v]=min(low[v],num[i]);
            }
        }
    }
}
int main(){
    int n,e; cin>>n>>e;
    while(n!=0 || e!=0){
        set<int>points;
        set<ii>bridges;
        for(int i=0; i<e; i++){
            int x,y; cin>>x>>y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        for(int i=0; i<n; i++){
            if(!num[i]){
                dfs(i,-1,1,points,bridges);
            }
        }
        cout<<bridges.size();
        for(auto i : bridges){
            cout<<' '<<i.f<<' '<<i.s;
        }
        cout<<endl;
        for(int i=0; i<1000; i++){
            adj[i].clear();
            num[i]=low[i]=0;
        }
        cin>>n>>e;
    }
}
