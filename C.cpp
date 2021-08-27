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
	int m; cin >> m;
	std::vector<std::string> vs(m);
	const int id = 0;
	for (int i = 0; i < m; ++i)
	{
		cin >> vs[i];
	}

	for (int kkt = 88; kkt <= 89; kkt++)
	{
		std::vector<std::vector<int>> dp, kkt89_cute;
		for (int jupi = 0; jupi < m; ++jupi)
		{
			if(jupi == id)
				continue;
			const auto &s = vs[jupi];
			const auto &t = vs[id];
			dp.clear(); dp.resize(s.size() + 1, std::vector<int>(t.size() + 1, inf));
			kkt89_cute.clear(); kkt89_cute.resize(s.size() + 1, std::vector<int>(t.size() + 1, inf));
			dp[0][0] = 0;
			for (int i = 0; i <= (int)s.size(); ++i)
			{
				for (int j = 0; j <= (int)t.size(); ++j)
				{
					if(i + 1 <= (int)s.size() and j + 1 <= (int)t.size())
					{
						if(s[i] == t[j] and chmin(dp[i + 1][j + 1], dp[i][j]))
						{
							kkt89_cute[i + 1][j + 1] = 0;
						}
						if(chmin(dp[i + 1][j + 1], dp[i][j] + 1))
						{
							kkt89_cute[i + 1][j + 1] = 0;
						}
					}
					if(kkt != 89)
					{
						if(i + 1 <= (int)s.size())
						{
							if(chmin(dp[i + 1][j], dp[i][j] + 1))
							{
								kkt89_cute[i + 1][j] = 1;
							}
						}
					}
					if(j + 1 <= (int)t.size())
					{
						if(chmin(dp[i][j + 1], dp[i][j] + 1))
						{
							kkt89_cute[i][j + 1] = 2;
						}
						if(t[j] == '-' and chmin(dp[i][j + 1], dp[i][j]))
						{
							kkt89_cute[i][j + 1] = 2;
						}
					}
				}
			}
			std::string rest, ress;
			int sid = (int)s.size(), tid = (int)t.size();
			while (sid > 0 or tid > 0)
			{
				if(kkt89_cute[sid][tid] == 0)
				{
					rest += t[tid - 1];
					ress += s[sid - 1];
					sid -= 1, tid -= 1;
				}
				else if(kkt89_cute[sid][tid] == 1)
				{
					rest += '-';
					ress += s[sid - 1];
					sid -= 1;
				}
				else
				{
					rest += t[tid - 1];
					ress += '-';
					tid -= 1;
				}
			}
			std::reverse(ress.begin(), ress.end());
			std::reverse(rest.begin(), rest.end());
			std::swap(vs[id], rest);
			std::swap(vs[jupi], ress);
		}
	}
	for (int i = 0; i < m; ++i)
	{
		cout << vs[i] << "\n";
	}
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