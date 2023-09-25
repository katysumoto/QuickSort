#include <iostream>

using namespace std;

void quicksort(int v[], int lb, int ub);
int particiona(int v[], int lb, int ub);

int main()
{
    int v[5] = {5, 10, 1, 52, 18};
    for(int i=0; i<5; i++)
    {
        cout << v[i] << "\t";
    }
    cout << endl;
    quicksort(v, 0, 4);
    for(int i=0; i<5; i++)
    {
        cout << v[i] << "\t";
    }
    cout << endl;
    return 0;
}

void quicksort(int v[], int lb, int ub)
{
    if(lb >= ub)
        return;
    int pivo = particiona(v, lb, ub);
    quicksort(v, lb, pivo-1);
    quicksort(v, pivo+1, ub);
}

int particiona(int v[], int lb, int ub)
{
    int up = ub;
    int down = lb;
    int pivo = v[lb];
    int aux;
    while(up >= down)
    {
        while(v[down]<=pivo)
            down++;
        while(v[up]>pivo)
            up--;
        if(up>=down)
        {
            aux = v[up];
            v[up] = v[down];
            v[down] = aux;
        }
    }
    v[lb] = v[up];
    v[up] = pivo;
    return up;

}
