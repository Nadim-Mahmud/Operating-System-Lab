#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
#define MX 1000000

pii ara[MX];
pii Schedule[MX];

void sjfs(int n){
    int i,time=0,total=0;
    double avg;
    sort(ara+1,ara+n+1);
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
    //Brust time
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>ara[i].first;
        ara[i].second = i;
    }
    sjfs(n);
    return 0;
}

