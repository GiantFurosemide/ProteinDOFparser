/**
 * Project ProteinDOFparser
 * @author Mu Wang
 */


#ifndef _DOFFILEPARSER_H
#define _DOFFILEPARSER_H

#include "ProteinDOFparser_common.h"
#include "IOParser.h"

class DOFfileParser: public IOParser {
public: 
    std::vector<std::string> sequence;
    std::vector<std::string> chain;
    std::vector<double> phi;
    std::vector<double> psi;
};

#endif //_DOFFILEPARSER_H