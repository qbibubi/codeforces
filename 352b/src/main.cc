#include <bits/stdc++.h>

namespace {
using namespace std;

} // namespace

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  size_t n;
  cin >> n;
  map<size_t, vector<size_t>> m = {};
  for (size_t i = 1; i <= n; ++i) {
    size_t a;
    cin >> a;
    auto it = m.find(a);
    if (it != m.end()) {
      it->second.push_back(i);
      continue;
    }
    m.insert(make_pair(a, vector<size_t>{i}));
  }

  map<size_t, size_t> result = {};
  for (auto const &[k, v] : m) {
    size_t distance = 0;

    bool failed = false;
    if (v.size() > 1) {
      size_t firstDistance = v[1] - v[0];
      for (size_t i = 0; i < v.size() - 1; ++i) {
        size_t currentDistance = v[i + 1] - v[i];
        if (firstDistance != currentDistance) {
          failed = true;
          break;
        }
        distance = currentDistance;
      }
    }

    if (failed) {
      continue;
    }

    result[k] = distance;
  }

  cout << result.size() << endl;
  for (auto const &[k, v] : result) {
    cout << k << ' ' << v << endl;
  }
  return 0;
}