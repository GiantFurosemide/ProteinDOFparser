#ifndef PRODofError_H
#define PRODofError_H

#include "ProteinDOFparser_common.h"

// define macro for error handling
#define PRODofError_EXIT_FAILURE 1
#define PRODofError_EXIT_SUCCESS 0



class ProDofError: public std::exception {
public:
    std::string message;
    ProDofError(const std::string& message);
    const char* what() const noexcept override;
};
#endif

