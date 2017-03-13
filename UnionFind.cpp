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
int cntGroup = 0;
int p[N+2];
inline void initSet(){
	for(int i = 0;i < N;i++)p[i] = i;
	cntGroup = N;
}
inline int Find(int x){ //To find x's Boss.
	return x == p[x]?x:(p[x] = Find(p[x]));
}
/*void Union(int x,int y){
	p[Find(x)] = Find(y);
}*/
void Union(int x,int y){
	int px = Find(x),py = Find(y);
	if(px == py)return;
	p[px] = py;
	cntGroup--;
}
int main(){
	int a,b,c;cin >> a >> b >> c;
	printf("Now give number to original set,10 numbers.\n");
	for(int i = 0;i < N;i++)scanf("%d",&p[i]);
	initSet();
	printf("Now we have totally %d groups.\n",cntGroup);
	printf("find %d times.\n",a);
	while(a--){
		int m;cin >> m;
		printf("the Boos of %d: ",m);
		cout << Find(m) << endl;
	}
	cout << endl;
	printf("Union %d times.\n",b);
	while(b--){
		int m,n;cin >> m >> n;
		Union(m,n);
		printf("union %d and %d successfully.\n",m ,n);
	}
	cout << endl;
	printf("Now we have totally %d groups.\n",cntGroup);
	printf("Now find again,%d times.\n",c);
	while(c--){
		int m;cin >> m;
		printf("the Boos of %d: ",m);
		cout << Find(m) << endl;		
	}
	cout << endl;
	cout << "##Proccessing Is Over##" << endl;
	return 0;
}



