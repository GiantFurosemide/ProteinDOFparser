// constant values from alphafold/common/residue_constants.py
// https://github.com/google-deepmind/alphafold


#include <map>
#include <string>
#include <vector>
#include <tuple>

namespace residue_constants {

// Distance from one CA to next CA [trans configuration: omega = 180].
const double ca_ca = 3.80209737096;


// Format: The list for each AA type contains chi1, chi2, chi3, chi4 in
// this order (or a relevant subset from chi1 onwards). ALA and GLY don't have
// chi angles so their chi angle lists are empty.
const std::map<std::string, std::vector<std::vector<std::string>>> 
chi_angles_atoms = {
    {"ALA", {}},
    // Chi5 in arginine is always 0 +- 5 degrees, so ignore it.
    {"ARG", {{"N", "CA", "CB", "CG"}, {"CA", "CB", "CG", "CD"},
             {"CB", "CG", "CD", "NE"}, {"CG", "CD", "NE", "CZ"}}},
    {"ASN", {{"N", "CA", "CB", "CG"}, {"CA", "CB", "CG", "OD1"}}},
    {"ASP", {{"N", "CA", "CB", "CG"}, {"CA", "CB", "CG", "OD1"}}},
    {"CYS", {{"N", "CA", "CB", "SG"}}},
    {"GLN", {{"N", "CA", "CB", "CG"}, {"CA", "CB", "CG", "CD"},
             {"CB", "CG", "CD", "OE1"}}},
    {"GLU", {{"N", "CA", "CB", "CG"}, {"CA", "CB", "CG", "CD"},
             {"CB", "CG", "CD", "OE1"}}},
    {"GLY", {}},
    {"HIS", {{"N", "CA", "CB", "CG"}, {"CA", "CB", "CG", "ND1"}}},
    {"ILE", {{"N", "CA", "CB", "CG1"}, {"CA", "CB", "CG1", "CD1"}}},
    {"LEU", {{"N", "CA", "CB", "CG"}, {"CA", "CB", "CG", "CD1"}}},
    {"LYS", {{"N", "CA", "CB", "CG"}, {"CA", "CB", "CG", "CD"},
             {"CB", "CG", "CD", "CE"}, {"CG", "CD", "CE", "NZ"}}},
    {"MET", {{"N", "CA", "CB", "CG"}, {"CA", "CB", "CG", "SD"},
             {"CB", "CG", "SD", "CE"}}},
    {"PHE", {{"N", "CA", "CB", "CG"}, {"CA", "CB", "CG", "CD1"}}},
    {"PRO", {{"N", "CA", "CB", "CG"}, {"CA", "CB", "CG", "CD"}}},
    {"SER", {{"N", "CA", "CB", "OG"}}},
    {"THR", {{"N", "CA", "CB", "OG1"}}},
    {"TRP", {{"N", "CA", "CB", "CG"}, {"CA", "CB", "CG", "CD1"}}},
    {"TYR", {{"N", "CA", "CB", "CG"}, {"CA", "CB", "CG", "CD1"}}},
    {"VAL", {{"N", "CA", "CB", "CG1"}}}
};


// If chi angles given in fixed-length array, this matrix determines how to mask
// them for each AA type. The order is as per restype_order (see below).
const std::vector<std::vector<float>> 
chi_angles_mask = {
    {0.0, 0.0, 0.0, 0.0},  // ALA
    {1.0, 1.0, 1.0, 1.0},  // ARG
    {1.0, 1.0, 0.0, 0.0},  // ASN
    {1.0, 1.0, 0.0, 0.0},  // ASP
    {1.0, 0.0, 0.0, 0.0},  // CYS
    {1.0, 1.0, 1.0, 0.0},  // GLN
    {1.0, 1.0, 1.0, 0.0},  // GLU
    {0.0, 0.0, 0.0, 0.0},  // GLY
    {1.0, 1.0, 0.0, 0.0},  // HIS
    {1.0, 1.0, 0.0, 0.0},  // ILE
    {1.0, 1.0, 0.0, 0.0},  // LEU
    {1.0, 1.0, 1.0, 1.0},  // LYS
    {1.0, 1.0, 1.0, 0.0},  // MET
    {1.0, 1.0, 0.0, 0.0},  // PHE
    {1.0, 1.0, 0.0, 0.0},  // PRO
    {1.0, 0.0, 0.0, 0.0},  // SER
    {1.0, 0.0, 0.0, 0.0},  // THR
    {1.0, 1.0, 0.0, 0.0},  // TRP
    {1.0, 1.0, 0.0, 0.0},  // TYR
    {1.0, 0.0, 0.0, 0.0}   // VAL
};





struct coord {
    double x;
    double y;
    double z;
    // initialize with 0, 0, 0
    coord() : x(0), y(0), z(0) {}
    coord(double x, double y, double z) : x(x), y(y), z(z) {}
};



struct rigid_group_atom_position {
    std::string atom_name;
    int group_idx;
    coord atom_position;
};
/*
 Atoms positions relative to the 8 rigid groups, defined by the pre-omega, phi,
 psi and chi angles:
 0: 'backbone group',
 1: 'pre-omega-group', (empty)
 2: 'phi-group', (currently empty, because it defines only hydrogens)
 3: 'psi-group',
 4,5,6,7: 'chi1,2,3,4-group'
 The atom positions are relative to the axis-end-atom of the corresponding
 rotation axis. The x-axis is in direction of the rotation axis, and the y-axis
 is defined such that the dihedral-angle-definiting atom (the last entry in
 chi_angles_atoms above) is in the xy-plane (with a positive y-coordinate).
 format: [atom_name, group_idx, rel_position]
*/
const std::map<std::string, std::vector<rigid_group_atom_position>> 
rigid_group_atom_positions = {
    {"ALA", {
        {"N", 0, coord(-0.525, 1.363, 0.000)},
        {"CA", 0, coord(0.000, 0.000, 0.000)},
        {"C", 0, coord(1.526, -0.000, -0.000)},
        {"CB", 0, coord(-0.529, -0.774, -1.205)},
        {"O", 3, coord(0.627, 1.062, 0.000)}
    }},
    {"ARG", {
        {"N", 0, coord(-0.524, 1.362, -0.000)},
        {"CA", 0, coord(0.000, 0.000, 0.000)},
        {"C", 0, coord(1.525, -0.000, -0.000)},
        {"CB", 0, coord(-0.524, -0.778, -1.209)},
        {"O", 3, coord(0.626, 1.062, 0.000)},
        {"CG", 4, coord(0.616, 1.390, -0.000)},
        {"CD", 5, coord(0.564, 1.414, 0.000)},
        {"NE", 6, coord(0.539, 1.357, -0.000)},
        {"NH1", 7, coord(0.206, 2.301, 0.000)},
        {"NH2", 7, coord(2.078, 0.978, -0.000)},
        {"CZ", 7, coord(0.758, 1.093, -0.000)}
    }},
    {"ASN", {
        {"N", 0, coord(-0.536, 1.357, 0.000)},
        {"CA", 0, coord(0.000, 0.000, 0.000)},
        {"C", 0, coord(1.526, -0.000, -0.000)},
        {"CB", 0, coord(-0.531, -0.787, -1.200)},
        {"O", 3, coord(0.625, 1.062, 0.000)},
        {"CG", 4, coord(0.584, 1.399, 0.000)},
        {"ND2", 5, coord(0.593, -1.188, 0.001)},
        {"OD1", 5, coord(0.633, 1.059, 0.000)}
    }},
    {"ASP", {
        {"N", 0, coord(-0.525, 1.362, -0.000)},
        {"CA", 0, coord(0.000, 0.000, 0.000)},
        {"C", 0, coord(1.527, 0.000, -0.000)},
        {"CB", 0, coord(-0.526, -0.778, -1.208)},
        {"O", 3, coord(0.626, 1.062, -0.000)},
        {"CG", 4, coord(0.593, 1.398, -0.000)},
        {"OD1", 5, coord(0.610, 1.091, 0.000)},
        {"OD2", 5, coord(0.592, -1.101, -0.003)}
    }},
    {"CYS", {
        {"N", 0, coord(-0.522, 1.362, -0.000)},
        {"CA", 0, coord(0.000, 0.000, 0.000)},
        {"C", 0, coord(1.524, 0.000, 0.000)},
        {"CB", 0, coord(-0.519, -0.773, -1.212)},
        {"O", 3, coord(0.625, 1.062, -0.000)},
        {"SG", 4, coord(0.728, 1.653, 0.000)}
    }},
    {"GLN", {
        {"N", 0, coord(-0.526, 1.361, -0.000)},
        {"CA", 0, coord(0.000, 0.000, 0.000)},
        {"C", 0, coord(1.526, 0.000, 0.000)},
        {"CB", 0, coord(-0.525, -0.779, -1.207)},
        {"O", 3, coord(0.626, 1.062, -0.000)},
        {"CG", 4, coord(0.615, 1.393, 0.000)},
        {"CD", 5, coord(0.587, 1.399, -0.000)},
        {"NE2", 6, coord(0.593, -1.189, -0.001)},
        {"OE1", 6, coord(0.634, 1.060, 0.000)}
    }},
    {"GLU", {
        {"N", 0, coord(-0.528, 1.361, 0.000)},
        {"CA", 0, coord(0.000, 0.000, 0.000)},
        {"C", 0, coord(1.526, -0.000, -0.000)},
        {"CB", 0, coord(-0.526, -0.781, -1.207)},
        {"O", 3, coord(0.626, 1.062, 0.000)},
        {"CG", 4, coord(0.615, 1.392, 0.000)},
        {"CD", 5, coord(0.600, 1.397, 0.000)},
        {"OE1", 6, coord(0.607, 1.095, -0.000)},
        {"OE2", 6, coord(0.589, -1.104, -0.001)}
    }},
    {"GLY", {
        {"N", 0, coord(-0.572, 1.337, 0.000)},
        {"CA", 0, coord(0.000, 0.000, 0.000)},
        {"C", 0, coord(1.517, -0.000, -0.000)},
        {"O", 3, coord(0.626, 1.062, -0.000)}
    }},
    {"HIS", {
        {"N", 0, coord(-0.527, 1.360, 0.000)},
        {"CA", 0, coord(0.000, 0.000, 0.000)},
        {"C", 0, coord(1.525, 0.000, 0.000)},
        {"CB", 0, coord(-0.525, -0.778, -1.208)},
        {"O", 3, coord(0.625, 1.063, 0.000)},
        {"CG", 4, coord(0.600, 1.370, -0.000)},
        {"CD2", 5, coord(0.889, -1.021, 0.003)},
        {"ND1", 5, coord(0.744, 1.160, -0.000)},
        {"CE1", 5, coord(2.030, 0.851, 0.002)},
        {"NE2", 5, coord(2.145, -0.466, 0.004)}
    }},
    {"ILE", {
        {"N", 0, coord(-0.493, 1.373, -0.000)},
        {"CA", 0, coord(0.000, 0.000, 0.000)},
        {"C", 0, coord(1.527, -0.000, -0.000)},
        {"CB", 0, coord(-0.536, -0.793, -1.213)},
        {"O", 3, coord(0.627, 1.062, -0.000)},
        {"CG1", 4, coord(0.534, 1.437, -0.000)},
        {"CG2", 4, coord(0.540, -0.785, -1.199)},
        {"CD1", 5, coord(0.619, 1.391, 0.000)}
    }},
    {"LEU", {
        {"N", 0, coord(-0.520, 1.363, 0.000)},
        {"CA", 0, coord(0.000, 0.000, 0.000)},
        {"C", 0, coord(1.525, -0.000, -0.000)},
        {"CB", 0, coord(-0.522, -0.773, -1.214)},
        {"O", 3, coord(0.625, 1.063, -0.000)},
        {"CG", 4, coord(0.678, 1.371, 0.000)},
        {"CD1", 5, coord(0.530, 1.430, -0.000)},
        {"CD2", 5, coord(0.535, -0.774, 1.200)}
    }},
    {"LYS", {
        {"N", 0, coord(-0.526, 1.362, -0.000)},
        {"CA", 0, coord(0.000, 0.000, 0.000)},
        {"C", 0, coord(1.526, 0.000, 0.000)},
        {"CB", 0, coord(-0.524, -0.778, -1.208)},
        {"O", 3, coord(0.626, 1.062, -0.000)},
        {"CG", 4, coord(0.619, 1.390, 0.000)},
        {"CD", 5, coord(0.559, 1.417, 0.000)},
        {"CE", 6, coord(0.560, 1.416, 0.000)},
        {"NZ", 7, coord(0.554, 1.387, 0.000)}
    }},
    {"MET", {
        {"N", 0, coord(-0.521, 1.364, -0.000)},
        {"CA", 0, coord(0.000, 0.000, 0.000)},
        {"C", 0, coord(1.525, 0.000, 0.000)},
        {"CB", 0, coord(-0.523, -0.776, -1.210)},
        {"O", 3, coord(0.625, 1.062, -0.000)},
        {"CG", 4, coord(0.613, 1.391, -0.000)},
        {"SD", 5, coord(0.703, 1.695, 0.000)},
        {"CE", 6, coord(0.320, 1.786, -0.000)}
    }},
    {"PHE", {
        {"N", 0, coord(-0.518, 1.363, 0.000)},
        {"CA", 0, coord(0.000, 0.000, 0.000)},
        {"C", 0, coord(1.524, 0.000, -0.000)},
        {"CB", 0, coord(-0.525, -0.776, -1.212)},
        {"O", 3, coord(0.626, 1.062, -0.000)},
        {"CG", 4, coord(0.607, 1.377, 0.000)},
        {"CD1", 5, coord(0.709, 1.195, -0.000)},
        {"CD2", 5, coord(0.706, -1.196, 0.000)},
        {"CE1", 5, coord(2.102, 1.198, -0.000)},
        {"CE2", 5, coord(2.098, -1.201, -0.000)},
        {"CZ", 5, coord(2.794, -0.003, -0.001)}
    }},
    {"PRO", {
        {"N", 0, coord(-0.566, 1.351, -0.000)},
        {"CA", 0, coord(0.000, 0.000, 0.000)},
        {"C", 0, coord(1.527, -0.000, 0.000)},
        {"CB", 0, coord(-0.546, -0.611, -1.293)},
        {"O", 3, coord(0.621, 1.066, 0.000)},
        {"CG", 4, coord(0.382, 1.445, 0.0)},
        {"CD", 5, coord(0.477, 1.424, 0.0)}  // manually made angle 2 degrees larger
    }},
    {"SER", {
        {"N", 0, coord(-0.529, 1.360, -0.000)},
        {"CA", 0, coord(0.000, 0.000, 0.000)},
        {"C", 0, coord(1.525, -0.000, -0.000)},
        {"CB", 0, coord(-0.518, -0.777, -1.211)},
        {"O", 3, coord(0.626, 1.062, -0.000)},
        {"OG", 4, coord(0.503, 1.325, 0.000)}
    }},
    {"THR", {
        {"N", 0, coord(-0.517, 1.364, 0.000)},
        {"CA", 0, coord(0.000, 0.000, 0.000)},
        {"C", 0, coord(1.526, 0.000, -0.000)},
        {"CB", 0, coord(-0.516, -0.793, -1.215)},
        {"O", 3, coord(0.626, 1.062, 0.000)},
        {"CG2", 4, coord(0.550, -0.718, -1.228)},
        {"OG1", 4, coord(0.472, 1.353, 0.000)}
    }},
    {"TRP", {
        {"N", 0, coord(-0.521, 1.363, 0.000)},
        {"CA", 0, coord(0.000, 0.000, 0.000)},
        {"C", 0, coord(1.525, -0.000, 0.000)},
        {"CB", 0, coord(-0.523, -0.776, -1.212)},
        {"O", 3, coord(0.627, 1.062, 0.000)},
        {"CG", 4, coord(0.609, 1.370, -0.000)},
        {"CD1", 5, coord(0.824, 1.091, 0.000)},
        {"CD2", 5, coord(0.854, -1.148, -0.005)},
        {"CE2", 5, coord(2.186, -0.678, -0.007)},
        {"CE3", 5, coord(0.622, -2.530, -0.007)},
        {"NE1", 5, coord(2.140, 0.690, -0.004)},
        {"CH2", 5, coord(3.028, -2.890, -0.013)},
        {"CZ2", 5, coord(3.283, -1.543, -0.011)},
        {"CZ3", 5, coord(1.715, -3.389, -0.011)}
    }},
    {"TYR", {
        {"N", 0, coord(-0.522, 1.362, 0.000)},
        {"CA", 0, coord(0.000, 0.000, 0.000)},
        {"C", 0, coord(1.524, -0.000, -0.000)},
        {"CB", 0, coord(-0.522, -0.776, -1.213)},
        {"O", 3, coord(0.627, 1.062, -0.000)},
        {"CG", 4, coord(0.607, 1.382, -0.000)},
        {"CD1", 5, coord(0.716, 1.195, -0.000)},
        {"CD2", 5, coord(0.713, -1.194, -0.001)},
        {"CE1", 5, coord(2.107, 1.200, -0.002)},
        {"CE2", 5, coord(2.104, -1.201, -0.003)},
        {"OH", 5, coord(4.168, -0.002, -0.005)},
        {"CZ", 5, coord(2.791, -0.001, -0.003)}
    }},
    {"VAL", {
        {"N", 0, coord(-0.494, 1.373, -0.000)},
        {"CA", 0, coord(0.000, 0.000, 0.000)},
        {"C", 0, coord(1.527, -0.000, -0.000)},
        {"CB", 0, coord(-0.533, -0.795, -1.213)},
        {"O", 3, coord(0.627, 1.062, -0.000)},
        {"CG1", 4, coord(0.540, 1.429, -0.000)},
        {"CG2", 4, coord(0.533, -0.776, 1.203)}
    }}
};


// A list of atoms (excluding hydrogen) for each AA type. PDB naming convention.
const std::map<std::string, std::vector<std::string>> 
residue_atoms = {
    {"ALA", {"C", "CA", "CB", "N", "O"}},
    {"ARG", {"C", "CA", "CB", "CG", "CD", "CZ", "N", "NE", "O", "NH1", "NH2"}},
    {"ASP", {"C", "CA", "CB", "CG", "N", "O", "OD1", "OD2"}},
    {"ASN", {"C", "CA", "CB", "CG", "N", "ND2", "O", "OD1"}},
    {"CYS", {"C", "CA", "CB", "N", "O", "SG"}},
    {"GLU", {"C", "CA", "CB", "CG", "CD", "N", "O", "OE1", "OE2"}},
    {"GLN", {"C", "CA", "CB", "CG", "CD", "N", "NE2", "O", "OE1"}},
    {"GLY", {"C", "CA", "N", "O"}},
    {"HIS", {"C", "CA", "CB", "CG", "CD2", "CE1", "N", "ND1", "NE2", "O"}},
    {"ILE", {"C", "CA", "CB", "CG1", "CG2", "CD1", "N", "O"}},
    {"LEU", {"C", "CA", "CB", "CG", "CD1", "CD2", "N", "O"}},
    {"LYS", {"C", "CA", "CB", "CG", "CD", "CE", "N", "NZ", "O"}},
    {"MET", {"C", "CA", "CB", "CG", "CE", "N", "O", "SD"}},
    {"PHE", {"C", "CA", "CB", "CG", "CD1", "CD2", "CE1", "CE2", "CZ", "N", "O"}},
    {"PRO", {"C", "CA", "CB", "CG", "CD", "N", "O"}},
    {"SER", {"C", "CA", "CB", "N", "O", "OG"}},
    {"THR", {"C", "CA", "CB", "CG2", "N", "O", "OG1"}},
    {"TRP", {"C", "CA", "CB", "CG", "CD1", "CD2", "CE2", "CE3", "CZ2", "CZ3",
             "CH2", "N", "NE1", "O"}},
    {"TYR", {"C", "CA", "CB", "CG", "CD1", "CD2", "CE1", "CE2", "CZ", "N", "O",
             "OH"}},
    {"VAL", {"C", "CA", "CB", "CG1", "CG2", "N", "O"}}
};



// Naming swaps for ambiguous atom names.
// Due to symmetries in the amino acids the naming of atoms is ambiguous in
// 4 of the 20 amino acids.
// (The LDDT paper lists 7 amino acids as ambiguous, but the naming ambiguities
// in LEU, VAL and ARG can be resolved by using the 3d constellations of
// the 'ambiguous' atoms and their neighbours)
const std::map<std::string, std::map<std::string, std::string>>
residue_atom_renaming_swaps = {
    {"ASP", {{"OD1", "OD2"}}},
    {"GLU", {{"OE1", "OE2"}}}, 
    {"PHE", {{"CD1", "CD2"}, {"CE1", "CE2"}}},
    {"TYR", {{"CD1", "CD2"}, {"CE1", "CE2"}}}
};

// Van der Waals radii [Angstroem] of the atoms(element types) (from Wikipedia)
const std::map<char, double> van_der_waals_radius = {
    {'C', 1.7},
    {'N', 1.55}, 
    {'O', 1.52},
    {'S', 1.8}
};

// atom types to element names
const std::map<std::string, std::string> atom_type_to_element = {
    {"N", "N"}, 
    {"CA", "C"}, 
    {"C", "C"}, 
    {"CB", "C"}, 
    {"O", "O"}, 
    {"CG", "C"},
    {"CG1", "C"}, 
    {"CG2", "C"}, 
    {"OG", "O"}, 
    {"OG1", "O"}, 
    {"SG", "S"}, 
    {"CD", "C"},
    {"CD1", "C"}, 
    {"CD2", "C"}, 
    {"ND1", "N"}, 
    {"ND2", "N"}, 
    {"OD1", "O"}, 
    {"OD2", "O"},
    {"SD", "S"}, 
    {"CE", "C"}, 
    {"CE1", "C"}, 
    {"CE2", "C"}, 
    {"CE3", "C"},
    {"NE", "N"}, 
    {"NE1", "N"}, 
    {"NE2", "N"}, 
    {"OE1", "O"}, 
    {"OE2", "O"},
    {"CH2", "C"}, 
    {"NH1", "N"}, 
    {"NH2", "N"}, 
    {"OH", "O"}, 
    {"CZ", "C"},
    {"CZ2", "C"}, 
    {"CZ3", "C"}, 
    {"NZ", "N"}, 
    {"OXT", "O"}
};



struct Bond {
    std::string atom1_name;
    std::string atom2_name;
    double length;
    double stddev;
    
    Bond(std::string a1, std::string a2, double l, double sd) :
        atom1_name(a1), atom2_name(a2), length(l), stddev(sd) {}
};

struct BondAngle {
    std::string atom1_name;
    std::string atom2_name;
    std::string atom3name;
    double angle_rad;
    double stddev;
    
    BondAngle(std::string a1, std::string a2, std::string a3, double ar, double sd) :
        atom1_name(a1), atom2_name(a2), atom3name(a3), angle_rad(ar), stddev(sd) {}
};

// This mapping is used when we need to store atom data in a format that requires
// fixed atom data size for every residue (e.g. a numpy array).
const std::vector<std::string> atom_types = {
    "N", "CA", "C", "CB", "O", "CG", "CG1", "CG2", "OG", "OG1", "SG", "CD",
    "CD1", "CD2", "ND1", "ND2", "OD1", "OD2", "SD", "CE", "CE1", "CE2", "CE3",
    "NE", "NE1", "NE2", "OE1", "OE2", "CH2", "NH1", "NH2", "OH", "CZ", "CZ2",
    "CZ3", "NZ", "OXT"
};

const std::map<std::string, int> atom_order = []() {
    std::map<std::string, int> order;
    for (size_t i = 0; i < atom_types.size(); i++) {
        order[atom_types[i]] = i;
    }
    return order;
}();

const int atom_type_num = atom_types.size(); // := 37

// A compact atom encoding with 14 columns
const std::map<std::string, std::vector<std::string>> 
restype_name_to_atom14_names = {
    {"ALA", {"N", "CA", "C", "O", "CB", "",    "",    "",    "",    "",    "",    "",    "",    ""}},
    {"ARG", {"N", "CA", "C", "O", "CB", "CG",  "CD",  "NE",  "CZ",  "NH1", "NH2", "",    "",    ""}},
    {"ASN", {"N", "CA", "C", "O", "CB", "CG",  "OD1", "ND2", "",    "",    "",    "",    "",    ""}},
    {"ASP", {"N", "CA", "C", "O", "CB", "CG",  "OD1", "OD2", "",    "",    "",    "",    "",    ""}},
    {"CYS", {"N", "CA", "C", "O", "CB", "SG",  "",    "",    "",    "",    "",    "",    "",    ""}},
    {"GLN", {"N", "CA", "C", "O", "CB", "CG",  "CD",  "OE1", "NE2", "",    "",    "",    "",    ""}},
    {"GLU", {"N", "CA", "C", "O", "CB", "CG",  "CD",  "OE1", "OE2", "",    "",    "",    "",    ""}},
    {"GLY", {"N", "CA", "C", "O", "",   "",    "",    "",    "",    "",    "",    "",    "",    ""}},
    {"HIS", {"N", "CA", "C", "O", "CB", "CG",  "ND1", "CD2", "CE1", "NE2", "",    "",    "",    ""}},
    {"ILE", {"N", "CA", "C", "O", "CB", "CG1", "CG2", "CD1", "",    "",    "",    "",    "",    ""}},
    {"LEU", {"N", "CA", "C", "O", "CB", "CG",  "CD1", "CD2", "",    "",    "",    "",    "",    ""}},
    {"LYS", {"N", "CA", "C", "O", "CB", "CG",  "CD",  "CE",  "NZ",  "",    "",    "",    "",    ""}},
    {"MET", {"N", "CA", "C", "O", "CB", "CG",  "SD",  "CE",  "",    "",    "",    "",    "",    ""}},
    {"PHE", {"N", "CA", "C", "O", "CB", "CG",  "CD1", "CD2", "CE1", "CE2", "CZ",  "",    "",    ""}},
    {"PRO", {"N", "CA", "C", "O", "CB", "CG",  "CD",  "",    "",    "",    "",    "",    "",    ""}},
    {"SER", {"N", "CA", "C", "O", "CB", "OG",  "",    "",    "",    "",    "",    "",    "",    ""}},
    {"THR", {"N", "CA", "C", "O", "CB", "OG1", "CG2", "",    "",    "",    "",    "",    "",    ""}},
    {"TRP", {"N", "CA", "C", "O", "CB", "CG",  "CD1", "CD2", "NE1", "CE2", "CE3", "CZ2", "CZ3", "CH2"}},
    {"TYR", {"N", "CA", "C", "O", "CB", "CG",  "CD1", "CD2", "CE1", "CE2", "CZ",  "OH",  "",    ""}},
    {"VAL", {"N", "CA", "C", "O", "CB", "CG1", "CG2", "",    "",    "",    "",    "",    "",    ""}},
    {"UNK", {"",  "",   "",  "",  "",   "",    "",    "",    "",    "",    "",    "",    "",    ""}}
};

// This is the standard residue order when coding AA type as a number.
// 1-letter AA codes
// Reproduce it by taking 3-letter AA codes and sorting them alphabetically.
const std::vector<std::string> restypes = {
    "A", "R", "N", "D", "C", "Q", "E", "G", "H", "I", "L", "K", "M", "F", "P",
    "S", "T", "W", "Y", "V"
};

const std::map<std::string, int> restype_order = []() {
    std::map<std::string, int> order;
    for (size_t i = 0; i < restypes.size(); i++) {
        order[restypes[i]] = i;
    }
    return order;
}();

const int restype_num = restypes.size(); // := 20
const int unk_restype_index = restype_num; // Catch-all index for unknown restypes

const std::vector<std::string> restypes_with_x = []() {
    std::vector<std::string> types = restypes;
    types.push_back("X");
    return types;
}();

const std::map<std::string, int> restype_order_with_x = []() {
    std::map<std::string, int> order;
    for (size_t i = 0; i < restypes_with_x.size(); i++) {
        order[restypes_with_x[i]] = i;
    }
    return order;
}();
const std::map<std::string, std::string> restype_1to3 = {
    {"A", "ALA"},
    {"R", "ARG"}, 
    {"N", "ASN"},
    {"D", "ASP"},
    {"C", "CYS"},
    {"Q", "GLN"},
    {"E", "GLU"},
    {"G", "GLY"},
    {"H", "HIS"},
    {"I", "ILE"},
    {"L", "LEU"},
    {"K", "LYS"},
    {"M", "MET"},
    {"F", "PHE"},
    {"P", "PRO"},
    {"S", "SER"},
    {"T", "THR"},
    {"W", "TRP"},
    {"Y", "TYR"},
    {"V", "VAL"}
};

// NB: restype_3to1 differs from Bio.PDB.protein_letters_3to1 by being a simple
// 1-to-1 mapping of 3 letter names to one letter names. The latter contains
// many more, and less common, three letter names as keys and maps many of these
// to the same one letter name (including 'X' and 'U' which we don't use here).
const std::map<std::string, std::string> restype_3to1 = []() {
    std::map<std::string, std::string> map;
    for (const auto& [k, v] : restype_1to3) {
        map[v] = k;
    }
    return map;
}();

// Define a restype name for all unknown residues.
const std::string unk_restype = "UNK";

const std::vector<std::string> resnames = []() {
    std::vector<std::string> names;
    for (const auto& r : restypes) {
        names.push_back(restype_1to3.at(r));
    }
    names.push_back(unk_restype);
    return names;
}();

const std::map<std::string, int> resname_to_idx = []() {
    std::map<std::string, int> map;
    for (size_t i = 0; i < resnames.size(); i++) {
        map[resnames[i]] = i;
    }
    return map;
}();

}
