// Урок 54
// Быстрая сортировка
#include <vector>
#include <iostream>
using namespace std;

void sort(vector<int> &v, int b0, int e0)
{
    auto d = v[e0];
    auto b = b0;
    auto e = e0;
    do 
    {
        while (v[b] < d)
            ++b;
        while (v[e] > d)
            --e;
        if (b <= e)
        {
            swap(v[b], v[e]);
            ++b;
            --e;
        }
    } while (b <= e);
    if (e > b0)
        sort(v, b0, e);
    if (b < e0)
        sort(v, b, e0);
}

int main()
{
    vector<int> v;
    for (int i = 0; i < 20; ++i)
        v.push_back(i);
    for (size_t i = 0; i < v.size(); ++i)
        swap(v[i], v[rand() % (v.size() - i) + i]);
    for (auto i: v)
        cout << i << " ";
    cout << endl;
    sort(v, 0, v.size() - 1);
    for (auto i: v)
        cout << i << " ";
    cout << endl;
}
