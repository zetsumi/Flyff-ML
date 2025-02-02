#pragma once

#include <framework_fengine.h>


namespace fe
{
    /**
     * @brief Enumeration des éléments d'une arme
     * 
     */
    enum class PROP_ITEM_ELEMENT : uint64_t
    {
        NO_PROP = 0,
        FIRE,
        WATER,
        ELECTRICITY,
        WIND,
        EARTH,
        END_PROP
    };

    /**
     * @brief Objet Interface permettant de creer différents type de propriétés
     * Une propriété peut etre definie par un fichier de configuration ou structure de donnée spécifique a Flyff
     */
    struct API_DECLSPEC PropertyContainer
    {
        PropertyContainer() = default;
        PropertyContainer(const PropertyContainer&) = default;
        PropertyContainer(PropertyContainer&&) noexcept = default;
        PropertyContainer& operator=(const PropertyContainer&) = default;
        PropertyContainer& operator=(PropertyContainer&&) = default;
        PropertyContainer(const PropertyContainer* o) : PropertyContainer(*o) {}
        virtual ~PropertyContainer() = default;
    };
}
