#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int contador=0;
void permutaciones(vector<string> & permutacion, vector<bool> & seleccionado, vector<string> & lista,int n) {
    if (permutacion.size() == lista.size()) {
        cout<<"("<<permutacion[0];
        for (int i = 1; i < (int) permutacion.size(); i++)
            cout <<","<< permutacion[i];
        cout<<")";
        cout << '\n';
        return;
    }

    for (int i = 0; i < (int) lista.size(); i++) {
        if (!seleccionado[i]) {
            seleccionado[i] = true;
            permutacion.push_back(lista[i]);
            permutaciones(permutacion, seleccionado, lista,n);
            permutacion.pop_back();
            seleccionado[i] = false;
        }
    }
}
int main(){
	int numero;
	while(cin>>numero){
		vector <string> implementar (numero);
		vector <bool> seleccionar(numero);
		vector <string> lista;
		for(int i=0;i<numero;i++){
			cin>>implementar[i];
		}
		permutaciones(lista,seleccionar,implementar,0);
	}
	return 0;
}
