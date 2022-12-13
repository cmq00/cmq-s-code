#include "Triplet.h"
#include <bits/stdc++.h>
using namespace std;

status InitTriplet(Triplet *T,DataType v1,DataType v2,DataType v3)
{
    *T = (DataType*)malloc(3 * sizeof(DataType));
    if(!T)
        return ERROR;
    (*T)[0] = v1,(*T)[1] = v2,(*T)[3] = v3;
    return OK;
}

status DestoryTriplet(Triplet *T)
{
    free(*T);
    T = NULL;
    return OK;
}

status Get(Triplet *T,int i,DataType *e)
{
    if(i < 1 || i > 3)
        return ERROR;
    *e = (*T)[i - 1];
    return OK;
}

status Put(Triplet *T,int i,DataType e)
{
    if(i < 1 || i > 3)
        return ERROR;
    e = (*T)[i - 1];
    return OK;
}

status IsAscending(Triplet T)
{
    return(T[0] <= T[1] && T[1] <= T[2]);
}

status IsDescending(Triplet T)
{
    return(T[0] >= T[1] && T[1] >= T[2]);
}

status Max(Triplet T,DataType *e)
{
    *e = max(T[0],max(T[1],T[2]));
    return OK;
}

status Min(Triplet T,DataType *e)
{
    *e = min(T[0],min(T[1],T[2]));
    return OK;
}

status Average(Triplet T,float *f)
{
    *f = (T[0] + T[1] + T[2]) / 3.0;
    return OK;
}
