#include<bits/stdc++.h>
#define pii pair<int,int>
#define P(X) cout<<"db "<<X<<endl;
#define P2(X,Y) cout<<"d2 "<<X<<" "<<Y<<endl;
#define P3(X,Y,Z) cout<<"d3 "<<X<<" "<<Y<<" "<<Z<<endl;
using namespace std;
#define MX 1000000

int brust_time[MX],turn_around[MX];
queue<pii>q;

void round_robin(int n,int quantum){
    int time=0,wait=0,turn=0,i;
    double avg_wait,avg_turn_around;

    while(!q.empty()){
        pii x = q.front();
        q.pop();
        if(x.second<=quantum){
            time = time+x.second;
            turn_around[x.first] = time;
            turn += time;
            wait += (turn_around[x.first] - brust_time[x.first]);
            continue;
        }
        x.second -= quantum;
        q.push(x);
        time += quantum;
    }

    puts("Short remaining time job first serve : \n");
    avg_wait = (double)wait/(double)n;
    avg_turn_around = (double)turn/(double)n;
    printf("Average waiting time : %lf\n\n",avg_wait);
    printf("Average turn around time : %lf\n\n",avg_turn_around);
    //P2(avg_wait,avg_turn_around);

    puts("............................................................");
    puts("| Process ID | Burst Time | Waiting Time | Turnaround Time |");
    puts("|..........................................................|");
    for(i=1;i<=n;i++){
        printf("|    %3d     |    %3d     |     %3d      |     %3d         |\n",i,brust_time[i],turn_around[i]-brust_time[i],turn_around[i]);
    }
    puts("------------------------------------------------------------");
}

int main(){
    int i,j,k,l,m,n,quantum;
    freopen("round_robin.txt","r",stdin);
    cin>>n>>quantum;
    for(i=1;i<=n;i++){
        cin>>brust_time[i];
        q.push(pii(i,brust_time[i]));
    }
    round_robin(n,quantum);
    return 0;
}

