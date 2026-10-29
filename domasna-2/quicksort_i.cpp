
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void quickSort(int a[], int n, long long &iter)
{
    int *levo = new int[n];
    int *desno = new int[n];

    int vrv = 0;
    levo[vrv] = 0;
    desno[vrv] = n - 1;

    while (vrv >= 0)
    {
        int l = levo[vrv];
        int d = desno[vrv];
        vrv--;

        int i = l;
        int j = d;
        int pivot = a[(l + d) / 2];

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

        if (l < j)
        {
            vrv++;
            levo[vrv] = l;
            desno[vrv] = j;
        }

        if (i < d)
        {
            vrv++;
            levo[vrv] = i;
            desno[vrv] = d;
        }
    }

    delete[] levo;
    delete[] desno;
}

int main()
{
    srand(42);

    int golemini[] = {100, 10000, 1000000};

    for (int k = 0; k < 3; k++)
    {
        int n = golemini[k];
        int *a = new int[n];

        for (int i = 0; i < n; i++)
            a[i] = rand() % 2000001 - 1000000;

        long long iter = 0;

        clock_t pocetok = clock();

        quickSort(a, n, iter);

        clock_t kraj = clock();

        double vreme = double(kraj - pocetok) / CLOCKS_PER_SEC;

        cout << "Elementi: " << n << endl;
        cout << "Vreme: " << vreme << " sekundi" << endl;
        cout << "Iteracii: " << iter << endl << endl;

        delete[] a;
    }

    return 0;
}
