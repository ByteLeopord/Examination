#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>

using namespace std;

int sumpeople(int n, int m, vector<vector<int>>& group){
	set<int> people;
	queue<int> notused;
	people.insert(0);
	notused.push(0);
	while (!notused.empty()){
		int temp = notused.front();
		notused.pop();
		for (int i = 0; i < m; i++){
			if (find(group[i].begin(), group[i].end(), temp) != group[i].end()){
				for (auto it : group[i]){
					if (!people.count(it)){
						notused.push(it);
						people.insert(it);
					}
				}
			}
		}
	}
	return people.size();
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> group(m, vector<int>());
	for (int i = 0; i < m; i++){
		int x;
		cin >> x;
		int num;
		while (x--){
			cin >> num;
			group[i].push_back(num);
		}
	}
	cout << sumpeople(n, m, group) << endl;
	system("pause");
	return 0;
}
