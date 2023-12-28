obj-m += i2cHeader.o
i2cHeader-objs += kernel_modulei2c.o driver_device.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean