#include<iostream>
#include<algorithm>
using namespace std;

int a[1000000];

int most(int *a,int n,int s) {
	int i=0,sum=0;
	while(i<n) {
		sum=a[i]+sum;
		if(sum<=s) i++;
		else return i;
	}
	return n;
}

int main() {
	int i,n,s;
	scanf("%d %d\n",&n,&s);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	printf("%d",most(a,n,s));
	return 0;
}
