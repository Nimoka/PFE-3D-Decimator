#ifndef MESH_H
#define MESH_H

#include <pmp/SurfaceMesh.h>

using namespace pmp;

class Mesh : public SurfaceMesh
{
public:
    void DeleteFaces(int toDelete);
    
    // Accessors to vertex attributes as Eigen's matrices:
    Eigen::Map<Eigen::Matrix3Xf> positions() {
        auto &vertices = get_vertex_property<pmp::Point>("v:point").vector();
        return Eigen::Map<Eigen::Matrix3Xf>(vertices[0].data(), 3, vertices.size());
    }

    Eigen::Map<Eigen::Matrix3Xf> colors() {
        auto &vcolors = get_vertex_property<pmp::Color>("v:color").vector();
        return Eigen::Map<Eigen::Matrix3Xf>(vcolors[0].data(), 3, vcolors.size());
    }

    Eigen::Map<Eigen::Matrix2Xf> texcoords() {
        auto &texcoords = get_vertex_property<pmp::TexCoord>("v:texcoord").vector();
        return Eigen::Map<Eigen::Matrix2Xf>(texcoords[0].data(), 2,
                                            texcoords.size());
    }

    Eigen::Map<Eigen::VectorXi> marks() {
        auto &marks = get_edge_property<int>("e:mark").vector();
        return Eigen::Map<Eigen::VectorXi>(marks.data(), marks.size());
    }
};

#endif // MESH_H