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

vector<int>adj[100];
vector<bool>vis(100);
void dfs(int v){
    vis[v]=true;
    for(int i : adj[v]){
        if(!vis[i]){
            dfs(i);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        int cont=0;
        char c;cin>>c;
        vector<string>vec;
        cin.ignore();
        string str; getline(cin, str);
        while(str!="\0"){
            vec.pb(str);
            getline(cin, str);
        }
        for(int i=0; i<vec.size(); i++){
            adj[int(vec[i][0])-65].pb(int(vec[i][1])-65);
            adj[int(vec[i][1])-65].pb(int(vec[i][0])-65);
        }
        for(int i=0; i<=int(c)-65; i++){
            if(!vis[i]){
                dfs(i);
                cont++;
            }
        }
        for(int i=0; i<30; i++){
            adj[i].clear();
            vis[i]=false;
        }
        cout<<cont<<endl;
        if(t>0){
            cout<<endl;
        }
    }
}
