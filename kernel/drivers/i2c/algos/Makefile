obj-$(CONFIG_I2C_ALGOBIT)	+= i2c-algo-bit.o
obj-$(CONFIG_I2C_ALGOPCF)	+= i2c-algo-pcf.o
obj-$(CONFIG_I2C_ALGOPCA)	+= i2c-algo-pca.o

ifeq ($(CONFIG_I2C_DEBUG_ALGO),y)
EXTRA_CFLAGS += -DDEBUG
endif
