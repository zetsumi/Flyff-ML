#include <iostream>
#include <ctime>

#include <framework_fengine.h>
#include <property/prop_item.hpp>
#include <property/property_manager.hpp>
#include <project/project_manager.hpp>
#include <util/log.hpp>


static fe::PropItem* createPropItem()
{
    fe::PropItem* propItem = new fe::PropItem();
    propItem->id = std::rand() % 1000 + 1;
    propItem->name.assign("weapon");
    return propItem;
}

void propitem_without_project()
{
    fe::PropertyManager managerItems;


    std::vector<uint64_t> listIdItems;
    for (uint64_t i = 0; i < 10; ++i)
    {
        auto p = createPropItem();
        managerItems.push(p->id, p);
        listIdItems.push_back(p->id);
    }

    for (auto id : listIdItems)
    {
        fe::PropItem* p = dynamic_cast<fe::PropItem*>(managerItems.get(id));
        if (p != nullptr)
            std::cout << "p : " << p->id << " " << p->name << std::endl;
        else
            std::cerr << "item " << id << " not found" << std::endl;

        fe::PropItem* p2 = managerItems.get<fe::PropItem*>(id);
        if (p2 != nullptr)
            std::cout << "p2 : " << p2->id << " " << p2->name << std::endl;
        else
            std::cerr << "item " << id << " not found" << std::endl;
    }
}


bool    propitem_load_from_file(fe::LOADER_MODE mode)
{
    fe::ProjectManager project;

    if (project.loadHeader("../../ressource/json/header/header_attribute.json", fe::LOADER_MODE::JSON) == false)
        return false;
    if (project.loadHeader("../../ressource/json/header/header_define.json", fe::LOADER_MODE::JSON) == false)
        return false;
    if (project.loadHeader("../../ressource/json/header/header_item.json", fe::LOADER_MODE::JSON) == false)
        return false;
    if (project.loadHeader("../../ressource/json/header/header_itemkind.json", fe::LOADER_MODE::JSON) == false)
        return false;
    if (project.loadHeader("../../ressource/json/header/header_job.json", fe::LOADER_MODE::JSON) == false)
        return false;
    if (project.loadHeader("../../ressource/json/header/header_neuz.json", fe::LOADER_MODE::JSON) == false)
        return false;
    if (project.loadHeader("../../ressource/json/header/header_obj.json", fe::LOADER_MODE::JSON) == false)
        return false;
    if (project.loadHeader("../../ressource/json/header/header_sound.json", fe::LOADER_MODE::JSON) == false)
        return false;
    if (project.loadHeader("../../ressource/json/header/header_skill.json", fe::LOADER_MODE::JSON) == false)
        return false;
    if (project.loadHeader("../../ressource/json/header/header_world.json", fe::LOADER_MODE::JSON) == false)
        return false;

    FE_CONSOLELOG("CHS_DARK : %s", project.getHeader().get("CHS_DARK"));
    FE_CONSOLELOG("JOB_ALL : %s", project.getHeader().get("JOB_ALL"));
    FE_CONSOLELOG("DEFINE_UNKNOW : %s", project.getHeader().get("DEFINE_UNKNOW"));
    FE_CONSOLELOG("DST_ADJDEF : %s", project.getHeader().get("DST_ADJDEF"));

    std::string extension;
    switch (mode)
    {
        case fe::LOADER_MODE::JSON:
            extension = "json";
            break;
        case fe::LOADER_MODE::XML:
            extension = "xml";
            break;
        case fe::LOADER_MODE::CSV:
            extension = "csv";
            break;
        default:
            break;
    }

    if (project.loadPropItem("../../ressource/"+extension+"/prop/propItem."+extension, mode) == false)
        return false;
    return true;
}