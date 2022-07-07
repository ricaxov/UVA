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

int one,zero;
vector<int>adj[200], color(200);
bool bfsColors(int v){
    queue<int>q;
    q.push(v);
    color[v]=1;
    one++;
    bool ver=true;
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(int i : adj[u]){
            if(color[i]==inf){
                color[i]=!color[u];
                (color[i] ? one++ : zero++);
                q.push(i);
            }
            else{
                if(color[i]==color[u]){
                    ver=false;
                }
            }
        }
    }
    return ver;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t,n,e,x; cin>>t;
    while(t--){
        for(int i=0; i<200; i++){
            color[i]=inf;
            adj[i].clear();
        }
        int ans=0;
        string fds; getline(cin,fds);
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>e;
            for(int j=0; j<e; j++){
                cin>>x;
                x--;
                if(x<n){
                    adj[x].pb(i);
                    adj[i].pb(x);
                }
            }
        }
        for(int i=0; i<n; i++){
            if(color[i]==inf){
                one=zero=0;
                if(bfsColors(i)){
                    ans+=max(1,max(one,zero));
                }
            }
        }
        cout<<ans<<endl;
    }
}
