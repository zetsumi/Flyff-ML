#include <pch_fnetwork.h>
#include <handler/handler_login.hpp>
#include <ctime>


void fe::HandlerLogin::sendQueryTickCount(SOCKET id)
{
	lockerSend.lock();
	fe::PacketBuilder pb;

	std::time_t	tm = std::time(nullptr);
	pb.write<fe::type::_32uint>(PACKETTYPE_QUERYTICKCOUNT);
	pb.write<fe::type::_32int>(static_cast<fe::type::_32uint>(tm));
	pb.writeHeader(sessionID, handlerType);
	FE_SEND(pb, id);

	lockerSend.unlock();
}

void fe::HandlerLogin::sendGetListPlayer(SOCKET id, const char* protocolVersion, fe::type::_32uint authKey,
										const char* account, const char* password, fe::type::_32uint idServer)
{
	lockerSend.lock();
	fe::PacketBuilder pb;

	std::time_t	tm = std::time(nullptr);
	pb.write<fe::type::_32uint>(PACKETTYPE_GETPLAYERLIST);
	pb.writeString(protocolVersion);
	pb.write<fe::type::_32uint>(authKey);
	pb.writeString(account);
	pb.writeString(password);
	pb.write<fe::type::_32uint>(idServer);
	pb.writeHeader(sessionID, handlerType);
	FE_SEND(pb, id);

	lockerSend.unlock();
}

void fe::HandlerLogin::sendPreJoin(SOCKET id)
{
}
