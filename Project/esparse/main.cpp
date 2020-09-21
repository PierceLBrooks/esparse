
// Author: Pierce Brooks

#include <set>
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
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
    std::set<uint32_t> all;
    std::map<uint32_t, std::map<std::string, std::vector<uint32_t>>> net;
    std::map<uint32_t, std::pair<const Record*, std::string>> records;
    std::map<std::string, std::vector<std::pair<const Record*, std::string>>> clusters;
    std::map<std::string, std::vector<std::string>> skyrim;
    std::map<std::string, std::vector<std::string>> oblivion;
    std::map<std::string, std::vector<std::string>>* subrecords;
    std::ofstream output;
    std::string type;
    GameId gameId = getPluginType(name);
    ElderScrolls plugin(gameId);
    plugin.load(name);
    std::cout << plugin.getName() << std::endl;
    std::cout << plugin.getHeaderRecord().getType() << std::endl;
    std::cout << plugin.getFormIds().size() << std::endl;
    subrecords = &oblivion;
    (*subrecords)["ACHR"] = std::vector<std::string>();
    (*subrecords)["ACHR"].push_back("NAME");
    (*subrecords)["ACHR"].push_back("XHRS");
    (*subrecords)["ACHR"].push_back("XMRC");
    (*subrecords)["ACRE"] = std::vector<std::string>();
    (*subrecords)["ACRE"].push_back("NAME");
    (*subrecords)["ACRE"].push_back("XOWN");
    (*subrecords)["ACRE"].push_back("XRNK");
    (*subrecords)["ACTI"] = std::vector<std::string>();
    (*subrecords)["ACTI"].push_back("SCRI");
    (*subrecords)["ACTI"].push_back("SNAM");
    (*subrecords)["ALCH"] = std::vector<std::string>();
    (*subrecords)["ALCH"].push_back("SCRI");
    (*subrecords)["AMMO"] = std::vector<std::string>();
    (*subrecords)["AMMO"].push_back("ENAM");
    (*subrecords)["ANIO"] = std::vector<std::string>();
    (*subrecords)["ANIO"].push_back("DATA");
    (*subrecords)["APPA"] = std::vector<std::string>();
    (*subrecords)["APPA"].push_back("SCRI");
    (*subrecords)["ARMO"] = std::vector<std::string>();
    (*subrecords)["ARMO"].push_back("SCRI");
    (*subrecords)["ARMO"].push_back("ENAM");
    (*subrecords)["BOOK"] = std::vector<std::string>();
    (*subrecords)["BOOK"].push_back("SCRI");
    (*subrecords)["BOOK"].push_back("ENAM");
    (*subrecords)["BSGN"] = std::vector<std::string>();
    (*subrecords)["BSGN"].push_back("SPLO");
    (*subrecords)["CELL"] = std::vector<std::string>();
    (*subrecords)["CELL"].push_back("XOWN");
    (*subrecords)["CELL"].push_back("XGLB");
    (*subrecords)["CELL"].push_back("XCCM");
    (*subrecords)["CELL"].push_back("XCWT");
    (*subrecords)["CELL"].push_back("XCLR");
    (*subrecords)["CLOT"] = std::vector<std::string>();
    (*subrecords)["CLOT"].push_back("SCRI");
    (*subrecords)["CLOT"].push_back("ENAM");
    (*subrecords)["CONT"] = std::vector<std::string>();
    (*subrecords)["CONT"].push_back("SNAM");
    (*subrecords)["CONT"].push_back("QNAM");
    (*subrecords)["CONT"].push_back("SCRI");
    (*subrecords)["CONT"].push_back("CNTO");
    (*subrecords)["CREA"] = std::vector<std::string>();
    (*subrecords)["CREA"].push_back("SNAM");
    (*subrecords)["CREA"].push_back("INAM");
    (*subrecords)["CREA"].push_back("SPLO");
    (*subrecords)["CREA"].push_back("SCRI");
    (*subrecords)["CREA"].push_back("CNTO");
    (*subrecords)["CREA"].push_back("PKID");
    (*subrecords)["CREA"].push_back("ZNAM");
    (*subrecords)["CREA"].push_back("CSCR");
    (*subrecords)["CREA"].push_back("CSDI");
    /*(*subrecords)["DIAL"] = std::vector<std::string>();
    (*subrecords)["DIAL"].push_back("QSTI");
    (*subrecords)["DIAL"].push_back("QSTR");*/
    (*subrecords)["DOOR"] = std::vector<std::string>();
    (*subrecords)["DOOR"].push_back("SCRI");
    (*subrecords)["DOOR"].push_back("SNAM");
    (*subrecords)["DOOR"].push_back("ANAM");
    (*subrecords)["DOOR"].push_back("BNAM");
    (*subrecords)["DOOR"].push_back("TNAM");
    (*subrecords)["ENCH"] = std::vector<std::string>();
    (*subrecords)["ENCH"].push_back("SCIT");
    (*subrecords)["FLOR"] = std::vector<std::string>();
    (*subrecords)["FLOR"].push_back("SCRI");
    (*subrecords)["FLOR"].push_back("PFIG");
    (*subrecords)["FURN"] = std::vector<std::string>();
    (*subrecords)["FURN"].push_back("SCRI");
    (*subrecords)["INFO"] = std::vector<std::string>();
    (*subrecords)["INFO"].push_back("QSTI");
    (*subrecords)["INFO"].push_back("PNAM");
    (*subrecords)["INFO"].push_back("TCLT");
    (*subrecords)["INFO"].push_back("NAME");
    (*subrecords)["INFO"].push_back("SCRO");
    (*subrecords)["INGR"] = std::vector<std::string>();
    (*subrecords)["INGR"].push_back("SCRI");
    (*subrecords)["KEYM"] = std::vector<std::string>();
    (*subrecords)["KEYM"].push_back("SCRI");
    (*subrecords)["LIGH"] = std::vector<std::string>();
    (*subrecords)["LIGH"].push_back("SCRI");
    (*subrecords)["LIGH"].push_back("SNAM");
    (*subrecords)["LTEX"] = std::vector<std::string>();
    (*subrecords)["LTEX"].push_back("GNAM");
    (*subrecords)["LVLC"] = std::vector<std::string>();
    (*subrecords)["LVLC"].push_back("SCRI");
    (*subrecords)["LVLC"].push_back("TNAM");
    (*subrecords)["MISC"] = std::vector<std::string>();
    (*subrecords)["MISC"].push_back("SCRI");
    (*subrecords)["NPC_"] = std::vector<std::string>();
    (*subrecords)["NPC_"].push_back("SNAM");
    (*subrecords)["NPC_"].push_back("INAM");
    (*subrecords)["NPC_"].push_back("RNAM");
    (*subrecords)["NPC_"].push_back("SPLO");
    (*subrecords)["NPC_"].push_back("SCRI");
    (*subrecords)["NPC_"].push_back("CNTO");
    (*subrecords)["NPC_"].push_back("PKID");
    (*subrecords)["NPC_"].push_back("CNAM");
    (*subrecords)["NPC_"].push_back("HNAM");
    (*subrecords)["NPC_"].push_back("ENAM");
    (*subrecords)["NPC_"].push_back("ZNAM");
    (*subrecords)["QUST"] = std::vector<std::string>();
    (*subrecords)["QUST"].push_back("SCRI");
    (*subrecords)["QUST"].push_back("SCRO");
    (*subrecords)["REFR"] = std::vector<std::string>();
    (*subrecords)["REFR"].push_back("XOWN");
    (*subrecords)["REFR"].push_back("XGLB");
    (*subrecords)["REFR"].push_back("XTRG");
    (*subrecords)["REFR"].push_back("XRTM");
    (*subrecords)["SGST"] = std::vector<std::string>();
    (*subrecords)["SGST"].push_back("SCRI");
    (*subrecords)["SLGM"] = std::vector<std::string>();
    (*subrecords)["SLGM"].push_back("SCRI");
    (*subrecords)["WEAP"] = std::vector<std::string>();
    (*subrecords)["WEAP"].push_back("SCRI");
    (*subrecords)["WEAP"].push_back("ENAM");
    (*subrecords)["WRLD"] = std::vector<std::string>();
    (*subrecords)["WRLD"].push_back("WNAM");
    (*subrecords)["WRLD"].push_back("CNAM");
    (*subrecords)["WRLD"].push_back("NAM2");
    (*subrecords)["WTHR"] = std::vector<std::string>();
    (*subrecords)["WTHR"].push_back("SNAM");
    subrecords = &skyrim;
    subrecords = nullptr;
    switch (gameId)
    {
        case GameId::OBLIVION:
            type = "OBLIVION";
            subrecords = &oblivion;
            break;
        case GameId::SKYRIM:
            type = "SKYRIM";
            subrecords = &skyrim;
            break;
        default:
            subrecords = nullptr;
            break;
    }
    if (subrecords == nullptr)
    {
        return -1;
    }
    output.open(name+".dot");
    output << std::endl << "digraph " << type << " {" << std::endl;
    index = 0;
    for (std::vector<Record>::const_iterator i = plugin.getRecords().begin(); i != plugin.getRecords().end(); i++)
    {
        clusters[i->getType()] = std::vector<std::pair<const Record*, std::string>>();
        for (std::vector<Subrecord>::const_iterator j = i->getSubrecords().begin(); j != i->getSubrecords().end(); j++)
        {
            if (j->getType() == "EDID")
            {
                net[i->getFormId()] = std::map<std::string, std::vector<uint32_t>>();
                records[i->getFormId()] = std::pair<const Record*, std::string>(&(*i), std::string(j->getRawData().first.get()));
                //std::cout << i->getFormId() << " -> " << std::string(j->getRawData().first.get()) << std::endl;
                break;
            }
        }
    }
    for (std::map<uint32_t, std::pair<const Record*, std::string>>::const_iterator i = records.begin(); i != records.end(); i++)
    {
        std::map<std::string, std::vector<std::string>>::iterator iter;
        for (iter = subrecords->begin(); iter != subrecords->end(); iter++)
        {
            for (int idx = 0; idx < iter->second.size(); idx++)
            {
                net[i->first][iter->second[idx]] = std::vector<uint32_t>();
            }
        }
        iter = subrecords->find(i->second.first->getType());
        if (iter != subrecords->end())
        {
            clusters[i->second.first->getType()].push_back(std::pair<const Record*, std::string>(i->second.first, i->second.second));
            for (std::vector<Subrecord>::const_iterator j = i->second.first->getSubrecords().begin(); j != i->second.first->getSubrecords().end(); j++)
            {
                for (int idx = 0; idx < iter->second.size(); idx++)
                {
                    if (j->getType() == iter->second[idx])
                    {
                        uint32_t formId;
                        std::map<uint32_t, std::pair<const Record*, std::string>>::iterator temp;
                        memcpy(&formId, j->getRawData().first.get(), sizeof(uint32_t));
                        temp = records.find(formId);
                        //std::cout << i->first << " -> " << formId << std::endl;
                        if (temp != records.end())
                        {
                            net[i->first][j->getType()].push_back(formId);
                            //std::cout << i->second.second << " -> " << temp->second.second << std::endl;
                        }
                        break;
                    }
                }
            }
        }
    }
    for (std::map<std::string, std::vector<std::pair<const Record*, std::string>>>::iterator iter = clusters.begin(); iter != clusters.end(); iter++)
    {
        if (!iter->second.empty())
        {
            output << "\tsubgraph cluster_" << index << " {" << std::endl << "\t\tlabel = \"" << iter->first << "\";" << std::endl;
            for (int idx = 0; idx < iter->second.size(); idx++)
            {
                all.insert(iter->second[idx].first->getFormId());
                output << "\t\tnode_" << iter->second[idx].first->getFormId() << " [label=\"" << iter->second[idx].second << "\"];" << std::endl;
            }
            output << "\t}" << std::endl;
            ++index;
        }
    }
    for (std::map<uint32_t, std::map<std::string, std::vector<uint32_t>>>::iterator i = net.begin(); i != net.end(); i++)
    {
        for (std::map<std::string, std::vector<uint32_t>>::iterator j = i->second.begin(); j != i->second.end(); j++)
        {
            if (j->second.size() < 20)
            {
                for (int idx = 0; idx < j->second.size(); idx++)
                {
                    if (all.find(j->second[idx]) != all.end())
                    {
                        output << "\tnode_" << i->first << " -> node_" << j->second[idx] << " [label=\"" << j->first << "\"];" << std::endl;
                    }
                }
            }
        }
    }
    output << "}" << std::endl;
    output.close();
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
