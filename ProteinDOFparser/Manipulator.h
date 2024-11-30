/**
 * Project ProteinDOFparser
 * @author Mu Wang
 */


#ifndef _MANIPULATOR_H
#define _MANIPULATOR_H

#include "ProteinDOFparser_common.h"
#include "Pose.h"
#include "Protocol.h"
#include "EnergyScoreFunction.h"
#include "Selector.h"

class Manipulator {
public: 
    Poes pose_in;
    Pose pose_out;
    Protocol protocol;
    EnergyScoreFunction energy_score_function;
    Selector selector;
    
void run_protocol();
};

#endif //_MANIPULATOR_H