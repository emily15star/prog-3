
#include <iostream>
using namespace std;

int n;
int tabla[20][20];

bool bezbedno(int red, int kolona)
{
    for (int i = 0; i < red; i++)
        if (tabla[i][kolona] == 1)
            return false;

    for (int i = red - 1, j = kolona - 1; i >= 0 && j >= 0; i--, j--)
        if (tabla[i][j] == 1)
            return false;

    for (int i = red - 1, j = kolona + 1; i >= 0 && j < n; i--, j++)
        if (tabla[i][j] == 1)
            return false;

    return true;
}

void kralici(int red)
{
    if (red == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << tabla[i][j] << " ";

            cout << endl;
        }

        cout << endl;
        return;
    }

    for (int kolona = 0; kolona < n; kolona++)
    {
        if (bezbedno(red, kolona))
        {
            tabla[red][kolona] = 1;

            kralici(red + 1);

            tabla[red][kolona] = 0;
        }
    }
}

int main()
{
    cin >> n;

    kralici(0);

    return 0;
}
