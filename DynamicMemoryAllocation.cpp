#include<bits/stdc++.h>
using namespace std;

#define MX 100000

int hsize[MX];
int psize[MX];
int tmph[MX];
int allocation[MX];

void printOutput(int p){
    cout<<"Process No\tProcess Size\tHole No\n";
    for(int i=0; i<p; i++){
        if(allocation[i] == -1) cout<<i+1<<"\t\t"<<psize[i]<<"\t\tNot Allocated\n";
        else cout<<i+1<<"\t\t"<<psize[i]<<"\t\t"<<allocation[i]+1<<"\n";
    }
    return;
}

void firstFit(int h, int p){
    int i,j,mr;
    for(i=0;i<p;i++){
        allocation[i] = -1;
        for(j=0;j<h;j++){
            if(psize[i]<=tmph[j]){
                tmph[j] -= psize[i];
                allocation[i] = j;
                break;
            }
        }
    }
    cout<<"\nFirst fit allocation : \n";
    printOutput(p);
}

int main(){
    int i,j,k,l,n,m,h,p;

    freopen("DynamicMemoryAllocation.txt","r",stdin);

    cout<<"Enter the number of memory hole and number of process to be allocate : ";
    cin>>h>>p;

    cout<<"\nEnter the hole sizes : ";
    for(i=0;i<h;i++){
        cin>>hsize[i];
    }

    cout<<"\nEnter the process sizes : ";
    for(i=0;i<p;i++){
        cin>>psize[i];
    }

    copy(hsize,hsize+h,tmph);
    firstFit(h,p);

    return 0;
}
