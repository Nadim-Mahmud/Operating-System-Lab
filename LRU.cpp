#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
#define MX 10000000

int ara[MX],frame_sz;
int frame[MX];
int timec[MX+MX+MX];
int mp[MX];

int putPosition(){
    int in=0;
    for(int i=0;i<frame_sz;i++){
        if(frame[i]==-1) return i;
        if(timec[frame[i]]<timec[frame[in]]){
            in = i;
        }
    }
    return in;
}

void LRU(int n){
    int cn=0,i,in=0,j,mn,mni;

    memset(mp,0,sizeof mp);
    memset(timec,0,sizeof timec);
    memset(frame,-1,sizeof frame);

    for(i=0;i<n;i++){
        if(!mp[ara[i]]){
            cn++;
            in = putPosition();
            if(frame[in]!=-1){
                mp[frame[in]] = 0;
            }
            frame[in] = ara[i];
            mp[ara[i]] = 1;
        }
        timec[ara[i]] = i;
    }
    cout<<"LRU page fault : ";
    cout<<cn<<endl;
}

int main(){
    int i,j,k,l,n;
    freopen("lru.txt","r",stdin);
    cin>>n>>frame_sz;
    for(i=0;i<n;i++){
        cin>>ara[i];
    }
    LRU(n);
    return 0;
}

