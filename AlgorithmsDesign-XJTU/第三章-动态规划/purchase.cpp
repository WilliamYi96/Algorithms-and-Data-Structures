#include <iostream>  
#include <cstdio>  
#include <algorithm>  
#include <cstring>  
#include <queue>  
#include <set>  
#include <map>  
#include <time.h>  
using namespace std;  
  
int sale[1000][6] = {0};    //分别表示每个优惠中每个商品数量   
int saleprice[1000] = {0};  //优惠总价   
int salelength[1000] = {0}; //优惠总共有几个商品   
int salenumber[1000][1000] = {0};   //优惠商品的ID   
int good[6][4] = {0};       //1 -> number   2 -> price  3 -> last num  
int num[1000];              //商品ID   
int dp[6][6][6][6][6];    
int n,m;  
  
void input()  {  
        cin>>n;  
        for(int i = 1; i  <= n; i++)  {  
            cin>>good[i][1]>>good[i][3]>>good[i][2];  
            num[i] = good[i][1];  
        }  
        cin>>m;  
        for(int i = 1; i <= m; i++)  {  
                cin>>salelength[i];  
                for(int j = 1; j <= salelength[i]; j++)  {  
                        cin>>salenumber[i][j];  
                        cin>>sale[i][salenumber[i][j]];  
                }  
                cin>>saleprice[i];  
        }  
}  
  
void output()  {  
    for(int i = 1; i  <= n; i++)  
        cout<<"goodnum: "<<good[i][1]<<" goodprice: "
			<<good[i][2]<<" goodlast: "<<good[i][3]<<endl;  
    for(int i = 1; i  <= m; i++)  {  
        cout<<"sale"<<i<<" : ";  
        for(int j = 1; j <= salelength[i]; j++)  
                cout<<"num: "<<salenumber[i][j]<<" count: "<<sale[i][salenumber[i][j]]<<" ";  
        cout<<endl;  
        cout<<" price: "<<saleprice[i]<<endl;   
    }  
}  

int main()  {  
    //freopen("in2","r",stdin);  
    input();  
    // output();  
    dp[0][0][0][0][0] = 0;  
      for(int i = 0; i <= good[1][3]; i++)  
            for(int j= 0; j <= good[2][3]; j++)  
                    for(int k = 0; k <= good[3][3] ;k++)  
                            for(int l = 0; l <= good[4][3]; l++)  
                                    for(int p = 0; p <= good[5][3]; p++)  
	{  
	int minx = i * good[1][2] + j * good[2][2] + k * good[3][2]  
	 			+ l * good[4][2] + p * good[5][2];  
	    for(int q = 1; q <= m; q++)  {  
	        if(i -sale[q][num[1]]<0 || i - sale[q][num[2]]<0 ||   
				i-sale[q][num[3]]<0 || i-sale[q][num[4]]<0 ||i-sale[q][num[5]]<0)  continue;  
	        int t = dp[i - sale[q][num[1]]][j - sale[q][num[2]]][k - sale[q][num[3]]]
				[l - sale[q][num[4]]][p - sale[q][num[5]]] + saleprice[q];  
	  		if(t < minx) minx = t;  
	    }  
		dp[i][j][k][l][p] = minx;  
	}  
    cout<<dp[good[1][3]][good[2][3]][good[3][3]][good[4][3]][good[5][3]]<<endl;  
	return 0;  
}  
