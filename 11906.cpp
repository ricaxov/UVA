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

int matrix[100][100],par,impar;
bool vis[100][100];
void bfs(int maxX, int maxY, int x, int y){
    queue<ii>q;
    q.push({0,0});
    vis[0][0]=true;
    set<ii>s;
    int dx[8]={x,x,-x,-x,y,y,-y,-y};
    int dy[8]={y,-y,y,-y,x,-x,x,-x};
    while(!q.empty()){
        ii u=q.front(); q.pop();
        s.clear();
        for(int i=0; i<8; i++){
            int ax=u.f+dx[i];
            int ay=u.s+dy[i];
            if(ax>=0 && ax<maxX && ay>=0 && ay<maxY && matrix[ax][ay]!=-1){
                s.insert({ax,ay});
            }
        }
        for(auto i : s){
            matrix[i.f][i.s]++;
            if(matrix[i.f][i.s]!=0 && matrix[i.f][i.s]!=-1 && !vis[i.f][i.s]){
                vis[i.f][i.s]=true;
                q.push({i.f,i.s});
            }
        }
    }
    for(int i=0; i<maxX; i++){
        for(int j=0; j<maxY; j++){
            if(vis[i][j]){
                if(matrix[i][j]%2==0){
                    par++;
                }
                else{
                    if(matrix[i][j]!=-1 && matrix[i][j]%2==1){
                        impar++;
                    }
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t,n,m,x,y,c,a,b,v=1; cin>>t;
    while(t--){
        par=impar=0;
        cin>>n>>m>>x>>y>>c;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                matrix[i][j]=0;
                vis[i][j]=false;
            }
        }
        for(int i=0; i<c; i++){
            cin>>a>>b;
            matrix[a][b]=-1;
        }
        bfs(n,m,x,y);
        cout<<"Case "<<v++<<": "<<par<<" "<<impar<<endl;
    }
}
