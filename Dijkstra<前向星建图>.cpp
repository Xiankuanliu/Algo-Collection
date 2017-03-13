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
const int maxn = 50;
const int maxm = 100<<1;
struct Edge{
	int from,to;
	int len;
	int nxt;
	Edge(){}
	Edge(int u,int v,int l,int f):from(u),to(v),len(l),nxt(f){}
};
struct heapNode{
	int u,relx;
	heapNode(){}
	heapNode(int u_,int relx_):u(u_),relx(relx_){}
	bool operator < (const heapNode& rhs)const{
		return relx > rhs.relx;
	} 
};
Edge edges[maxm];
int d[maxn],p[maxn];
int head[maxn];
int r,n,m;
void addEdge(int u,int v,int len){ //这里写的是无向图，可以根据题意调整 
	edges[r++] = Edge(u,v,len,head[u]);
	head[u] = r-1;
	edges[r++] = Edge(v,u,len,head[v]);
	head[v] = r-1;
}
void Dijkstra(int s){
	bool done[maxn];
	memset(done,false,sizeof(done));
	for(int i = 0;i < n;i++)p[i] = i;
	for(int i = 0;i < n;i++)d[i] = INF;
	priority_queue<heapNode> pque;
	d[s] = 0;pque.push(heapNode(s,0));
	while(!pque.empty()){
		heapNode node = pque.top();pque.pop();
		int u = node.u;
		if(done[u])continue;
		//if(done[t])break;
		done[u] = true;
		for(int i = head[u];i!=-1;i = edges[i].nxt){
			Edge& e = edges[i];
			if(d[e.to]>d[u]+e.len){
				d[e.to] = d[u]+e.len;
				p[e.to] = u;
				pque.push(heapNode(e.to,d[e.to]));
			}
		}
	}
}
void printPath(int s,int cur){
	if(cur == s){cout << s;return;}
	printPath(s,p[cur]);
	printf(" %d",cur);
}
int main(){
	freopen("input.txt","r",stdin);
	while(scanf("%d%d",&n,&m)!=EOF){
		r = 0;memset(head,-1,sizeof(head));
		for(int i = 0;i < m;i++){
			int u,v,l;
			scanf("%d%d%d",&u,&v,&l);
			addEdge(u,v,l);
		}
		Dijkstra(0);//构造Dijkstra树
		int qurey;scanf("%d",&qurey);
		while(qurey--){
			int t;scanf("%d",&t);
			printPath(0,t);cout << endl;
			printf("%d\n",d[t]);
		}
	}
	return 0;
}

