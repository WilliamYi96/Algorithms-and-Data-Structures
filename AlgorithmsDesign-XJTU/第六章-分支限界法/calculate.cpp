#include<iostream>
using namespace std;

int k;
class readin {
	friend int nreadin(int n,int m);
private:
	bool found();                  //found判断是否找到解
	bool search(int t);
	int n,m,x;
    int* a;                        //给定的用于运算的n个正整数的存放位置
	int* num;                      //存放运算的产生整数m
	int* operate;                     
	int* flag;     
	char* ptr;                     //存储结果中的运算符
};

bool readin::search(int depth)  {
	if(depth>k) {
		if(found()) 
			return true;           //判断结点是否满足条件，即是否找到解
		else
			return false;
	}
	else
		for(int i=0;i<n;i++)
			if(flag[i]==0){
				num[depth]=a[i];
				flag[i]=1;
				for(int j=0;j<4;j++){
					operate[depth]=j;
					if(search(depth+1))
						return true;
				}
				flag[i]=0;
			}
			return false;
}

bool readin::found(){
	int x=num[0];
	for(int i=0;i<k;i++){
		switch (operate[i]){
		case 0:x+=num[i+1];ptr[i]='+';break;
		case 1:x-=num[i+1];ptr[i]='-';break;
		case 2:x*=num[i+1];ptr[i]='*';break;
		case 3:x/=num[i+1];ptr[i]='/';break;
		}
	}
	return(x==m);
}

//读入初始数据
int nreadin(int n,int m){
	readin X;
	int* a=new int[n];
    int* num=new int[n];
    int* operate=new int[n];
    int* flag=new int[n];
	char* ptr=new char[n];
	X.n=n;
	X.m=m;
	X.a=a;
	X.operate=operate;
	X.flag=flag;
	X.num=num;
	X.ptr=ptr;
	for(int i=0;i<n;i++)
{
		cin>>a[i];
		flag[i]=0;
	}
	for(k=0;k<n;k++)
		if(X.search(0)){
	        cout<<k<<endl; 
	        for(int i=0;i<=k;i++){
				cout<<num[i]<<ptr[i];
			}
			cout<<endl;
			return 0;
		}
		return 0;
}

int main(){
	int n;
    int m;
	cin>>n>>m;
    nreadin(n,m);	
    return 0;
}

