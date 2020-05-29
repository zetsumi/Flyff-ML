#pragma once

namespace fe
{
	namespace packet
	{
		enum class PACKETTYPE : fe::type::_32uint
		{
			WELCOME = 0x00000000,
			QUERYTICKCOUNT = 0x0000000b,
			PING = 0x00000014,
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
			ERROR_STRING = 0x70000003,
			LOGIN_PROTECT_NUMPAD = 0x88100200,
			LOGIN_PROTECT_CERT = 0x88100201,
			SNAPSHOT = 0xffffff00,
			QUERYGETPOS = 0xffffff08,
			MAX_ERROR
		};
	}
}

