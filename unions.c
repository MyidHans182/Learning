#include <stdio.h>
#include <stdint.h>
union Address
{
    uint16_t ShortAddr;
    uint32_t LongAddr;
};
union Packet // 4 byte
{
    uint32_t packetValues;
    struct
    {
        uint32_t crc : 2; // LSB
        uint32_t status : 1;
        uint32_t payload : 12;
        uint32_t bat : 3;
        uint32_t sensor : 3;
        uint32_t longAddr : 8;
        uint32_t shortAddr : 2;
        uint32_t addrmore : 1; // MSB
    }packetFields;
};

int main()
{
    union Packet packet;
    printf("Enter the 32bit packet value:");
    scanf("%X",&packet.packetValues);
    printf("crc: %x \n ", packet.packetFields.crc);
    printf("status: %x \n ", packet.packetFields.status);
    printf("payload: %x \n ", packet.packetFields.payload);
    printf("sensor: %x \n ", packet.packetFields.sensor);
    printf("longAddr: %x \n ", packet.packetFields.longAddr);
    printf("shortAddr: %x \n ", packet.packetFields.shortAddr);
    printf("bat: %x \n ", packet.packetFields.bat);
    printf("addrmore: %x \n ", packet.packetFields.addrmore);
    return 0;
}