#pragma once

namespace fe
{
    namespace snapshot
    {
        enum class  SNAPSHOTTYPE : unsigned short
        {
            CHAT = 0x0001,
            CREATESFXOBJ = 0x000f,
            GETPOS = 0x001f,
            GAMERATE = 0x002e,
            SM_MODE_ALL = 0x003e,
            MONSTERPROP = 0x004e,
            ENVIRONMENT = 0x0060,
            ENVIRONMENTALL = 0x0063,
            ADDPARTYNAME = 0x0068,
            ADDFRIENDGAMEJOIN = 0x0074,
            ADDGAMEJOIN = 0x0078,
            GAME_TIMER = 0x0096,
            TASKBAR = 0x0097,
            GUILD = 0x009e,
            ALL_GUILDS = 0x009f,
            FLYFF_EVENT = 0x00b2,
            ALL_ACTION = 0x00b7,
            GUILDCOMBAT = 0x00b8,
            DESTPOS = 0x00c1,
            MOVER_MOVED = 0x00ca,
            MOVER_BEHAVIOR = 0x00cb,
            MOVER_MOVED_2 = 0x00cc,
            MOVER_BEHAVIOR_2 = 0x00cd,
            MOVERCORR = 0x00c8,
            ADD_OBJ = 0x00f0,
            TAG = 0x00f7,
            QUERY_PLAYER_DATA = 0x0141,
            SECRET_ROOM_MNG_STATE = 0x0300,
            TAX_ALLINFO = 0x0400,
            GUILDHOUSE_ALLINFO = 0x8812,
            LORD = 0x8F06,
            HOUSING_ALLINFO = 0x9200,
            WORLD_READINFO = 0x9910,
            MAX_ERROR
        };
    }
}

