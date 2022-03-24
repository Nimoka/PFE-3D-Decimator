#include "mesh.h"
#include <stdlib.h>

using namespace std;
using namespace Eigen;

void Mesh::DeleteFaces(int toDelete) {
	cout << "Started with " << n_faces() << " faces, need " << (n_faces() - toDelete) << endl;
	int start = toDelete;

	/*add_edge_property<int>("e:mark");
	Map<VectorXi> available = marks();
	available.setZero();*/

	Vertex v0, v1;
	int updateCount = 0;
	int garbageCollectionThreshold = 0;

	SurfaceMesh::HalfedgeAroundVertexCirculator hvit, hvend;
	while (toDelete > 0) {
		int firstEdge = (*edges_begin()).idx(), 
		    lastEdge = n_edges() - 1, 
			shift = (*(++edges_begin())).idx() - firstEdge,
			possible = (lastEdge - firstEdge) / shift;
		Edge current = Edge(firstEdge + rand() % possible);
		Halfedge currentHalfedge;

		// Check for collapse legality
		bool isV1First = false;
		v0 = vertex(current, 0);
		v1 = vertex(current, 1);
		Halfedge toFind = find_halfedge(v0, v1);
		if (!is_valid(toFind) || !is_collapse_ok(toFind)) {
			toFind = find_halfedge(v1, v0);
			if (!is_valid(toFind) || !is_collapse_ok(toFind)) {
				// TODO: Mark current edge
				continue;
			}
		}
		currentHalfedge = toFind;

		Vertex v2 = to_vertex(currentHalfedge);
		
		toDelete -= is_boundary(edge(currentHalfedge)) ? 1 : 2;
		collapse(currentHalfedge);

		// Mark all neighboring edges to prevent them from being deleted
		/*for (int i = 0; i < 2; i++) {
			hvit = hvend = halfedges(v2);
			do {
				std::vector<Edge>::iterator it = find(available.begin(), available.end(), edge(*hvit));
				if (it != available.end())
					available.array();
			} while (++hvit != hvend);
		}*/

		if (++updateCount >= min(10000.0, start / 100.0)) {
			updateCount = 0;
			int diffTest = (start - toDelete);
			cout << diffTest << " / " << start << " (" << ((float)diffTest / start * 100.0) << "%)" << endl;
			if (garbageCollectionThreshold + 1 < (float)diffTest / start * 4.0) {
				cout << "Garbage collection started!" << endl;
				garbageCollectionThreshold++;
				garbage_collection();
			}
		}
	}
}