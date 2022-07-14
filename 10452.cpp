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

map<int,char>mp;
vector<string>ans;
char matrix[10][10];
int dx[3]={-1,0,0},dy[3]={0,1,-1};
void floodfill(int x, int y, int maxX, int maxY, int index){
    for(int i=0; i<3; i++){
        int ax=x+dx[i];
        int ay=y+dy[i];
        if(ax>=0 && ax<maxX && ay>=0 && ay<maxY && (matrix[ax][ay]==mp[index] || (matrix[ax][ay]=='#' && index>5))){
            if(i==0){
                ans.pb("forth");
            }
            else{
                if(i==1){
                    ans.pb("right");
                }
                else{
                    ans.pb("left");
                }
            }
            if(index<6){
                floodfill(ax,ay,maxX,maxY,index+1);
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    mp[0]='I',mp[1]='E',mp[2]='H',mp[3]='O',mp[4]='V',mp[5]='A';
    int t,n,m; cin>>t;
    while(t--){
        ii start;
        cin>>n>>m;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>matrix[i][j];
                if(matrix[i][j]=='@'){
                    start={i,j};
                }
            }
        }
        floodfill(start.f,start.s,n,m,0);
        for(int i=0; i<ans.size(); i++){
            cout<<ans[i];
            if(i<ans.size()-1){
                cout<<' ';
            }
        }
        cout<<endl;
        ans.clear();
    }
}
