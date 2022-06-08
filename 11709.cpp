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

stack<string>stk;
map<string,vector<string>>adj, adjT;
map<string,vector<string>>::iterator it;
map<string, bool>vis;
void dfs1(string v){
    vis[v]=true;
    for(auto i : adj[v]){
        if(!vis[i]){
            dfs1(i);
        }
    }
    stk.push(v);
}
void dfs2(string v){
    vis[v]=true;
    for(auto i : adjT[v]){
        if(!vis[i]){
            dfs2(i);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,e; cin>>n>>e;
    while(n!=0 || e!=0){
        int cont=0;
        string str,a,b;
        cin.ignore();
        vector<string>vec;
        for(int i=0; i<n; i++){
            getline(cin,str);
            vec.pb(str);
        }
        for(int i=0; i<e; i++){
            getline(cin,a);
            getline(cin,b);
            adj[a].pb(b);
            adjT[b].pb(a);
        }
        for(int i=0; i<vec.size(); i++){
            if(!vis[vec[i]]){
                dfs1(vec[i]);
            }
        }
        vis.clear();
        while(!stk.empty()){
            string u=stk.top(); stk.pop();
            if(!vis[u]){
                cont++;
                dfs2(u);
            }
        }
        cout<<cont<<endl;
        vis.clear();
        adj.clear();
        adjT.clear();
        cin>>n>>e;
    }
}
