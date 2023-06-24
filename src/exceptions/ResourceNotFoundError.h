//
// Created by alex on 25.01.22.
//

#ifndef TANO_RESOURCENOTFOUNDERROR_H
#define TANO_RESOURCENOTFOUNDERROR_H


#include <system_error>
#include <string>

class ResourceNotFoundError : public std::runtime_error {
    std::string path, reason;
 public:
    explicit ResourceNotFoundError(const std::string &path, const std::string &reason = "")
            : std::runtime_error("Could not load " + path + ". Reason: " + reason), path(path), reason(reason) { }

    [[nodiscard]] std::string getPath() const { return path; }

    [[nodiscard]] std::string getReason() const { return reason; }
};


#endif //TANO_RESOURCENOTFOUNDERROR_H
