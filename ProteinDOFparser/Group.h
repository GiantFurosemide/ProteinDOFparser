/**
 * Project ProteinDOFparser
 * @author Mu Wang
 */


#ifndef _GROUP_H
#define _GROUP_H

#include "ProteinDOFparser_common.h"

template <typename T>
class Group {
public: 
    
    void get();
    
    void set();
    
    void report();

    Group():data_size(0) {};

protected: 
    
    std::vector<T> data;
    int data_size;
};

#endif //_GROUP_H