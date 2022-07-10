#include <bits/stdc++.h>
#define f first
#define s second
#define pi 3.14159
#define pb push_back
#define tos to_string
#define inf 100000000
#define inf64 1000000000000000000
#define entrada freopen("input.txt", "r", stdin);
#define saida freopen("output.txt", "w", stdout);

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

map<string,bool>vis;
map<string,string>ans;
map<string,vector<string>>adj;
bool bfs(string start, string finish){
    queue<string>q;
    q.push(start);
    vis[start]=true;
    while(!q.empty()){
        string u=q.front(); q.pop();
        if(u==finish){
            return true;
        }
        for(string i : adj[u]){
            if(!vis[i]){
                vis[i]=true;
                q.push(i);
                ans[i]=u;
            }
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int e;
    bool ver=false;
    while(cin>>e){
        if(ver){
            cout<<endl;
        }
        for(int i=0; i<e; i++){
            string a,b; cin>>a>>b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        string start,finish; cin>>start>>finish;
        if(bfs(start,finish)){
            vector<pair<string,string>>caminho;
            while(start!=finish){
                caminho.pb({ans[finish],finish});
                finish=ans[finish];
            }
            reverse(caminho.begin(), caminho.end());
            for(int i=0; i<caminho.size(); i++){
                cout<<caminho[i].f<<' '<<caminho[i].s<<endl;
            }
        }
        else{
            cout<<"No route"<<endl;
        }
        ver=true;
        adj.clear(),ans.clear(),vis.clear();
    }
}
