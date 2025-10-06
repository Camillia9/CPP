#include "Harl.hpp"

int getLogLevel(const std::string& level) {
    if (level == "DEBUG") return 0;
    if (level == "INFO") return 1;
    if (level == "WARNING") return 2;
    if (level == "ERROR") return 3;
    return -1;
}

int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << "Usage: " << av[0] << " <log_level>" << std::endl;
        std::cout << "Levels: DEBUG, INFO, WARNING, ERROR" << std::endl;
        return 1;
    }
    Harl harl;
    std::string level = av[1];
    int levelNum = getLogLevel(level);
    
    switch (levelNum) {
        case 0:
            harl.complain("DEBUG");
        case 1:
            harl.complain("INFO");
        case 2:
            harl.complain("WARNING");
        case 3:
            harl.complain("ERROR");
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
    return 0;
}