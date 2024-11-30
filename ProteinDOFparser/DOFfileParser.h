/**
 * Project ProteinDOFparser
 * @author Mu Wang
 */


#ifndef _DOFFILEPARSER_H
#define _DOFFILEPARSER_H

#include "IOParser.h"


class DOFfileParser: public IOParser {
public: 
    std::vector sequence;
    std::vector chain;
    void phi;
    void psi;
};

#endif //_DOFFILEPARSER_H