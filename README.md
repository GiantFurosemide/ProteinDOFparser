# ProteinDOFparser
/* A Practice Project */
A tool to manipulate DOF of protein for structural analysis and generation.

## Rosetta philosophy

A simple abstract on how Rosetta works is that the molecular system to be modeled has a certain number of degrees of freedom (DOFs), such as phi/psi/chi in protein folding, rigid-body translation/rotation in docking and amino acid sequence in design. Together with other fixed parameters by default assumption, these DOFs are translated into actual xyz positions of atoms in Cartesian space, via processes such as "refold" and [&#34;pack_rotamers&#34;](https://docs.rosettacommons.org/docs/latest/rosetta_basics/structural_concepts/Rosetta-overview#packer). Afterwards, a physically-based energy function is used to evaluate the energy state of the current system based on these atom positions. The "DOF-XYZ-Energy" regime is coupled with algorithms such as Monte Carlo Minimization to sample the conformational space defined by those DOFs in order to locate the conformation with the lowest-energy state, which presumably should be close to the native state of the system.

For a detailed description of how Rosetta works, please see [Leaver-Fay et al. 2011, Methods in Enzymology 487:545-74](http://www.ncbi.nlm.nih.gov/pubmed/21187238).
