// Урок 58 Музыка
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

enum N { A0 = 0, As0, B0, C, Cs, D, Ds, E, F, Fs, G, Gs, A, As, B, C2, Cs2, D2, Ds2, E2, F2, Fs2, G2, Gs2, A2, As2, B2, C3 };

class Aa
{
public:
    Aa(vector<pair<int, int> > &v):
        melody(v)
    {}
    Aa &operator()(N n, float d)
    {
        melody.push_back(make_pair(n, 16 / d));
        return *this;
    };
private:
    vector<pair<int, int> > &melody;
};

int main()
{
    float k = pow(2.0f, 1.0f / 12.0f);
    vector<pair<int, int> > melody;
    
    Aa a{melody};
    
    a
        (G, 16.0 / 3.0)
        (E, 16)
        (C, 4)
        (E, 4)
        (G, 4)
        (C2, 2)
        (E2, 16.0 / 3.0)
        (D2, 16)
        (C2, 4)
        (E, 4)
        (Fs, 4)
        (G, 2)
        (G, 8)
        (G, 8)
        (E2, 8.0 / 3.0)
        (D2, 8)
        (C2, 4)
        (B, 2)
        (A, 16.0 / 3.0)
        (B, 16)
        (C2, 4)
        (C2, 4)
        (G, 4)
        (E, 4)
        (C, 4)
        
        (G, 16.0 / 3.0)
        (E, 16)
        (C, 4)
        (E, 4)
        (G, 4)
        (C2, 2)
        (E2, 16.0 / 3.0)
        (D2, 16)
        (C2, 4)
        (E, 4)
        (Fs, 4)
        (G, 2)
        (G, 8)
        (G, 8)
        (E2, 8.0 / 3.0)
        (D2, 8)
        (C2, 4)
        (B, 2)
        (A, 16.0 / 3.0)
        (B, 16)
        (C2, 4)
        (C2, 4)
        (G, 4)
        (E, 4)
        (C, 4)

        (E2, 8)
        (E2, 8)
        (E2, 4)
        (F2, 4)
        (G2, 4)
        (G2, 2)
        (F2, 16.0 / 3.0)
        (E2, 16)

        (D2, 4)
        (E2, 4)
        (F2, 4)
        (F2, 2)
        (F2, 4)
        (E2, 8.0f / 3.0f)
        (D2, 8)
        (C2, 4)
        (B, 2)
        (A, 16.0 / 3.0)
        (B, 16)
        (C2, 4)
        (E, 4)
        (Fs, 4)
        (G, 2)
        (G, 4)
        (C2, 4)
        (C2, 4)
        (C2, 8)
        (B, 8)
        (A, 4)
        (A, 4)
        (A, 4)
        (D2, 4)
        (F2, 8)
        (E2, 8)
        (D2, 8)
        (C2, 8)
        (C2, 4)
        (B, 4)
        (G, 8)
        (G, 8)
        (C2, 16.0f / 3.0f)
        (D2, 16)
        (E2, 8)
        (F2, 8)
        (G2, 2)
        (C2, 8)
        (D2, 8)
        (E2, 8.0f / 3.0f)
        (F2, 8)
        (D2, 4)
        (C2, 1)
        ;
    for (auto n: melody)
    {
        int freq = 440.0f * pow(k, n.first);
        for (int i = 0; i < n.second * 60 * 44100 / 100 / 4 - 440; ++i)
        {
            int16_t a = i % (44100 / freq) > (44100 / freq / 2) ? 32000 : -32000;
            cout.write((const char *)&a, sizeof(a));
        }
        for (int i = 0; i < 440; ++i)
        {
            int16_t a = 0;
            cout.write((const char *)&a, sizeof(a));
        }
    }
}
