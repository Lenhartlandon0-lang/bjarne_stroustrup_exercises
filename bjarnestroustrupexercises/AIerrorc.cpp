//
//  AIerrorc.cpp
//  bjarnestroustrupexercises
//
//  AI-generated to provide an example of error handling which I don't really understand as of 8/19/2026
//

#include <iostream>
#include <system_error>

// 1. Define custom error codes
enum class HttpError {
    Success = 0,
    BadRequest = 400,
    NotFound = 404
};

// 2. Map your enum to the std::is_error_code_enum trait
namespace std {
    template <>
    struct is_error_code_enum<HttpError> : true_type {};
}

// 3. Create a custom category class
class HttpCategory : public std::error_category {
public:
    const char* name() const noexcept override { return "HttpErrorCategory"; }
    std::string message(int ev) const override {
        switch (static_cast<HttpError>(ev)) {
            case HttpError::Success: return "HTTP 200 OK";
            case HttpError::BadRequest: return "HTTP 400 Bad Request";
            case HttpError::NotFound: return "HTTP 404 Not Found";
            default: return "Unknown HTTP Error";
        }
    }
};

// 4. Expose the global category instance and overload make_error_code
const HttpCategory http_category_instance;

std::error_code make_error_code(HttpError e) {
    return {static_cast<int>(e), http_category_instance};
}

int main() {
    // Explicit conversion via overloaded make_error_code
    std::error_code ec = HttpError::NotFound;
    
    std::cout << ec.message() << " (Code: " << ec.value() << ")\n";
}
