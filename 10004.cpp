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

vector<int>adj[200];
vector<bool>vis(200),color(200);
bool dfsBipartite(int v){
    for(int i : adj[v]){
        if(!vis[i]){
            vis[i]=true;
            color[i]=!color[v];
            if(!dfsBipartite(i)){
                return false;
            }
        }
        else{
            if(color[i]==color[v]){
                return false;
            }
        }
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    saida
    int n,e,x,y; cin>>n;
    while(n!=0){
        cin>>e;
        for(int i=0; i<e; i++){
            cin>>x>>y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        vis[0]=true;
        if(dfsBipartite(0)){
            cout<<"BICOLORABLE."<<endl;
        }
        else{
            cout<<"NOT BICOLORABLE."<<endl;
        }
        for(int i=0; i<200; i++){
            adj[i].clear();
            vis[i]=false;
        }
        cin>>n;
    }
}
