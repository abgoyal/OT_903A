
#ifndef _I8042_H
#define _I8042_H




#if defined(CONFIG_MACH_JAZZ)
#include "i8042-jazzio.h"
#elif defined(CONFIG_SGI_HAS_I8042)
#include "i8042-ip22io.h"
#elif defined(CONFIG_SNI_RM)
#include "i8042-snirm.h"
#elif defined(CONFIG_PPC)
#include "i8042-ppcio.h"
#elif defined(CONFIG_SPARC)
#include "i8042-sparcio.h"
#elif defined(CONFIG_X86) || defined(CONFIG_IA64)
#include "i8042-x86ia64io.h"
#else
#include "i8042-io.h"
#endif


#define I8042_CTL_TIMEOUT	10000


#define I8042_STR_PARITY	0x80
#define I8042_STR_TIMEOUT	0x40
#define I8042_STR_AUXDATA	0x20
#define I8042_STR_KEYLOCK	0x10
#define I8042_STR_CMDDAT	0x08
#define I8042_STR_MUXERR	0x04
#define I8042_STR_IBF		0x02
#define	I8042_STR_OBF		0x01


#define I8042_CTR_KBDINT	0x01
#define I8042_CTR_AUXINT	0x02
#define I8042_CTR_IGNKEYLOCK	0x08
#define I8042_CTR_KBDDIS	0x10
#define I8042_CTR_AUXDIS	0x20
#define I8042_CTR_XLATE		0x40


#define I8042_RET_CTL_TEST	0x55


#define I8042_BUFFER_SIZE	16


#define I8042_NUM_MUX_PORTS	4


#ifdef DEBUG
static unsigned long i8042_start_time;
#define dbg_init() do { i8042_start_time = jiffies; } while (0)
#define dbg(format, arg...) 							\
	do { 									\
		if (i8042_debug)						\
			printk(KERN_DEBUG __FILE__ ": " format " [%d]\n" ,	\
	 			## arg, (int) (jiffies - i8042_start_time));	\
	} while (0)
#else
#define dbg_init() do { } while (0)
#define dbg(format, arg...) do {} while (0)
#endif

#endif /* _I8042_H */
