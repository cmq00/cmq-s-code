#include<bits/stdc++.h>
using namespace std;
int main()
{
    int v;
    string s;
    while(cin>>v)
    {cin>>s;
  int k,num,kk,kkk,zmq,ss;
  k=0;num=0;kk=0;zmq=0;ss=0;
  for(int i=0;i<s.size();i++)
  {
     if(s[i]=='1')
     {kk++;
     if(kk==v)
     {kkk=i;}
     }
  }
  if(kk<v)
  {
    num=(v-kk)/2+kk;
    zmq=s.size()-num;
    zmq=zmq*num;
    num=num*(1+num)/2;
    num=zmq+num;
  }
  else
  {
      num=v*(v+1)/2;
   ss=num*( s.size()-kkk-1);
   num=ss+num;
  }
cout<<num<<endl;
s.clear();}
}