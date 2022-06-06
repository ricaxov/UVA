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

bool matrix[25][25];
int cont, dx[8]={0,1,0,-1,1,1,-1,-1}, dy[8]={1,0,-1,0,1,-1,1,-1};
void floodfill(int x, int y, int maxX, int maxY){
    matrix[x][y]=false;
    cont++;
    for(int i=0; i<8; i++){
        int ax=x+dx[i];
        int ay=y+dy[i];
        if(ax>=0 && ax<maxX && ay>=0 && ay<maxY && matrix[ax][ay]){
            floodfill(ax,ay,maxX,maxY);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t; cin>>t;
    cin.ignore();
    string fds; getline(cin,fds);
    while(t--){
        cont=0;
        int maior=0;
        vector<string>vec;
        string str; getline(cin,str);
        while(str!="\0"){
            vec.pb(str);
            getline(cin,str);
        }
        for(int i=0; i<vec.size(); i++){
            for(int j=0; j<vec[0].size(); j++){
                matrix[i][j]=vec[i][j]-48;
            }
        }
        for(int i=0; i<vec.size(); i++){
            for(int j=0; j<vec[0].size(); j++){
                if(matrix[i][j]==1){
                    floodfill(i,j,vec.size(),vec[0].size());
                }
                maior=max(cont,maior);
                cont=0;
            }
        }
        cout<<maior<<endl;
        if(t>0){
            cout<<endl;
        }
    }
}
