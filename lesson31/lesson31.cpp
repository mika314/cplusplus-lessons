#include <iostream>
using namespace std; string s = "\";\nvoid r(string &s, char c, string str)\n{\n  size_t p = 0;\n  while ((p = s.find(c, p)) != string::npos)\n  { s = s.substr(0, p) + str + s.substr(p + 1); p += str.size(); }\n}\nint main()\n{\n  string z = s;\n  r(z, '\\\\', \"\\\\\\\\\"); r(z, '\\n', \"\\\\n\"); r(z, '\"', \"\\\\\\\"\");\n  cout << \"#include <iostream>\\nusing namespace std; string s = \\\"\" << z << s;\n}\n";
void r(string &s, char c, string str)
{
  size_t p = 0;
  while ((p = s.find(c, p)) != string::npos)
  { s = s.substr(0, p) + str + s.substr(p + 1); p += str.size(); }
}
int main()
{
  string z = s;
  r(z, '\\', "\\\\"); r(z, '\n', "\\n"); r(z, '"', "\\\"");
  cout << "#include <iostream>\nusing namespace std; string s = \"" << z << s;
}
