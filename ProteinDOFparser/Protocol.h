/**
 * Project ProteinDOFparser
 * @author Mu Wang
 */


#ifndef _PROTOCOL_H
#define _PROTOCOL_H

#include "ProteinDOFparser_common.h"
#include "Pose.h"
#include "Selector.h"

class Protocol {
public:
    Pose pose;
    Selector selector;
    
    Protocol(Pose& pose, Selector& selector);
    void init();
    void run();
};

#endif //_PROTOCOL_H