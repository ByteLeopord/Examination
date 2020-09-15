/*
n/(i∗10)∗i 表示 (i) 位上 'k' 的出现个数 
min(i, max(0, n %(i*10)-k*i+1)) 表示需要额外数的 (i*10)(i∗10) 位上 \text{'1'}’1’ 的个数。
*/
class Solution{
public:
	int countNum1(int n, int k){
		int res = 0;
		for(long long i = 1; i <= n; i *= 10){
			long long digmask = i*10;
			res += n/digmask * i + min(i, max(0, n%digmask-k*i+1));
		}
		return res;
	}
};
