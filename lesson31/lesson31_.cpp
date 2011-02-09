// Урок 30
// Программа которая распечатывает саму себя
#include <iostream>
using namespace std;

const char *src =
  "int main()\n"
  "{\n"
  "  cout << \"#include <iostream>\" << endl;\n"
  "  cout << \"using namespace std;\" << endl;\n"
  "  cout << \"const char *src =\";\n"
  "  bool newLine = true;\n"
  "  for (const char *i = src; *i != '\\0'; ++i)\n"
  "  {\n"
  "    if (newLine)\n"
  "    {\n"
  "      cout << \"\\n  \"\";\n"
  "      newLine = false;\n"
  "    }\n"
  "    switch (*i) \n"
  "    {\n"
  "    case '\\n':\n"
  "      cout << \"\\\\n\\\";\n"
  "      newLine = true;\n"
  "      break;\n"
  "    case '\"':\n"
  "      cout << \"\\\"\";\n"
  "      break;\n"
  "    case '\\':\n"
  "      cout << \"\\\\\";\n"
  "      break;\n"
  "    default:\n"
  "      cout << *i;\n"
  "    }\n"
  "  }\n"
  "  cout << \";\\n\";\n"
  "  cout << src;\n"
  "}\n";
int main()
{
  cout << "#include <iostream>" << endl;
  cout << "using namespace std;" << endl;
  cout << "const char *src =";
  bool newLine = true;
  for (const char *i = src; *i != '\0'; ++i)
  {
    if (newLine)
    {
      cout << "\n  \"";
      newLine = false;
    }
    switch (*i) 
    {
    case '\n':
      cout << "\\n\"";
      newLine = true;
      break;
    case '"':
      cout << "\\\"";
      break;
    case '\\':
      cout << "\\\\";
      break;
    default:
      cout << *i;
    }
  }
  cout << ";\n";
  cout << src;
}
