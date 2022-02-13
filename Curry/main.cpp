#include <iostream>
#include <optional>
#include <variant>

std::optional<std::string> open(const std::string &path) {
    if (path.empty())
        return {};
    return std::string{"OK"};
}

int main() {
    if (open("url").has_value()) {
        std::cout << "OK" << std::endl;
    }
    std::variant<int, std::string> variant;
    variant = 1024;
    variant = "11";
    std::cout << variant.index();
    try {
        std::cout << std::get<0>(variant) << std::endl;
//    std::cout << std::get<std::string>(variant) << std::endl;
    }catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
