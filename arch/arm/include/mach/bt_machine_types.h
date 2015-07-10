#ifndef _BT_MACHINE_TYPES_H_
#define _BT_MACHINE_TYPES_H_

typedef enum _BT_MACH_TYPE {
	BT_MACH_NONE=0,
	BT_MACH_CORTEX_M0=1,
	BT_MACH_CORTEX_M3=2,
	BT_MACH_ZYNQ=3,
	BT_MACH_BCM2835=4,
	BT_MACH_IMX=5,
} BT_MACH_TYPE;

#endif
