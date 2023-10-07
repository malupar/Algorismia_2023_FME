#include <iostream>
using namespace std;
const int n=9;
bool ok;
void sudoku(int a,int b,int sud[][n],int r[][n],int c[][n],int sq[][n],int& cont){
	if(cont==81){
		ok=true;
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				cout<<sud[i][j];
				if(j<8)cout<<' ';
				if(j==2||j==5)cout<<"| ";
			}
			cout<<'\n';
			if(i==2||i==5)cout<<"------+-------+------\n";
		}
		cout<<'\n';
		return;
	}
	if(sud[a][b]&&b==8)sudoku(a+1,0,sud,r,c,sq,cont);
	else if(sud[a][b])sudoku(a,b+1,sud,r,c,sq,cont);
	else{
		int s=a/3*3+b/3;
		for(int i=0;i<n;i++){
			if(!c[b][i]&&!r[a][i]&&!sq[s][i]){
				sud[a][b]=i+1;
				cont++;
				c[b][i]=r[a][i]=sq[s][i]=1;
				if(b==8)sudoku(a+1,0,sud,r,c,sq,cont);
				else sudoku(a,b+1,sud,r,c,sq,cont);
				sud[a][b]=0;
				cont--;
				c[b][i]=r[a][i]=sq[s][i]=0;
			}
		}
	}
}
int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	int t;
	string str;
	char c;
	cin>>t;
	while(t--){
		ok=false;
		int cont=0;
		int sud[9][9],r[n][n],co[n][n],sq[n][n];
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++)r[i][j]=co[i][j]=sq[i][j]=0;
		}
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				cin>>sud[i][j];
				if(sud[i][j]){
					cont++;
					r[i][sud[i][j]-1]=co[j][sud[i][j]-1]=1;
					if(i<3&&j<3)sq[0][sud[i][j]-1]=1;
					else if(i<3&&j<6)sq[1][sud[i][j]-1]=1;
					else if(i<3)sq[2][sud[i][j]-1]=1;
					else if(i<6&&j<3)sq[3][sud[i][j]-1]=1;
					else if(i<6&&j<6)sq[4][sud[i][j]-1]=1;
					else if(i<6)sq[5][sud[i][j]-1]=1;
					else if(j<3)sq[6][sud[i][j]-1]=1;
					else if(j<6)sq[7][sud[i][j]-1]=1;
					else sq[8][sud[i][j]-1]=1;
				}
				if((j+1)%3==0&&j<8)cin>>c;
			}
			if((i+1)%3==0&&i<8)cin>>str;
		}
		sudoku(0,0,sud,r,co,sq,cont);
		if(!ok)cout<<"no solution\n";
		cout<<"******************************\n";
	}
}