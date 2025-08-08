#include <stdio.h>
typedef enum Status_Device
{
    IDLE = 1,
    RUN = 2,
    ERROR = 3,
    INIT = 4,
    SLEEP = 5,
    SHUTDOW = 6,
    UPDATE = 7,
    MAINTENANCE = 8,
}Status_Device;
void handleDeviceState(Status_Device status)
{
    switch (status)
    {
    case 1:
        printf("IDLE");
        break;
    case 2:
        printf("RUN");
        break;
    case 3:
        printf("ERROR");
        break;
    case 4:
        printf("INIT");
        break;
    case 5:
        printf("SLEEP");
        break;
    case 6:
        printf("SHUTDOWN");
        break;
    case 7:
        printf("UPDATE");
        break;
    case 8:
        printf("MAINTENANCE");
        break;
    default:
        printf("Unknown State");
        break;
    }
}
int main()
{
    enum Status_Device status;
    int n = 0;
    printf(" Nhap trang thai cua he thong = ");
    scanf("%d",&n);
    status = n;
    handleDeviceState(status);
    return 0;
}