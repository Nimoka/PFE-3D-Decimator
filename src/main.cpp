#include "context.h"

Context* context;

int main(int argc, char** argv) {
    srand(time(0));

	context = new Context();

    int error = context->LoadOptions(argc, argv);
    if (error)
        return error;

    context->Launch();

    return 0;
}