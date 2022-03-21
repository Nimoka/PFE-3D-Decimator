#include "mesh.h"

void Mesh::DeleteEdges(int toDelete) {
	std::cout << "DeleteEdges (" << toDelete << " out of " << nbFaces << ")" << std::endl;
	/*add_vertex_property<int>("v:handled");
	handleds().fill(0);

	vector<Edge> allEdges;
	SurfaceMesh::EdgeIterator eit, eend = edges_end();
	for (eit = edges_begin(); eit != eend; ++eit)
		allEdges.push_back(*eit);

	vector<Edge> available = allEdges;

	SurfaceMesh::HalfedgeAroundVertexCirculator hvit, hvend;
	int newEdgeCount = 1000;
	int edgeCount = 10000;
	while (edgeCount > newEdgeCount) {
		if (available.size() == 0)
			available = allEdges;
		Edge current = available[rand() % available.size()];
		for (int i = 0; i < 2; i++) {
			v0 = this->vertex(current, i);
			hvit = hvend = this->halfedges(v0);
			do {
				std::vector<Edge>::iterator it = std::find(available.begin(), available.end(), this->edge(*hvit));
				if (it != available.end())
					available.erase(it);
			} while (++hvit != hvend);
		}
		std::vector<Edge>::iterator it = std::find(available.begin(), available.end(), current);
		allEdges.erase(it);
		this->remove_edge(current);
		edgeCount--;
	}*/
}