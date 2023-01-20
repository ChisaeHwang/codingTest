#include <iostream>
using namespace  std;

int arr[1000001]={1,1,1,0,};

int main() {
  int n, left, right;

  for(int i=2; i*i<1000000; i++)
  {
    if(arr[i]==0)
    for(int j=i*i; j<1000000; j+=i)
    {
      arr[j]=1;
    }
  }

  cin.tie(NULL);
  ios_base::sync_with_stdio(0);

  while(1)
  {
    cin>>n;
    if(!n) break;

    left=3;
    right=n-3;

    while(left <= right)
    {
      if(!arr[left] && !arr[right])
        if((left+right) == n)
          break;
      left+=2;
      right-=2;
    }

    if(left>right)  cout<<"Goldbach's conjecture is wrong.";
    else cout<<n<<" = "<<left<<" + "<<right<<'\n';
  }
}
