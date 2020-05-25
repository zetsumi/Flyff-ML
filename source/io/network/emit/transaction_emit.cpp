#include <pch_fnetwork.h>
#include <io/network/emit/transaction.hpp>


bool fe::Transaction::sender(fe::type::_SOCKET idSocket, unsigned int size, const char* data)
{
	if (_socket == nullptr)
		return false;
#if defined(_WIN64)
	int errorCode = ::send(idSocket, data, size, 0);
	if (errorCode == SOCKET_ERROR)
	{
		FE_CONSOLELOG("fe::type::_SOCKET ERROR with client<%u>", idSocket);
		return false;
	}
#else
#endif
	return true;
}

bool fe::Transaction::sender(fe::type::_SOCKET idSocket, PacketBuilder& packet)
{
	if (_socket == nullptr)
		return false;
	return sender(idSocket, packet.getSize(), reinterpret_cast<const char*>(packet.getData()));
}

bool fe::Transaction::sender(PacketBuilder& packet)
{
	fe::type::_SOCKET idSocket = _socket->getSocket();
	return sender(idSocket, packet);
}

fe::PacketStructure* fe::Transaction::receiver(fe::type::_SOCKET idSocket)
{
	return receiver(idSocket, lengthBuffer);
}

fe::PacketStructure* fe::Transaction::receiver(fe::type::_SOCKET idSocket, unsigned int bufferSize)
{
	char* buffer = new char[bufferSize];
	int octects = 0;
#if defined(_WIN64)
	ZeroMemory(buffer, sizeof(buffer));
	octects = ::recv(idSocket, buffer, bufferSize, 0);
#else
#endif
	if (octects <= 0)
		return nullptr;
	if (octects > static_cast<int>(bufferSize))
		return nullptr;

	fe::PacketStructure* ps = new fe::PacketStructure();
	if (ps == nullptr)
		return nullptr;
	ps->data = (unsigned char*)buffer;
	ps->size = octects;
	return ps;
}
