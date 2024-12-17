#include <iostream>
#include <algorithm>
using namespace std;

void qsort(int a[],int left ,int right){
    if(left>=right) return;
    int provit = a[left];
    int i =left;
    int j = right;
    while (i<j)
    {
        while(i<j && a[j]>=provit) j--;
        while(i<j && a[i]<=provit) i++;
        if(i<j) swap(a[i],a[j]);
    }
    swap(a[left],a[j]); 
    qsort(a,left,j-1);
    qsort(a,j+1,right);
}
int main(){
    int a[] = {5,3,8,6,2,7,1,4};
    int n = sizeof(a)/sizeof(a[0]);
    qsort(a,0,n-1);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}
