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

vector<string>vec;
map<string,bool>vis;
int bfs(string start, string finish){
    queue<pair<string,int>>q;
    q.push({start,0});
    vis[start]=true;
    while(!q.empty()){
        pair<string,int> u=q.front(); q.pop();
        if(u.f==finish){
            return u.s;
        }
        for(int i=0; i<vec.size(); i++){
            int difs=0;
            for(int j=0; j<vec[i].size(); j++){
                if(u.f.size()==vec[i].size() && u.f[j]!=vec[i][j]){
                    difs++;
                }
            }
            if(difs==1 && !vis[vec[i]]){
                q.push({vec[i],u.s+1});
                vis[vec[i]]=true;
            }
        }
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t; cin>>t;
    string fds;getline(cin,fds);
    while(t--){
        string str,start,finish,input; 
        while(cin>>str && str!="*"){
            vec.pb(str);
        }
        cin.ignore();
        while(getline(cin,input) && input!=""){
            stringstream ss(input);
            ss>>start>>finish;
            cout<<start<<' '<<finish<<' '<<bfs(start,finish)<<endl;
            vis.clear();
        }
        vec.clear();
        if(t>0){
            cout<<endl;
        }
    }
}
