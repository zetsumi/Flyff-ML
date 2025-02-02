#pragma once

namespace fe
{
    namespace snapshot
    {
        struct SnapshotGetPosition : public Snapshot
        {
            fe::util::Vector3D<float>		pos{ 0,0,0 };
            float					angle = 0;

            SnapshotGetPosition() = default;
            ~SnapshotGetPosition() = default;
            SnapshotGetPosition& operator<<(fe::PacketBuilder& pb) override
            {
                pos.x = pb.read<float>();
                pos.y = pb.read<float>();
                pos.z = pb.read<float>();
                angle = pb.read<float>();
                return *this;
            }
        };
    }
}