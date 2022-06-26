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

void f(string str, int n, int x){
    if(n==0){
        if(x==0){
            cout<<str<<endl;
        }
        return;
    }
    f(str+"0",n-1,x);
    f(str+"1",n-1,x-1);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t,n,x; cin>>t;
    while(t--){
        string fds; getline(cin,fds);
        cin>>n>>x;
        f("",n,x);
        if(t>0){
            cout<<endl;
        }
    }
}
