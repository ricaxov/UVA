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
vector<string>vec;
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
    vec.pb(v);
    vis[v]=true;
    for(auto i : adjT[v]){
        if(!vis[i]){
            dfs2(i);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,e,x=1; cin>>n>>e;
    bool ver=false;
    while(n!=0 || e!=0){
        if(ver){
            cout<<endl;
        }
        for(int i=0; i<e; i++){
            string str1, str2; cin>>str1>>str2;
            adj[str1].pb(str2);
            adjT[str2].pb(str1);
        }
        for(it=adj.begin(); it!=adj.end(); it++){
            if(!vis[it->first]){
                dfs1(it->first);
            }
        }
        vis.clear();
        cout<<"Calling circles for data set "<<x++<<":"<<endl;
        while(!stk.empty()){
            string u=stk.top(); stk.pop();
            if(!vis[u]){
                dfs2(u);
                for(int i=0; i<vec.size(); i++){
                    cout<<vec[i];
                    if(i<vec.size()-1){
                        cout<<", ";
                    }
                }
                cout<<endl;
                vec.clear();
            }
        }
        ver=true;
        vis.clear();
        adj.clear();
        adjT.clear();
        cin>>n>>e;
    }
}
