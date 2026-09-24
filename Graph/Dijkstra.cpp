#include<bits/stdc++.h>
using namespace std;
const int N = 510;
int g[N][N];
#define INF 0x3f3f3f3f
int d[N];
bool st[N];
int n,m;
int dijkstra(){
    memset(d,0x3f,sizeof d);
    d[1] = 0;
    for(int i = 1; i <= n;i ++){
        int t = -1;
        for(int j = 1;j <= n;j ++){
            if(!st[j] && (t == -1 || d[t] > d[j])){
                t = j;
            }
        }
            st[t] = true;
            for(int j = 1;j <= n;j ++){
                if(d[j] > d[t] + g[t][j]){
                    d[j] = d[t] + g[t][j];
                }
            }
        }
    
    return d[n];
    
    
}
int main(){
    cin >> n >> m;
    memset(g,INF,sizeof g);
    
    for(int i = 1;i <= m;i ++){
        int a,b,c;cin >> a >> b >> c;
        g[a][b] = min(g[a][b],c);
    }
    
    int t = dijkstra();
    
    if(t == INF) cout << -1 << endl;
    else cout << t << endl;
    return 0;
}
