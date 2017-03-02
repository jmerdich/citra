// Copyright 2014 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

#include <chrono>
#include <cstdarg>
#include <string>
#include <utility>
#include "common/logging/log.h"

namespace Log {

class Filter;

/**
 * A log entry. Log entries are store in a structured format to permit more varied output
 * formatting on different frontends, as well as facilitating filtering and aggregation.
 */
struct Entry {
    std::chrono::microseconds timestamp;
    Class log_class;
    Level log_level;
    std::string location;
    std::string message;
    size_t count;

    Entry() = default;
    Entry(Entry&& o) = default;

    Entry& operator=(Entry&& o) = default;
};

inline bool operator==(const Entry& lhs, const Entry& rhs) {
    return (lhs.log_class == rhs.log_class) && (lhs.log_level == rhs.log_level) &&
           (lhs.location == rhs.location) && (lhs.message == rhs.message);
}

/**
 * Returns the name of the passed log class as a C-string. Subclasses are separated by periods
 * instead of underscores as in the enumeration.
 */
const char* GetLogClassName(Class log_class);

/**
 * Returns the name of the passed log level as a C-string.
 */
const char* GetLevelName(Level log_level);

/// Creates a log entry by formatting the given source location, and message.
Entry CreateEntry(Class log_class, Level log_level, const char* filename, unsigned int line_nr,
                  const char* function, const char* format, va_list args);

void SetFilter(Filter* filter);
}
