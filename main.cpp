#include <iostream>
#include <string>

using namespace std;

int main()
{
    const unsigned int S = 257;
    unsigned int Sm1 = 1; // S^(m-1)
    string P = "Hello", T = "sdHellosadfsaHellolloHellodasdsassdfa";
    int m = P.length(), n = T.length();

    unsigned int M = 1;
    M<<=10; M--;

    //cout<<M<<endl;

    for (int j = 0; j < m-1; j++)
    {
        Sm1 = (Sm1 * S) & M;
    }

    unsigned int h = 0; // hash of P

    for (int j = 0; j < m; j++)
    {
        h = (((h * S) & M) + P[j] ) & M;
        //cout<<h;
    }

    cout<<"The hash for P is "<< h <<endl<<endl;
    unsigned int rollh = 0; // Horner's rule

    for (int i = 0; i < m; i++)
        rollh = (((rollh * S) & M) + T[i] ) & M;

    int i=0;
    cout <<"Shift "<<i<<"\t rollhash "<<rollh<<endl;
    if (h == rollh) {
        int j = 0;
        while (j < m && T[j] == P[j])
            j++;
        if (j == m)
            cout<<"Hit"<<endl;
        else
            cout << "A spurious hit"<<endl;
    }

    for (int i = 1; i < n - m; i++)
    {
        rollh = (((rollh + (M + 1 - ((T[i-1] * Sm1) & M) )&M ) * S & M) + T[i + m - 1]) & M;
        cout <<"Shift "<<i<<"\t rollhash "<<rollh<<endl;
        if (h == rollh) {
            int j = 0;
            while (j < m && T[i+j] == P[j])
                j++;
            if (j == m)
                cout<<"Hit"<<endl;
            else
                cout << "A spurious hit"<<endl;
        }
    }


    return 0;
}
