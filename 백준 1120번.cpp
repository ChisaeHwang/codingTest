#include<iostream>
#include<string>
using namespace std;

int main(){
    int cnt;
    int min = 50;
    string a,b;

    cin >> a >> b;

    for(int i=0; i<=b.length()-a.length(); i++){
        cnt = 0;
        
        for(int j=0; j<a.length(); j++){
            if(a[j] != b[j+i])cnt++;
        }
        
        min = min>=cnt ? cnt:min; // 맞으면 cnt 틀리면 min 순회 

    }
    
    cout<< min << '\n';
}
