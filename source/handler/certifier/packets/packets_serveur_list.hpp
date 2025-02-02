#pragma once

namespace fe
{
    namespace packet
    {
        struct PacketServerList : public PacketMessage
        {
            struct ServerInfo
            {
                uint32_t parent = 0;
                uint32_t id = 0;
                const char* name = nullptr;
                const char* addr = nullptr;
                uint32_t unknow = 0;
                uint32_t count = 0;
                uint32_t enable = 0;
                uint32_t max = 0;

                ServerInfo() = default;
                ~ServerInfo() = default;
                ServerInfo operator<<(fe::PacketBuilder& pb)
                {
                    pb >> parent >> id;
                    name = pb.readString();
                    addr = pb.readString();
                    pb >> unknow >> count >> enable >> max;

                    return *this;
                }
            };

            uint32_t	authKey = 0;
            uint8_t	accountFlag = 0;
            char* account = nullptr;
            uint32_t	numberServer = 0;
            ServerInfo* servers = nullptr;

            PacketServerList() = default;
            ~PacketServerList() = default;

            PacketServerList& operator<<(fe::PacketBuilder& pb) override
            {
                pb >> authKey >> accountFlag;
                account = const_cast<char*>(pb.readString());
                pb >> numberServer;

                servers = new ServerInfo[numberServer];
                for (uint32_t i = 0; i < numberServer; ++i)
                    servers[i] << pb;
                return *this;
            }

            void	release() override final
            {
                delete account;
                account = nullptr;
                for (uint32_t i = 0; i < numberServer; ++i)
                {
                    delete servers[i].addr;
                    delete servers[i].name;
                    servers[i].addr = nullptr;
                    servers[i].name = nullptr;
                }
                delete[] servers;
                servers = nullptr;
            }
        };
    }
}