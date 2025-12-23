#include <bits/stdc++.h>

namespace {
using namespace std;

} // namespace

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> pos(n + 1);

  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    pos[a] = i;
  }

  long long vas = 0;
  long long pet = 0;
  long long m;
  cin >> m;

  while (m--) {
    int b;
    cin >> b;

    int p = pos[b];
    vas += p;
    pet += (n - p + 1);
  }

  cout << vas << ' ' << pet;

  return 0;
}