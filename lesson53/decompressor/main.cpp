#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    struct Node
    {
        char ch;
        int parent;
        int zero;
        int one;
        bool branch;
    };
    vector<Node> tree;

    ifstream f("../lesson48.huff");
    int treeSize;
    f.read((char *)&treeSize, sizeof(treeSize));
    for (int i = 0; i < treeSize; ++i)
    {
        Node n;
        f.read((char *)&n, sizeof(n));
        tree.push_back(n);
    }
    vector<bool> data;
    while (!f.eof())
    {
        unsigned char ch;
        f.read((char *)&ch, sizeof(ch));
        for (int i = 0; i < 8; ++i)
            data.push_back((ch & (1 << i)) != 0);
    }
    auto n = tree.size() - 1;
    for (auto i: data)
    {
        if (i)
            n = tree[n].one;
        else
            n = tree[n].zero;
        if (tree[n].one == -1)
        {
            cout << tree[n].ch;
            n = tree.size() - 1;
        }
    }
}
