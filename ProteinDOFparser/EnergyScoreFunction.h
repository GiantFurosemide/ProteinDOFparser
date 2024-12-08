/**
 * Project ProteinDOFparser
 * @author Mu Wang
 */


#ifndef _ENERGYSCOREFUNCTION_H
#define _ENERGYSCOREFUNCTION_H

#include "ScoreFunctionWeight.h"
class EnergyScoreFunction {
public:
    Parameter parameters;
    EnergyScoreFunction(Parameter parameters);
};

#endif //_ENERGYSCOREFUNCTION_H