#include <cstdlib>
#include <sstream>
#include <math.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


int main (int argc, char *argv[]) {
   std::ifstream archivo("input2.txt"); // Abre el archivo en modo lectura
    if (!archivo.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo." << std::endl;
        return 1;
    }

	string cad;
	vector<int>v;
	bool cond, subir ,bajar,seguir;
	int i;
	int safe =0;
	string element ;
    // Leer el archivo línea por línea
    while (getline(archivo,cad)) { // Lee dos enteros por línea
		cout << cad<<endl;
		stringstream ss(cad);
		while (ss>>element) {
			v.push_back(stoi(element));
		}	
		i=0;
		subir=false;
		bajar=false;
		seguir=true;

			while(i<v.size()-1 && seguir){
				if(i ==0){
					if(v[i] <v[i+1]){
						subir =true;
					}	
					else if (v[i] >v[i+1]){
						bajar=true;
					}
					else{
						seguir=false;
					}
				
				}else{
					cond =abs(v[i]-v[i+1])>=1 && abs(v[i]-v[i+1])<=3;
					if(subir==true ){
						if(v[i]<v[i+1]&& cond){
							seguir =true;
						}else{
							seguir =false;
						}
					}
					if(bajar==true ){
						if(v[i]>v[i+1]&& cond){
							seguir =true;
						}else{
							seguir =false;
						}
					}
				}
				i++;
			}
			if(seguir == true){
				safe+=1;
				cout<< safe<< endl;
			}
			v.clear();
					
		}
    

    archivo.close(); // Cierra el archivo
	
	cout << "solution is "<< safe<<endl;
	return 0;
}
