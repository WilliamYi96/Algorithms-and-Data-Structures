#include<iostream>
using namespace std;
 
void perm(char list[], int k, int m);
void swap(char &a, char &b);
int ok(char list[],int k,int i);

int main() {
	int a,c;
	char list[] = {'a','a','c','c'};
	perm(list, 0, 3);
	scanf("&d ",&a);
}
 

void perm(char list[], int k, int m) {
	if (k==m) {
		for (int i = 0; i <=m; i++) printf("%c",list[i]);
		printf("\n");
	}
	else{
		for (int i = k; i <= m; i++){
			if(ok(list,k,i)){
				swap(list[k], list[i]);
				perm(list, k + 1, m);
				swap(list[k], list[i]);
			}
		}
	}
}

void swap(char &a, char &b){
	int temp = a;
	a = b;
	b = temp;
}

int ok(char list[],int k,int i){
	if(i>k)
		for(int t=k;t<i;t++)
			if(list[t]==list[i]) return 0;
	return 1;
}
