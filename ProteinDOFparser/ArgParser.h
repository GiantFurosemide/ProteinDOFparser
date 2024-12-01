#ifndef _ARGPARSER_H
#define _ARGPARSER_H

#include "ProteinDOFparser_common.h"
#include "IOParser.h"
#include "Parameter.h"
#include <getopt.h>

/**
 * @brief Class for parsing command line arguments
 */
class ArgParser : public IOParser {
public:
    Parameter parameters;
    std::string usage;
    // parse command line arguments and store them in parameters
    void parse(int argc, char *argv[]);
};
#endif //_ARGPARSER_H