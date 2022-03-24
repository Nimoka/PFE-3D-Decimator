#include "context.h"

Context::Context() { };

int Context::LoadOptions(int argc, char** argv) {
    return cli.LoadContext(this, argc, argv);
}

void Context::SetInputFile(std::string file) {
    inputFile = file;
}
std::string Context::GetInputFile() {
    return inputFile;
}

void Context::SetOutputFile(std::string file) {
    outputFile = file;
}
std::string Context::GetOutputFile() {
    return outputFile;
}

void Context::SetDecimationFactor(float factor) {
    decimationFactor = factor;
}
float Context::GetDecimationFactor() {
    return decimationFactor;
}

void Context::SetRandomSeed(int seed) {
    randomSeed = seed;
    srand(seed);
}
int Context::GetRandomSeed() {
    return randomSeed;
}

void Context::SetMesh(Mesh mesh) {
    this->mesh = mesh;
}
Mesh Context::GetMesh() {
    return mesh;
}

CLILoader Context::GetCLI() {
    return cli;
}

void Context::Launch() {
    IOFlags flags = IOFlags();
    flags.use_binary = true;
    
    std::cout << "Loading file '" << GetInputFile() << "'...";
    std::cout.flush(); 
    mesh.read(GetInputFile(), flags);
    std::cout << "loaded, found " << mesh.n_faces() << " faces." << std::endl;
    int newFacesNumber = mesh.n_faces() / decimationFactor;

    mesh.DeleteFaces(mesh.n_faces() - newFacesNumber);

	mesh.garbage_collection();
    mesh.write(GetOutputFile(), flags);
}