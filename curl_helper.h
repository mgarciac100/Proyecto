#ifndef CURL_HELPER_H
#define CURL_HELPER_H

#include <string>

class CurlHelper {
public:
    static std::string translate(const std::string& q, const std::string& source, const std::string& target);
};

#endif // CURL_HELPER_H
