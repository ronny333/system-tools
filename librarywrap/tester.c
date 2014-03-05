
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "ftdi_reference.h"

static struct ftdi_context *ctxitem0z;
static char bufitem0z[64];
static char bufitem1z[128];
static char bufitem2z[64];
static unsigned char item0z[] = {
     0xaa, 
     0x87, 
};
static unsigned char item1z[] = {
     0xab, 
     0x87, 
};
static unsigned char item2z[] = {
     0x85, 
     0x8a, 
     0x86, 0x01, 0x00, 
     0x80, 0xe8, 0xeb, 
     0x82, 0x20, 0x30, 
     0x82, 0x30, 0x00, 
     0x82, 0x00, 0x00, 
     0x4b, 0x04, 0x1f, 
};
static unsigned char item3z[] = {
     0x4b, 0x00, 0x01, 
     0x4b, 0x04, 0x7f, 
     0x4b, 0x03, 0x02, 
     0x3d, 0x3e, 
     0x00, 0xff, 0x00, 0x00, 
     0x00, 0xff, 0x00, 0x00, 
     0x00, 0xff, 0x00, 0x00, 
     0x00, 0xff, 0x00, 0x00, 
     0x00, 0xff, 0x00, 0x00, 
     0x00, 0xff, 0x00, 0x00, 
     0x00, 0xff, 0x00, 0x00, 
     0x00, 0xff, 0x00, 0x00, 
     0x00, 0xff, 0x00, 0x00, 
     0x00, 0xff, 0x00, 0x00, 
     0x00, 0xff, 0x00, 0x00, 
     0x00, 0xff, 0x00, 0x00, 
     0x00, 0xff, 0x00, 0x00, 
     0x00, 0xff, 0x00, 0x00, 
     0x00, 0xff, 0x00, 0x00, 
     0x00, 0xff, 0x00, 0x00, 
     0x3f, 0x06, 0x00, 
     0x6f, 0x02, 0x03, 
     0x87, 
};
static unsigned char item4z[] = {
     0x4b, 0x02, 0x07, 
     0x4b, 0x04, 0x7f, 
     0x4b, 0x03, 0x02, 
     0x3d, 0x3e, 
     0x00, 0xff, 0x00, 0x00, 
     0x00, 0xff, 0x00, 0x00, 
     0x00, 0xff, 0x00, 0x00, 
     0x00, 0xff, 0x00, 0x00, 
     0x00, 0xff, 0x00, 0x00, 
     0x00, 0xff, 0x00, 0x00, 
     0x00, 0xff, 0x00, 0x00, 
     0x00, 0xff, 0x00, 0x00, 
     0x00, 0xff, 0x00, 0x00, 
     0x00, 0xff, 0x00, 0x00, 
     0x00, 0xff, 0x00, 0x00, 
     0x00, 0xff, 0x00, 0x00, 
     0x00, 0xff, 0x00, 0x00, 
     0x00, 0xff, 0x00, 0x00, 
     0x00, 0xff, 0x00, 0x00, 
     0x00, 0xff, 0x00, 0x00, 
     0x3f, 0x06, 0x00, 
     0x6f, 0x02, 0x03, 
     0x87, 
};
static unsigned char item5z[] = {
     0x4b, 0x03, 0x03, 
     0x1b, 0x04, 0xff, 
     0x4b, 0x02, 0x83, 
     0x4b, 0x03, 0x03, 
     0x1b, 0x04, 0xc3, 
     0x4b, 0x02, 0x03, 
     0x4b, 0x02, 0x01, 
     0x2c, 0x02, 0x00, 
     0x2e, 0x06, 
     0x6f, 0x02, 0x03, 
     0x87, 
};
static unsigned char item6z[] = {
     0x4b, 0x03, 0x03, 
     0x1b, 0x04, 0xff, 
     0x4b, 0x02, 0x83, 
     0x4b, 0x03, 0x03, 
     0x1b, 0x04, 0xc3, 
     0x4b, 0x02, 0x03, 
     0x4b, 0x02, 0x01, 
     0x19, 0x00, 0x00, 
          0x69, 
     0x1b, 0x01, 0x00, 
     0x2c, 0x02, 0x00, 
     0x2e, 0x06, 
     0x6f, 0x02, 0x03, 
     0x87, 
};
static unsigned char item7z[] = {
     0x4b, 0x03, 0x03, 
     0x1b, 0x04, 0xff, 
     0x4b, 0x02, 0x83, 
     0x4b, 0x03, 0x03, 
     0x1b, 0x04, 0xc3, 
     0x4b, 0x02, 0x03, 
     0x4b, 0x02, 0x01, 
     0x1b, 0x04, 0x0c, 
     0x4b, 0x02, 0x03, 
     0x4b, 0x02, 0x01, 
     0x19, 0x00, 0x00, 
          0x69, 
     0x1b, 0x01, 0x00, 
     0x2c, 0x02, 0x00, 
     0x2e, 0x06, 
     0x6f, 0x02, 0x03, 
     0x87, 
};
static unsigned char item8z[] = {
     0x4b, 0x02, 0x07, 
     0x4b, 0x00, 0x7f, 
};
static unsigned char item9z[] = {
     0x86, 0x01, 0x00, 
};
static unsigned char item10z[] = {
     0x4b, 0x00, 0x01, 
     0x4b, 0x00, 0x7f, 
     0x4b, 0x00, 0x01, 
     0x4b, 0x00, 0x7f, 
     0x4b, 0x00, 0x00, 
     0x4b, 0x02, 0x01, 
     0x3d, 0x7e, 
     0x00, 0xff, 0xff, 0xff, 
     0xff, 0xff, 0xff, 0xff, 
     0xff, 0xff, 0xff, 0xff, 
     0xff, 0xff, 0xff, 0xff, 
     0xff, 0xff, 0xff, 0xff, 
     0xff, 0xff, 0xff, 0xff, 
     0xff, 0xff, 0xff, 0xff, 
     0xff, 0xff, 0xff, 0xff, 
     0xff, 0xff, 0xff, 0xff, 
     0xff, 0xff, 0xff, 0xff, 
     0xff, 0xff, 0xff, 0xff, 
     0xff, 0xff, 0xff, 0xff, 
     0xff, 0xff, 0xff, 0xff, 
     0xff, 0xff, 0xff, 0xff, 
     0xff, 0xff, 0xff, 0xff, 
     0xff, 0xff, 0xff, 0xff, 
     0xff, 0xff, 0xff, 0xff, 
     0xff, 0xff, 0xff, 0xff, 
     0xff, 0xff, 0xff, 0xff, 
     0xff, 0xff, 0xff, 0xff, 
     0xff, 0xff, 0xff, 0xff, 
     0xff, 0xff, 0xff, 0xff, 
     0xff, 0xff, 0xff, 0xff, 
     0xff, 0xff, 0xff, 0xff, 
     0xff, 0xff, 0xff, 0xff, 
     0xff, 0xff, 0xff, 0xff, 
     0xff, 0xff, 0xff, 0xff, 
     0xff, 0xff, 0xff, 0xff, 
     0xff, 0xff, 0xff, 0xff, 
     0xff, 0xff, 0xff, 0xff, 
     0xff, 0xff, 0xff, 0xff, 
     0xff, 0xff, 0xff, 0xff, 
     0x3f, 0x06, 0xff, 
     0x6f, 0x01, 0x81, 
     0x87, 
};
static unsigned char item11z[] = {
     0x4b, 0x04, 0x1f, 
     0x4b, 0x00, 0x7f, 
     0x4b, 0x00, 0x00, 
     0x4b, 0x03, 0x03, 
     0x1b, 0x04, 0xc8, 
     0x4b, 0x02, 0x03, 
     0x4b, 0x02, 0x01, 
     0x2c, 0x02, 0x00, 
     0x2e, 0x06, 
     0x6f, 0x02, 0x03, 
     0x87, 
};
static unsigned char item12z[] = {
     0x4b, 0x03, 0x03, 
     0x3f, 0x04, 0xff, 
     0x6f, 0x02, 0x83, 
     0x87, 
};
static unsigned char item13z[] = {
     0x4b, 0x02, 0x07, 
     0x4b, 0x00, 0x00, 
     0x4b, 0x03, 0x03, 
     0x1b, 0x04, 0xc5, 
     0x4b, 0x02, 0x03, 
     0x4b, 0x02, 0x01, 
     0x19, 0x12, 0x00, 
          0xff, 0xff, 0xff, 0xff, 0x55, 0x99, 0xaa, 0x66, 0x02, 0x00, 0x00, 0x00, 0x14, 0x00, 0x07, 0x80, 
          0x00, 0x00, 0x00, 
     0x1b, 0x06, 0x00, 
     0x4b, 0x02, 0x03, 
     0x4b, 0x03, 0x03, 
     0x1b, 0x04, 0xc4, 
     0x4b, 0x02, 0x03, 
     0x4b, 0x02, 0x01, 
     0x2c, 0x02, 0x00, 
     0x2e, 0x06, 
     0x6f, 0x02, 0x03, 
     0x87, 
};
static unsigned char item14z[] = {
     0x4b, 0x02, 0x07, 
};
static unsigned char item15z[] = {
     0x4b, 0x02, 0x07, 
     0x4b, 0x00, 0x7f, 
     0x4b, 0x00, 0x00, 
     0x4b, 0x03, 0x03, 
     0x1b, 0x04, 0x0b, 
     0x4b, 0x00, 0x01, 
     0x4b, 0x01, 0x01, 
     0x4b, 0x03, 0x03, 
     0x1b, 0x04, 0x14, 
     0x4b, 0x00, 0x01, 
     0x4b, 0x01, 0x01, 
     0x80, 0xe0, 0xfb, 
     0x80, 0xe0, 0xfa, 
     0x8f, 0xff, 0xff, 
     0x8f, 0xff, 0xff, 
     0x8f, 0x6b, 0xdc, 
     0x80, 0xe0, 0xfb, 
     0x80, 0xe0, 0xeb, 
     0x4b, 0x03, 0x03, 
     0x3f, 0x04, 0x14, 
     0x6f, 0x00, 0x01, 
     0x87, 
};
static unsigned char item16z[] = {
     0x4b, 0x01, 0x01, 
     0x4b, 0x03, 0x03, 
     0x3f, 0x04, 0x05, 
     0x6f, 0x00, 0x01, 
     0x87, 
};
static unsigned char readdata0z[] = {
     0xfa, 
};
static unsigned char readdata1z[] = {
     0xaa, 
};
static unsigned char readdata2z[] = {
     0xab, 
};
static unsigned char readdata3z[] = {
     0x93, 0x10, 0x65, 0x43, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 
     0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 
     0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 
     0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 
     0x00, 
};
static unsigned char readdata4z[] = {
     0x00, 0x00, 0x00, 0x00, 0x00, 
};
static unsigned char readdata5z[] = {
     0x93, 0x10, 0x65, 0x43, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
     0xff, 
};
static unsigned char readdata6z[] = {
     0xff, 0xff, 0xff, 0xff, 0xff, 
};
static unsigned char readdata7z[] = {
     0xaf, 0xf5, 
};
static unsigned char readdata8z[] = {
     0x02, 0x08, 0x9e, 0x7f, 0x0f, 
};
static unsigned char readdata9z[] = {
     0x88, 0x44, 
};
static unsigned char readdata10z[] = {
     0x8a, 0x45, 
};
static unsigned char readdata11z[] = {
     0x00, 0x00, 0x00, 0x00, 0x80, 
};
static unsigned char readdata12z[] = {
     0xac, 0xd6, 
};
static unsigned char readdata13z[] = {
     0x02, 0x08, 0x9e, 0x7f, 0x3f, 
};
static unsigned char readdata14z[] = {
     0xa9, 0xf5, 
};
static unsigned char item17z[] = {
     0x80, 0xe0, 0xfb, 
     0x80, 0xe0, 0xfa, 
     0x8f, 0x3d, 0x49, 
     0x80, 0xe0, 0xfb, 
     0x80, 0xe0, 0xeb, 
     0x4b, 0x03, 0x03, 
     0x1b, 0x04, 0x05, 
     0x4b, 0x00, 0x01, 
     0x4b, 0x01, 0x01, 
     0x4b, 0x02, 0x01, 
     0x19, 0x03, 0x00, 
          0xff, 0xff, 0xff, 0xff, 
     0x19, 0x03, 0x00, 
          0x55, 0x99, 0xaa, 0x66, 
     0x19, 0x03, 0x00, 
          0x04, 0x00, 0x00, 0x00, 
     0x19, 0x03, 0x00, 
          0x14, 0x40, 0x03, 0x80, 
     0x19, 0x03, 0x00, 
          0x04, 0x00, 0x00, 0x00, 
     0x19, 0x03, 0x00, 
          0x04, 0x00, 0x00, 0x00, 
     0x19, 0x03, 0x00, 
          0x0c, 0x00, 0x01, 0x80, 
     0x19, 0x03, 0x00, 
          0x00, 0x00, 0x00, 0xb0, 
     0x19, 0x03, 0x00, 
          0x04, 0x00, 0x00, 0x00, 
     0x19, 0x02, 0x00, 
          0x04, 0x00, 0x00, 
     0x1b, 0x06, 0x00, 
     0x4b, 0x00, 0x01, 
     0x4b, 0x01, 0x01, 
     0x4b, 0x03, 0x03, 
     0x1b, 0x04, 0x04, 
     0x4b, 0x00, 0x01, 
     0x4b, 0x01, 0x01, 
     0x4b, 0x02, 0x01, 
     0x3d, 0x02, 
     0x00, 0x00, 0x00, 0x00, 
     0x3f, 0x06, 0x00, 
     0x6f, 0x00, 0x01, 
     0x87, 
};
static unsigned char item18z[] = {
     0x4b, 0x01, 0x01, 
     0x4b, 0x03, 0x03, 
     0x1b, 0x04, 0x3f, 
     0x4b, 0x00, 0x81, 
     0x4b, 0x01, 0x01, 
     0x4b, 0x03, 0x03, 
     0x1b, 0x04, 0x0c, 
     0x4b, 0x00, 0x01, 
     0x4b, 0x01, 0x01, 
     0x4b, 0x00, 0x00, 
     0x4b, 0x06, 0x00, 
     0x4b, 0x06, 0x00, 
     0x4b, 0x06, 0x00, 
     0x4b, 0x06, 0x00, 
     0x4b, 0x06, 0x00, 
     0x4b, 0x06, 0x00, 
     0x4b, 0x06, 0x00, 
     0x4b, 0x06, 0x00, 
     0x4b, 0x06, 0x00, 
     0x4b, 0x06, 0x00, 
     0x4b, 0x06, 0x00, 
     0x4b, 0x06, 0x00, 
     0x4b, 0x06, 0x00, 
     0x4b, 0x06, 0x00, 
     0x4b, 0x01, 0x00, 
     0x4b, 0x03, 0x03, 
     0x3f, 0x04, 0x3f, 
     0x6f, 0x00, 0x81, 
     0x87, 
};
static unsigned char item19z[] = {
     0x4b, 0x01, 0x01, 
     0x4b, 0x03, 0x03, 
     0x1b, 0x04, 0x05, 
     0x4b, 0x00, 0x01, 
     0x4b, 0x01, 0x01, 
     0x4b, 0x02, 0x01, 
     0x19, 0x03, 0x00, 
          0xff, 0xff, 0xff, 0xff, 
     0x19, 0x03, 0x00, 
          0x55, 0x99, 0xaa, 0x66, 
     0x19, 0x03, 0x00, 
          0x04, 0x00, 0x00, 0x00, 
     0x19, 0x03, 0x00, 
          0x14, 0x00, 0x07, 0x80, 
     0x19, 0x03, 0x00, 
          0x04, 0x00, 0x00, 0x00, 
     0x19, 0x03, 0x00, 
          0x04, 0x00, 0x00, 0x00, 
     0x19, 0x03, 0x00, 
          0x0c, 0x00, 0x01, 0x80, 
     0x19, 0x03, 0x00, 
          0x00, 0x00, 0x00, 0xb0, 
     0x19, 0x03, 0x00, 
          0x04, 0x00, 0x00, 0x00, 
     0x19, 0x02, 0x00, 
          0x04, 0x00, 0x00, 
     0x1b, 0x06, 0x00, 
     0x4b, 0x00, 0x01, 
     0x4b, 0x01, 0x01, 
     0x4b, 0x03, 0x03, 
     0x1b, 0x04, 0x04, 
     0x4b, 0x00, 0x01, 
     0x4b, 0x01, 0x01, 
     0x4b, 0x02, 0x01, 
     0x3d, 0x02, 
     0x00, 0x00, 0x00, 0x00, 
     0x3f, 0x06, 0x00, 
     0x6f, 0x00, 0x01, 
     0x87, 
};
static unsigned char item20z[] = {
     0x4b, 0x01, 0x01, 
     0x4b, 0x03, 0x03, 
     0x1b, 0x04, 0x3f, 
     0x4b, 0x00, 0x81, 
     0x4b, 0x01, 0x01, 
};
static unsigned char item21z[] = {
     0x4b, 0x02, 0x07, 
     0x4b, 0x00, 0x7f, 
     0x4b, 0x00, 0x00, 
     0x4b, 0x03, 0x03, 
     0x3f, 0x04, 0xff, 
     0x6f, 0x02, 0x83, 
     0x87, 
};
static unsigned char item22z[] = {
     0x4b, 0x02, 0x07, 
     0x4b, 0x00, 0x7f, 
     0x4b, 0x00, 0x01, 
     0x4b, 0x00, 0x00, 
     0x4b, 0x03, 0x03, 
     0x1b, 0x04, 0xc5, 
     0x4b, 0x02, 0x03, 
     0x4b, 0x02, 0x01, 
     0x19, 0x12, 0x00, 
          0xff, 0xff, 0xff, 0xff, 0x55, 0x99, 0xaa, 0x66, 0x02, 0x00, 0x00, 0x00, 0x14, 0x00, 0x07, 0x80, 
          0x00, 0x00, 0x00, 
     0x1b, 0x06, 0x00, 
     0x4b, 0x02, 0x03, 
     0x4b, 0x03, 0x03, 
     0x1b, 0x04, 0xc4, 
     0x4b, 0x02, 0x03, 
     0x4b, 0x02, 0x01, 
     0x2c, 0x02, 0x00, 
     0x2e, 0x06, 
     0x6f, 0x02, 0x03, 
     0x87, 
};
static int inputfd;
#define BUFFER_MAX_LEN 1000000
static unsigned char readbuffer[BUFFER_MAX_LEN];
static unsigned char *readptr = readbuffer;

void foo(void)
{
//force loading of libpthread
pthread_create(NULL, NULL, NULL, NULL);
}
struct ftdi_transfer_control* writetc;
void check_ftdi_read_data_submit(struct ftdi_context *ftdi, unsigned char *buf, int size)
{
struct ftdi_transfer_control* tc = ftdi_read_data_submit(ftdi, buf, size);
ftdi_transfer_data_done(writetc);
ftdi_transfer_data_done(tc);
//printf("[%s:%d]\n", __FUNCTION__, __LINE__);
}
void c2heck_ftdi_read_data_submit(struct ftdi_context *ftdi, unsigned char *buf, int size)
{
struct ftdi_transfer_control* tc = ftdi_read_data_submit(ftdi, buf, size);
//ftdi_transfer_data_done(writetc);
ftdi_transfer_data_done(tc);
//printf("[%s:%d]\n", __FUNCTION__, __LINE__);
}
unsigned char hdr1[] = {
      0x4b, 0x01, 0x01, 
      0x4b, 0x02, 0x01, 
      0x19, 0x03, 0x00, 
           0x00, 0x00, 0x00, 0x00, 
};
static unsigned char hdr4b[] = {
      0x4b, 0x01, 0x01, 
};
static unsigned char bitswap[256];
static int once = 1;
static void add1byte(int last, unsigned char argch)
{
    unsigned char ch = argch;
    *readptr++ = 0x1b;
    *readptr++ = 0x06;
    if (!last) {
        read(inputfd, readptr, 1);
        ch = bitswap[*readptr];
    }
    *readptr++ = ch;
    if (last) {
    *readptr++ = 0x4b;
    *readptr++ = 0x00;
    *readptr++ = 0x01;
    }
    memcpy(readptr, hdr4b, sizeof(hdr4b));
    readptr += sizeof(hdr4b);
    *(readptr-1) |= (0x80 & ch);
}
static int indata(int len)
{
    int i;
                for (i = 0; once && i < sizeof(bitswap); i++)
                    bitswap[i] = ((i &    1) << 7) | ((i &    2) << 5)
                       | ((i &    4) << 3) | ((i &    8) << 1)
                       | ((i & 0x10) >> 1) | ((i & 0x20) >> 3)
                       | ((i & 0x40) >> 5) | ((i & 0x80) >> 7);
    *readptr++ = 0x19;
    unsigned char *p = readptr;
    *readptr++ = len;
    *readptr++ = len >> 8;
    int rlen = read(inputfd, readptr, len+1);
    for (i = 0; i < rlen; i++) {
        *readptr = bitswap[*readptr];
        readptr++;
    }
    rlen--;
    if (rlen != len) {
        rlen--;
        p[0] = rlen;
        p[1] = rlen >> 8;
        add1byte(1, *--readptr);
    }
    return rlen;
}
static void outbuffer(struct ftdi_context *ftdi)
{
    printf("[%s:%d] len %ld\n", __FUNCTION__, __LINE__, readptr - readbuffer);
    writetc = ftdi_write_data_submit(ftdi, readbuffer, readptr - readbuffer);
    ftdi_transfer_data_done(writetc);
    writetc = NULL;
    readptr = readbuffer;
}
int main()
{
int i;
    struct ftdi_device_list *devlist, *curdev;
    //char manufacturer[128], description[128];

printf("[%s:%d]\n", __FUNCTION__, __LINE__);
ctxitem0z = ftdi_new();
printf("[%s:%d] init\n", __FUNCTION__, __LINE__);
ftdi_init(ctxitem0z);
printf("[%s:%d]\n", __FUNCTION__, __LINE__);
ftdi_usb_find_all(ctxitem0z, &devlist, 0x0, 0x0);
    curdev = devlist;
printf("[%s:%d]\n", __FUNCTION__, __LINE__);
ftdi_usb_get_strings(ctxitem0z, curdev->dev, bufitem2z, sizeof(bufitem2z), bufitem1z, sizeof(bufitem1z), bufitem0z, sizeof(bufitem0z));
printf("[%s:%d]\n", __FUNCTION__, __LINE__);

printf("[%s:%d] %s %s %s\n", __FUNCTION__, __LINE__, bufitem2z, bufitem1z, bufitem0z);
//ftdi_usb_get_strings: ret 0 man=Digilent
//      desc=Digilent Adept USB Device
//      serial=210203339470
ftdi_usb_open_dev(ctxitem0z, curdev->dev);
printf("[%s:%d]\n", __FUNCTION__, __LINE__);
ftdi_usb_reset(ctxitem0z);
printf("[%s:%d]\n", __FUNCTION__, __LINE__);
ftdi_set_baudrate(ctxitem0z, 9600);
printf("[%s:%d]\n", __FUNCTION__, __LINE__);
ftdi_read_eeprom(ctxitem0z);
ftdi_eeprom_decode(ctxitem0z, 0);
int eeprom_val;
ftdi_get_eeprom_value(ctxitem0z, CHIP_TYPE, &eeprom_val);
printf("[%s:%d] CHIP_TYPE %x\n", __FUNCTION__, __LINE__, eeprom_val);
static unsigned char fbuf[256]; // since chiptype is 0x56, eerom size is 256
int rc = ftdi_get_eeprom_buf(ctxitem0z, fbuf, sizeof(fbuf));
printf("[%s:%d] %d\n", __FUNCTION__, __LINE__, rc);
ftdi_list_free(&devlist);
printf("[%s:%d]\n", __FUNCTION__, __LINE__);
ftdi_set_latency_timer(ctxitem0z, 255);
ftdi_set_bitmode(ctxitem0z, 0x0, 0x0);
ftdi_set_bitmode(ctxitem0z, 0x0, 0x2);
ftdi_usb_purge_buffers(ctxitem0z);
ftdi_usb_purge_rx_buffer(ctxitem0z);
ftdi_usb_purge_tx_buffer(ctxitem0z);
ftdi_write_data(ctxitem0z, item0z, sizeof(item0z));
ftdi_read_data(ctxitem0z, readdata0z, sizeof(readdata0z));
ftdi_read_data(ctxitem0z, readdata1z, sizeof(readdata1z));
ftdi_write_data(ctxitem0z, item0z, sizeof(item0z));
ftdi_read_data(ctxitem0z, readdata0z, sizeof(readdata0z));
ftdi_read_data(ctxitem0z, readdata1z, sizeof(readdata1z));
ftdi_write_data(ctxitem0z, item0z, sizeof(item0z));
ftdi_read_data(ctxitem0z, readdata0z, sizeof(readdata0z));
ftdi_read_data(ctxitem0z, readdata1z, sizeof(readdata1z));
ftdi_write_data(ctxitem0z, item0z, sizeof(item0z));
ftdi_read_data(ctxitem0z, readdata0z, sizeof(readdata0z));
ftdi_read_data(ctxitem0z, readdata1z, sizeof(readdata1z));
ftdi_write_data(ctxitem0z, item1z, sizeof(item1z));
ftdi_read_data(ctxitem0z, readdata0z, sizeof(readdata0z));
ftdi_read_data(ctxitem0z, readdata2z, sizeof(readdata2z));
ftdi_write_data(ctxitem0z, item2z, sizeof(item2z));
writetc = ftdi_write_data_submit(ctxitem0z, item3z, sizeof(item3z));
check_ftdi_read_data_submit(ctxitem0z, readdata3z, sizeof(readdata3z));

writetc = ftdi_write_data_submit(ctxitem0z, item4z, sizeof(item4z));
check_ftdi_read_data_submit(ctxitem0z, readdata3z, sizeof(readdata3z));
writetc = ftdi_write_data_submit(ctxitem0z, item5z, sizeof(item5z));
check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
writetc = ftdi_write_data_submit(ctxitem0z, item6z, sizeof(item6z));
check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
for (i = 0; i < 2; i++) {
    writetc = ftdi_write_data_submit(ctxitem0z, item7z, sizeof(item7z));
    check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
}
writetc = ftdi_write_data_submit(ctxitem0z, item5z, sizeof(item5z));
check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
writetc = ftdi_write_data_submit(ctxitem0z, item6z, sizeof(item6z));
check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
for (i = 0; i < 2; i++) {
    writetc = ftdi_write_data_submit(ctxitem0z, item7z, sizeof(item7z));
    check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
}
writetc = ftdi_write_data_submit(ctxitem0z, item5z, sizeof(item5z));
check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
writetc = ftdi_write_data_submit(ctxitem0z, item6z, sizeof(item6z));
check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
for (i = 0; i < 2; i++) {
    writetc = ftdi_write_data_submit(ctxitem0z, item7z, sizeof(item7z));
    check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
}
writetc = ftdi_write_data_submit(ctxitem0z, item5z, sizeof(item5z));
check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
writetc = ftdi_write_data_submit(ctxitem0z, item6z, sizeof(item6z));
check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
for (i = 0; i < 2; i++) {
    writetc = ftdi_write_data_submit(ctxitem0z, item7z, sizeof(item7z));
    check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
}
writetc = ftdi_write_data_submit(ctxitem0z, item4z, sizeof(item4z));
check_ftdi_read_data_submit(ctxitem0z, readdata3z, sizeof(readdata3z));
writetc = ftdi_write_data_submit(ctxitem0z, item5z, sizeof(item5z));
check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
writetc = ftdi_write_data_submit(ctxitem0z, item6z, sizeof(item6z));
check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
for (i = 0; i < 2; i++) {
    writetc = ftdi_write_data_submit(ctxitem0z, item7z, sizeof(item7z));
    check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
}
writetc = ftdi_write_data_submit(ctxitem0z, item5z, sizeof(item5z));
check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
writetc = ftdi_write_data_submit(ctxitem0z, item6z, sizeof(item6z));
check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
for (i = 0; i < 2; i++) {
    writetc = ftdi_write_data_submit(ctxitem0z, item7z, sizeof(item7z));
    check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
}
writetc = ftdi_write_data_submit(ctxitem0z, item5z, sizeof(item5z));
check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
writetc = ftdi_write_data_submit(ctxitem0z, item6z, sizeof(item6z));
check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
for (i = 0; i < 2; i++) {
    writetc = ftdi_write_data_submit(ctxitem0z, item7z, sizeof(item7z));
    check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
}
writetc = ftdi_write_data_submit(ctxitem0z, item8z, sizeof(item8z));
ftdi_transfer_data_done(writetc);
ftdi_write_data(ctxitem0z, item9z, sizeof(item9z));
writetc = ftdi_write_data_submit(ctxitem0z, item10z, sizeof(item10z));
check_ftdi_read_data_submit(ctxitem0z, readdata5z, sizeof(readdata5z));
writetc = ftdi_write_data_submit(ctxitem0z, item11z, sizeof(item11z));
check_ftdi_read_data_submit(ctxitem0z, readdata6z, sizeof(readdata6z));
for (i = 0; i < 3; i++) {
    writetc = ftdi_write_data_submit(ctxitem0z, item12z, sizeof(item12z));
    check_ftdi_read_data_submit(ctxitem0z, readdata7z, sizeof(readdata7z));
}
writetc = ftdi_write_data_submit(ctxitem0z, item13z, sizeof(item13z));
check_ftdi_read_data_submit(ctxitem0z, readdata8z, sizeof(readdata8z));
writetc = ftdi_write_data_submit(ctxitem0z, item14z, sizeof(item14z));
writetc = ftdi_write_data_submit(ctxitem0z, item3z, sizeof(item3z));
check_ftdi_read_data_submit(ctxitem0z, readdata3z, sizeof(readdata3z));
writetc = ftdi_write_data_submit(ctxitem0z, item5z, sizeof(item5z));
check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
writetc = ftdi_write_data_submit(ctxitem0z, item6z, sizeof(item6z));
check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
for (i = 0; i < 2; i++) {
    writetc = ftdi_write_data_submit(ctxitem0z, item7z, sizeof(item7z));
    check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
}
writetc = ftdi_write_data_submit(ctxitem0z, item5z, sizeof(item5z));
check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
writetc = ftdi_write_data_submit(ctxitem0z, item6z, sizeof(item6z));
check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
for (i = 0; i < 2; i++) {
    writetc = ftdi_write_data_submit(ctxitem0z, item7z, sizeof(item7z));
    check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
}
writetc = ftdi_write_data_submit(ctxitem0z, item5z, sizeof(item5z));
check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
writetc = ftdi_write_data_submit(ctxitem0z, item6z, sizeof(item6z));
check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
for (i = 0; i < 2; i++) {
    writetc = ftdi_write_data_submit(ctxitem0z, item7z, sizeof(item7z));
    check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
}
writetc = ftdi_write_data_submit(ctxitem0z, item4z, sizeof(item4z));
check_ftdi_read_data_submit(ctxitem0z, readdata3z, sizeof(readdata3z));
writetc = ftdi_write_data_submit(ctxitem0z, item5z, sizeof(item5z));
check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
writetc = ftdi_write_data_submit(ctxitem0z, item6z, sizeof(item6z));
check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
for (i = 0; i < 2; i++) {
    writetc = ftdi_write_data_submit(ctxitem0z, item7z, sizeof(item7z));
    check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
}
writetc = ftdi_write_data_submit(ctxitem0z, item5z, sizeof(item5z));
check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
writetc = ftdi_write_data_submit(ctxitem0z, item6z, sizeof(item6z));
check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
for (i = 0; i < 2; i++) {
    writetc = ftdi_write_data_submit(ctxitem0z, item7z, sizeof(item7z));
    check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
}
writetc = ftdi_write_data_submit(ctxitem0z, item5z, sizeof(item5z));
check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
writetc = ftdi_write_data_submit(ctxitem0z, item6z, sizeof(item6z));
check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
for (i = 0; i < 2; i++) {
    writetc = ftdi_write_data_submit(ctxitem0z, item7z, sizeof(item7z));
    check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
}
writetc = ftdi_write_data_submit(ctxitem0z, item4z, sizeof(item4z));
check_ftdi_read_data_submit(ctxitem0z, readdata3z, sizeof(readdata3z));
writetc = ftdi_write_data_submit(ctxitem0z, item5z, sizeof(item5z));
check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
writetc = ftdi_write_data_submit(ctxitem0z, item6z, sizeof(item6z));
check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
for (i = 0; i < 2; i++) {
    writetc = ftdi_write_data_submit(ctxitem0z, item7z, sizeof(item7z));
    check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
}
writetc = ftdi_write_data_submit(ctxitem0z, item5z, sizeof(item5z));
check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
writetc = ftdi_write_data_submit(ctxitem0z, item6z, sizeof(item6z));
check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
for (i = 0; i < 2; i++) {
    writetc = ftdi_write_data_submit(ctxitem0z, item7z, sizeof(item7z));
    check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
}
writetc = ftdi_write_data_submit(ctxitem0z, item5z, sizeof(item5z));
check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
writetc = ftdi_write_data_submit(ctxitem0z, item6z, sizeof(item6z));
check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
for (i = 0; i < 2; i++) {
    writetc = ftdi_write_data_submit(ctxitem0z, item7z, sizeof(item7z));
    check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
}
writetc = ftdi_write_data_submit(ctxitem0z, item4z, sizeof(item4z));
check_ftdi_read_data_submit(ctxitem0z, readdata3z, sizeof(readdata3z));
writetc = ftdi_write_data_submit(ctxitem0z, item5z, sizeof(item5z));
check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
writetc = ftdi_write_data_submit(ctxitem0z, item6z, sizeof(item6z));
check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
for (i = 0; i < 2; i++) {
    writetc = ftdi_write_data_submit(ctxitem0z, item7z, sizeof(item7z));
    check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
}
writetc = ftdi_write_data_submit(ctxitem0z, item5z, sizeof(item5z));
check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
writetc = ftdi_write_data_submit(ctxitem0z, item6z, sizeof(item6z));
check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
for (i = 0; i < 2; i++) {
    writetc = ftdi_write_data_submit(ctxitem0z, item7z, sizeof(item7z));
    check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
}
writetc = ftdi_write_data_submit(ctxitem0z, item5z, sizeof(item5z));
check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
writetc = ftdi_write_data_submit(ctxitem0z, item6z, sizeof(item6z));
check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
for (i = 0; i < 2; i++) {
    writetc = ftdi_write_data_submit(ctxitem0z, item7z, sizeof(item7z));
    check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
}
printf("[%s:%d]\n", __FUNCTION__, __LINE__);
writetc = ftdi_write_data_submit(ctxitem0z, item15z, sizeof(item15z));
check_ftdi_read_data_submit(ctxitem0z, readdata9z, sizeof(readdata9z));
printf("[%s:%d]\n", __FUNCTION__, __LINE__);
writetc = ftdi_write_data_submit(ctxitem0z, item16z, sizeof(item16z));
check_ftdi_read_data_submit(ctxitem0z, readdata10z, sizeof(readdata10z));
printf("[%s:%d]\n", __FUNCTION__, __LINE__);
     //4b, 01, 01, 
     //4b, 02, 01, 
     //19, 03, 00, 
          //00, 00, 00, 00, 
     //19, c0, 0f, 
          //ff, ff, ff, ff, ff, ff, ff, ff, ff, ff, ff, ff, ff, ff, ff, ff, 
          //ff, ff, ff, ff, ff, ff, ff, ff, ff, ff, ff, ff, ff, ff, ff, ff, 
          //00, 00, 00, dd, 88, 44, 00, 22, ff, ff, ff, ff, ff, ff, ff, ff, 
          //55, 99, aa, 66, 04, 00, 00, 00, 0c, 40, 04, 80, 00, 00, 00, 00, 
inputfd = open("mkPcieTop.bin", O_RDONLY);
memcpy(readptr, hdr1, sizeof(hdr1));
readptr += sizeof(hdr1);
int retlen = indata(0xfc0);
outbuffer(ctxitem0z); //4049
retlen = indata(0x97d);
add1byte(0, 0); // 0x1b 0x06 0xvv, 0x4b 0x01 0x01
outbuffer(ctxitem0z); //2439
printf("[%s:%d]\n", __FUNCTION__, __LINE__);
while (1) {
    memcpy(readptr, hdr4b, sizeof(hdr4b));
    readptr += sizeof(hdr4b);
    retlen = indata(0xfcd);
    outbuffer(ctxitem0z); //4052
    if (retlen != 0xfcd)
        break;
    retlen = indata(0x970);
    add1byte(0, 0); // 0x1b 0x06 0xvv
    outbuffer(ctxitem0z); //2426
    if (retlen != 0x970)
        break;
}
printf("[%s:%d]\n", __FUNCTION__, __LINE__);
printf("[%s:%d] before readseq\n", __FUNCTION__, __LINE__);
writetc = ftdi_write_data_submit(ctxitem0z, item17z, sizeof(item17z));
check_ftdi_read_data_submit(ctxitem0z, readdata11z, sizeof(readdata11z));
writetc = ftdi_write_data_submit(ctxitem0z, item18z, sizeof(item18z));
check_ftdi_read_data_submit(ctxitem0z, readdata12z, sizeof(readdata12z));
printf("[%s:%d]\n", __FUNCTION__, __LINE__);
writetc = ftdi_write_data_submit(ctxitem0z, item19z, sizeof(item19z));
check_ftdi_read_data_submit(ctxitem0z, readdata13z, sizeof(readdata13z));

writetc = ftdi_write_data_submit(ctxitem0z, item20z, sizeof(item20z));
ftdi_transfer_data_done(writetc);
writetc = ftdi_write_data_submit(ctxitem0z, item21z, sizeof(item21z));
check_ftdi_read_data_submit(ctxitem0z, readdata14z, sizeof(readdata14z));
writetc = ftdi_write_data_submit(ctxitem0z, item4z, sizeof(item4z));
check_ftdi_read_data_submit(ctxitem0z, readdata3z, sizeof(readdata3z));
writetc = ftdi_write_data_submit(ctxitem0z, item5z, sizeof(item5z));
check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
writetc = ftdi_write_data_submit(ctxitem0z, item6z, sizeof(item6z));
check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
for (i = 1; i < 2; i++) {
    writetc = ftdi_write_data_submit(ctxitem0z, item7z, sizeof(item7z));
    check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
}
writetc = ftdi_write_data_submit(ctxitem0z, item5z, sizeof(item5z));
check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
writetc = ftdi_write_data_submit(ctxitem0z, item6z, sizeof(item6z));
check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
for (i = 1; i < 2; i++) {
    writetc = ftdi_write_data_submit(ctxitem0z, item7z, sizeof(item7z));
    check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
}
writetc = ftdi_write_data_submit(ctxitem0z, item5z, sizeof(item5z));
check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
writetc = ftdi_write_data_submit(ctxitem0z, item6z, sizeof(item6z));
check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
for (i = 1; i < 2; i++) {
    writetc = ftdi_write_data_submit(ctxitem0z, item7z, sizeof(item7z));
    check_ftdi_read_data_submit(ctxitem0z, readdata4z, sizeof(readdata4z));
}
writetc = ftdi_write_data_submit(ctxitem0z, item22z, sizeof(item22z));
check_ftdi_read_data_submit(ctxitem0z, readdata8z, sizeof(readdata8z));
writetc = ftdi_write_data_submit(ctxitem0z, item14z, sizeof(item14z));
ftdi_transfer_data_done(writetc);
ftdi_deinit(ctxitem0z);
return 0;
}