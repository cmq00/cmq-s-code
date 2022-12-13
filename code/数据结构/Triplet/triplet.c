#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ok 1
#define error 0
#define overflow -2

typedef int status;
typedef int elemtype;
typedef elemtype* Triplet;

status InitTriplet(Triplet *T,elemtype v1,elemtype v2,elemtype v3)
{
    *T = (elemtype*)malloc(3 * sizeof(elemtype));
    if(!T)
        exit(overflow);
    (*T)[0] = v1;
    (*T)[1] = v2;
    (*T)[2] = v3;
    return ok;
}

status DestoryTriplet(Triplet *T)
{
    free(*T);
    return ok;
}

status Get(Triplet T,int i,elemtype *e)
{
    if(i < 1 || i > 3)
        return error;
    *e = T[i - 1];
    return ok;
}

status Put(Triplet *T,int i,elemtype e)
{
    if(i < 1 || i > 3)
        return error;
    (*T)[i - 1] = e;
    return ok;
}

status IsAscending(Triplet T)
{
    return T[0] <= T[1] && T[1] <= T[2];
}

status IsDescending(Triplet T)
{
    return T[0] >= T[1] && T[1] >= T[2];
}

status Max(Triplet T,elemtype *e)
{
    *e = T[0] >= T[1] ? (T[0] >= T[2] ? T[0] : T[2]) : (T[1] >= T[2] ? T[1] : T[2]);
    return ok;
}

status Min(Triplet T,elemtype *e)
{
     *e = T[0] <= T[1] ? (T[0] <= T[2] ? T[0] : T[2]) : (T[1] <= T[2] ? T[1] : T[2]);
    return ok;
}

status Average(Triplet T,float *f)
{
    *f = (T[0] + T[1] + T[2]) / 3.0;
    return ok;
}

status print(Triplet T)
{
    printf("%d %d %d\n",T[0],T[1],T[2]);
    return ok;
}

int main()
{
    Triplet T;
    // elemtype e,a,b,c;
    // scanf("%d %d %d",&a,&b,&c);
    // InitTriplet(&T,a,b,c);
    // print(T);
    // Put(&T,1,3);
    // print(T);
    // Max(T,&e);
    // printf("%d\n",e);
    // Min(T,&e);
    // printf("%d\n",e);
}