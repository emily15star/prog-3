
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void quickSort(int a[], int levo, int desno, long long &iter)
{
    int i = levo;
    int j = desno;
    int pivot = a[(levo + desno) / 2];

    while (i <= j)
    {
        iter++;

        while (a[i] < pivot)
            i++;

        while (a[j] > pivot)
            j--;

        if (i <= j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;

            i++;
            j--;
        }
    }

    if (levo < j)
        quickSort(a, levo, j, iter);

    if (i < desno)
        quickSort(a, i, desno, iter);
}

int main()
{
    srand(time(0));

    int golemini[] = {100, 10000, 1000000};

    for (int k = 0; k < 3; k++)
    {
        int n = golemini[k];
        int *a = new int[n];

        for (int i = 0; i < n; i++)
            a[i] = rand() % 2000001 - 1000000;

        long long iter = 0;

        clock_t pocetok = clock();

        quickSort(a, 0, n - 1, iter);

        clock_t kraj = clock();

        double vreme = double(kraj - pocetok) / CLOCKS_PER_SEC;

        cout << "Elementi: " << n << endl;
        cout << "Vreme: " << vreme << " sekundi" << endl;
        cout << "Iteracii: " << iter << endl << endl;

        delete[] a;
    }

    return 0;
}
