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

char matrix[200][200];
int dx[6]={0,1,0,-1,-1,1}, dy[6]={1,0,-1,0,-1,1};
void floodfill(int x, int y, int maximo){
    matrix[x][y]='x';
    for(int i=0; i<6; i++){
        int ax=x+dx[i];
        int ay=y+dy[i];
        if(ax>=0 && ax<maximo && ay>=0 && ay<maximo && matrix[ax][ay]=='w'){
            floodfill(ax,ay,maximo);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,v=1; cin>>n;
    while(n!=0){
        bool ver=false;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>matrix[i][j];
            }
        }
        for(int i=0; i<n; i++){
            if(matrix[i][0]=='w'){
                floodfill(i,0,n);
            }
        }
        for(int i=0; i<n; i++){
            if(matrix[i][n-1]=='x'){
                ver=true;
            }
        }
        cout<<v++<<' '<<(ver ? 'W' : 'B')<<endl;
        cin>>n;
    }
}
