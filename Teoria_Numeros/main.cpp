#include <iostream>

using namespace std;

int Euclides_Algoritmo1(int iMayor, int iMenor){
    int iresto;

    if (iMayor >=0) && (iMenor >=0){
        iresto = iMayor % iMenor;
        if (iresto == 0){
            return b;
        }
        else {
            iMayor = iMenor;
            iMenor = iresto;
        }
    }
}

int Euclides_Algoritmo2(int iMayor, int iMenor){
    int iresto;

    if (iMayor >=0) && (iMenor >=0){
        iresto = iMayor % iMenor;
        if (iresto == 0){
            return b;
        }
        if (iresto > (iMenor/2)){
            iresto = iMenor - iresto;
        }
        iMayor = iMenor;
        iMenor = iresto;
        }
    }
}

int Euclides_mcd (int iMayor, int iMenor){
    int iresto;

    if (iMayor >=0) && (iMenor >=0){
        if (iMenor == 0)
            return iMayor;
        return Euclides_mcd (iMenor, iMayor % iMenor);
    }
}

int Euclides_BinaryGcd (int iMayor, int iMenor){
    if (iMenor > iMayor)
        return Euclides_BinaryGcd (iMenor, iMayor)
    if (iMenor == 0)
        return iMayor;
    if (iMayor%2 == 0)%% (iMenor%2 == 0)
        return 2;
    if (iMayor%2 ==0) && (iMenor%2 != 0)
        return Euclides_BinaryGcd (iMayor/2,iMenor);
    if (iMayor%2 !=0) && (iMenor%2 == 0)
        return Euclides_BinaryGcd (iMayor,iMenor/2);
    else
        return Euclides_BinaryGcd ((iMayor - iMenor/2),iMenor);
}

int main()
{
    return 0;
}
