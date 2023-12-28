#include "i2cHeader.h"

static int altr_i2c_probe( struct platform_device *pdev ) {
    return -EINVAL;
}

static int altr_i2c_remove( struct platform_device *pdev ) {
    return -EINVAL;
}

static struct platform_driver module_kernel_driver = {
    .probe = altr_i2c_probe,
    .remove = altr_i2c_remove,
    .driver = {
        .name = "i2component",
    },
};

void register_i2cslave( void ) {
    int ret = platform_driver_register( &module_kernel_driver );
    if ( ret == 0 ) {
        printk( KERN_INFO DEVICE_NAME "Slave registered\n");
    }
}

void unregister_i2cslave( void ) {
    printk( KERN_INFO DEVICE_NAME "Slave unregistered\n" );
    platform_driver_unregister( &module_kernel_driver );
}
//module_kernel_driver(module_kernel_driver);