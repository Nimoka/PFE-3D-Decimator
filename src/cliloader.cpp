#include "cliloader.h"

#include "context.h"

int CLILoader::LoadContext(void *c, int argc, char **argv) {
	Context *context = (Context*) c;

	/* Create CLI context */

	CLI::App app{"Decimator"};

	std::string inputFile, outputFile;
    float decimationFactor = 1;
    int randomSeed = -1;

	/* Set CLI options */

	app.add_option("-i, --input", inputFile, "PLY file to load")
			->check(CLI::ExistingFile)->check(FileWithExtension("ply"))
            ->required();
	app.add_option("-o, --output", outputFile, "PLY file to save")
			->check(CLI::NonexistentPath)->check(FileWithExtension("ply"))
            ->required();
	app.add_option("-d", decimationFactor, "Decimation factor")
			->check(CLI::Range(1, 1000000))->required();
	app.add_option("-s", randomSeed, "Random seed to use")
			->check(CLI::PositiveNumber);

	/* Parse CLI options */

	CLI11_PARSE(app, argc, argv);

	/* Process CLI options found (if needed) */

	// PLY file to load
	context->SetInputFile(inputFile);

	// PLY file to save
	context->SetOutputFile(outputFile);

	// Decimation factor
	context->SetDecimationFactor(decimationFactor);

	// Set seed
    context->SetRandomSeed(randomSeed == -1 ? rand() : randomSeed);

	return 0;
}