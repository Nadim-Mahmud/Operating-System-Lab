#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
#define MX 1000000

struct node{
    int in,b,p;
    node(){}
    node(int _b, int _p){
        b = _b;
        p = _p;
    }
    bool operator < (const node&x){
        return p<x.p;
    }
};

node ara[MX];
pii Schedule[MX];

void pq_fcfs(int n){
    int i,time=0,total=0,turnaround=0;
    sort(ara+1,ara+n+1);
    double avg,avgtr;
    for(i=1;i<=n;i++){
        Schedule[i].first = time + 1;
        total += time;
        time += ara[i].b;
        Schedule[i].second = time;
        turnaround += time;
    }
    avg = (double)total/(double)n;
    avgtr = (double)turnaround/(double)n;
    puts("priority first come first : \n\n");
    printf("Average waiting time : %lf\n",avg);
    printf("Average turn around time : %lf\n\n",avgtr);
    cout<<" PID "<<"\t Start "<<"\t  END"<<endl;
    for(i=1;i<=n;i++){
        cout<<"  "<<ara[i].in<<"\t  "<<Schedule[i].first<<"\t  "<<Schedule[i].second<<endl;
    }
}

int main(){
    int i,j,k,l,m,n;
    freopen("test.txt","r",stdin);
    cin>>n;
    //Brust time
    for(i=1;i<=n;i++){
        cin>>ara[i].b>>ara[i].p;
        ara[i].in=i;
    }
    pq_fcfs(n);
    return 0;
}
