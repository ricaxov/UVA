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

vector<int>vec;
vector<bool>vis(20);
bool isprime(int x){
    for(int i=2; i<=sqrt(x); i++){
        if(x%i==0){
            return false;
        }
    }
    return true;
}
void f(int x, int n){
    if(x==n && isprime(vec[0]+vec[n-1])){
        for(int i=0; i<n; i++){
            cout<<vec[i];
            if(i<n-1){
                cout<<' ';
            }
        }
        cout<<endl;
        return;
    }
    for(int i=2; i<=n; i++){
        if(isprime(vec[x-1]+i) && !vis[i]){
            vis[i]=true;
            vec.pb(i);
            f(x+1,n);
            vec.pop_back();
            vis[i]=false;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,v=0;
    while(cin>>n){
        if(v>0){
            cout<<endl;
        }
        v++;
        vec.pb(1);
        cout<<"Case "<<v<<":"<<endl;
        f(1,n);
        for(int i=0; i<20; i++){
            vis[i]=false;
        }
        vec.clear();
    }
}
