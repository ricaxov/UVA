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
    int t,x,cont,soma; cin>>t;
    while(t--){
        vector<int>vec(50);
        vec[0]=1,vec[1]=3;
        cont=0,soma=4;
        for(int i=2; i<50; i++){
            cont++;
            if(cont>2){
                cont=1;
                soma+=2;
            }
            vec[i]=vec[i-1]+soma;
        }
        cin>>x;
        cout<<vec[x-1]<<endl;
    }
}
