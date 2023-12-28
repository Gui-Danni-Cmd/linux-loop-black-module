#include "i2cHeader.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Guilherme");
MODULE_DESCRIPTION("module loopback");
MODULE_VERSION("1.00");



static int device_open(struct inode *, struct file *);
static int device_release(struct inode *, struct file *);
static ssize_t device_read(struct file *, char *, size_t, loff_t *);
static ssize_t device_write(struct file *, const char *, size_t, loff_t *);
static int major_num;
static int device_open_count = 0;
static char msg_buffer[MSG_BUFFER_LEN];
static char *msg_ptr;





static struct file_operations file_ops = {
 .read = device_read,
 .write = device_write,
 .open = device_open,
 .release = device_release
};


static ssize_t device_read(struct file *flip, char *buffer, size_t len, loff_t *offset) {
 int bytes_read = 0;

 if (*msg_ptr == 0) {
 msg_ptr = msg_buffer;
 }

 while (len && *msg_ptr) {

 put_user(*(msg_ptr++), buffer++);
 len--;
 bytes_read++;
 }
 return bytes_read;
}

static ssize_t device_write(struct file *flip, const char *buffer, size_t len, loff_t *offset) {

 printk(KERN_ALERT "This operation is not supported.\n");
 return -EINVAL;
}

static int device_open(struct inode *inode, struct file *file) {

 if (device_open_count) {
 return -EBUSY;
 }
 device_open_count++;
 try_module_get(THIS_MODULE);
 return 0;
}

static int device_release(struct inode *inode, struct file *file) {
 
 device_open_count--;
 module_put(THIS_MODULE);
 unregister_i2cslave();
 return 0;
}
static int __init i2component_init( void ) {
    register_i2cslave();
    strncpy(msg_buffer, EXAMPLE_MSG, MSG_BUFFER_LEN);

    msg_ptr = msg_buffer;

    major_num = register_chrdev(341, DEVICE_NAME, &file_ops);
    if (major_num < 0) {
        printk(KERN_ALERT "Could not register device: %d\n", major_num);
        return major_num;
    } else {
        printk(KERN_INFO DEVICE_NAME "module loaded with device major number %d\n", major_num);
        return 0;
 }
}
static void __exit i2component_exit(void) {
 unregister_chrdev(major_num, DEVICE_NAME);
 printk(KERN_INFO "%s!\n", EXAMPLE_MSG);
}

module_init(i2component_init);
module_exit(i2component_exit);