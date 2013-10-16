#include <iostream>
#include <string>
#include <map>
using namespace std;

int fromRoman(string n)
{
    map<char, int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
    
    int tmp = 0;
    int res = 0;
    for (char c: n)
    {
        int n = m[c];
        if (n < tmp)
        {
            res += tmp;
            tmp = n;
        }
        else if (n > tmp)
        {
            if (tmp == 0)
                tmp = n;
            else
            {
                res += n - tmp;
                tmp = 0;
            }
        }
        else if (n == tmp)
        {
            res += tmp + n;
            tmp = 0;
        }
    }
    return res + tmp;
}

int main()
{
    const char *romanNumbers[] = {
        "IV",
        "IIII",
        "VIII",
        "IX",
        "XXXI",	
        "XLVI",	
        "XCIX",	
        "DLXXXIII",
        "DCCCLXXXVIII",
        "MDCLXVIII",
        "MCMLXXXIX",
        "MMX",
        "MMXI",
        "MMXII",
        "MMMCMXCIX"
    };
    for (auto r: romanNumbers)
        cout << r << " is " << fromRoman(r) << endl;
}
