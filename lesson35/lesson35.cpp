// Урок 35
// Кит и кот
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node
{
    Node(): yes(-1), no(-1) {}
    string q;
    int yes;
    int no;
};

int main()
{
    vector<Node> tree;
    Node n;
    n.q = "кит";
    tree.push_back(n);
    for (;;)
    {
        int i = 0;
        while (tree[i].yes != -1 && tree[i].no != -1)
        {
            cout << tree[i].q << "? (1 - да, 0 - нет) ";
            int ans;
            cin >> ans;
            if (ans == 1)
                i = tree[i].yes;
            else
                i = tree[i].no;
        }
        cout << "Это " << tree[i].q << "? (1 - да, 0 - нет) ";
        int ans;
        cin >> ans;
        if (ans == 1)
            cout << "Угадали!" << endl;
        else
        {
            cout << "Кто это? ";
            string anim;
            cin >> anim;
            cout << "Чем" << tree[i].q << " отличается от " << anim << "? ";
            string diff;
            cin >> diff;
            Node yes = tree[i];
            Node no;
            no.q = anim;
            tree[i].yes = tree.size();
            tree.push_back(yes);
            tree[i].no = tree.size();
            tree.push_back(no);
            tree[i].q = diff;
        }
        cout << "Ещё? (1 - да, 0 - нет) ";
        cin >> ans;
        if (ans == 0)
            break;
    }
}
