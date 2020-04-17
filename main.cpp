#include <bits/stdc++.h>
#define d 10000
using namespace std;
typedef int_least64_t inte;
void mod_(int, int *);
void digalloc(int *, inte);
void copy_(int *, int *);
void disp(int *);
inte fact(int);
int main()
{
    inte j = 1;
    int i = 1, *k, n, t;
    cin >> t;
    while (t--)
    {

        cin >> n;
        k = (int *)calloc(d, sizeof(int));
        if (n <= 20)
            cout << endl
                 << fact(n);
        else
        {
            j = fact(20);
            //cout<<endl<<j<<endl;
            digalloc(k, j);
            for (i = 21; i <= n; i++)
            {
                mod_(i, k);
            }
            disp(k);
        }
    }
}
inte fact(int n)
{
    inte j = 1;
    for (int i = 1; i <= n; i++)
        j *= i;
    return j;
}
void mod_(int a, int *b)
{
    int *t, i;
    t = (int *)calloc(d, sizeof(int));
    copy_(b, t);
    for (i = 1; i < a; i++)
    {
        for (inte j = 0; j < d; j++)
        {
            b[j] = b[j] + t[j];
            if (b[j] >= 10)
            {
                b[j] -= 10;
                b[j + 1]++;
            }
        }
    }
}
void digalloc(int *a, inte b) /*to allot individual digits to single array cell*/
{
    int i = 0;
    while (b / 10)
    {
        a[i] += b % 10;
        b = b / 10;
        //cout<<endl<<a[i]<<endl<<b;
        i++; //3523844179886080000(fact 21),2432902008176640000(fact 20)
    }
    a[i] = b;
}
void copy_(int *a, int *b)
{
    for (int i = 0; i < d; i++)
        b[i] = a[i];
}
void disp(int *a)
{
    int j = d - 1;
    while (a[j] == 0)
        j--;
    j++;
    cout << j + 1 << endl;
    for (int i = 0; i < j; i++)
    {
        cout << a[j - i - 1];
    }
}
