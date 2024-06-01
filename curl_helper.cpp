#include "curl_helper.h"
#include <iostream>
#include <curl/curl.h>
#include "json.hpp"

using json = nlohmann::json;

size_t writeCallback(char* ptr, size_t size, size_t nmemb, std::string* data) {
    data->append(ptr, size * nmemb);
    return size * nmemb;
}

std::string CurlHelper::translate(const std::string& q, const std::string& source, const std::string& target) {
    CURL *curl;
    CURLcode res;
    std::string translation;
    std::string response;

    curl = curl_easy_init();
    if(curl) {
        std::string url = "http://localhost:5000/translate?q=" + q + "&source=" + source + "&target=" + target + "&format=text&api_key=xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx";
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");

        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Cookie: session=c6abf654-c3f9-4133-a846-10f498841e53");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);
        if(res == CURLE_OK) {
            // Parsear la respuesta JSON
            try {
                json jsonResponse = json::parse(response);
                if (jsonResponse.contains("translatedText")) {
                    translation = jsonResponse["translatedText"].get<std::string>();
                }
            } catch (const std::exception& e) {
                std::cerr << "Error parsing JSON response: " << e.what() << std::endl;
            }
        } else {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }

        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }

    return translation;
}
