#include <iostream>
#include <map>

using namespace std;

//Fatorial com memorizacao.
map<int, unsigned long int> mem;
unsigned long int fat(int i) {
	if(mem.find(i) != mem.end()) {
		return mem[i];
	}
	if(i == 0) return 1;
	mem[i] = i*fat(i-1);
	return mem[i];
}

int main() {

	int t;
	cin >> t;
	int n = t;
	while(t--) {
		string s;
		cin >> s;

		//Numero total de maneiras.
		unsigned long int ways = fat(s.length());

		//Inicializa hash para contagem de caracteres.
		map<char, int> m;
		for(int i = 0; i < 300; i++) {
			m[(char)i] = 0;
		}

		//Remove duplicatas dividindo pelo fatorial da 
		//quantidade de ocorrencias para cada caracter.
		for(int i = 0; i < s.length(); i++) {
			m[s[i]]++;
			ways /= m[s[i]];
		}

		//Imprime resposta.
		cout << "Data set " << n-t << ": " << ways << endl;
	}

	return 0;
}
