// Урок 46
// Ханойская башня без рекурсии
#include <iostream>
#include <vector>
using namespace std;

struct State
{
    int n;
    int src;
    int dest;
    int tmp;
    int step;
};

void tower(int n, int src, int dest, int tmp)
{
    vector<State> stack;
    {
        State state;
        state.n = n;
        state.src = src;
        state.dest = dest;
        state.tmp = tmp;
        state.step = 0;
        stack.push_back(state);
    }
    while (stack.size() > 0)
    {
        State &state = stack.back();
        switch (state.step)
        {
        case 0:
            if (state.n == 0)
                stack.pop_back();
            else
            {
                ++state.step;
                State newState;
                newState.n = state.n - 1;
                newState.src = state.src;
                newState.dest = state.tmp;
                newState.tmp = state.dest;
                newState.step = 0;
                stack.push_back(newState);
            }
            break;
        case 1:
            cout << state.src << "->" << state.dest << endl;
            ++state.step;
            State newState;
            newState.n = state.n - 1;
            newState.src = state.tmp;
            newState.dest = state.dest;
            newState.tmp = state.src;
            newState.step = 0;
            stack.push_back(newState);
            break;
        case 2:
            stack.pop_back();
            break;
        }
    }
}

int main()
{
    tower(5, 1, 2, 3);
}
