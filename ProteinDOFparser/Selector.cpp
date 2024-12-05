/**
 * Project ProteinDOFparser
 * @author Mu Wang
 */


#include "Selector.h"

/**
 * selector implementation
 */
const std::string Selector::usage = R"(# comment line : start with '#'
# empty line : skip
# [ sel_name_1 ] : selector name
# chain A and residue 1-10 : selector
# one line one selector, one name one selector
# 
# syntax similar to pymol select command
# chain : chain name, e.g. A, B, C, etc.
# resn : residue name, e.g. GLY, ALA, etc.
# resi : residue index, e.g. 1, 2, 3, etc.
# atom : atom name, e.g. CA, CB, etc.
# boolean operator : and, or, not
# all : select all atoms
#
#
# usage:
#
# select chain A and resn 1-10, name as sel_name_1
#[ sel_name_1 ]
# chain A and resn 1-10
#
# select chain B and residue 1-10 and atom CA, name as sel_name_2
#[ sel_name_2 ]
# chain B and resn 1-10 and atom CA
# 
#
# select (chain A or chain B) and resn 1-10 not atom CA, name as sel_name_3
#[ sel_name_3 ]
# (chain A or chain B) and resn 1-10 not atom CA
#
# select all atoms as sel_name_4
#[ sel_name_4 ]
# all
[ sel_name_5 ]
all

)";

Selector::Selector() {
    // no selector file path provided, default selector file path
    this->selector_file_path = "select_atoms.txt";
    // check if selector file exists, if not, create it,and write usage to it
    std::ofstream file(this->selector_file_path);
    if (!file.good()) {
        file << Selector::usage;
    }
    file.close();

    this->init();

}

Selector::Selector(std::string selector_file_path) {
    this->selector_file_path = selector_file_path;
    this->init();
}

void Selector::init() {
    // check if selector file exists
    std::ifstream file(this->selector_file_path);
    if (!file.good()) {
        std::cerr << "Selector file does not exist: " << selector_file_path << std::endl;
        throw ProDofError("Selector file does not exist: " + selector_file_path);
    }
    file.close();

    // parse the selector file
    this->parse_selector_file();
}

void Selector::parse_selector_file() {
    // read the selector file line by line
    std::string line;
    std::ifstream file(this->selector_file_path);
    std::string sel_name_tmp="";


    // read the selector file line by line, and update the selector_map
    while (std::getline(file, line)) {
        // skip comment line and empty line
        if (line.empty() || line[0] == '#') {
            continue;
        }

        // if start with [, then it is a selector name, the next line is the selector
        if (line[0] == '[') {
            // extract the selector name between [],and remove the space
            std::string sel_name = line.substr(1, line.find(']') - 1);
            sel_name.erase(std::remove(sel_name.begin(), sel_name.end(), ' '), sel_name.end());
            sel_name_tmp = sel_name;
            continue;
        }
        // if the next line is not empty, then it is the selector
        if (!line.empty()) {
            this->selector_map[sel_name_tmp] = line;
            sel_name_tmp = "";
        }

    }


}

