/**
 * Project ProteinDOFparser
 * @author Mu Wang
 */


#include "Atom.h"

/**
 * Atom implementation
 */
// define constructor
Atom::Atom() {
    name = "";
    mass = 0;
    atom_index = 0;
    coordination = std::vector<double>(3, 0);
    velocity = std::vector<double>(3, 0);
    residue_internal_coordination = std::vector<double>(3, 0);
    residue_internal_atom_index = std::vector<double>(3, 0);
}

/**
 * @return string
 */
std::string Atom::report() {
    return "";
}

/**
 * @return map<string, double>
 */
std::map<std::string, double> Atom::get_data_map() {
    return std::map<std::string, double>();
}