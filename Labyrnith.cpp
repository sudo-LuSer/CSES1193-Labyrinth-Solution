#include <bits/stdc++.h>
using namespace std;
bool Visited[1000][1000];
int mp[1000][1000]; 
int Distance[1000][1000]; 
pair<int ,int> PreviousParent[1000][1000];
#define all(v) v.begin( ) , v.end( )
struct c{
	int xx,yy;
};
bool cmp(c c1 , c c2){
	if(c1.xx == c2.xx && c1.yy==c2.yy){
		return true;
	}
	return false;
}
bool checkValidmove(int n , int m , int i , int j){
	if(i>=0 && i<n && j>=0 && j<m && Visited[i][j]==0 && mp[i][j]==1){
		return true;
	}
	return false; 
}
void Intialize(){
	for(int i = 0 ; i < 1000 ; i++){
		for(int j = 0 ; j < 1000 ; j ++){
			Visited[i][j]= 0; 
			mp[i][j] = 0 ;
			Distance[i][j] = INT_MAX;
		}
	}
}
void bfs(int x_entrée , int y_entrée , int n ,int m , int x_arrivée , int y_arrivée){
	Distance[x_entrée][y_entrée] = 0; 
	deque <c> Q ;
	c init , fin , sommet; 
	init.xx = x_entrée;init.yy=y_entrée; 
	fin.xx = x_arrivée;fin.yy = y_arrivée;  
	Q.push_back(init);
	Visited[x_entrée][y_entrée] = 1;
	while(!Q.empty()){
		c t = Q[0];
		Q.pop_front();
		if(checkValidmove(n , m , t.xx +1 , t.yy) and Distance[t.xx +1][t.yy]==INT_MAX){
			Distance[t.xx +1][t.yy]= Distance[t.xx][t.yy] +1;
			Visited[t.xx +1][t.yy] = 1; 
			sommet.xx = t.xx +1 ; sommet.yy = t.yy;
			Q.push_back(sommet);
			PreviousParent[sommet.xx][sommet.yy] = make_pair(t.xx , t.yy);
			if(cmp(sommet , fin)){
				break; 
			}
		} 
		if(checkValidmove(n , m , t.xx -1, t.yy) and Distance[t.xx -1][t.yy]==INT_MAX){
			Distance[t.xx -1][t.yy]=Distance[t.xx][t.yy] +1;
			Visited[t.xx -1][t.yy] = 1; 
			sommet.xx = t.xx -1 ; sommet.yy = t.yy;
			Q.push_back(sommet);
			PreviousParent[sommet.xx][sommet.yy] = make_pair(t.xx , t.yy);
			if(cmp(sommet , fin)){
				break; 
			}
		} 
		if(checkValidmove(n , m , t.xx , t.yy +1)and Distance[t.xx][t.yy+1]==INT_MAX){
			Distance[t.xx][t.yy +1]=Distance[t.xx][t.yy]+1;
			Visited[t.xx][t.yy +1] = 1; 
			sommet.xx = t.xx ; sommet.yy = t.yy+1;
			Q.push_back(sommet);
			PreviousParent[sommet.xx][sommet.yy] = make_pair(t.xx , t.yy);
			if(cmp(sommet , fin)){
				break; 
			}
		} 
		if(checkValidmove(n , m , t.xx , t.yy -1)and Distance[t.xx][t.yy-1]==INT_MAX){
			Distance[t.xx][t.yy -1]=Distance[t.xx][t.yy]+1;
			Visited[t.xx][t.yy -1] = 1; 
			sommet.xx = t.xx ; sommet.yy = t.yy-1;
			Q.push_back(sommet);
			PreviousParent[sommet.xx][sommet.yy] = make_pair(t.xx , t.yy);
			if(cmp(sommet , fin)){
				break; 
			}
		} 
	}
	if(cmp(sommet , fin)){
		cout<<"YES"<<endl;
		vector<pair<int , int> > chemin;
		while(!cmp(sommet,init)){
			chemin.push_back(make_pair(sommet.xx , sommet.yy));
			c temp; 
			temp = sommet; 
			sommet.xx = PreviousParent[temp.xx][temp.yy].first; 
			sommet.yy = PreviousParent[temp.xx][temp.yy].second;
		}
		cout<<chemin.size()<<endl;
		reverse(all(chemin));
		int PosAct_x = init.xx , PosAct_y = init.yy; 
		for(int i = 0 ; i < chemin.size() ; i++){
			c move;
			move.xx = chemin[i].first - PosAct_x;
			move.yy = chemin[i].second - PosAct_y; 
			if(move.xx == 0 and move.yy == -1){
				cout<<'L';
			}
			else if(move.xx == 0 and move.yy == 1){
				cout<<'R';
			}
			else if(move.xx == -1 and move.yy == 0){
				cout<<'U';
			}
			else{
				cout<<'D';
			}
			PosAct_x = chemin[i].first;
			PosAct_y = chemin[i].second; 
		}

	}
	else{
		cout<<"NO";
	}
}
int main(){
	Intialize();
	int  n,m;cin>>n>>m;
	int x_a , y_a , x_b , y_b;
	for(int i = 0 ; i < n ; i++){
		string s;cin>>s; 
		for(int j = 0 ; j < m ; j++){
			if(s[j]=='.' or s[j]=='B' or s[j]=='A'){
				if(s[j]=='A'){
					x_a = i;
					y_a = j;
				}
				else if(s[j]=='B'){
					x_b = i;
					y_b = j;
				}
				mp[i][j]=1; 
			}
		}
	}	
	bfs(x_a, y_a , n , m , x_b , y_b);
}