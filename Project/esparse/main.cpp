
// Author: Pierce Brooks

#include <iostream>
#include "Plugin.h"

using namespace libespm;

int main()
{
    std::cout << "Hello, world!" << std::endl;
    Plugin plugin(GameId::SKYRIM);
    plugin.load("Skyrim.esm");
    return 0;
}
