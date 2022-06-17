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

bool vis[31][31][31];
char matrix[31][31][31];
int dx[12]={0,1,0,-1,0,0,0,0,1,0,-1,0}, dy[12]={1,0,-1,0,0,1,0,-1,0,0,0,0}, dz[12]={0,0,0,0,1,0,-1,0,0,1,0,-1};
int bfs(int xS, int yS, int zS, int xF, int yF, int zF, int maxX, int maxY, int maxZ){
    queue<pair<ii,ii>>q;
    q.push({{xS,yS},{zS,0}});
    vis[xS][yS][zS]=true;
    while(!q.empty()){
        pair<ii,ii>u=q.front(); q.pop();
        if(u.f.f==xF && u.f.s==yF && u.s.f==zF){
            return u.s.s;
        }
        for(int i=0; i<12; i++){
            int ax=u.f.f+dx[i];
            int ay=u.f.s+dy[i];
            int az=u.s.f+dz[i];
            if(ax>=0 && ax<maxX && ay>=0 && ay<maxY && az>=0 && az<maxZ && !vis[ax][ay][az]){
                vis[ax][ay][az]=true;
                q.push({{ax,ay},{az,u.s.s+1}});
            }
        }
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int x,n,m; cin>>x>>n>>m;
    while(x!=0 || n!=0 || m!=0){
        pair<int,ii>start,finish;
        for(int i=0; i<x; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<m; k++){
                    cin>>matrix[i][j][k];
                    vis[i][j][k]=false;
                    if(matrix[i][j][k]=='S'){
                        start={i,{j,k}};
                    }
                    else if(matrix[i][j][k]=='E'){
                        finish={i,{j,k}};
                    }
                    else if(matrix[i][j][k]=='#'){
                        vis[i][j][k]=true;
                    }
                }
            }
            string fds; getline(cin,fds);
        }
        int ans=bfs(start.f,start.s.f,start.s.s,finish.f,finish.s.f,finish.s.s,x,n,m);
        if(ans==-1){
            cout<<"Trapped!"<<endl;
        }
        else{
            cout<<"Escaped in "<<ans<<" minute(s)."<<endl;
        }
        cin>>x>>n>>m;
    }
}
