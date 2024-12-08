/**
 * Project ProteinDOFparser
 * @author Mu Wang
 */


#include "Protocol.h"

/**
 * Protocol implementation
 */

Protocol::Protocol(Pose& pose, Selector& selector) {
    this->pose = pose;
    this->selector = selector;
    this->init();
    this->run();
}

void Protocol::init() {}

void Protocol::run() {}