#include <bits/stdc++.h>
using namespace std;

class node
{ //priority , next , islast;

public:
    int priority[27];
    node *next[27];
    bool islast;
    bool used;
    node()
    {
        used = false;
        for (int i = 0; i < 27; i++)
        {
            priority[i] = 0;
            next[i] = NULL;
        }
        islast = false;
    }
};

class trie
{
private:
    node *root;
    unordered_map<int, string> store;

public:
    trie()
    {
        root = new node();
    }
    string find(string x)
    {
        string answer = "";
        node *current = root;

        int prior;
        for (int i = 0; i < x.length(); i++)
        {
            int index;
            if (x[i] == '-')
            {
                index = 26;
            }
            else
            {
                index = x[i] - 'a';
            }
            if (current->next[index] != NULL)
            {
                if (i == x.length() - 1)
                {
                    prior = current->priority[index];
                    return store[prior];
                }
                current = current->next[index];
            }
            else
            {
                return "-1";
            }
        }
    }
    void insert(string s, int p)
    {
        store[p] = s;
        node *current = root;
        for (int i = 0; i < s.length(); i++)
        {

            int index;
            if (s[i] == '-')
            {
                index = 26;
            }
            else
            {
                index = s[i] - 'a';
            }
            if (current->used == false)
            {
                current->used = true;
                current->priority[index] = p;
                current->next[index] = new node();
                current = current->next[index];
            }
            else
            {
                if (current->next[index] == NULL)
                {
                    current->priority[index] = p;
                    current->next[index] = new node();
                    current = current->next[index];
                }
                else
                {
                    if (p > current->priority[index])
                    {
                        current->priority[index] = p;
                    }
                    current = current->next[index];
                }
            }
            if (i == s.length() - 1)
            {
                current->islast = true;
            }
        }
    }
};

int main()
{
    trie tejus;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        string x;
        int y;
        cin >> x;
        cin >> y;
        tejus.insert(x, y);
    }
    int q;
    cin >> q;
    while (q--)
    {
        string df;
        cin >> df;
        cout << tejus.find(df) << "\n";
    }
}