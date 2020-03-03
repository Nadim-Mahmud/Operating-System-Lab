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

int available[MR];
int work[MR];
int finish[MP];
int new_res[MR];

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
    mr=0;
    safeSequence.clear();
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
    cout<<"Safe Sequence : ";
    for(auto it : safeSequence){
        cout<<it<<" ";
    }
    puts("");
}

void resourceRquest(int p, int r, int in){
    int i,j;
    puts("");
    for(i=0;i<r;i++){
        if(new_res[i]>need[in][i]){
            puts("\nThis process requesting greater than its allowed size.");
            return;
        }
    }
    for(i=0;i<r;i++){
        if(new_res[i]>available[i]){
            puts("\nNot enough resources.");
            return;
        }
    }
    for(i=0;i<r;i++){
        available[i] -= new_res[i];
        allocation[in][i] += new_res[i];
        need[in][i] -= new_res[i];
    }
    if(safetyAlgorithm(p,r)){
        puts("\nThe resource has been allocated.");
        printSequence();
    }
    else{
        puts("\nProcess should wait!");
        for(i=0;i<r;i++){
            available[i] += new_res[i];
            allocation[in][i] -= new_res[i];
            need[in][i] += new_res[i];
        }
    }
}


int main(){
    int i,j,k,p,r,mr,in;

    freopen("ResourceRequest.txt","r",stdin);

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
        while(true){
            cout<<"Enter 1 for new resource request 0 for exit : ";
            cin>>mr;
            if(!mr) break;
            cout<<"\nEnter Process number : ";
            cin>>in;
            cout<<"\nEnter resources: ";
            for(i=0;i<r;i++){
                cin>>new_res[i];
            }
            resourceRquest(p,r,in);
        }
    }

    return 0;
}

