#include <bits/stdc++.h>

namespace {
using namespace std;
} // namespace

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  size_t n, m, a;
  cin >> n >> m >> a;

  size_t squares_width = 0, squares_height = 0;

  if ((n % a) == 0) {
    squares_width = n / a;
  } else if ((n % a) > 0) {
    squares_width = (n / a) + 1;
  }

  if ((m % a) == 0) {
    squares_height = m / a;
  } else if ((m % a) > 0) {
    squares_height = (m / a) + 1;
  }

  size_t result = squares_width * squares_height;
  cout << result << endl;

  return 0;
}