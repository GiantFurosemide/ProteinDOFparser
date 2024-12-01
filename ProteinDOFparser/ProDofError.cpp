#include "ProDofError.h"
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>

ProDofError::ProDofError(const std::string& message) {
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << "[" << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S") << "] " << message;
    this->message = ss.str();
}