#include <bits/stdc++.h>
using namespace std;

// int main(){
//     cin.tie(nullptr)->sync_with_stdio(false);
//     string str, str2;
//     cin>> str>>str2;

//     int n = str.length(), m = str2.length();

//     vector<vector<int>> v(n+1, vector<int>(m+1));

//     for(int i = n-1; i>=0; i--){
//         for(int j = m-1;j>=0; j--){
//             if(str[i] == str2[j]){
//                 v[i][j] = i+v[i+1][j+1];
//                 continue;
//             }
//             v[i][j] = max(v[i][j], v[i+1][j]);
//             v[i][j] = max(v[i][j], v[i][j+1]);
//         }
//     }

//     cout<<v[0][0]<<'\n';
//     return 0;
// }
int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	string s, t;
	cin >> s >> t;
	int n = s.length() , m = t.length();

	vector<vector<int>> dp(n + 1, vector<int>(m + 1));

	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			// calculate dp(i)(j)
			if (s[i] == t[j]) {
				dp[i][j] = 1 + dp[i + 1][j + 1];
				continue;
			}
			dp[i][j] = max(dp[i][j], dp[i + 1][j]);
			dp[i][j] = max(dp[i][j], dp[i][j + 1]);
		}
	}

	cout << dp[0][0] << '\n';
	return 0;
}