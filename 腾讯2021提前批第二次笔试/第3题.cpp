#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>

using namespace std;

void solve(int n, int k, vector<string>& vs){
	map<string, int> m;
	for (int i = 0; i < n; i++){
		m[vs[i]]++;
	}
	vector<pair<string, int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), [](pair<string, int>& a, pair<string, int>& b){return a.second > b.second || (a.second == b.second && a.first < b.first); });
	for (int i = 0; i < k; i++){
		cout << v[i].first << " " << v[i].second << endl;
	}
	sort(v.begin(), v.end(), [](pair<string, int>& a, pair<string, int>& b){return a.second < b.second || (a.second == b.second && a.first < b.first); });
	for (int i = 0; i < k; i++){
		cout << v[i].first << " " << v[i].second << endl;
	}
}

int main()
{
	int n, k;
	cin >> n >> k;
	vector<string> vs(n);
	for (int i = 0; i < n; i++){
		cin >> vs[i];
	}
	solve(n, k, vs);
	system("pause");
	return 0;
}
