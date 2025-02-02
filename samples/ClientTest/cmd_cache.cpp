#include "./header.hpp"


extern fe::Transaction			transCertifier;
extern fe::Transaction			transLogin;
extern fe::Transaction			transCache;

extern fe::SocketClient			_socketCert;
extern fe::SocketClient			_socketLog;
extern fe::SocketClient			_socketCache;

extern fe::HandlerCertifier		certifier;
extern fe::HandlerLogin			login;
extern fe::HandlerCache			cache;



void cache_connect()
{
    FE_LOG("connecting CacheServer");
    std::thread tproxy(handler_cache);
    tproxy.detach();
}

void	cache_join()
{
    FE_LOG("Sending Join Game");
    cache.sendJoin(
        _socketCache.getSocket(),
        TEST_DEFAULT_ID_WORLD,
        TEST_DEFAULT_ID_PLAYER,
        certifier.getAuthKey(),
        0,
        0,
        0,
        1,
        0,
        TEST_DEFAULT_PLAYER_NAME,
        TEST_DEFAULT_ACCOUNT,
        TEST_DEFAULT_PASSWORD
    );
}

void	cache_get_pos()
{
    cache.sendGetPosition(
        _socketCache.getSocket(),
        TEST_DEFAULT_ID_PLAYER
    );
}

fe::util::Vector3D<float> dest{ 6959.27734f, 100.000000f, 3462.15723f };

void	cache_dest_pos()
{
    dest.x += 3;
    cache.sendDestinationPosition(
        _socketCache.getSocket(),
        dest,
        1
    );
}
