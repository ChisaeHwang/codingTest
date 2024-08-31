#include <iostream>
using namespace std;

int main() { 
	int N;                                // �Է¹��� �ܾ��� ����
	string word;                          // �Է¹��� �ܾ�
	int count = 0;                        // �׷� �ܾ �ƴ϶�� ī��Ʈ

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> word;
        
		// �ܾ�� ���ĺ� ������ ���������� ��Ÿ���� �迭 (���������� false)
		bool alphabet[26] = { false, };        
		alphabet[(int)(word[0]) - 97] = true;  // ù��° �ܾ�� true�� ����

		for (int i = 1; i < word.size(); i++) {
        
			// 1. i��° ���ڰ� i-1��° ���ڿ� ������ �����̹Ƿ� �Ѿ��.
			if (word[i] == word[i - 1]) {
				continue;
			}
            
			// 2. i��° ���ڰ� i-1��° ���ڿ� ���� �ʰ�, (�������� �ʰ�)
			//    �ش� �迭���� true��� (�̹� ���Դ� ���ڶ��)
			else if(word[i] != word[i - 1] 
            		&& alphabet[(int)(word[i]) - 97] == true){
				count++;	// �׷�ܾ �ƴϹǷ� ī��Ʈ
				break;
			}
            
			// 3. ���� �� ��쿡 �ش����� �ʴ� ���
			//    ó�� ������ ������ ���
			else {
				alphabet[(int)(word[i]) - 97] = true;
			}
		}
	}

	// �׷� �ܾ��� ���� = ��ü�ܾ��� ���� - �׷�ܾ �ƴ� �ܾ��� ����
	cout << N - count;

	return 0;
}
