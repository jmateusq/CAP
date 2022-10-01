#include "header.h"
bool IsAnyKeyPressed()
{
    bool keyPressed = false;
    int key = GetKeyPressed();

    if ((key >= 32) && (key <= 126)) keyPressed = true;

    return keyPressed;
}


char * intParaArray(int numero)
{
    int n = log10(numero) + 1;
    char *array = calloc(n, sizeof(char));
    for (int nada = n-1; nada >= 0; --nada, numero /= 10)
    {
        array[nada] = (numero % 10) + '0';
    }
    return array;
}

int compara(const void* a,const void* b){
    mitinho* p1 = (mitinho*) a;
    mitinho* p2 = (mitinho*) b;
    return (p2->pontos-p1->pontos);
}
