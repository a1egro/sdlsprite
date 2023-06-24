//
// Created by alex on 25.01.22.
//

#ifndef TANO_CREATETEXTUREERROR_H
#define TANO_CREATETEXTUREERROR_H


#include <system_error>
#include <string>

class CreateTextureError : public std::runtime_error {
    std::string path, reason;
 public:
    explicit CreateTextureError(const std::string &path, const std::string &reason = "")
            : std::runtime_error("Unable to create texture from " + path + ". Reason: " + reason), path(path),
              reason(reason) { }

    [[nodiscard]] std::string getPath() const { return path; }

    [[nodiscard]] std::string getReason() const { return reason; }
};


#endif //TANO_CREATETEXTUREERROR_H
