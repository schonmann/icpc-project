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
		void assertValidEdge(int u, int v) {
			assert(0 <= u && u < this->n && 0 <= v && v < this->n);
		};
	public:
		void ClearGraph(){
			for(int i = 0; i < this->Graph.size(); i++) {
				for(int j = 0; j < this->Graph[i].size(); j++) {
					this->Graph[i][j] = 0;
				}
			}
		}
		BitGraph(int n) {
			this->init(n, false);
		}
		BitGraph(int n, bool directed) {
			this->init(n, directed);
		}
		~BitGraph() {
			for(int i = 0; i < this->Graph.size(); i++) this->Graph[i].clear();
			this->Graph.clear();
		}
		bool HasEdge(int u, int v) {
			this->assertValidEdge(u,v);

			BitwiseIndex tv = BitwiseIndex(v);

			return this->Graph[u][tv.getIdx()] & tv.getOffset();
		}
		void AddEdge(int u, int v) {
			this->assertValidEdge(u,v);

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
			this->assertValidEdge(u,v);

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
			cout << (this->directed ? "Directed " : "") << "Graph: " << endl << endl;
			for(int i = 0; i < this->n; i++) {
				for(int j = 0; j < this->n; j++) {
					cout << this->HasEdge(i,j) << " ";
				}
				cout << endl;
			}
			cout << endl;
		}
};

int main(void) {
	BitGraph Graph(9);

	Graph.AddEdge(0,0);
	Graph.AddEdge(0,1);
	Graph.AddEdge(0,2);

	Graph.PrintGraph();
	
	BitGraph DirectedGraph(9, true);

	DirectedGraph.AddEdge(0,0);
	DirectedGraph.AddEdge(0,1);
	DirectedGraph.AddEdge(0,2);

	DirectedGraph.PrintGraph();

	return 0;
}

/* Output */:

// 	Graph:
//
// 	1 1 1 0 0 0 0 0 0
// 	1 0 0 0 0 0 0 0 0
// 	1 0 0 0 0 0 0 0 0
// 	0 0 0 0 0 0 0 0 0
// 	0 0 0 0 0 0 0 0 0
// 	0 0 0 0 0 0 0 0 0
// 	0 0 0 0 0 0 0 0 0
// 	0 0 0 0 0 0 0 0 0
// 	0 0 0 0 0 0 0 0 0
//
// 	Directed Graph:
//
// 	1 1 1 0 0 0 0 0 0
// 	0 0 0 0 0 0 0 0 0
// 	0 0 0 0 0 0 0 0 0
// 	0 0 0 0 0 0 0 0 0
// 	0 0 0 0 0 0 0 0 0
// 	0 0 0 0 0 0 0 0 0
// 	0 0 0 0 0 0 0 0 0
// 	0 0 0 0 0 0 0 0 0
// 	0 0 0 0 0 0 0 0 0
