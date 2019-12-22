/// Incomplete

#include<btis/stdc++.h>
using namespace std;

#define MX 1000000
#define MR 1000000

int available[MR],maxx[MP][MR],need[MP][MR],alloc[MP][MR],work[MP][MR],finish[MP];
vector<int>safe;

bool bankers(int p, int r){
    int i,j,k,flag;

    for(i=0;i<p;i++){
        for(j=0;j<r;j++){
            //need[i][j] = maxx[i][j] - alloc[i][j];
            work[i][j] = available[i][j];
        }
    }

    while(1){
        flag=0;
        for(i=0;i<p;i++){
            if(!finish[i]){

            }
        }
    }
}



int main(){
    int i,j,k,p,r;

    cin>>p>>r;

    puts("Enter the Available resource : ");
    for(i=0;i<r;i++) cin>>available[i];

    puts("Enter maximum resource instance of a program : ");
    for(i=0;i<p;i++)
        for(j=0;j<r;j++)
            cin>>maxx[i][j];

    puts("Enter allocated resource list : ");
    for(i=0;i<p;i++)
        for(j=0;j<r;j++)
            cin>>alloc[i][j];

    bankers(p,r);

    return 0;
}
