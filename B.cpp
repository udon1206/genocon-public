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
  const int sim[5][5] = { 
                    {1, -3, -3, -3, -5}, 
                    {-3, 1, -3, -3, -5},
                    {-3, -3, 1, -3, -5},
                    {-3, -3, -3, 1, -5},
                    {-5, -5, -5, -5, -5}
                  };
  std::string s, t; cin >> s >> t;
  std::vector<int> a(s.size()), b(t.size());
  for (int i = 0; i < (int)s.size(); ++i)
  {
    if(s[i] == 'A')
      a[i] = 0;
    else if(s[i] == 'C')
      a[i] = 1;
    else if(s[i] == 'G')
      a[i] = 2;
    else if(s[i] == 'T')
      a[i] = 3;
  }

  for (int i = 0; i < (int)t.size(); ++i)
  {
    if(t[i] == 'A')
      b[i] = 0;
    else if(t[i] == 'C')
      b[i] = 1;
    else if(t[i] == 'G')
      b[i] = 2;
    else if(t[i] == 'T')
      b[i] = 3;
  }

  std::vector dp(s.size() + 1, std::vector<int>(t.size() + 1, -inf));
  std::vector kkt89_cute(s.size() + 1, std::vector<std::pair<int, int>>(t.size() + 1, {-1, -1}));
  dp[0][0] = 0;
  for (int i = 0; i <= (int)a.size(); ++i)
  {
    for (int j = 0; j <= (int)b.size(); ++j)
    {
      if(i + 1 <= (int)a.size() and j + 1 <= (int)b.size())
      {
        if(chmax(dp[i + 1][j + 1], dp[i][j] + sim[a[i]][b[j]]))
        {
          kkt89_cute[i + 1][j + 1] = {i, j};
        }
      }
      if(i + 1 <= (int)a.size())
      {
        if(chmax(dp[i + 1][j], dp[i][j] + sim[a[i]][4]))
        {
          kkt89_cute[i + 1][j] = {i, j};
        }

      }
      if(j + 1 <= (int)b.size())
      {
        if(chmax(dp[i][j + 1], dp[i][j] + sim[4][b[j]]))
        {
          kkt89_cute[i][j + 1] = {i, j};
        }
      }
    }
  }

  std::pair<int, int> cur = {a.size(), b.size()};
  std::string resa, resb;
  while(cur.first + cur.second > 0)
  {
    const auto b = kkt89_cute[cur.first][cur.second];
    if(b.first + 1 == cur.first)
    {
      resa += s[b.first];
    }
    else
    {
      resa += '-';
    }
    if(b.second + 1 == cur.second)
    {
      resb += t[b.second];
    }
    else
    {
      resb += '-';
    }
    cur = b;
  }
  std::reverse(resa.begin(), resa.end());
  std::reverse(resb.begin(), resb.end());
  cout << resa << "\n";
  cout << resb << "\n";

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