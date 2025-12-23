#include <bits/stdc++.h>

namespace {
using namespace std;

} // namespace

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int x = 0;
  for (int i = 0; i < n; ++i) {
    string str{""};
    cin >> str;

    if (str[0] == 'X') {
      if (str[1] == '+') {
        x++;
      } else {
        x--;
      }
    } else if (str[0] == '+') {
      ++x;
    } else {
      --x;
    }
  }

  cout << x << endl;
  return 0;
}