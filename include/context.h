#ifndef CONTEXT_H
#define CONTEXT_H

#include <iostream>
#include <vector>

#include "cliloader.h"
#include "mesh.h"

class Context
{
public:
	/* Initialization */
	Context();
	int LoadOptions(int argc, char** argv);

	void Quit();

	void SetInputFile(std::string file);
	std::string GetInputFile();

    void SetOutputFile(std::string file);
    std::string GetOutputFile();

    void SetDecimationFactor(float factor);
    float GetDecimationFactor();

    void SetRandomSeed(int seed);
    int GetRandomSeed();

    void SetMesh(Mesh mesh);
    Mesh GetMesh();

	CLILoader GetCLI();

	void Launch();

    void LoadPLYFile(std::string filepath);

private:
    std::string inputFile = "";
    std::string outputFile = "";

    float decimationFactor = 1;
    int randomSeed = 1;

    Mesh mesh;

	CLILoader cli;
};

#endif // CONTEXT_H
