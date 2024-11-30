/**
 * Project ProteinDOFparser
 * @author Mu Wang
 */


#ifndef _RESIDUE_H
#define _RESIDUE_H

#include "AtomGroup.h"

class Residue {
public: 
    AtomGroup atoms;
    std::string name;
    std::string name_one_letter;
    std::string name_three_letter;
    std::string chain;
    int global_index;
    int resnum;
    bool if_C_ter;
    bool if_N_ter;
    double phi;
    double psi;
    
std::string report();
};

#endif //_RESIDUE_H