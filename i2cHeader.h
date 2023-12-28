#pragma once

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
#include <linux/i2c.h>

#include <linux/platform_device.h>



#define DEVICE_NAME "i2component"
#define EXAMPLE_MSG "Inicializando o processo!\n"
#define MSG_BUFFER_LEN 26


extern void register_i2cslave( void );
extern void unregister_i2cslave( void );