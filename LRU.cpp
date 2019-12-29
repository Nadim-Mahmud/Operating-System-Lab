/// Incomplete


#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
#define MX 10000000

int ara[MX],mr[MX],frame_sz;
pii st[MX];

void LRU(int n){
    int cn=0,i,in=0,j,mn,mni;
    memset(mr,0,sizeof mr);
    for(i=1;i<=n;i++){
        if(!mr[ara[i]]){
            cn++;
            //cout<<ara[i]<<endl;
            //for(j=1;j<=frame_sz;j++) cout<<st[j].first<<" ";
            //puts("");
        }
        if(in<frame_sz){
            st[++in].first = ara[i];
            st[in].second = i;
        }
        else if(!mr[ara[i]]){
            mn = st[1].second;
            mni = 1;
            for(j=1;j<=frame_sz;j++){
                if(st[j].second<mn){
                    mn = st[j].second;
                    mni = j;
                }
            }
            mr[st[mni].first] = 0;
            st[mni].first = ara[i];
            st[mni].second = i;
        }
        else{
            st[mr[ara[i]]].second = i;
        }
        mr[ara[i]] = i;
    }
    puts("LRU Fault : ");
    cout<<cn<<endl;
}

int main(){
    int i,j,k,l,n;
    freopen("lru.txt","r",stdin);
    cin>>n>>frame_sz;
    for(i=1;i<=n;i++){
        cin>>ara[i];
    }
    LRU(n);
    return 0;
}

