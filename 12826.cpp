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

bool vis[8][8];
int dx[8]={0,1,0,-1,1,1,-1,-1}, dy[8]={1,0,-1,0,1,-1,1,-1};
int bfs(int startX, int startY, int finishX, int finishY){
    queue<pair<int,ii>>q;
    q.push({startX,{startY,0}});
    vis[startX][startY]=true;
    while(!q.empty()){
        pair<int,ii>u=q.front(); q.pop();
        if(u.f==finishX && u.s.f==finishY){
            return u.s.s;
        }
        for(int i=0; i<8; i++){
            int ax=u.f+dx[i];
            int ay=u.s.f+dy[i];
            if(ax>=0 && ax<8 && ay>=0 && ay<8 && !vis[ax][ay]){
                vis[ax][ay]=true;
                q.push({ax,{ay,u.s.s+1}});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int x1,y1,x2,y2,x3,y3,n=1;
    while(cin>>x1>>y1>>x2>>y2>>x3>>y3){
        x1--;y1--;x2--;y2--;x3--;y3--;
        vis[x3][y3]=true;
        cout<<"Case "<<n++<<": "<<bfs(x1,y1,x2,y2)<<endl;
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                vis[i][j]=false;
            }
        }
    }
}
