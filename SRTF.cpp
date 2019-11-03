#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
#define MX 1000000

// Not Completed yet

struct node{
    int id,arr,bs;
    void node(int _id,int _arr,int _bs){
        id = _id;
        arr = _arr;
        bs = _bs;
    }
    bool operator < (const node &x){
        return bs < x.bs;
    }
}ara[MX];
pii Schedule[MX];

void sjfs(int n){
    int i,time=0,total=0,in=0;
    double avg;
    priority_queue<node>pq;
    node run = ara[];

    while(!pq.empty()){
        if(in<=n && ara[in].arr < pq.top().arr+pq.top().bs){
            if(pq.top().arr+pq.top().bs > ara[in].arr+ara[in].bs){

            }
            else pq.push(ara[in])
        }

    }


    for(i=1;i<=n;i++){
        Schedule[i].first = time + 1;
        total += time;
        time += ara[i].first;
        Schedule[i].second = time;
    }
    avg = (double)total/(double)n;
    puts("Short job first serve : \n\n");
    printf("Average waiting time : %lf\n\n",avg);
    for(i=1;i<=n;i++){
        cout<<"PID : "<<ara[i].second<<" Start : "<<Schedule[i].first<<" END : "<<Schedule[i].second<<endl;
    }
}

int main(){
    int i,j,k,l,m,n;
    freopen("test.txt","r",stdin);
    cin>>n;
    //Arrival tiem and brust time
    for(i=1;i<=n;i++){
        cin>>ara[i].first;
        ara[i].second = i;
    }
    sjfs(n);
    return 0;
}

