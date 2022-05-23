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

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,m; cin>>n>>m;
    while(n!=0 || m!=0){
        vector<int>vec1(n),vec2(m);
        for(int i=0; i<n; i++){
            cin>>vec1[i];
        }
        for(int i=0; i<m; i++){
            cin>>vec2[i];
        }
        if(n>m){
            cout<<"Loowater is doomed!"<<endl;
        }
        else{
            int ans=0,pos=0;
            sort(vec1.begin(), vec1.end());
            sort(vec2.begin(), vec2.end());
            for(int i=0; i<m && pos<n; i++){
                if(vec2[i]>=vec1[pos]){
                    ans+=vec2[i];
                    pos++;
                }
            }
            if(pos<n){
                cout<<"Loowater is doomed!"<<endl;
            }
            else{
                cout<<ans<<endl;
            }
        }
        cin>>n>>m;
    }
}
