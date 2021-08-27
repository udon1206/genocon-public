#include <bits/stdc++.h>
using ll = long long;
using std::cin;
using std::cout;
using std::endl;
std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int inf = (int)1e9 + 7;
const long long INF = 1LL << 60;

void solve()
{
	std::vector<std::string> vs;
	std::string s;
	while (cin >> s)
	{
		vs.emplace_back(s);
	}
	int Call = 0;
	std::array<int, 5> cnt;
	for (int j = 0; j < (int)vs[0].size(); ++j)
	{
		std::fill(cnt.begin(), cnt.end(), 0);
		for (int i = 0; i < (int)vs.size(); ++i)
		{
			if(vs[i][j] == 'A')
				cnt[0] += 1;
			if(vs[i][j] == 'C')
				cnt[1] += 1;
			if(vs[i][j] == 'G')
				cnt[2] += 1;
			if(vs[i][j] == 'T')
				cnt[3] += 1;
			if(vs[i][j] == '-')
				cnt[4] += 1;
		}
		Call += (int)vs.size() - *std::max_element(cnt.begin(), cnt.end());
	}
	const int score = std::max(((int)vs.size() <= 10) ? (200 - Call * 2 / 10) : (700 - Call / 10), 0);
	cout << score << endl;
}
int main()
{
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  int kkt = 1; 
  // cin >> kkt;
  while(kkt--)
    solve();
  return 0;
  
}