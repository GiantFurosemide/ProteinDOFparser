#ifndef _PARAMETER_H
#define _PARAMETER_H

#include "ProteinDOFparser_common.h"

/**
 * @brief Class for storing parameters
 */
class Parameter {
public:
    std::string input_file_path;
    std::string output_file_path;
    std::string selector_file_path;

    Parameter():
        input_file_path(""), 
        output_file_path(""), 
        selector_file_path("") {};
};

#endif // _PARAMETER_H