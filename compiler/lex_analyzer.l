%{
#include <iostream>
using namespace std;
%}

%option c++

%%

[0-9]+               { cout << "Number: " << yytext << endl; }
[a-zA-Z_][a-zA-Z0-9_]* { cout << "Command (Identifier): " << yytext << endl; }
\"[^\"]*\"           { cout << "Text: " << yytext << endl; }
\#[^\n]*            { cout << "Comment: " << yytext << endl; }
[\t\n ]+             { /* Ignore whitespace */ }
.                    { cout << "Unknown character: " << yytext << endl; }

%%

int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
