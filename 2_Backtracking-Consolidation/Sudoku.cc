#include <iostream>
using namespace std;
const int n=9;
bool ok;
void sudoku(int a,int b,int sud[][n],int r[][n],int c[][n],int sq[][n],int& cont, bool& trobat){
    if (trobat) return;
	if(cont==81){
		ok=true;
		trobat = true;
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				cout<<sud[i][j];
				if(j<8)cout<<' ';
			}
			cout<<endl;
		}
		return;
	}
	if(sud[a][b]&&b==8)sudoku(a+1,0,sud,r,c,sq,cont, trobat);
	else if(sud[a][b])sudoku(a,b+1,sud,r,c,sq,cont, trobat);
	else{
		int s=a/3*3+b/3;
		//cout<<a<<' '<<b<<' '<<s<<'\n';
		for(int i=0;i<n;i++){
			if(!c[b][i]&&!r[a][i]&&!sq[s][i]){
				sud[a][b]=i+1;
				cont++;
				c[b][i]=r[a][i]=sq[s][i]=1;
				if(b==8)sudoku(a+1,0,sud,r,c,sq,cont, trobat);
				else sudoku(a,b+1,sud,r,c,sq,cont, trobat);
				if (trobat) return;
				sud[a][b]=0;
				cont--;
				c[b][i]=r[a][i]=sq[s][i]=0;
			}
		}
	}
}
int main(){
	int t;
	string str;
	char c;
	cin>>t;
	cout << t << endl;
	while(t--){
        cout << endl;
		ok=false;
		int cont=0;
		int sud[9][9],r[n][n],co[n][n],sq[n][n];
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++)r[i][j]=co[i][j]=sq[i][j]=0;
		}
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				cin>>c;
				if (c == '.') sud[i][j] = 0;
				else sud[i][j] = c-'0';
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
			}
		}
        bool trobat = false;
		sudoku(0,0,sud,r,co,sq,cont, trobat);
	}
}