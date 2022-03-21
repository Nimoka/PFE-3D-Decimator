#ifndef MESH_H
#define MESH_H

#include <pmp/SurfaceMesh.h>

using namespace pmp;

class Mesh : public SurfaceMesh
{
public:
    void Mesh();
    void DeleteEdges(int toDelete);
    
    // Accessors to vertex attributes as Eigen's matrices:
    Eigen::Map<Eigen::Matrix3Xf> positions() {
        auto &vertices = get_vertex_property<pmp::Point>("v:point").vector();
        return Eigen::Map<Eigen::Matrix3Xf>(vertices[0].data(), 3, vertices.size());
    }

    Eigen::Map<Eigen::Matrix3Xf> colors() {
        auto &vcolors = get_vertex_property<pmp::Color>("v:color").vector();
        return Eigen::Map<Eigen::Matrix3Xf>(vcolors[0].data(), 3, vcolors.size());
    }

    Eigen::Map<Eigen::Matrix3Xf> normals() {
        auto &vnormals = get_vertex_property<pmp::Normal>("v:normal").vector();
        return Eigen::Map<Eigen::Matrix3Xf>(vnormals[0].data(), 3, vnormals.size());
    }

    Eigen::Map<Eigen::Matrix2Xf> texcoords() {
        auto &texcoords = get_vertex_property<pmp::TexCoord>("v:texcoord").vector();
        return Eigen::Map<Eigen::Matrix2Xf>(texcoords[0].data(), 2,
                                            texcoords.size());
    }

    Eigen::Map<Eigen::MatrixXi> handleds() {
        auto &handleds = get_vertex_property<int>("v:handled").vector();
        return Eigen::Map<Eigen::MatrixXi>(handleds.data(), handleds.size());
    }
};

#endif // MESH_H