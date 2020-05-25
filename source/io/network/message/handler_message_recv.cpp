#include <pch_fnetwork.h>
#include <io/network/message/handler_message.hpp>


void fe::HandlerMessage::onMsg(fe::type::_SOCKET id, fe::PacketStructure* ps)
{
	fe::type::_uchar	mark = 0;
	fe::type::_32uint	length = 0;
	fe::type::_32uint	packetType = 0;

	FE_CONSOLELOG("****************");
	packetBuilder.reset();
	if (packetBuilder.setPacket(ps) == false)
	{
		FE_CONSOLELOG("fail on setPacket");
		return;
	}

	loadHeader(mark, length, packetType);

	fe::type::_SOCKET idSocket = transaction->getSocket()->getSocket();
	unsigned int lenData = length - sizeof(fe::type::_32uint); // Taille moins sizeof() packettype
	if (lenData > 0)
	{
		fe::PacketStructure* psData = transaction->receiver(idSocket, lenData);
		packetBuilder.reset();
		if (packetBuilder.setPacket(psData) == false)
		{
			FE_CONSOLELOG("fail on setPacket");
			return;
		}
	}

	auto it = actions.find(packetType);
	if (it != actions.end())
	{
		fe::PacketMessage* msg = it->second(id);
		if (msg != nullptr)
		{
			msg->type = packetType;
			mtMessage.lock();
			messages.push(msg);
			mtMessage.unlock();
		}
	}
	else
	{
		FE_CONSOLELOG("packet type unknow<%#010x>", packetType);
	}

	FE_CONSOLELOG("****************");
}


fe::PacketMessage* fe::HandlerMessage::onWelcome(fe::type::_SOCKET id)
{
	sessionID = packetBuilder.read<fe::type::_32uint>();
	FE_CONSOLELOG("sessionID:{%u}{%#010x}", sessionID);

	auto fct = std::bind(&HandlerMessage::processPing, this, id);
	ping = std::thread(fct);
	ping.detach();
	return nullptr;
}

fe::PacketMessage* fe::HandlerMessage::onKeepAlive(fe::type::_SOCKET id)
{
	sendKeepAlive(id);
	return nullptr;
}

fe::PacketMessage* fe::HandlerMessage::onPing(fe::type::_SOCKET id)
{
	return nullptr;
}

fe::PacketMessage* fe::HandlerMessage::onError(fe::type::_SOCKET id)
{
	fe::type::_32uint opcodeError = packetBuilder.read<fe::type::_32uint>();
	FE_CONSOLELOG("OP CODE: %#010x", opcodeError);
	sendError(id);
	return nullptr;
}

fe::PacketMessage* fe::HandlerMessage::onErrorString(fe::type::_SOCKET id)
{
	const char* messageError = packetBuilder.readString();
	if (messageError != nullptr)
		FE_CONSOLELOG("Message Error: %s", messageError);
	sendError(id);
	return nullptr;
}
