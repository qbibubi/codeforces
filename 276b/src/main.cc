#include <bits/stdc++.h>

namespace {
using namespace std;

[[nodiscard]] bool is_palindrome_possible(string const &s) {
  unordered_map<char, size_t> m;

  for (auto const &ch : s) {
    auto it = m.find(ch);
    if (it != m.end()) {
      it->second += 1ul;
      continue;
    }

    m.insert(make_pair(ch, 1ul));
  }

  bool palindrome_possible = true;
  if (m.size() % 2 == 0) {
    for (auto const &[ch, count] : m) {
      if (count % 2 == 0) {
        palindrome_possible &= true;
      } else {
        return false;
      }
    }
  } else {
    bool odd_found = false;

    for (auto const &[ch, count] : m) {
      if (count % 2 != 0 && !odd_found) {
        odd_found = true;
      } else {
        return false;
      }

      if (count % 2 == 0) {
        continue;
      }
    }
  }

  return palindrome_possible;
}
} // namespace

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string str;
  cin >> str;

  bool turn = false, game_finished = false;

  while (true) {
    for (auto i = 0; i < str.size(); ++i) {
      if (is_palindrome_possible(str)) {
        game_finished = true;
        break;
      }

      auto str_copy = str;

      cout << "---------------------\n";
      cout << "(before) str: " << str << endl;
      cout << "(before) str_copy: " << str_copy << endl;

      str_copy.erase(i, 1);

      cout << "(after) str: " << str << endl;
      cout << "(after) str_copy: " << str_copy << endl;

      if (!is_palindrome_possible(str_copy)) {
        str = str_copy;
        break;
      }

      turn = !turn;
    }

    if (game_finished) {
      break;
    }
  }

  if (turn) {
    cout << "Second" << endl;
  } else {
    cout << "First" << endl;
  }
  return 0;
}