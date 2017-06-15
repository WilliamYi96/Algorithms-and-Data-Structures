#include<iostream>
using namespace std;
int main() {
    int n,sum=0,i,d;
    cin>>n;
    for(i=2;;++i) {
        sum+=i;
        d=sum-n;
        if(d>=0) break;
    }
    unsigned int result=1;
    if(d==1) {
        for(int j=3;j<i;++j) result*=j;
        i++;
        result *= i;
    } else {
        for(int j=2;j<=i;++j) {
            if(j==d) continue;
            result*=j;
        }
    }
    //cout<<"The result is "<<result<<endl;
    cout << result << endl;
    return 0;
}
