#include <cstdio>
#include "graphviewer.h"
#include <fstream>
#include <iostream>
#include <sstream>

void exercicio1();
void exercicio2();
void exercicio3();


void exercicio1() {
	GraphViewer *gv = new GraphViewer(600, 600, true);
	gv->createWindow(600, 600);
	gv->defineVertexColor("blue");
	gv->defineEdgeColor("black");
	gv->addNode(1);
	gv->addNode(2);
	gv->addNode(3);
	gv->rearrange();
	// para arestas bidireccionais
	gv->addEdge(1,1,2,EdgeType::UNDIRECTED);
	// para arestas direccionais
	gv->addEdge(2,1,3, EdgeType::DIRECTED);
	gv->setVertexLabel(1, "Isto e um no");
}

void exercicio2()
{

}

void exercicio3()
{

}


int main() {
	exercicio1();
	//exercicio2();
	//exercicio3();
	getchar();
	return 0;
}
