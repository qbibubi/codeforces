#include <bits/stdc++.h>

namespace {
using namespace std;

[[nodiscard]] bool is_palindrome_possible(string const &str) {
  unordered_map<char, size_t> counts;

  for (auto const &ch : str) {
    auto it = counts.find(ch);
    if (it != counts.end()) {
      it->second += 1;
      continue;
    }

    counts.insert(make_pair(ch, 1));
  }

  auto odds = count_if(counts.begin(), counts.end(),
                       [](auto const &pair) { return pair.second % 2 != 0; });
  if (odds <= 1) {
    return true;
  }

  return false;
}
} // namespace

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string str;
  cin >> str;

  bool turn = false;

  while (true) {
    if (is_palindrome_possible(str)) {
      break;
    }

    vector<size_t> possible_palindromes;

    for (auto i = 0; i < str.length(); ++i) {
      auto copy = str;
      copy.erase(i, 1);

      auto const possible_palindrome = is_palindrome_possible(copy);
      if (possible_palindrome) {
        possible_palindromes.push_back(1);
        continue;
      }

      possible_palindromes.push_back(0);
      break;
    }

    for (auto i = 0; i < possible_palindromes.size(); ++i) {
      if (possible_palindromes[i] != 1) {
        str.erase(i, 1);
        break;
      }

      str.erase(0, 1);
      break;
    }

    turn = !turn;
  }

  if (turn) {
    cout << "Second" << endl;
  } else {
    cout << "First" << endl;
  }

  return 0;
}