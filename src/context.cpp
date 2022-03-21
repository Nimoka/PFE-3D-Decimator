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

void Context::SetPLYReader(PLYReader* reader) {
    this->reader = reader;
}
PLYReader* Context::GetPLYReader() {
    return reader;
}

void Context::SetMesh(Mesh* mesh) {
    this->mesh = mesh;
}
Mesh* Context::GetMesh() {
    return mesh;
}

CLILoader Context::GetCLI() {
    return cli;
}

void Context::Launch() {
    LoadPLYFile(inputFile);
    int newFacesNumber = mesh->nbFaces / decimationFactor;
    mesh->DeleteEdges(mesh->nbFaces - newFacesNumber);
    //SavePLYFile(outputFile);
}

void Context::LoadPLYFile(std::string filepath) {
	PLYReader* reader = new PLYReader(this, filepath);
	if (reader->Load()) {
		if (this->reader != nullptr)
			delete this->reader;
		this->reader = reader;

		SetMesh(reader->GetMesh());
	} else {
		std::cerr << "Failed to load file '" + filepath + "'." << std::endl;
		delete reader;
	}
}