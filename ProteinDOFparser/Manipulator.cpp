/**
 * Project ProteinDOFparser
 * @author Mu Wang
 */


#include "Manipulator.h"

/**
 * manipulator implementation
 */
/**
 * @brief Read command line arguments and store them in manipulator's parameters
 * @param argc Number of arguments
 * @param argv Array of argument strings
 */
void Manipulator::read(int argc, char *argv[]) {
    ArgParser arg_parser;
    arg_parser.parse(argc, argv);
    // store parameters in manipulator
    this->parameters = arg_parser.parameters;
    this->usage = arg_parser.usage;
}

/**
     * @brief Initializes the manipulator with loaded data
     * @throws ProDofError If initialization fails
 */
void Manipulator::init() {
    // read parameters
    // initialize Pose
    // initialize DOF
    // initialize selector
    // initialize protocol


}

/**
     * @brief Executes the main manipulation protocol
     * @return void
 */
void Manipulator::run() {
    // run protocol
    // save processed pose to pdb file
    // save processed DOF to dof file
}






void Manipulator::report() {
    std::cout << this->usage << std::endl;
}