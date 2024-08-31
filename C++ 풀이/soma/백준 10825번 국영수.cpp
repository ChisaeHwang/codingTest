#include <bits/stdc++.h>

using namespace std;

#define list aa

struct Student {
    string name;
    int kor, eng, mat; // ���� ���� ���� 
};

bool comp(Student a, const Student b) {
    if(a.kor == b.kor) {
        if(a.eng == b.eng) {
            if(a.mat == b.mat) {
                return a.name < b.name; // ������ ���� 
            }
            else return a.mat > b.mat; // ���� ���� 
        }
        else return a.eng < b.eng; // ���� ���� 
    }
    else return a.kor > b.kor; // ���� ���� 
}

int main() {
	
	int n;
	cin >> n;
	
	
	vector<Student> li(n);
	
	
	for (int i = 0; i < n; i++) {
		cin >> li[i].name >> li[i].kor >> li[i].eng >> li[i].mat;
	}
	
	sort(li.begin(), li.end(), comp);
	
	for (auto a : li) {
		cout << a.name << '\n';
	}
	
	
	
	return 0;
} 
