#include <stdio.h>
<<<<<<< HEAD
#include <stddef.h>
#include <stdint.h>
=======
#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <sys/time.h>
>>>>>>> d959d62 (step1)

#include "platform.h"

#include "util.h"
#include "net.h"

<<<<<<< HEAD
/* NOTE: if you want to add/delete the entries after net_run(), you need to protect these lists with a mutex. */
static struct net_device *devices;

struct net_device *
net_device_alloc(void)
{
    struct net_device *dev;

    dev = memory_alloc(sizeof(*dev));
    if (!dev) {
        errorf("memory_alloc() failure");
        return NULL;
    }
    return dev;
}

/* NOTE: must not be call after net_run() */
=======
static struct net_device *devices;

struct net_device *net_device_alloc(void) 
{
    struct net_device *dev = memory_alloc(sizeof(struct net_device));
    if (!dev) {
        errorf("memory_alloc error");
        return NULL;
    }

    return dev;
}

>>>>>>> d959d62 (step1)
int
net_device_register(struct net_device *dev)
{
    static unsigned int index = 0;
<<<<<<< HEAD

    dev->index = index++;
    snprintf(dev->name, sizeof(dev->name), "net%d", dev->index);
=======
    dev->index = index++;
    snprintf(dev-> name, sizeof(dev->name), "net%d", dev->index);
>>>>>>> d959d62 (step1)
    dev->next = devices;
    devices = dev;
    infof("registered, dev=%s, type=0x%04x", dev->name, dev->type);
    return 0;
}

static int
net_device_open(struct net_device *dev)
{
    if (NET_DEVICE_IS_UP(dev)) {
<<<<<<< HEAD
        errorf("already opened, dev=%s", dev->name);
=======
        errorf("aleady opened, dev=%s", dev->name);
>>>>>>> d959d62 (step1)
        return -1;
    }
    if (dev->ops->open) {
        if (dev->ops->open(dev) == -1) {
            errorf("failure, dev=%s", dev->name);
            return -1;
        }
    }
<<<<<<< HEAD
=======

>>>>>>> d959d62 (step1)
    dev->flags |= NET_DEVICE_FLAG_UP;
    infof("dev=%s, state=%s", dev->name, NET_DEVICE_STATE(dev));
    return 0;
}

static int
<<<<<<< HEAD
net_device_close(struct net_device *dev)
{
=======
net_device_close(struct net_device *dev) {
>>>>>>> d959d62 (step1)
    if (!NET_DEVICE_IS_UP(dev)) {
        errorf("not opened, dev=%s", dev->name);
        return -1;
    }
    if (dev->ops->close) {
        if (dev->ops->close(dev) == -1) {
            errorf("failure, dev=%s", dev->name);
            return -1;
        }
    }
    dev->flags &= ~NET_DEVICE_FLAG_UP;
<<<<<<< HEAD
    infof("dev=%s, state=%s", dev->name, NET_DEVICE_STATE(dev));
    return 0;
}

int
net_device_output(struct net_device *dev, uint16_t type, const uint8_t *data, size_t len, const void *dst)
=======
    infof("dev=%s. state=%s", dev->name, NET_DEVICE_STATE(dev));
    return 0;
}

int net_device_output(struct net_device *dev, uint16_t type, const uint8_t *data, size_t len, const void *dst)
>>>>>>> d959d62 (step1)
{
    if (!NET_DEVICE_IS_UP(dev)) {
        errorf("not opened, dev=%s", dev->name);
        return -1;
    }
    if (len > dev->mtu) {
<<<<<<< HEAD
        errorf("too long, dev=%s, mtu=%u, len=%zu", dev->name, dev->mtu, len);
        return -1;
    }
=======
        errorf("too long, dev=%s, len=%zu", dev->name, len);
        return -1;
    }

>>>>>>> d959d62 (step1)
    debugf("dev=%s, type=0x%04x, len=%zu", dev->name, type, len);
    debugdump(data, len);
    if (dev->ops->transmit(dev, type, data, len, dst) == -1) {
        errorf("device transmit failure, dev=%s, len=%zu", dev->name, len);
        return -1;
    }
<<<<<<< HEAD
=======

>>>>>>> d959d62 (step1)
    return 0;
}

int
net_input_handler(uint16_t type, const uint8_t *data, size_t len, struct net_device *dev)
{
    debugf("dev=%s, type=0x%04x, len=%zu", dev->name, type, len);
    debugdump(data, len);
    return 0;
}

int
net_run(void)
{
    struct net_device *dev;
<<<<<<< HEAD

    if (intr_run() == -1) {
        errorf("intr_run() failure");
        return -1;
    }
    debugf("open all devices...");
    for (dev = devices; dev; dev = dev->next) {
        net_device_open(dev);
    }
    debugf("running...");
=======
    debugf("open all");
    for (dev = devices; dev; dev = dev->next) {
        net_device_open(dev);
    }
    debugf("running");
>>>>>>> d959d62 (step1)
    return 0;
}

void
net_shutdown(void)
{
    struct net_device *dev;
<<<<<<< HEAD

    debugf("close all devices...");
=======
    debugf("close all");
>>>>>>> d959d62 (step1)
    for (dev = devices; dev; dev = dev->next) {
        net_device_close(dev);
    }
    intr_shutdown();
    debugf("shutting down");
}

int
net_init(void)
{
<<<<<<< HEAD
    if (intr_init() == -1) {
        errorf("intr_init() failure");
        return -1;
    }
=======
<<<<<<< HEAD
>>>>>>> 4b20ef0 (step1)
    infof("initialized");
=======
    infof("init");
>>>>>>> d959d62 (step1)
    return 0;
}
