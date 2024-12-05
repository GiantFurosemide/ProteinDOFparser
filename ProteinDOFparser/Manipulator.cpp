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
    std::string input_file_path = this->parameters.input_file_path;
    std::string output_file_path = this->parameters.output_file_path;
    std::string selector_file_path = this->parameters.selector_file_path;
    // initialize Pose
    this->pose_in = Pose(input_file_path);
    // initialize DOF()// already initialized in Pose
    // initialize selector (default: all atoms)
    this->selector = Selector(selector_file_path);
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