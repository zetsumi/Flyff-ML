#pragma once

namespace fe
{
    namespace packet
    {
        enum class PACKETTYPE : uint32_t
        {
            WELCOME = 0x00000000,
            QUERYTICKCOUNT = 0x0000000b,
            PING = 0x00000014,
            GET_CLOCK = 0x00000015,
            CLOSE_EXISTING_CONNECTION = 0x00000016,
            KEEP_ALIVE = 0x00000018,
            NEW_ACCOUNT = 0x000000f0,
            CACHE_ADDR = 0x000000f2,
            PLAYER_LIST	 = 0x000000f3,
            CERTIFY = 0x000000fc,
            SRVR_LIST = 0x000000fd,
            PERROR = 0x000000fe,
            GETPLAYERLIST = 0x000000f6,
            JOIN = 0x0000ff00,
            PRE_JOIN = 0x0000ff05,
            GAME_RATE = 0x0000ff06,
            ERROR_STRING = 0x70000003,
            LOGIN_PROTECT_NUMPAD = 0x88100200,
            LOGIN_PROTECT_CERT = 0x88100201,
            SAY = 0x00ff00e0,
            GET_PLAYER_ADDR = 0x00ff00e7,
            GET_PLAYER_COUNT = 0x00ff00e8,
            GET_CORE_PLAYER = 0x00ff00e9,
            SYSTEM = 0x00ff00ea,
            DEFINED_TEXT = 0x00ff00ec,
            GMSAY = 0x00ff00ed,
            CAPTION = 0x00ff00d6,
            REPLACE = 0x00ff0f00,
            SNAPSHOT = 0xffffff00,
            QUERYGETPOS = 0xffffff08,
            MAX_ERROR
        };
    }
}
