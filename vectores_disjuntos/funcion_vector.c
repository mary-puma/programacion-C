#include <stdio.h>
#include <stdlib.h>

int vectorDisjunto(int* vec1,int* vec2,int tam1, int tam2)
{
    int i,j;
    int* pini=vec2;
    for(i=0; i<tam1; i++)
    {
        for(j=0; j<tam2; j++)
        {
            if((*vec1)!=(*vec2))
            {
                vec2++;
            }
            else
            {
                return 0;
            }
        }
        vec2=pini;

        vec1++;
    }

    return 1;
}
