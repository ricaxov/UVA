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
    string str1,str2;
    while(cin>>str1>>str2){
        int x=0;
        for(int i=0; i<str2.size(); i++){
            if(str2[i]==str1[x]){
                x++;
            }
        }
        cout<<(x==str1.size() ? "Yes" : "No")<<endl;
    }
}
