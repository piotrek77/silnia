#include <iostream>

using namespace std;


/*
Program ma liczyæ silniê dla n z zakresu od 1 do 50
50! = 30414093201713378043612608166064768844377641568960512000000000000
49! = 608281864034267560872252163321295376887552831379210240000000000
.
.
.
5! = 120
4! = 24
3! = 6
2! = 2
1! = 1

Jak widaæ 50! ma 65 znaków, ¿aden typ w C++ nie potrafi przenosiæ dok³adnie takich liczb ca³kowitych




*/
int const  rozmiarMax = 700;


class BigInt
{

    int rozmiar; //ile cyfr ma liczba
    int liczba[rozmiarMax];

public:

    void Wyzeruj()
    {
        for (int i = 0; i <rozmiarMax; i++)
        {
            liczba[i]  =0;
        }
        rozmiar = 0;
    }

    void UstawJeden()
    {
        Wyzeruj();
        liczba[0]=1;
        rozmiar = 1;

    }

    BigInt()
    {
        Wyzeruj();
    }


    string LiczbaStr()
    {
        string wynik ="";
        for (int i=rozmiar + 1 ;i>=0;i--)
        {
            if ((liczba[i]!=0) || ( wynik.length()>0 ))
            {
                wynik += liczba[i] +48; //taka sztuczka aby przekonwertowaæ cyfrê na znak (ascii)

            }
        }
        return wynik;
    }


    //mno¿y liczbê liczba[] * mnoznik
    //wynik zapisuje w liczba[]
    void Pomnoz(int mnoznik)
    {
       int doPrzeniesienia = 0;


    for (int i=0; i<rozmiar; i++)
    {
        int prod = liczba[i] * mnoznik + doPrzeniesienia;
        liczba[i] = prod % 10;
        doPrzeniesienia  = prod/10;
    }


    while (doPrzeniesienia)
    {
        liczba[rozmiar] = doPrzeniesienia%10;
        doPrzeniesienia = doPrzeniesienia/10;
        rozmiar++;
    }

    }

};

int main()
{
    BigInt duzaLiczba;
    duzaLiczba.UstawJeden();


    int l = 100;

    for (int i = 2;i<=l;i++)
    {
        duzaLiczba.Pomnoz(i);
    }

    cout << duzaLiczba.LiczbaStr()<<endl;
    return 0;
}
