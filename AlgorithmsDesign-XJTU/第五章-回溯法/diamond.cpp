#include<iostream>  
#include<fstream>  
using namespace std;  
  
class Diamond {  
public:  
    int color;//颜色编号  
    int shape;//形状编号  
    int use;//是否已经排列，默认1为未排列  
};  
  
 //初始化n*n个宝石  
void init(Diamond *a,int n) {  
    //分别为n种颜色各具n种形状的宝石赋初值  
    for(int i=1;i<=n*n;i++)  {  
        a[i].color=(i-1)/n+1;  
        a[i].shape=(i-1)%n+1;  
        a[i].use=1;  
    }  
}  
  
//检验宝石是否可放  
bool place(Diamond *a,int **s,int x,int y) {  
    for(int i=1;i<y;i++)  { //判断行中是否有颜色形状重复    
        if(a[s[x][i]].color==a[s[x][y]].color || a[s[x][i]].shape==a[s[x][y]].shape)  
            return 0;  
    }  
    for(int j=1;j<x;j++)  {  //判断列中是否有颜色形状重复  
        if(a[s[j][y]].color==a[s[x][y]].color || a[s[j][y]].shape==a[s[x][y]].shape)  
            return 0;  
    }  
    return 1;  
}  
  
//用回溯法递归搜索  
void backtrack(Diamond *a,int **s,int t,int n,int &sum)  {  
    int x,y;  
    x=(t-1)/n+1;//存放的行号  
    y=(t-1)%n+1;//存放的列号  
    if(x>n)sum++;  
    else  
        for(int i=1;i<=n*n;i++)  {  
            if(a[i].use) { //当前宝石未排列  
                s[x][y]=i;  
                if(place(a,s,x,y)) { //当前宝石颜色形状不重复  
                {  
                    a[i].use=0;  
                    backtrack(a,s,t+1,n,sum);  
                    a[i].use=1;  
                }  
            }  
        }  
}  
  
//计算当前宝石排列的方案数  
int numDiamond(int n) {  
    Diamond *a=new Diamond[n*n+1];  
    init(a,n);  
    int sum=0;  
    int **s=new int*[n+1];  
    for(int m=1;m<=n;m++)  
        s[m]=new int[n+1];  
    backtrack(a,s,1,n,sum);  
    return sum;  
}  
  
int main()  {  
    //读出输入文件中的数据  
    fstream fin;  
    fin.open("input.txt",ios::in);  
    if(fin.fail()) {  
        cout<<"File does not exist!"<<endl;  
        cout<<"Exit program"<<endl;  
        return 0;  
    }  
  
    int n;  
    fin>>n;  
  
    //调用函数  
    int number=numDiamond(n);  
    cout<<"宝石排列的方案数为："<<number<<"种"<<endl;  
  
    //将结果数据写入到输出文件  
    fstream fout;  
    fout.open("output.txt",ios::out);  
    fout<<number;  
  
    fin.close();  
    fout.close();  
    system("pause");  
    return 0;  
}  
