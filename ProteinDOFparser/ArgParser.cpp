#include "ArgParser.h"
#include <format>

ArgParser::ArgParser() {
    // default values of variables
    this->parameters.input_file_path = "protein.pdb";
    this->parameters.output_file_path = "DOF_protein.txt";
}


void ArgParser::parse(int argc, char *argv[]) {
    // TODO: Implement parse functionality
    this->usage = R"(Usage: prodof_)" + std::string(argv[0]) + R"( [options])
Options:
    -i, --input_file <path>    Input PDB file path
    -o, --output_file <path>   Output DOF file path
    -s, --selector_file <path> Selector file path
    -v, --verbose              Print verbose output
    -h, --help                 Print help message
    )";

    // default values of variables

    bool verbose = false;
    bool help = false;
    std::string selector_file_path = "select_atoms.txt";

    // argument options parsing
    static struct option long_options[] = {
        {"input_file", required_argument, 0, 'i'},
        {"output_file", required_argument, 0, 'o'},
        {"selector_file", no_argument, 0, 's'},
        {"verbose", no_argument, 0, 'v'},
        {"help", no_argument, 0, 'h'},
        {0, 0, 0, 0}
    };
    int option_index = 0;
    int c = getopt_long(argc, argv, "i:o:vh", long_options, &option_index);
    while (c != -1) {
        switch (c) {
            case 'i': this->parameters.input_file_path = optarg; break;
            case 'o': this->parameters.output_file_path = optarg; break;
            case 's': this->parameters.selector_file_path = optarg; break;
            case 'v': verbose = true; break;
            case 'h': help = true; break;
            default: std::cerr << usage << std::endl; exit(EXIT_FAILURE);
        }
    }
    if (help) {
        std::cout << usage << std::endl;
        exit(EXIT_SUCCESS);
    }

    // check if input file exists or empty
    if (this->parameters.input_file_path.empty()) {
        std::cerr << "Input file path is empty" << std::endl;
        throw ProDofError("Input file path is empty");
    }
    // check if output file path is empty
    if (this->parameters.output_file_path.empty()) {
        std::cerr << "Output file path is empty" << std::endl;
        throw ProDofError("Output file path is empty");
    }
    



}