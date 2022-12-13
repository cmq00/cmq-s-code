#pragma once
#ifndef TRIIPLET_H_INCLUDED
#define TRIIPLET_H_INCLUDED
#include <bits/stdc++.h>
using namespace std;
//#include <stdio.h>

#define True 1
#define Flase 0
#define OK 1
#define ERROR 0
//#define OVERFLOW -2

typedef int status;
typedef int DataType;
typedef DataType* Triplet;

//初始化
status InitTriplet(Triplet &T,DataType v1,DataType v2,DataType v3);
//销毁
status DestoryTriplet(Triplet &T);

status Get(Triplet &T,int i,DataType &e);

status Put(Triplet &T,int i,DataType e);

status IsAscending(Triplet T);

status IsDescending(Triplet T);

status Max(Triplet T,DataType &e);

status Min(Triplet T,DataType &e);

status Average(Triplet T,float &f);

#endif