#include <bits/stdc++.h>
#define f first
#define s second
#define pi 3.14159
#define pb push_back
#define ll long long
#define ii pair<int,int>

using namespace std;

bool vis[1001][1001];
int bfs(int sx, int sy, int fx, int fy, int mx, int my){
    queue<pair<int,ii> >q;
    q.push({sx,{sy,0}});
    vis[sx][sy]=true;
    while(!q.empty()){
        pair<int,ii> u=q.front();q.pop();
        if(u.f==fx && u.s.f==fy){
            return u.s.s;
        }
        if(u.f-1>=0 && !vis[u.f-1][u.s.f]){
            q.push({u.f-1,{u.s.f,u.s.s+1}});
            vis[u.f-1][u.s.f]=true;
        }
        if(u.f+1<mx && !vis[u.f+1][u.s.f]){
            q.push({u.f+1,{u.s.f,u.s.s+1}});
            vis[u.f+1][u.s.f]=true;
        }
        if(u.s.f-1>=0 && !vis[u.f][u.s.f-1]){
            q.push({u.f,{u.s.f-1,u.s.s+1}});
            vis[u.f][u.s.f-1]=true;
        }
        if(u.s.f+1<my && !vis[u.f][u.s.f+1]){
            q.push({u.f,{u.s.f+1,u.s.s+1}});
            vis[u.f][u.s.f+1]=true;
        }
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,m,v,x,c,z,sx,sy,fx,fy;cin>>n>>m;
    while(n!=0 || m!=0){
        cin>>v;             
        for(int i=0; i<v; i++){
            cin>>x>>c;
            for(int j=0; j<c; j++){
                cin>>z;
                vis[x][z]=true;
            }
        }
        cin>>sx>>sy>>fx>>fy;
        cout<<bfs(sx,sy,fx,fy,n,m)<<endl;
        for(int i=0; i<1001; i++){
            for(int j=0; j<1001; j++){
                vis[i][j]=false;
            }
        }
        cin>>n>>m;
    }
}
