#include <cstdio> 
#include <queue>  
#include <cstring>  
#include <algorithm>  
#define N 105  
#define K 15  
#define inf 0x3f3f3f3f  
using namespace std;  
const int dx[4]={1,0,-1,0};  
const int dy[4]={0,1,0,-1};  
struct Lux  
{  
    int k,x,y;  
    Lux(int a,int b,int c):k(a),x(b),y(c){}  
    Lux(){}  
};  
  
int map[N][N],id[N][N],cnt;  
int n,p,A,B,C;  
int dist[K][N][N];  
bool in[K][N][N];  
Lux s,t;  
  
int spfa()  {  
    int i,vx,vy,fee,fee2;  
    queue<Lux>q;  
    memset(dist,0x3f,sizeof(dist));  
    dist[s.k][s.x][s.y]=0;  
    in[s.k][s.x][s.y]=1;  
    q.push(s);  
    while(!q.empty())  
    {  
        Lux U=q.front();q.pop();in[U.k][U.x][U.y]=0;  
        if(!U.k)continue; 
        for(fee=i=0;i<4;i++)  {  
            vx=U.x+dx[i];  
            vy=U.y+dy[i];  
            if(i==2)fee=B;/*往回走要多付的费用在这里处理。*/  
            if(!id[vx][vy])continue;  
            if(!map[vx][vy])  
            {  
                fee2=C;/*新开油站，准确的说这里的思想是把全图都开成加油站，原加油站强制加油，新加油站不强制，但加油要多付钱*/  
                if(U.k&&dist[U.k-1][vx][vy]>dist[U.k][U.x][U.y]+fee)  
                {/*因为加油站强制加油，所以不是加油站才能这么转移。*/  
                    dist[U.k-1][vx][vy]=dist[U.k][U.x][U.y]+fee;  
                    if(!in[U.k-1][vx][vy])in[U.k-1][vx][vy]=1,q.push(Lux(U.k-1,vx,vy));  
                }  
            }  
            else fee2=0;/*已经有原加油站了就不需要再付额外费用了*/  
              
            if(dist[p][vx][vy]>dist[U.k][U.x][U.y]+A+fee+fee2)  
            {/*加油的转移*/  
                dist[p][vx][vy]=dist[U.k][U.x][U.y]+A+fee+fee2;  
                if(!in[p][vx][vy])in[p][vx][vy]=1,q.push(Lux(p,vx,vy));  
            }  
        }  
    }  
    int ret=inf;  
    for(i=0;i<=p;i++)ret=min(ret,dist[i][t.x][t.y]);  
    return ret;  
}  
  
int main()  {  
    scanf("%d%d%d%d%d",&n,&p,&A,&B,&C);  
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%d",&map[i][j]),id[i][j]=++cnt;  
    s=Lux(p,1,1),t=Lux(0,n,n);  
    printf("%d\n",spfa());  
    return 0;  
}  
