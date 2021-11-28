#include <map>
#include <string>

class Configuration : public std::map <std::string, std::string>
{
    public:
        void set_composed();
        void print_composed();
        void set_inherited();
        void print_inherited();
        std::map<std::string, std::string> submap;
};
