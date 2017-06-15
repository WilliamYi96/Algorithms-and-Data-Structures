#include<iostream>  
#include<fstream>  
using namespace std;  
  
class Diamond {  
public:  
    int color;//��ɫ���  
    int shape;//��״���  
    int use;//�Ƿ��Ѿ����У�Ĭ��1Ϊδ����  
};  
  
 //��ʼ��n*n����ʯ  
void init(Diamond *a,int n) {  
    //�ֱ�Ϊn����ɫ����n����״�ı�ʯ����ֵ  
    for(int i=1;i<=n*n;i++)  {  
        a[i].color=(i-1)/n+1;  
        a[i].shape=(i-1)%n+1;  
        a[i].use=1;  
    }  
}  
  
//���鱦ʯ�Ƿ�ɷ�  
bool place(Diamond *a,int **s,int x,int y) {  
    for(int i=1;i<y;i++)  { //�ж������Ƿ�����ɫ��״�ظ�    
        if(a[s[x][i]].color==a[s[x][y]].color || a[s[x][i]].shape==a[s[x][y]].shape)  
            return 0;  
    }  
    for(int j=1;j<x;j++)  {  //�ж������Ƿ�����ɫ��״�ظ�  
        if(a[s[j][y]].color==a[s[x][y]].color || a[s[j][y]].shape==a[s[x][y]].shape)  
            return 0;  
    }  
    return 1;  
}  
  
//�û��ݷ��ݹ�����  
void backtrack(Diamond *a,int **s,int t,int n,int &sum)  {  
    int x,y;  
    x=(t-1)/n+1;//��ŵ��к�  
    y=(t-1)%n+1;//��ŵ��к�  
    if(x>n)sum++;  
    else  
        for(int i=1;i<=n*n;i++)  {  
            if(a[i].use) { //��ǰ��ʯδ����  
                s[x][y]=i;  
                if(place(a,s,x,y)) { //��ǰ��ʯ��ɫ��״���ظ�  
                {  
                    a[i].use=0;  
                    backtrack(a,s,t+1,n,sum);  
                    a[i].use=1;  
                }  
            }  
        }  
}  
  
//���㵱ǰ��ʯ���еķ�����  
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
    //���������ļ��е�����  
    fstream fin;  
    fin.open("input.txt",ios::in);  
    if(fin.fail()) {  
        cout<<"File does not exist!"<<endl;  
        cout<<"Exit program"<<endl;  
        return 0;  
    }  
  
    int n;  
    fin>>n;  
  
    //���ú���  
    int number=numDiamond(n);  
    cout<<"��ʯ���еķ�����Ϊ��"<<number<<"��"<<endl;  
  
    //���������д�뵽����ļ�  
    fstream fout;  
    fout.open("output.txt",ios::out);  
    fout<<number;  
  
    fin.close();  
    fout.close();  
    system("pause");  
    return 0;  
}  
