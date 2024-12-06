/**
 * @brief Main class for manipulating protein structures
 * @details Handles protein structure manipulation, including reading input,
 *          running protocols, and generating output
 * @author Mu Wang
 */


#ifndef _MANIPULATOR_H
#define _MANIPULATOR_H

#include "ProteinDOFparser_common.h"
#include "Pose.h"
#include "Protocol.h"
#include "EnergyScoreFunction.h"
#include "Selector.h"
#include "ProDofError.h"
#include "ArgParser.h"
#include "Parameter.h"

/**
 * @brief Main class for manipulating protein structures
 * @details Handles protein structure manipulation, including reading input,
 *          running protocols, and generating output
 */
class Manipulator {
public: 
    Pose pose_in;
    Pose pose_out;
    Protocol protocol;
    EnergyScoreFunction energy_score_function;
    Selector selector;
    Parameter parameters;
    std::string usage;

    Manipulator();
    
    /**
     * @brief Reads and parses command line arguments and stores them in parameters
     * @param argc Number of arguments
     * @param argv Array of argument strings
     * @throws ProDofError If invalid arguments are provided
     */
    void read(int argc, char *argv[]);

    /**
     * @brief Initializes the manipulator with loaded data
     * @throws ProDofError If initialization fails
     */
    void init();

    /**
     * @brief Executes the main manipulation protocol
     * @return void
     */
    void run();

    /**
     * @brief Generates a report of the manipulation results
     * @return void
     */ 
    void report();
    
};

#endif //_MANIPULATOR_H