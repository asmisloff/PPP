#include "../std_lib_facilities.h"

int main()
{
  vector<int> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  vector<string> words = {"zero", "one", "two", "three", "four", "five", "six",
                          "seven", "eight", "nine"};
  string arg;
  string input;
  int number;

  while (true) {
    cout << "Enter digit or word: ";
    cin >> input;
    try {
      number = stoi(input);
      if (number >= 0 && number <= 9) {
        cout << words[number] << endl;
      }
      else {
        cout << "Unknown number -- " << number << endl;
      }
    }
    catch (...) {
      int i;
      for (i = 0; i < words.size(); i++) {
        if (words[i] == input) {
          cout << digits[i] << endl;
          break;
        }
      }
      if (i == words.size()) {
        cout << "Unknown word -- " << input << endl;
      }
    }
  }
}
