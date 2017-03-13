#include<iostream>
#include<vector>
#include<string.h>
#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<string>
#include<map>
#include<set>
#include<list>
#include<queue>
#include<math.h>
#include<algorithm>
#include<cstdlib>
#include<stack>
#include<cctype>
#include<sstream>
#define INF 0x7777777f
#define sys std::ios::sync_with_stdio(false)
#define LL long long
#define Uint unsigned int
using namespace std;
const int N = 10;
int arr[N+2];
struct Node{
	int sum;
	//int max;
	//int min;
	//...;
}nodes[1 << N];
inline LC(int i){return i<<1;}
inline RC(int i){return (i<<1)+1;}
void build(int L,int R,int i){
	if(L == R){nodes[i].sum = arr[L];return;}
	int M = L + ((R-L)>>1);
	build(L,M,LC(i));
	build(M+1,R,RC(i));
	nodes[i].sum = nodes[LC(i)].sum + nodes[RC(i)].sum;
}
void update(int L,int R,int i,int& x,int &n){
	if(L == R){nodes[i].sum = n;return;}
	int M = L + ((R-L)>>1);
	if(x <= M)update(L,M,LC(i),x,n);
	else update(M+1,R,RC(i),x,n);
	nodes[i].sum = nodes[LC(i)].sum + nodes[RC(i)].sum;
}
void query(int L,int R,int i,int& x1,int& x2,int &total){
	if(x1 <= L && R <= x2){total += nodes[i].sum;return;}
	int M = L +((R-L)>>1);
	if(x1 <= M)query(L,M,LC(i),x1,x2,total);
	if(x2 > M)query(M+1,R,RC(i),x1,x2,total);
}
int main(){	
	for(int i = 0;i < N;i++)scanf("%d",&arr[i]);
	build(0,N-1,1);
	int a,b,c;cin >> a >> b >> c;
	printf("Query %d times.\n",a);
	while(a--){
		int l,r,total = 0;
		cin >> l >> r;
		query(0,N-1,1,l,r,total);
		printf("Get %d~%d :%d\n",l,r,total);
	}
	printf("Update %d times.\n",b);
	while(b--){
		int p,w;cin >> p >> w;
		update(0,N-1,1,p,w);
		printf("arr[%d] updated-->%d\n",p,w);
	}
	printf("Now query again,%d times.\n",c);
	while(c--){
		int l,r,total = 0;
		cin >> l >> r;
		query(0,N-1,1,l,r,total);
		printf("Get %d~%d :%d\n",l,r,total);
	}
	return 0;
}




