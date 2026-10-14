#include <iostream>
using namespace std;

void quickSort(int a[], int levo, int desno)
{
    int i = levo;
    int j = desno;
    int pivot = a[(levo + desno) / 2];

    while (i <= j)
    {
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
        quickSort(a, levo, j);

    if (i < desno)
        quickSort(a, i, desno);
}

int main()
{
    int a[] = {8, -3, 4, 7, -10, 3, 7, 0, -1, 6};
    int n = sizeof(a) / sizeof(a[0]);// sizeof(a) dava vkupna golemina, dodeka pak sizeof([a]) dava golemina na eden elem od nizata, i dvete racunaat vo bajti, byte(se sostoi od 8 bita (bit)) 

    quickSort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
