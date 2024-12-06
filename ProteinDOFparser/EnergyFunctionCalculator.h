/**
 * Project ProteinDOFparser
 * @author Mu Wang
 */


#ifndef _ENERGYFUNCTIONCALCULATOR_H
#define _ENERGYFUNCTIONCALCULATOR_H

#include "ProteinDOFparser_common.h"
class EnergyFunctionCalculator {
public: 
    std::vector<float> weight;
    
    std::vector<float> scorefunction();
};

#endif //_ENERGYFUNCTIONCALCULATOR_H