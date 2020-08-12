/*
乔治拿来一组等长的木棒，将它们随机地砍断，使得每一节木棍的长度都不超过50个长度单位。然后他又想把这些木棍恢复到为裁截前的状态，但忘记了初始时有多少木棒以及木棒的初始长度。请你设计一个程序，帮助乔治计算木棒的可能最小长度。每一节木棍的长度都用大于零的整数表示。

Input
输入包含多组数据，每组数据包括两行。第一行是一个不超过64的整数，表示砍断之后共有多少节木棍。第二行是截断以后，所得到的各节木棍的长度。在最后一组数据之后，是一个零。

Output
为每组数据，分别输出原始木棒的可能最小长度，每组数据占一行。
*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, sum, num;
bool flag;
int a[70], vis[70];

//pid:尝试的最小长度
//cnt:相加为最小长度的组合数量
//x  :当前组合相加的长度
bool dfs(int x, int pid, int cnt)
{
	//if (flag) return;
	if (x == pid) cnt++, x = 0;		//找出相加为pid的组合 cnt加1
	if (cnt == sum / pid)			//所有组合的数量为 总长/pid 时意味着所有木棍用完 递归结束
	{
		//flag = true;
		return true;
	}

	for (int k = n-1; k >= 0; k--)		//从长木棍开始加，因为短木棍的灵活度更高
	{
		if (vis[k]) continue;			//剪枝：该木棍已被使用
		if (x + a[k] > pid) continue;	//剪枝：该木棍加到组合中会超过pid限制

		vis[k] = 1;
		if (dfs(x + a[k], pid, cnt)) return true;		//找到最小pid 提前退出
		vis[k] = 0;
	}
	return false;
}
int main()
{
	vector<int> res;
	while (cin >> n)
	{
		if (n == 0) break;
		memset(a, 0, sizeof(a));
		memset(vis, 0, sizeof(vis));
		sum = 0; num = 0;
		for (int i = 1; i <= n; i++)
		{
			int tmp;
			cin >> tmp;
			if (tmp <= 50)
			{
				a[num++] = tmp;
				sum += tmp;
			}
		}
		sort(a, a + n);
		for (int i = a[n - 1]; i <= sum; i++)
		{
			if (sum%i != 0) continue;	//所选长度必须可以被总长整除
			flag = false;
			if (dfs(0, i, 1)){
				res.push_back(i);
				break;
			}
		}
	}
	for (auto it : res){
		cout << it << endl;
	}
	system("pause");
	return 0;
}
