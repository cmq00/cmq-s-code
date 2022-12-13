#include<iostream>
using namespace std;

const int N=100010;
typedef long long ll;
ll a[N],n,m,summ,mina=1e9+1,maxa;

int check(int mid)
{
	ll cnt=0,sum=0;
	for(int i=1;i<=n-1;i++)
	{
		sum+=a[i];
		if(sum+a[i+1]>mid) cnt++,sum=0; //不能满足 "区间间距小于最大距离"，那就分段 
	}
	if(cnt+1<=m) return 1;	//总的段数小于等于需要的段数，这样都能满足mid为每段的最大值，那么多分几段，肯定还能满足 
	return 0;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i],summ+=a[i];	
		if(a[i]<mina) mina=a[i];
		if(a[i]>maxa) maxa=a[i];
	}
	
	int l=maxa,r=summ;	//l要设为maxa，所有段的最大值肯定大于等于maxa 
	while(l<r)
	{
		int mid=(l+r)>>1;
        cout << l << " " << r << " " << mid << endl;
		if(check(mid)) r=mid; //求的是最大值的最小，故尽量往左来 
		else l=mid+1;
	}
	cout<<l;
	return 0;
} 


