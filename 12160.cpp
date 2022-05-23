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

vector<bool>vis(10000);
int bfs(int start, int finish, vector<int>&botoes){
    vis[start]=true;
    queue<ii>q;
    q.push({start,0});
    while(!q.empty()){
        ii u=q.front(); q.pop();
        if(u.f==finish){
            return u.s;
        }
        for(int i=0; i<botoes.size(); i++){
            if(!vis[(u.f+botoes[i])%10000]){
                q.push({(u.f+botoes[i])%10000,u.s+1});
                vis[(u.f+botoes[i])%10000]=true;
            }
        }
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int start,finish,n,x=0; cin>>start>>finish>>n;
    while(start!=0 || finish!=0 || n!=0){
        x++;
        vector<int>vec(n);
        for(int i=0; i<n; i++){
            cin>>vec[i];
        }
        cout<<"Case "<<x<<": ";
        int ans=bfs(start,finish,vec);
        if(ans!=-1){
            cout<<ans<<endl;
        }
        else{
            cout<<"Permanently Locked"<<endl;
        }
        for(int i=0; i<10000; i++){
            vis[i]=false;
        }
        cin>>start>>finish>>n;
    }
}
