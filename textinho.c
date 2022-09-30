#include "header.h"
bool IsAnyKeyPressed()
{
    bool keyPressed = false;
    int key = GetKeyPressed();

    if ((key >= 32) && (key <= 126)) keyPressed = true;

    return keyPressed;
}


char * toArray(int number)
{
    int n = log10(number) + 1;
    char *numberArray = calloc(n, sizeof(char));
    for (int nada = n-1; nada >= 0; --nada, number /= 10)
    {
        numberArray[nada] = (number % 10) + '0';
    }
    return numberArray;
}

int compara(const void* a,const void* b){
    mitinho* p1 = (mitinho*) a;
    mitinho* p2 = (mitinho*) b;
    return (p2->pontos-p1->pontos);
}

int compara2(const void* a,const void* b){
    mitinho* p1 = (mitinho*) a;
    mitinho* p2 = (mitinho*) b;
    return (p1->pontos-p2->pontos);
}