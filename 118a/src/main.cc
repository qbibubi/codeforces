#include <bits/stdc++.h>

namespace {
using namespace std;

bool is_uppercase(char ch) {
  if (ch >= 'A' && ch <= 'Z') {
    return true;
  }
  return false;
}

char to_lowercase(char ch) {
  if (ch <= 'Z' && ch >= 'A') {
    return ch - ('Z' - 'z');
  }
  return ch;
}

bool is_vowel(char ch) {
  char vowels[] = {'A', 'O', 'Y', 'E', 'U', 'I'};
  for (int i = 0; i < sizeof(vowels) / sizeof(vowels[0]); ++i) {
    if (ch == vowels[i] || ch == to_lowercase(vowels[i])) {
      return true;
    }
  }

  return false;
}
} // namespace

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string str, res;
  cin >> str;

  for (auto const ch : str) {
    if (is_vowel(ch)) {
      continue;
    }

    if (is_uppercase(ch)) {
      res = res + "." + to_lowercase(ch);
      continue;
    }

    res = res + "." + ch;
  }

  cout << res << endl;

  return 0;
}