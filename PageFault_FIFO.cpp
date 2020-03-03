#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
#define MX 10000000

int ara[MX],frame_sz;
int mp[MX];

void FIFO(int n){
    int cn=0,i,in=0,j,mn,mni;
    queue<int>q;
    memset(mp,0,sizeof mp);

    for(i=0;i<n;i++){
        if(!mp[ara[i]]){
            cn++;
            if(q.size()>=frame_sz){
                mp[q.front()]=0;
                q.pop();
            }
            q.push(ara[i]);
            mp[ara[i]]=1;
        }
    }
    cout<<"FIFO page fault : ";
    cout<<cn<<endl;
}

int main(){
    int i,j,k,l,n;
    freopen("PageFault_FIFO.txt","r",stdin);
    cin>>n>>frame_sz;
    for(i=0;i<n;i++){
        cin>>ara[i];
    }
    FIFO(n);
    return 0;
}


