#include "InputSomething.h"

int main() {
    InputSomething* program = new InputSomething;
    program -> Run();
    program -> Quit();
    delete program;
    return 0;
}

