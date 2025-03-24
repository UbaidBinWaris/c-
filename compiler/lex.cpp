#include <iostream>
#include <regex>
using namespace std;

void analyzeToken(const string &token)
{
  // Regular expressions for different token types
  regex numberRegex("^[0-9]+$");
  regex identifierRegex("^[a-zA-Z_][a-zA-Z0-9_]*$");
  regex textRegex("^\"[^\"]*\"$");
  regex commentRegex("^#.*$");

  if (regex_match(token, numberRegex))
  {
    cout << "Number: " << token << endl;
  }
  else if (regex_match(token, identifierRegex))
  {
    cout << "Command (Identifier): " << token << endl;
  }
  else if (regex_match(token, textRegex))
  {
    cout << "Text: " << token << endl;
  }
  else if (regex_match(token, commentRegex))
  {
    cout << "Comment: " << token << endl;
  }
  else
  {
    cout << "Unknown Token: " << token << endl;
  }
}

int main()
{
  string input;
  cout << "Enter tokens (Type 'exit' to quit):\n";

  while (true)
  {
    cout << "> ";
    getline(cin, input);

    if (input == "exit")
      break;

    analyzeToken(input);
  }

  return 0;
}
