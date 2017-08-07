/* BitGraph  */
/*	     */
/* Implementation making use of bitwise operations in order to spend much less memory. */
/* Up to 8 times less memory usage than an usual simple graph implementation. */

#include <iostream>
#include <vector>
#include <cmath>
#include <assert.h>

using namespace std;

class BitwiseIndex {
	private:
		int idx; //Indice traduzido.
		char byteOffset; //Posicao dentro do byte.

	public:
		BitwiseIndex(int realIndex) {
			this->idx = realIndex/8;
			this->byteOffset = 0x1 << (realIndex%8);
		}
		int getIdx() {
			return this->idx;
		}
		char getOffset() {
			return this->byteOffset;
		}
};

class BitGraph {
	private:
		int n;
		bool directed;
		vector< vector<char> > Graph;
		void resizeGraph(int n) {
			this->n = n;
			this->Graph.resize(n);
			for(int i = 0; i < this->Graph.size(); i++) this->Graph[i].resize(ceil(n/8.0));
		}
		void init(int n, bool directed) {
			this->resizeGraph(n);
			this->directed = directed;
		}
	public:
		void ClearGraph(){
			for(int i = 0; i < this->Graph.size(); i++) {
				for(int j = 0; j < this->Graph[i].size(); j++) {
					this->Graph[i][j] = 0;
				}
			}
		}
		BitGraph(int n) {
			this->init(n, true);
		}
		BitGraph(int n, bool directed) {
			this->init(n, directed);
		}
		~BitGraph() {
			for(int i = 0; i < this->Graph.size(); i++) this->Graph[i].clear();
			this->Graph.clear();
		}
		bool HasEdge(int u, int v) {
			assert(u < this->n && v < this->n);

			BitwiseIndex tv = BitwiseIndex(v);
			return this->Graph[u][tv.getIdx()] & tv.getOffset();
		}
		void AddEdge(int u, int v) {
			assert(u < this->n && v < this->n);

			/* Traduz indice da coluna para indice dentro do byte. */
			BitwiseIndex tv = BitwiseIndex(v);
			/* Faz bitwise OR com o offset, adicionando '1' na posicao correspondente do byte. */
			this->Graph[u][tv.getIdx()] |= tv.getOffset();

			if (!this->directed) {
				BitwiseIndex tu = BitwiseIndex(u);
				this->Graph[v][tu.getIdx()] |= tu.getOffset();				
			}
		}
		void RemoveEdge(int u, int v) {
			assert(u < this->n && v < this->n);

			/* Traduz indice da coluna para indice dentro do byte. */
			BitwiseIndex tv = BitwiseIndex(v);
			/* Faz bitwise AND com o complemento do offset, removendo o '1' da posicao correspondente no byte */
			this->Graph[u][tv.getIdx()] &= ~tv.getOffset();

			if (!this->directed) {
				BitwiseIndex tu = BitwiseIndex(u);
				this->Graph[v][tu.getIdx()] &= ~tu.getOffset();				
			}
		}

		void PrintGraph() {
			for(int i = 0; i < this->Graph.size(); i++) {
				for(int j = 0; j < this->Graph[i].size(); j++) {
					char byte = this->Graph[i][j];
					for(int b = 7; b >= 0; b--) cout << !!((byte << b) & 0x80);
					cout << " ";
				}
				cout << endl;
			}
		}
};

int main(void) {
	BitGraph G(10);
	G.AddEdge(0,4);
	G.AddEdge(0,0);
	G.AddEdge(0,3);
	G.AddEdge(0,2);
	G.AddEdge(0,1);
	G.AddEdge(0,9);
	G.PrintGraph();
	
	return 0;
}
