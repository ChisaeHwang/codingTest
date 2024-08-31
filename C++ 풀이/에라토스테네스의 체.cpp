int prime[100]; // 소수 저장 
int pn = 0; // 소수의 개수 
bool check[101]; // 지워졌으면 true 
int n = 100; // 100까지 소수 
for (int i=2; i<=n; i++){
	if(check[i] == false){
		prime[pn++] = i;
		for (int j=i*2; j<=n; j+=i ){ // int 범위 때문에i*i 보다는 i*2 가 더 낫다 
			check[j] = true;
		}
	}
} 
