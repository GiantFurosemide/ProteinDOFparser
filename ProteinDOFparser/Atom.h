/**
 * Project ProteinDOFparser
 * @author Mu Wang
 */

#ifndef _ATOM_H
#define _ATOM_H

#include "ProteinDOFparser_common.h"

class Atom {
public: 
    std::string name;
    float mass;
    int atom_index;

    /* coordination, velocity, residue_internal_coordination, residue_internal_atom_index 
    are all vectors of size 3, initialized to 0
    */
    std::vector<double> coordination;
    std::vector<double> velocity;
    std::vector<double> residue_internal_coordination;
    std::vector<double> residue_internal_atom_index;

    // define constructor
    Atom();

    // define methods
    std::string report();
    std::map<std::string, double> get_data_map();
};

#endif //_ATOM_H