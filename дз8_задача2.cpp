#include <iostream>
#include <curl/curl.h>
#include <regex>



size_t write_callback(char* ptr, size_t size, size_t nmemb, void* userdata) {
    std::string* data = reinterpret_cast<std::string*>(userdata);
    size_t real_size = size * nmemb;
    data->append(ptr, real_size);
    return real_size;
}

int main() {
    CURL* curl = curl_easy_init();
    if (!curl) {
        std::cerr << "Ошибка инициализации библиотеки libcurl." << std::endl;
        return 1;
    }

    std::string url = "https://get-albums.ru/";
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

    std::string response;
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    CURLcode res = curl_easy_perform(curl);

    if (res != CURLE_OK) {
        std::cerr << "Ошибка выполнения запроса: " << curl_easy_strerror(res) << std::endl;
        curl_easy_cleanup(curl);
        return 1;
    }

    
    std::regex country_regex("<span class=\"country\">(.*?)</span>");
    std::smatch match;

    std::cout << "Список исполнителей на сайте " << url << ":" << std::endl;
    while (std::regex_search(response, match, artists_regex)) {
        std::cout << "- " << match[1].str() << std::endl;
        response = match.suffix().str();
    }

    std::cout << "Страна на сайте " << url << ": ";
    if (std::regex_search(response, match, country_regex)) {
        std::cout << match[1].str() << std::endl;
    }
    else {
        std::cout << "не найдена" << std::endl;
    }

    curl_easy_cleanup(curl);
    return 0;
}
