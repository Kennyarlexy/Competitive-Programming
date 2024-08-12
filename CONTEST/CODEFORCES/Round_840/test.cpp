#include <iostream>
#include<string>
using namespace std;

int main(){
    int ko=0,m;
    cin>>m;
    char a[m],b[m];
    cin>>a>>b;
    for(int i=0;i<m;++i){
        if(a[i]>b[i]){
            while(i < m && a[i]>=b[i]){
                ++i;
            }
            ko++;
        }
    }
    cout<<ko;
    return 0;
}