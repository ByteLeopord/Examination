#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n;
	vector<int> num1(n);
	for (int i = 0; i < n; i++){
		cin >> num1[i];
	}
	cin >> m;
	vector<int> num2(m);
	for (int i = 0; i < m; i++){
		cin >> num2[i];
	}
	int p1 = 0, p2 = 0;
	while (p1 < n && p2 < m){
		if (num1[p1] == num2[p2]){
			cout << num1[p1] << " ";
			p1++;
			p2++;
		}
		else if (num1[p1] > num2[p2]){
			p1++;
		}
		else{
			p2++;
		}
	}
	cout << endl;
	system("pause");
	return 0;
}
