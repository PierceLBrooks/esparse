
// Author: Pierce Brooks

#include <set>
#include <string>
#include <iostream>
#include "Plugin.h"

using namespace libespm;

class ElderScrolls : public Plugin
{
    public:
        inline ElderScrolls(GameId gameId) : Plugin(gameId)
        {
            std::cout << "Hello, world!" << std::endl;
        }
        inline const Record& getHeaderRecord()
        {
            return headerRecord;
        }
};

GameId getPluginType(const std::string& name)
{
    if (name == "Skyrim.esm")
    {
        return GameId::SKYRIM;
    }
    if (name == "Oblivion.esm")
    {
        return GameId::OBLIVION;
    }
    return GameId::MORROWIND;
}

int run(const std::string& name)
{
    int index;
    std::vector<std::string> names;
    std::string type = "";
    ElderScrolls plugin(getPluginType(name));
    plugin.load(name);
    std::cout << plugin.getName() << std::endl;
    std::cout << plugin.getHeaderRecord().getType() << std::endl;
    std::cout << plugin.getFormIds().size() << std::endl;
    /*for (const auto& subrecord : plugin.getHeaderRecord().getSubrecords())
    {
        std::cout << subrecord.getType() << std::endl;
    }*/
    index = 0;
    /*for (std::set<FormId>::const_iterator i = plugin.getFormIds().begin(); i != plugin.getFormIds().end(); i++)
    {
        if (i->getPluginName() != name)
        {
            std::cout << i->getPluginName() << " @ " << index << std::endl;
        }
        ++index;
    }*/
    index = 0;
    for (std::vector<Record>::const_iterator i = plugin.getRecords().begin(); i != plugin.getRecords().end(); i++)
    {
        if ((type.empty()) || (type != i->getType()))
        {
            type = i->getType();
            //std::cout << type << " @ " << index << std::endl;
            type = "";
            for (std::vector<Subrecord>::const_iterator j = i->getSubrecords().begin(); j != i->getSubrecords().end(); j++)
            {
                if ((type.empty()) || (type != j->getType()))
                {
                    type = j->getType();
                    //std::cout << "\t" << type << std::endl;
                    if (type == "EDID")
                    {
                        //names.push_back(Plugin::convertToUtf8(std::string(j->getRawData().first.get())));
                        names.push_back(std::string(j->getRawData().first.get()));
                        std::cout << names.back() << " @ " << index << " ( " << i->getType() << " ) " << std::endl;
                    }
                }
            }
            type = i->getType();
        }
        ++index;
    }
    return 0;
}

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        return run("Skyrim.esm");
    }
    std::string name = std::string(argv[1]);
    return run(name);
}
