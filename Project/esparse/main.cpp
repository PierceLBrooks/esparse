
// Author: Pierce Brooks

#include <iostream>
#include "Plugin.h"

#define SKYRIM_PLUGIN "Skyrim.esm"

using namespace libespm;

class Skyrim : public Plugin
{
    public:
        inline Skyrim(GameId gameId) : Plugin(gameId)
        {
            std::cout << "Hello, world!" << std::endl;
        }
        inline const Record& getHeaderRecord()
        {
            return headerRecord;
        }
};

int main()
{
    int index = 0;
    Skyrim plugin(GameId::SKYRIM);
    plugin.load(SKYRIM_PLUGIN);
    std::cout << plugin.getFormIds().size() << std::endl;
    for (const auto& subrecord : plugin.getHeaderRecord().getSubrecords())
    {
        std::cout << subrecord.getType() << std::endl;
    }
    for (std::set<FormId>::const_iterator iter = plugin.getFormIds().begin(); iter != plugin.getFormIds().end(); iter++)
    {
        if (iter->getPluginName() != SKYRIM_PLUGIN)
        {
            std::cout << iter->getPluginName() << "@" << index << std::endl;
        }
        ++index;
    }
    return 0;
}
