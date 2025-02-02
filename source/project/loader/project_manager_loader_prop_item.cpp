#include <pch_fressource.h>
#include <project/project_manager.hpp>
#include <io/file/reader_json.hpp>
#include <io/file/reader_xml.hpp>
#include <property/prop_item.hpp>


bool    fe::ProjectManager::loadPropItem(const std::string& fileName, LOADER_MODE mode) noexcept
{
    if (fileName.empty())
        return false;

    switch (mode)
    {
        case fe::LOADER_MODE::JSON:
            loadPropItemJson(fileName);
            break;
        case fe::LOADER_MODE::XML:
            loadPropItemXml(fileName);
            break;
        default:
            return false;
    }
    return true;
}

bool fe::ProjectManager::loadPropItemJson(const std::string& fileName) noexcept
{
    ReaderJson  reader;
    reader.header = getHeader();

    if (reader.load(fileName) == false)
        return false;
    fe::type::json::object& datas = reader.get<fe::type::json::object>(reader.root);
    for (auto& it : datas)
    {
        fe::type::json::object& item = reader.get<fe::type::json::object>(it.second);
        fe::PropItem* prop = new fe::PropItem();

        prop->version = reader.getNumber<uint64_t, fe::type::json::value>(item["version"]);
        prop->id = reader.getNumber<uint64_t, fe::type::json::value>(item["dwID"]);
        prop->name = reader.get<std::string>(item["szName"]);
        prop->num = reader.getNumber<uint64_t, fe::type::json::value>(item["dwNum"]);
        prop->packMax = reader.getNumber<uint64_t, fe::type::json::value>(item["dwPackMax"]);
        prop->itemKind1 = reader.getNumber<uint64_t, fe::type::json::value>(item["dwItemKind1"]);
        prop->itemKind2 = reader.getNumber<uint64_t, fe::type::json::value>(item["dwItemKind2"]);
        prop->itemKind3 = reader.getNumber<uint64_t, fe::type::json::value>(item["dwItemKind3"]);
        prop->itemJob = reader.getNumber<uint64_t, fe::type::json::value>(item["dwItemJob"]);
        prop->permanence = reader.getBoolean(item["bPermanence"]);
        prop->useable = reader.getNumber<uint64_t, fe::type::json::value>(item["dwUseable"]);
        prop->itemSex = reader.getNumber<uint64_t, fe::type::json::value>(item["dwItemSex"]);
        prop->cost = reader.getNumber<uint64_t, fe::type::json::value>(item["dwCost"]);
        prop->endurance = reader.getNumber<uint64_t, fe::type::json::value>(item["dwEndurance"]);
        prop->abrasion = reader.getNumber<int64_t, fe::type::json::value>(item["nAbrasion"]);
        prop->maxRepair = reader.getNumber<int64_t, fe::type::json::value>(item["nMaxRepair"]);
        prop->handed = reader.getNumber<uint64_t, fe::type::json::value>(item["dwHanded"]);
        prop->flag = reader.getNumber<uint64_t, fe::type::json::value>(item["dwFlag"]);
        prop->parts = reader.getNumber<uint64_t, fe::type::json::value>(item["dwParts"]);
        prop->partsub = reader.getNumber<uint64_t, fe::type::json::value>(item["dwPartsub"]);
        prop->partFile = reader.getBoolean(item["bPartFile"]);
        prop->exclusive = reader.getNumber<uint64_t, fe::type::json::value>(item["dwExclusive"]);
        prop->basePartsIgnore = reader.getNumber<uint64_t, fe::type::json::value>(item["dwBasePartsIgnore"]);
        prop->itemLV = reader.getNumber<uint64_t, fe::type::json::value>(item["dwItemLV"]);
        prop->itemRare = reader.getNumber<uint64_t, fe::type::json::value>(item["dwItemRare"]);
        prop->shopAble = reader.getNumber<uint64_t, fe::type::json::value>(item["dwShopAble"]);
        prop->log = reader.getBoolean(item["bLog"]);
        prop->charged = reader.getBoolean(item["bCharged"]);
        prop->linkKindBullet = reader.getNumber<uint64_t, fe::type::json::value>(item["dwLinkKindBullet"]);
        prop->linkKind = reader.getNumber<uint64_t, fe::type::json::value>(item["dwLinkKind"]);
        prop->abilityMin = reader.getNumber<uint64_t, fe::type::json::value>(item["dwAbilityMin"]);
        prop->abilityMax = reader.getNumber<uint64_t, fe::type::json::value>(item["dwAbilityMax"]);
        prop->itemType = static_cast<fe::PROP_ITEM_ELEMENT>(reader.getNumber<uint64_t, fe::type::json::value>(item["eItemType"]));
        prop->itemEAtk = reader.getNumber<short, fe::type::json::value>(item["wItemEAtk"]);
        prop->parry = reader.getNumber<uint64_t, fe::type::json::value>(item["dwParry"]);
        prop->blockRating = reader.getNumber<uint64_t, fe::type::json::value>(item["dwBlockRating"]);
        prop->addSkillMin = reader.getNumber<uint64_t, fe::type::json::value>(item["dwAddSkillMin"]);
        prop->addSkillMax = reader.getNumber<uint64_t, fe::type::json::value>(item["dwAddSkillMax"]);
        prop->atkStyle = reader.getNumber<uint64_t, fe::type::json::value>(item["dwAtkStyle"]);
        prop->weaponType = reader.getNumber<uint64_t, fe::type::json::value>(item["dwWeaponType"]);
        prop->itemAtkOrder1 = reader.getNumber<uint64_t, fe::type::json::value>(item["dwItemAtkOrder1"]);
        prop->itemAtkOrder2 = reader.getNumber<uint64_t, fe::type::json::value>(item["dwItemAtkOrder2"]);
        prop->itemAtkOrder3 = reader.getNumber<uint64_t, fe::type::json::value>(item["dwItemAtkOrder3"]);
        prop->itemAtkOrder4 = reader.getNumber<uint64_t, fe::type::json::value>(item["dwItemAtkOrder4"]);
        prop->continuousPain = reader.getBoolean(item["bContinuousPain"]);
        prop->shellQuantity = reader.getNumber<uint64_t, fe::type::json::value>(item["dwShellQuantity"]);
        prop->recoil = reader.getNumber<uint64_t, fe::type::json::value>(item["dwRecoil"]);
        prop->loadingTime = reader.getNumber<uint64_t, fe::type::json::value>(item["dwLoadingTime"]);
        prop->adjHitRate = reader.getNumber<int64_t, fe::type::json::value>(item["nAdjHitRate"]);
        prop->attackSpeed = reader.getNumber<uint64_t, fe::type::json::value>(item["dwAttackSpeed"]);
        prop->dmgShift = reader.getNumber<uint64_t, fe::type::json::value>(item["dwDmgShift"]);
        prop->attackRange = reader.getNumber<uint64_t, fe::type::json::value>(item["dwAttackRange"]);
        prop->probability = reader.getNumber<uint64_t, fe::type::json::value>(item["dwProbability"]);
        prop->destParam1 = reader.getNumber<uint64_t, fe::type::json::value>(item["dwDestParam1"]);
        prop->destParam2 = reader.getNumber<uint64_t, fe::type::json::value>(item["dwDestParam2"]);
        prop->destParam3 = reader.getNumber<uint64_t, fe::type::json::value>(item["dwDestParam3"]);
        prop->adjParamVal1 = reader.getNumber<int64_t, fe::type::json::value>(item["nAdjParamVal1"]);
        prop->adjParamVal2 = reader.getNumber<int64_t, fe::type::json::value>(item["nAdjParamVal2"]);
        prop->adjParamVal3 = reader.getNumber<int64_t, fe::type::json::value>(item["nAdjParamVal3"]);
        prop->chgParamVal1 = reader.getNumber<uint64_t, fe::type::json::value>(item["dwChgParamVal1"]);
        prop->chgParamVal2 = reader.getNumber<uint64_t, fe::type::json::value>(item["dwChgParamVal2"]);
        prop->chgParamVal3 = reader.getNumber<uint64_t, fe::type::json::value>(item["dwChgParamVal3"]);
        prop->destData1 = reader.getNumber<uint64_t, fe::type::json::value>(item["dwdestData1"]);
        prop->destData2 = reader.getNumber<uint64_t, fe::type::json::value>(item["dwdestData2"]);
        prop->destData3 = reader.getNumber<uint64_t, fe::type::json::value>(item["dwdestData3"]);
        prop->activeskill = reader.getNumber<uint64_t, fe::type::json::value>(item["dwactiveskill"]);
        prop->activeskillLv = reader.getNumber<uint64_t, fe::type::json::value>(item["dwactiveskillLv"]);
        prop->activeskillper = reader.getNumber<uint64_t, fe::type::json::value>(item["dwactiveskillper"]);
        prop->reqMp = reader.getNumber<uint64_t, fe::type::json::value>(item["dwReqMp"]);
        prop->repFp = reader.getNumber<uint64_t, fe::type::json::value>(item["dwRepFp"]);
        prop->reqDisLV = reader.getNumber<uint64_t, fe::type::json::value>(item["dwReqDisLV"]);
        prop->reSkill1 = reader.getNumber<uint64_t, fe::type::json::value>(item["dwReSkill1"]);
        prop->reSkillLevel1 = reader.getNumber<uint64_t, fe::type::json::value>(item["dwReSkillLevel1"]);
        prop->reSkill2 = reader.getNumber<uint64_t, fe::type::json::value>(item["dwReSkill2"]);
        prop->reSkillLevel2 = reader.getNumber<uint64_t, fe::type::json::value>(item["dwReSkillLevel2"]);
        prop->skillReadyType = reader.getNumber<uint64_t, fe::type::json::value>(item["dwSkillReadyType"]);
        prop->skillReady = reader.getNumber<uint64_t, fe::type::json::value>(item["dwSkillReady"]);
        prop->skillRange = reader.getNumber<uint64_t, fe::type::json::value>(item["dwSkillRange"]);
        prop->sfxElemental = reader.getNumber<uint64_t, fe::type::json::value>(item["dwSfxElemental"]);
        prop->sfxObj = reader.getNumber<uint64_t, fe::type::json::value>(item["dwSfxObj"]);
        prop->sfxObj2 = reader.getNumber<uint64_t, fe::type::json::value>(item["dwSfxObj2"]);
        prop->sfxObj3 = reader.getNumber<uint64_t, fe::type::json::value>(item["dwSfxObj3"]);
        prop->sfxObj4 = reader.getNumber<uint64_t, fe::type::json::value>(item["dwSfxObj4"]);
        prop->sfxObj5 = reader.getNumber<uint64_t, fe::type::json::value>(item["dwSfxObj5"]);
        prop->useMotion = reader.getNumber<uint64_t, fe::type::json::value>(item["dwUseMotion"]);
        prop->circleTime = reader.getNumber<uint64_t, fe::type::json::value>(item["dwCircleTime"]);
        prop->skillTime = reader.getNumber<uint64_t, fe::type::json::value>(item["dwSkillTime"]);
        prop->exeTarget = reader.getNumber<uint64_t, fe::type::json::value>(item["dwExeTarget"]);
        prop->useChance = reader.getNumber<uint64_t, fe::type::json::value>(item["dwUseChance"]);
        prop->spellRegion = reader.getNumber<uint64_t, fe::type::json::value>(item["dwSpellRegion"]);
        prop->spellType = reader.getNumber<uint64_t, fe::type::json::value>(item["dwSpellType"]);
        prop->referStat1 = reader.getNumber<uint64_t, fe::type::json::value>(item["dwReferStat1"]);
        prop->referStat2 = reader.getNumber<uint64_t, fe::type::json::value>(item["dwReferStat2"]);
        prop->referTarget1 = reader.getNumber<uint64_t, fe::type::json::value>(item["dwReferTarget1"]);
        prop->referTarget2 = reader.getNumber<uint64_t, fe::type::json::value>(item["dwReferTarget2"]);
        prop->referValue1 = reader.getNumber<uint64_t, fe::type::json::value>(item["dwReferValue1"]);
        prop->referValue2 = reader.getNumber<uint64_t, fe::type::json::value>(item["dwReferValue2"]);
        prop->skillType = reader.getNumber<uint64_t, fe::type::json::value>(item["dwSkillType"]);
        prop->itemResistElecricity = reader.getNumber<float, fe::type::json::value>(item["fItemResistElecricity"]);
        prop->itemResistFire = reader.getNumber<float, fe::type::json::value>(item["fItemResistFire"]);
        prop->itemResistWind = reader.getNumber<float, fe::type::json::value>(item["fItemResistWind"]);
        prop->itemResistWater = reader.getNumber<float, fe::type::json::value>(item["fItemResistWater"]);
        prop->itemResistEarth = reader.getNumber<float, fe::type::json::value>(item["fItemResistEarth"]);
        prop->evildoing = reader.getNumber<int64_t, fe::type::json::value>(item["nEvildoing"]);
        prop->expertLV = reader.getNumber<uint64_t, fe::type::json::value>(item["dwExpertLV"]);
        prop->expertMax = reader.getNumber<uint64_t, fe::type::json::value>(item["ExpertMax"]);
        prop->subDefine = reader.getNumber<uint64_t, fe::type::json::value>(item["dwSubDefine"]);
        prop->exp = reader.getNumber<uint64_t, fe::type::json::value>(item["dwExp"]);
        prop->comboStyle = reader.getNumber<uint64_t, fe::type::json::value>(item["dwComboStyle"]);
        prop->flightSpeed = reader.getNumber<float, fe::type::json::value>(item["fFlightSpeed"]);
        prop->flightLRAngle = reader.getNumber<float, fe::type::json::value>(item["fFlightLRAngle"]);
        prop->flightTBAngle = reader.getNumber<float, fe::type::json::value>(item["fFlightTBAngle"]);
        prop->flightLimit = reader.getNumber<uint64_t, fe::type::json::value>(item["dwFlightLimit"]);
        prop->fFuelReMax = reader.getNumber<uint64_t, fe::type::json::value>(item["dwFFuelReMax"]);
        prop->aFuelReMax = reader.getNumber<uint64_t, fe::type::json::value>(item["dwAFuelReMax"]);
        prop->fuelRe = reader.getNumber<uint64_t, fe::type::json::value>(item["dwFuelRe"]);
        prop->limitLevel1 = reader.getNumber<uint64_t, fe::type::json::value>(item["dwLimitLevel1"]);
        prop->reflect = reader.getNumber<uint64_t, fe::type::json::value>(item["dwReflect"]);
        prop->sndAttack1 = reader.getNumber<uint64_t, fe::type::json::value>(item["dwSndAttack1"]);
        prop->sndAttack2 = reader.getNumber<uint64_t, fe::type::json::value>(item["dwSndAttack2"]);
        prop->icon = reader.get<std::string>(item["szIcon"]);
        prop->questID = reader.getNumber<uint64_t, fe::type::json::value>(item["dwQuestID"]);
        prop->textFile = reader.get<std::string>(item["szTextFile"]);
        prop->comment = reader.get<std::string>(item["szComment"]);

        propitem.push(prop->id, prop);
    }

    return true;
}


bool fe::ProjectManager::loadPropItemXml(const std::string& fileName) noexcept
{
    ReaderXml reader;
    reader.header = getHeader();

    if (reader.load(fileName) == false)
        return false;
    fe::type::xml::node head = reader.document.child("items");
    auto fctLoaderItem = [&](fe::type::xml::node& item)
    {
        fe::PropItem* prop = new fe::PropItem();
        prop->version = reader.getNumber<uint64_t>(item, "version");
        prop->id = reader.getNumber<uint64_t>(item, "dwID");
        prop->name = reader.getString(item, "szName");
        prop->num = reader.getNumber<uint64_t>(item, "dwNum");
        prop->packMax = reader.getNumber<uint64_t>(item, "dwPackMax");
        prop->itemKind1 = reader.getNumber<uint64_t>(item, "dwItemKind1");
        prop->itemKind2 = reader.getNumber<uint64_t>(item, "dwItemKind2");
        prop->itemKind3 = reader.getNumber<uint64_t>(item, "dwItemKind3");
        prop->itemJob = reader.getNumber<uint64_t>(item, "dwItemJob");
        prop->permanence = reader.getBoolean(item, "bPermanence");
        prop->useable = reader.getNumber<uint64_t>(item, "dwUseable");
        prop->itemSex = reader.getNumber<uint64_t>(item, "dwItemSex");
        prop->cost = reader.getNumber<uint64_t>(item, "dwCost");
        prop->endurance = reader.getNumber<uint64_t>(item, "dwEndurance");
        prop->abrasion = reader.getNumber<int64_t>(item, "nAbrasion");
        prop->maxRepair = reader.getNumber<int64_t>(item, "nMaxRepair");
        prop->handed = reader.getNumber<uint64_t>(item, "dwHanded");
        prop->flag = reader.getNumber<uint64_t>(item, "dwFlag");
        prop->parts = reader.getNumber<uint64_t>(item, "dwParts");
        prop->partsub = reader.getNumber<uint64_t>(item, "dwPartsub");
        prop->partFile = reader.getBoolean(item, "bPartFile");
        prop->exclusive = reader.getNumber<uint64_t>(item, "dwExclusive");
        prop->basePartsIgnore = reader.getNumber<uint64_t>(item, "dwBasePartsIgnore");
        prop->itemLV = reader.getNumber<uint64_t>(item, "dwItemLV");
        prop->itemRare = reader.getNumber<uint64_t>(item, "dwItemRare");
        prop->shopAble = reader.getNumber<uint64_t>(item, "dwShopAble");
        prop->log = reader.getBoolean(item, "bLog");
        prop->charged = reader.getBoolean(item, "bCharged");
        prop->linkKindBullet = reader.getNumber<uint64_t>(item, "dwLinkKindBullet");
        prop->linkKind = reader.getNumber<uint64_t>(item, "dwLinkKind");
        prop->abilityMin = reader.getNumber<uint64_t>(item, "dwAbilityMin");
        prop->abilityMax = reader.getNumber<uint64_t>(item, "dwAbilityMax");
        prop->itemType = static_cast<fe::PROP_ITEM_ELEMENT>(reader.getNumber<uint64_t>(item, "eItemType"));
        prop->itemEAtk = reader.getNumber<short>(item, "wItemEAtk");
        prop->parry = reader.getNumber<uint64_t>(item, "dwParry");
        prop->blockRating = reader.getNumber<uint64_t>(item, "dwBlockRating");
        prop->addSkillMin = reader.getNumber<uint64_t>(item, "dwAddSkillMin");
        prop->addSkillMax = reader.getNumber<uint64_t>(item, "dwAddSkillMax");
        prop->atkStyle = reader.getNumber<uint64_t>(item, "dwAtkStyle");
        prop->weaponType = reader.getNumber<uint64_t>(item, "dwWeaponType");
        prop->itemAtkOrder1 = reader.getNumber<uint64_t>(item, "dwItemAtkOrder1");
        prop->itemAtkOrder2 = reader.getNumber<uint64_t>(item, "dwItemAtkOrder2");
        prop->itemAtkOrder3 = reader.getNumber<uint64_t>(item, "dwItemAtkOrder3");
        prop->itemAtkOrder4 = reader.getNumber<uint64_t>(item, "dwItemAtkOrder4");
        prop->continuousPain = reader.getBoolean(item, "bContinuousPain");
        prop->shellQuantity = reader.getNumber<uint64_t>(item, "dwShellQuantity");
        prop->recoil = reader.getNumber<uint64_t>(item, "dwRecoil");
        prop->loadingTime = reader.getNumber<uint64_t>(item, "dwLoadingTime");
        prop->adjHitRate = reader.getNumber<int64_t>(item, "nAdjHitRate");
        prop->attackSpeed = reader.getNumber<uint64_t>(item, "dwAttackSpeed");
        prop->dmgShift = reader.getNumber<uint64_t>(item, "dwDmgShift");
        prop->attackRange = reader.getNumber<uint64_t>(item, "dwAttackRange");
        prop->probability = reader.getNumber<uint64_t>(item, "dwProbability");
        prop->destParam1 = reader.getNumber<uint64_t>(item, "dwDestParam1");
        prop->destParam2 = reader.getNumber<uint64_t>(item, "dwDestParam2");
        prop->destParam3 = reader.getNumber<uint64_t>(item, "dwDestParam3");
        prop->adjParamVal1 = reader.getNumber<int64_t>(item, "nAdjParamVal1");
        prop->adjParamVal2 = reader.getNumber<int64_t>(item, "nAdjParamVal2");
        prop->adjParamVal3 = reader.getNumber<int64_t>(item, "nAdjParamVal3");
        prop->chgParamVal1 = reader.getNumber<uint64_t>(item, "dwChgParamVal1");
        prop->chgParamVal2 = reader.getNumber<uint64_t>(item, "dwChgParamVal2");
        prop->chgParamVal3 = reader.getNumber<uint64_t>(item, "dwChgParamVal3");
        prop->destData1 = reader.getNumber<uint64_t>(item, "dwdestData1");
        prop->destData2 = reader.getNumber<uint64_t>(item, "dwdestData2");
        prop->destData3 = reader.getNumber<uint64_t>(item, "dwdestData3");
        prop->activeskill = reader.getNumber<uint64_t>(item, "dwactiveskill");
        prop->activeskillLv = reader.getNumber<uint64_t>(item, "dwactiveskillLv");
        prop->activeskillper = reader.getNumber<uint64_t>(item, "dwactiveskillper");
        prop->reqMp = reader.getNumber<uint64_t>(item, "dwReqMp");
        prop->repFp = reader.getNumber<uint64_t>(item, "dwRepFp");
        prop->reqDisLV = reader.getNumber<uint64_t>(item, "dwReqDisLV");
        prop->reSkill1 = reader.getNumber<uint64_t>(item, "dwReSkill1");
        prop->reSkillLevel1 = reader.getNumber<uint64_t>(item, "dwReSkillLevel1");
        prop->reSkill2 = reader.getNumber<uint64_t>(item, "dwReSkill2");
        prop->reSkillLevel2 = reader.getNumber<uint64_t>(item, "dwReSkillLevel2");
        prop->skillReadyType = reader.getNumber<uint64_t>(item, "dwSkillReadyType");
        prop->skillReady = reader.getNumber<uint64_t>(item, "dwSkillReady");
        prop->skillRange = reader.getNumber<uint64_t>(item, "dwSkillRange");
        prop->sfxElemental = reader.getNumber<uint64_t>(item, "dwSfxElemental");
        prop->sfxObj = reader.getNumber<uint64_t>(item, "dwSfxObj");
        prop->sfxObj2 = reader.getNumber<uint64_t>(item, "dwSfxObj2");
        prop->sfxObj3 = reader.getNumber<uint64_t>(item, "dwSfxObj3");
        prop->sfxObj4 = reader.getNumber<uint64_t>(item, "dwSfxObj4");
        prop->sfxObj5 = reader.getNumber<uint64_t>(item, "dwSfxObj5");
        prop->useMotion = reader.getNumber<uint64_t>(item, "dwUseMotion");
        prop->circleTime = reader.getNumber<uint64_t>(item, "dwCircleTime");
        prop->skillTime = reader.getNumber<uint64_t>(item, "dwSkillTime");
        prop->exeTarget = reader.getNumber<uint64_t>(item, "dwExeTarget");
        prop->useChance = reader.getNumber<uint64_t>(item, "dwUseChance");
        prop->spellRegion = reader.getNumber<uint64_t>(item, "dwSpellRegion");
        prop->spellType = reader.getNumber<uint64_t>(item, "dwSpellType");
        prop->referStat1 = reader.getNumber<uint64_t>(item, "dwReferStat1");
        prop->referStat2 = reader.getNumber<uint64_t>(item, "dwReferStat2");
        prop->referTarget1 = reader.getNumber<uint64_t>(item, "dwReferTarget1");
        prop->referTarget2 = reader.getNumber<uint64_t>(item, "dwReferTarget2");
        prop->referValue1 = reader.getNumber<uint64_t>(item, "dwReferValue1");
        prop->referValue2 = reader.getNumber<uint64_t>(item, "dwReferValue2");
        prop->skillType = reader.getNumber<uint64_t>(item, "dwSkillType");
        prop->itemResistElecricity = reader.getNumber<float>(item, "fItemResistElecricity");
        prop->itemResistFire = reader.getNumber<float>(item, "fItemResistFire");
        prop->itemResistWind = reader.getNumber<float>(item, "fItemResistWind");
        prop->itemResistWater = reader.getNumber<float>(item, "fItemResistWater");
        prop->itemResistEarth = reader.getNumber<float>(item, "fItemResistEarth");
        prop->evildoing = reader.getNumber<int64_t>(item, "nEvildoing");
        prop->expertLV = reader.getNumber<uint64_t>(item, "dwExpertLV");
        prop->expertMax = reader.getNumber<uint64_t>(item, "ExpertMax");
        prop->subDefine = reader.getNumber<uint64_t>(item, "dwSubDefine");
        prop->exp = reader.getNumber<uint64_t>(item, "dwExp");
        prop->comboStyle = reader.getNumber<uint64_t>(item, "dwComboStyle");
        prop->flightSpeed = reader.getNumber<float>(item, "fFlightSpeed");
        prop->flightLRAngle = reader.getNumber<float>(item, "fFlightLRAngle");
        prop->flightTBAngle = reader.getNumber<float>(item, "fFlightTBAngle");
        prop->flightLimit = reader.getNumber<uint64_t>(item, "dwFlightLimit");
        prop->fFuelReMax = reader.getNumber<uint64_t>(item, "dwFFuelReMax");
        prop->aFuelReMax = reader.getNumber<uint64_t>(item, "dwAFuelReMax");
        prop->fuelRe = reader.getNumber<uint64_t>(item, "dwFuelRe");
        prop->limitLevel1 = reader.getNumber<uint64_t>(item, "dwLimitLevel1");
        prop->reflect = reader.getNumber<uint64_t>(item, "dwReflect");
        prop->sndAttack1 = reader.getNumber<uint64_t>(item, "dwSndAttack1");
        prop->sndAttack2 = reader.getNumber<uint64_t>(item, "dwSndAttack2");
        prop->icon = reader.getString(item, "szIcon");
        prop->questID = reader.getNumber<uint64_t>(item, "dwQuestID");
        prop->textFile = reader.getString(item, "szTextFile");
        prop->comment = reader.getString(item, "szComment");

        propitem.push(prop->id, prop);
    };
    auto fctLooper = [&](fe::type::xml::node& head)
    {
        for (fe::type::xml::node& section : head)
        {
            for (fe::type::xml::node& subSection : section)
            {
                if (std::string(subSection.name()) == "item")
                    fctLoaderItem(subSection);
                else
                {
                    for (fe::type::xml::node& subSubSection : subSection)
                    {
                        if (std::string(subSubSection.name()) == "item")
                            fctLoaderItem(subSubSection);
                        else
                        {
                            for (fe::type::xml::node& subSubSubSection : subSubSection)
                            {
                                if (std::string(subSubSubSection.name()) == "item")
                                    fctLoaderItem(subSubSubSection);
                            }
                        }
                    }
                }
            }
        }
    };
    fctLooper(head);
    return true;
}