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

vector<int>adj[10000];
vector<int>dist(10000);
double bfs(int start, int n, set<int>important){
    queue<int>q;
    q.push(start);
    dist[start]=0;
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(int i : adj[u]){
            if(dist[i]==-1){
                dist[i]=dist[u]+1;
                q.push(i);
            }
        }
    }
    double ans=0;
    for(auto i : important){
        ans+=dist[i];
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t,n,e,x; cin>>t;
    while(t--){
        cin>>n>>e;
        int index;
        set<int>all,important;
        for(int i=0; i<e; i++){
            vector<int>vec;
            cin>>x;
            while(x!=0){
                vec.pb(x-1);
                cin>>x;
            }
            for(int i=0; i<vec.size(); i++){
                if(i+1<vec.size()){
                    adj[vec[i]].pb(vec[i+1]);
                    adj[vec[i+1]].pb(vec[i]);
                }
                if(!all.count(vec[i])){
                    all.insert(vec[i]);
                }
                else{
                    important.insert(vec[i]);
                }
            }
        }
        float menor=inf;
        for(int i=0; i<n; i++){
            for(int j=0; j<10000; j++){
                dist[j]=-1;
            }
            float media=bfs(i,n,important)/important.size();
            if(media<menor){
                menor=media;
                index=i+1;
            }
        }
        cout<<"Krochanska is in: "<<index<<endl;
        for(int i=0; i<10000; i++){
            adj[i].clear();
        }
    }
}
