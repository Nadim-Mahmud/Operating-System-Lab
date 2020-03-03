#include<bits/stdc++.h>
#define P(X) cout<<"db "<<X<<endl;
#define P2(X,Y) cout<<"d2 "<<X<<" "<<Y<<endl;
#define P3(X,Y,Z) cout<<"d3 "<<X<<" "<<Y<<" "<<Z<<endl;
using namespace std;

#define MP 100000
#define MR 1000

int allocation[MP][MR];
int request[MP][MR];

int available[MP];
int work[MP];
int finish[MP];

vector<int>safeSequence;

bool requestCheck(int in,int r){
    for(int j=0;j<r;j++){
        if(request[in][j]>work[j]) return 0;
    }
    return 1;
}

bool safetyAlgorithm(int p,int r){

    int cn=0,i,j,k,in=0,mr=0;

    for(i=0;i<p;i++){
        finish[i] = 0;
        work[i] = available[i];
    }

    while(true){

        if(!finish[in]&&requestCheck(in,r)){
            for(i=0;i<r;i++){
                work[i] += allocation[in][i];
            }
            safeSequence.push_back(in);
            finish[in] = 1;
            cn++;
            mr=1;
        }
        in++;
        if(in==p){
            if(mr==0) break;
            in=mr=0;
        }
    }
    return (cn==p);
}

void printSequence(){
    cout<<"\n\nSafe Sequence : ";
    for(auto it : safeSequence){
        cout<<it<<" ";
    }
    puts("");
}

void printDeadLock(int p){
    puts("The system is in a deadlocked state.");
    cout<<"The Deadlocked processes are : ";
    for(int i=0;i<p;i++){
        if(!finish[i]) cout<<i<<" ";
    }
    puts("");
}

int main(){
    int i,j,k,p,r;

    freopen("DeadLoackDetection.txt","r",stdin);

    puts("Enter number of process and number of resource : ");
    cin>>p>>r;

    puts("Enter available resources : ");
    for(i=0;i<r;i++){
        cin>>available[i];
    }

    puts("Enter allocated resource list : ");
    for(i=0;i<p;i++)
        for(j=0;j<r;j++)
            cin>>allocation[i][j];

    puts("Enter resource requests : ");
    for(i=0;i<p;i++){
        for(j=0;j<r;j++){
            cin>>request[i][j];
        }
    }

    if(!safetyAlgorithm(p,r)){
        printDeadLock(p);
    }
    else{
        printSequence();
    }

    return 0;
}

