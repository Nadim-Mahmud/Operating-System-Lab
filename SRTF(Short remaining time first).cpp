#include<bits/stdc++.h>
#define pii pair<int,int>
#define P(X) cout<<"db "<<X<<endl;
#define P2(X,Y) cout<<"d2 "<<X<<" "<<Y<<endl;
#define P3(X,Y,Z) cout<<"d3 "<<X<<" "<<Y<<" "<<Z<<endl;
using namespace std;
#define MX 1000000

struct node{
    // id arrival time, brust time
    int id,arr,bs; // bs will use as ending time in schedule
    bool operator < (const node&x)const{
        return  bs>x.bs;
    }
}ara[MX],schedule[MX];

void srtfs(int n){
    int i,time=0,in=1,wait=0,sc=0;
    double avg;
    priority_queue<node>pq;
    node tmp;

    schedule[0].id=-1;
    pq.push(ara[in++]);
    while(!pq.empty()||in<n){
        while(ara[in].arr<=time&&in<=n){
            pq.push(ara[in++]);
        }
        tmp = pq.top();
        pq.pop();

        // calculation segment
        wait += time - tmp.arr;
        if(schedule[sc].id!=tmp.id){
            schedule[++sc].id = tmp.id;
            schedule[sc].arr = time;
        }
        schedule[sc].bs = time;

        tmp.arr=time+1;
        tmp.bs--;
        if(tmp.bs>0) pq.push(tmp);
        time++;
    }

    puts("Short remaining time job first serve : \n");
    avg = (double)wait/(double)n;
    printf("Average waiting time : %lf\n\n",avg);
    for(i=1;i<=sc;i++){
        cout<<"PID : "<<schedule[i].id<<" Start : "<<schedule[i].arr<<" END : "<<schedule[i].bs+1<<endl;
    }
}

int main(){
    int i,j,k,l,m,n;
    freopen("SRTF.txt","r",stdin);
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>ara[i].id>>ara[i].arr>>ara[i].bs;
    }
    srtfs(n);
    return 0;
}

