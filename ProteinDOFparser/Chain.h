/**
 * Project ProteinDOFparser
 * @author Mu Wang
 */


#ifndef _CHAIN_H
#define _CHAIN_H

#include "ResidueGroup.h"

class Chain {
public: 
    ResidueGroup residues;
    std::string name;
    
void init();
    
    std::string report();
};

#endif //_CHAIN_H