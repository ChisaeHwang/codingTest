#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct person
{
    int age, idx;
    string name; //int�� �ٲ��ָ� ���� �ȳ�
};

bool compare(const person& now, const person& last)
{
    if(now.age != last.age) return now.age < last.age;
    return now.idx < last.idx;
}

int main()
{	
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int N;
    cin >> N;
    person people[100001]; //����ü �迭

    for (int i = 0; i < N; i++) //�迭�� �� �־���
    {    
        cin >> people[i].age >> people[i].name;
        people[i].idx = i;
    }

    //����
    //stable_sort(people, people + N, compare);
    sort(people, people + N, compare);

    //�� ���
    for (int i = 0; i < N; i++)
        cout << people[i].age << " " << people[i].name << "\n";
}
