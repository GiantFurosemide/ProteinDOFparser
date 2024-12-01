/**
 * Project ProteinDOFparser
 * @author Mu Wang
 */


#ifndef _POES_H
#define _POES_H

#include "ChainGroup.h"

class Pose {
public: 
    std::string name;
    ChainGroup chains;
    
void init();
    
std::string report();
};

#endif //_POES_H