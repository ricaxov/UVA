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
    int n; cin>>n;
    while(n!=0){
        queue<int>q;
        int x=1,ans;
        bool ver=true;
        while(ver){
            for(int j=0; j<n; j++){
                q.push(j+1);
            }
            while(!q.empty()){
                ans=q.front();
                q.pop();
                for(int j=1; j<x; j++){
                    q.push(q.front());
                    q.pop();
                }
            }
            if(ans==13){
                cout<<x<<endl;
                ver=false;
            }
            x++;
        }
        cin>>n;
    }
}
