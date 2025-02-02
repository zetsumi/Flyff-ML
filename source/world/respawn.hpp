#pragma once

#include <framework_fengine.h>
#include <util/vector.hpp>
#include <util/rect.hpp>


namespace fe
{
    /*
    ** @brief structure representant les respawn d'un monstre dans le monde World
    */
    struct API_DECLSPEC	ReSpawn
    {
        // missing parameters !
        uint32_t type = 0;
        uint32_t id = 0;
        Vector3D<float> pos = {0.f, 0.f, 0.f};
        //self.nMaxcb = int()
        //self.ncb = int(0)
        uint32_t time = 0;
        //self.nMaxAttackNum = int()
        //self.nActiveAttackNum = int(0)
        //self.fY = int(0)
        Rect<float>  rect = { 0.f, 0.f, 0.f, 0.f };
        //self.nDayMin = int()
        //self.nDayMax = int()
        //self.nHourMin = int()
        //self.nHourMax = int()
        //self.nItemMin = int()
        //self.nItemMax = int()
        //self.dwAiState = int()
        float angle = 0.f;
        //self.dwPatrolIndex = int()
        //self.bPatrolCycle = int()
        //self.nControl = int()
        //self.ctrlElement = CtrlElement()

        ReSpawn() = default;
        ReSpawn(const ReSpawn&) = default;
        ReSpawn(ReSpawn&&) noexcept = default;
        ReSpawn& operator=(const ReSpawn&) = default;
        ReSpawn& operator=(ReSpawn&&) = default;
        virtual ~ReSpawn() = default;
    };
}
#pragma warning( default : 4251 )
