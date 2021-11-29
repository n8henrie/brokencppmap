#pragma once

class Configuration
{
    struct ConfigImpl;
    ConfigImpl *impl;
    public:
        Configuration();
        ~Configuration();
        void set_composed();
        void print_composed();
};
