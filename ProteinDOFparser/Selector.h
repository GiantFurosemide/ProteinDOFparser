/**
 * Project ProteinDOFparser
 * @author Mu Wang
 */


#ifndef _SELECTOR_H
#define _SELECTOR_H

#include "ProteinDOFparser_common.h"
#include "SelectorParser.h"

class Selector {
public:
    std::string selector_file_path;
    std::map<std::string, std::string> selector_map;
    static const std::string usage;

    Selector();
    Selector(std::string selector_file_path);
    

    // generate "select_atoms.txt" if not exist, 
    // and default select all atoms
    void init();

private:
    // parse the selector file, and store the result in selector_map
    void parse_selector_file();
    void parse_selector_string(std::string selector_string);
};

#endif //_SELECTOR_H