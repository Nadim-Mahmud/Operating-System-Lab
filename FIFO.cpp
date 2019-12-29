#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
#define MX 10000000

int ara[MX],mr[MX],frame_sz;
queue<int>q;

void FIFO(int n){
    int cn=0,i;
    memset(mr,0,sizeof mr);

    for(i=1;i<=n;i++){
        if(!mr[ara[i]]) cn++;
        if(q.size()<frame_sz){
            q.push(ara[i]);
        }
        else if(!mr[ara[i]]){
            mr[q.front()] = 0;
            q.pop();
            q.push(ara[i]);
        }
        mr[ara[i]] = 1;
    }
    while(!q.empty()) q.pop();
    puts("FIFO Fault : ");
    cout<<cn<<endl;
}

int main(){
    int i,j,k,l,n;
    freopen("fifo.txt","r",stdin);
    cin>>n>>frame_sz;
    for(i=1;i<=n;i++){
        cin>>ara[i];
    }
    FIFO(n);
    return 0;
}

