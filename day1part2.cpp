#include <cstdlib>
#include <set>
#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;


int main (int argc, char *argv[]) {
	multiset<int> left;
	multiset<int> right;
   std::ifstream archivo("datos.txt"); // Abre el archivo en modo lectura
    if (!archivo.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo." << std::endl;
        return 1;
    }

    int num1, num2;

    // Leer el archivo línea por línea
    while (archivo >> num1 >> num2) { // Lee dos enteros por línea
		cout << num1<<" "<< num2<<endl;
        left.insert(num1);
        right.insert(num2);
    }

    archivo.close(); // Cierra el archivo
	
	auto itl = left.begin();
	int sol = 0;

	for(;itl!=left.end();itl++){
		sol += right.count(*itl)*(*itl);
	}
	cout << "solution is "<< sol<<endl;
	return 0;
}
