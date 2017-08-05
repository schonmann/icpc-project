#include <iostream>
#include <vector>
#include <cmath>
#include <assert.h>

using namespace std;

class Edge {
	public:
		Edge(int u, int v) {
			this->u = u;
			this->v = v;
		};
		int getU() {
			return this->u;
		};
		int getV() {
			return this->v;
		};
	private:
		int u,v;
};

class BitwiseIndex {
	private:
		int idx; //Indice traduzido.
		char byteOffset; //Posicao dentro do byte.

	public:
		BitwiseIndex(int realIndex) {
			this->idx = floor(realIndex/8.0);
			this->byteOffset = 0x01 << (realIndex%8);
		};
		int getIdx() {
			return this->idx;
		};
		char getOffset() {
			return this->byteOffset;
		};
};

class BitGraph {
	private:
		int n;
		vector< vector<char> > Graph;
		void resizeGraph(int n) {
			this->n = n;
			this->Graph.resize(n);
			for(int i = 0; i < this->Graph.size(); i++) this->Graph[i].resize(ceil(n/8.0));
		};

	public:
		void ClearGraph(){
			for(int i = 0; i < this->Graph.size(); i++) {
				for(int j = 0; j < this->Graph[i].size(); j++) {
					this->Graph[i][j] = 0;
				}
			}
		};
		BitGraph(int n) {
			this->resizeGraph(n);
		};
		~BitGraph() {
			for(int i = 0; i < this->Graph.size(); i++) this->Graph[i].clear();
			this->Graph.clear();
		};
		void AddEdge(Edge edge) {
			int u = edge.getU(); int v = edge.getV();
			assert(u < this->n && v < this->n);

			/* Traduz indice da coluna para indice dentro do byte. */

			BitwiseIndex tv = BitwiseIndex(v);

			/* Faz bitwise OR com o offset, adicionando '1' na posicao correspondente do byte. */

			this->Graph[u][tv.getIdx()] |= tv.getOffset();
		};
		void RemoveEdge(Edge edge) {
			int u = edge.getU(); int v = edge.getV();
			assert(u < this->n && v < this->n);

			/* Traduz indice da coluna para indice dentro do byte. */

			BitwiseIndex tv = BitwiseIndex(v);

			/* Faz bitwise AND com o complemento do offset, removendo o '1' da posicao correspondente no byte */

			this->Graph[u][tv.getIdx()] &= ~tv.getOffset();
		};

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
	G.AddEdge(Edge(0,4));
	G.AddEdge(Edge(0,0));
	G.AddEdge(Edge(0,3));
	G.AddEdge(Edge(0,2));
	G.AddEdge(Edge(0,1));
	G.AddEdge(Edge(0,9));
	G.PrintGraph();
	return 0;
}
