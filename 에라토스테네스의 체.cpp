int prime[100]; // �Ҽ� ���� 
int pn = 0; // �Ҽ��� ���� 
bool check[101]; // ���������� true 
int n = 100; // 100���� �Ҽ� 
for (int i=2; i<=n; i++){
	if(check[i] == false){
		prime[pn++] = i;
		for (int j=i*2; j<=n; j+=i ){ // int ���� ������i*i ���ٴ� i*2 �� �� ���� 
			check[j] = true;
		}
	}
} 
