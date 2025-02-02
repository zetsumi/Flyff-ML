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


bool	handler_cache()
{
    fe::Network network;

    const char* ipCacheServer = login.getCacheServerAddr();
    network.setIP(ipCacheServer);
    network.setPort(fe::portCacheServer);
    if (network.isValid() == false)
        return false;

    if (_socketCache.connect(network) == false)
        return false;
    if (transCache.setSocket(&_socketCache) == false)
        return false;
    transCache.setMode(fe::MODE_TRANSACTION::MODE_CLIENT);
    uint32_t headerLength = sizeof(uint8_t) + sizeof(uint32_t) + sizeof(uint32_t);
    transCache.setLengthBuffer(headerLength);

    cache.initialize();
    cache.setTransaction(&transCache);

    auto onMsg = std::bind(&fe::HandlerMessage::onMsg, &cache, std::placeholders::_1);
    if (transCache.run(onMsg) == false)
        return false;

    transCache.wait();
    FE_CONSOLELOG("out");
    return true;
}