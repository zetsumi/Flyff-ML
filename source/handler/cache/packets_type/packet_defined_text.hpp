#pragma once

namespace fe
{
    namespace packet
    {
#pragma warning( disable: 4251 )
        struct API_DECLSPEC PacketDefinedText : public fe::PacketMessage
        {
            uint32_t	textId = 0;
            const char* textMessage = nullptr;

            PacketDefinedText() = default;
            ~PacketDefinedText() = default;
            PacketDefinedText(const PacketSystem&) = delete;
            PacketDefinedText(PacketSystem&&) = delete;

            PacketDefinedText& operator<<(fe::PacketBuilder& pb)
            {
                pb >> textId;
                textMessage = pb.readString();
                return *this;
            }

            void	release() override final
            {
                delete textMessage;
                textMessage = nullptr;
            }
        };
#pragma warning( default : 4251 )
    }
}
