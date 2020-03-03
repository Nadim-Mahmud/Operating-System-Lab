#include<bits/stdc++.h>
#define P(X) cout<<"db "<<X<<endl;
#define P2(X,Y) cout<<"d2 "<<X<<" "<<Y<<endl;
#define P3(X,Y,Z) cout<<"d3 "<<X<<" "<<Y<<" "<<Z<<endl;
using namespace std;

#define MP 100000
#define MR 1000

int allocation[MP][MR];
int maxx[MP][MR];
int need[MP][MR];

int available[MP];
int work[MP];
int finish[MP];

vector<int>safeSequence;

bool needCheck(int in,int r){
    for(int j=0;j<r;j++){
        if(need[in][j]>work[j]) return 0;
    }
    return 1;
}


bool safetyAlgorithm(int p,int r){
    int cn=0,i,j,k,in=0,mr;
    for(i=0;i<=p;i++){
        finish[i] = 0;
        work[i] = available[i];
    }
    for(i=0;i<=p;i++){
        for(j=0;j<=r;j++){
            need[i][j] = maxx[i][j]-allocation[i][j];
        }
    }
    while(true){
        if(!finish[in]&&needCheck(in,r)){
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

int main(){
    int i,j,k,p,r;

    freopen("safetyAlgo.txt","r",stdin);

    puts("Enter number of process and number of resource : ");
    cin>>p>>r;

    puts("Enter available resources : ");
    for(i=0;i<r;i++){
        cin>>available[i];
    }

    puts("Enter maximum resource instance of a program : ");
    for(i=0;i<p;i++){
        for(j=0;j<r;j++){
            cin>>maxx[i][j];
        }
    }

    puts("Enter allocated resource list : ");
    for(i=0;i<p;i++)
        for(j=0;j<r;j++)
            cin>>allocation[i][j];

    if(!safetyAlgorithm(p,r)) puts("No safe sequence found!");
    else{
        printSequence();
    }

    return 0;
}
