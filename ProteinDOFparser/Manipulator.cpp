/**
 * Project ProteinDOFparser
 * @author Mu Wang
 */


#include "Manipulator.h"

/**
 * manipulator implementation
 */

void Manipulator::read(int argc, char *argv[]) {
    ArgParser arg_parser;
    arg_parser.parse(argc, argv);
    // store parameters in manipulator
    this->parameters = arg_parser.parameters;
    this->usage = arg_parser.usage;
}




void Manipulator::report() {
    std::cout << this->usage << std::endl;
}