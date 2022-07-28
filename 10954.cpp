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
    int n,x; cin>>n;
    while(n!=0){
        priority_queue<int, vector<int>, greater<int>>q;
        for(int i=0; i<n; i++){
            cin>>x;
            q.push(x);
        }
        int sum=0,ans=0;
        while(q.size()>1){    
            sum+=q.top(); q.pop();
            sum+=q.top(); q.pop();
            q.push(sum);
            ans+=sum; 
            sum=0;
        }
        cout<<ans<<endl;
        cin>>n;
    }
}
