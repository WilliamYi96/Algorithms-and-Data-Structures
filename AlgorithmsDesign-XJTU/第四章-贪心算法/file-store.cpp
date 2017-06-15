#include <iostream>
#include <stdio.h>   
#include <algorithm>
using namespace std;   
  
int cmp (const void *a , const void *b) {    
    return *(double *)a - *(double *)b;    
}   
  
double greedy(double a[],int n) {   
    qsort(a,n,sizeof(double),cmp);   
    int mid = (n - 1) / 2;   
    double x[n];   
    x[mid] = a[n-1];   
    for(int i = mid+1;i < n;i++)   
        x[i] = a[n - 2*(i-mid)];   
    for(int i = mid-1;i >= 0;i--)   
        x[i] = a[n - 2*(mid-i) - 1];   
    double sum = 0,exp = 0;   
    for(int i = 0;i < n;i++) {   
        sum += a[i];   
        for(int j = i+1;j < n;j++)   
            exp += x[i]*x[j]*(j-i);   
    }   
    return exp/sum/sum;   
}   
           
int main() {   
    int i,j,n;   
    double a[1000],exp;   
    scanf("%d",&n);   
    for(i = 0;i < n;i++)   
        scanf("%lf",&a[i]);   
    exp = greedy(a,n);   
    printf("%lf\n",exp);    
} 
