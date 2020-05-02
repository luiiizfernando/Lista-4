#include <stdio.h>
#include <stdlib.h>
#include "com112_sort.h"
#include "com112_file.h"

void escolha(int opcao, int *v, int n, int *comparacao, int *movimento)
{
    if(opcao == 1)
    {
        metodoBolha(v, n, comparacao, movimento);
    }
    else if(opcao == 2)
    {
        selection_sort(v, n, comparacao, movimento);
    }
    else if(opcao == 3)
    {
        insertion_sort(v, n, comparacao, movimento);
    }
}

void metodoBolha(int *v,int n, int *comparacao, int *movimento)
{
    int aux;

    for(int j = 0; j < n; j++)
    {
        for(int i = 0; i < n-1; i++)
        {
            *comparacao = *comparacao + 1;
            if(v[i] > v[i+1])
            {
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                *movimento = *movimento + 1;
            }
        }
    }
}

void selection_sort(int *v, int n, int *comparacao, int *movimento)
{
    int menor, troca;
    for(int i = 0; i < n-1; i++)
    {
        menor = i;
        for(int j = i+1; j < n; j++)
        {
            *comparacao = *comparacao + 1;
            if(v[j] < v[menor])
            {
                menor = j;
            }
        }
        if(i != menor)
        {
            troca = v[i];
            v[i] = v[menor];
            v[menor] = troca;
            *movimento = *movimento + 1;
        }
    }
}

void insertion_sort(int *v, int n, int *comparacao, int *movimento)
{
    int aux, j;
    for(int i = 1; i < n; i++)
    {
        aux = v[i];
        *comparacao = *comparacao + 1;
        for(j = i; (j > 0) && (aux < v[j - 1]); j--)
        {
            v[j] = v[j - 1];
            *movimento = *movimento + 1;
        }
        v[j] = aux;
    }
}
