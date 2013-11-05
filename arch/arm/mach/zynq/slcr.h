/**
 *	ZYNQ System Level Control Register definitions.
 **/
#ifndef _SLCR_H_
#define _SLCR_H_

#include <bt_struct.h>						///< Provides a convenient reserved section macro.


typedef struct _ZYNQ_SLCR_REGS {
	BT_u32	SCL;
	BT_u32	SLCR_LOCK;
	BT_u32	SLCR_UNLOCK;
	BT_u32	SLCR_LOCKSTA;

#define ZYNQ_SLCR_PLL_LOCKSTA_LOCK_STATUS	0x00000001

	BT_STRUCT_RESERVED_u32(0, 0xC, 0x100);			// Reserves the section from 0xC to 0x100

	BT_u32	ARM_PLL_CTRL;
	BT_u32	DDR_PLL_CTRL;
	BT_u32	IO_PLL_CTRL;

#define ZYNQ_SLCR_PLL_CTRL_FDIV 			0x0003F000
#define ZYNQ_SLCR_PLL_CTRL_FDIV_VAL(x)		((x & ZYNQ_SLCR_PLL_CTRL_FDIV) >> 12)

#define ZYNQ_SLCR_PLL_CTRL_BYPASS_FORCE 	0x00000010
#define ZYNQ_SLCR_PLL_CTRL_BYPASS_QUAL 		0x00000008
#define ZYNQ_SLCR_PLL_CTRL_PWRDWN 			0x00000002
#define ZYNQ_SLCR_PLL_CTRL_RESET 			0x00000001

	BT_u32	PLL_STATUS;
	BT_u32	ARM_PLL_CONFIG;
	BT_u32	DDR_PLL_CONFIG;
	BT_u32	IO_PLL_CONFIG;

	BT_STRUCT_RESERVED_u32(1, 0x118, 0x120);		// Reserves the section from 0xC to 0x100

	BT_u32	ARM_CLK_CTRL;
	BT_u32	DDR_CLK_CTRL;
	BT_u32	DCI_CLK_CTRL;
	BT_u32	APER_CLK_CTRL;
	BT_u32	USB0_CLK_CTRL;
	BT_u32	USB1_CLK_CTRL;
	BT_u32	GEM0_RCLK_CTRL;
	BT_u32 	GEM1_RCLK_CTRL;
	BT_u32	GEM0_CLK_CTRL;
	BT_u32	GEM1_CLK_CTRL;
	BT_u32	SMC_CLK_CTRL;
	BT_u32	LQSPI_CLK_CTRL;
	BT_u32	SDIO_CLK_CTRL;
	BT_u32	UART_CLK_CTRL;
	BT_u32	SPI_CLK_CTRL;
	BT_u32	CAN_CLK_CTRL;
	BT_u32	CAN_MIOCLK_CTRL;
	BT_u32	DBG_CLK_CTRL;
	BT_u32	PCAP_CLK_CTRL;
	BT_u32	TOPSW_CLK_CTRL;
	BT_u32	FPGA0_CLK_CTRL;
	BT_STRUCT_RESERVED_u32(2, 0x170, 0x180);

	BT_u32	FPGA1_CLK_CTRL;
	BT_STRUCT_RESERVED_u32(3, 0x180, 0x190);

	BT_u32	FPGA2_CLK_CTRL;
	BT_STRUCT_RESERVED_u32(4, 0x190, 0x1A0);

	BT_u32	FPGA3_CLK_CTRL;

#define ZYNQ_SLCR_CLK_CTRL_CLKACT_0			0x00000001
#define ZYNQ_SLCR_CLK_CTRL_CLKACT_1			0x00000002
#define ZYNQ_SLCR_CLK_CTRL_DIVISOR 			0x00003F00
#define ZYNQ_SLCR_CLK_CTRL_DIVISOR_VAL(x) 	((x & ZYNQ_SLCR_CLK_CTRL_DIVISOR) >> 8)

#define ZYNQ_SLCR_CLK_CTRL_SRCSEL			0x00000030
#define ZYNQ_SLCR_CLK_CTRL_SRCSEL_VAL(x)	((x & ZYNQ_SLCR_CLK_CTRL_SRCSEL) >> 4)
#define ZYNQ_SLCR_CLK_CTRL_SRCSEL_IOPLL		0x0
#define ZYNQ_SLCR_CLK_CTRL_SRCSEL_ARMPLL	0x2
#define ZYNQ_SLCR_CLK_CTRL_SRCSEL_DDRPLL	0x3


	BT_STRUCT_RESERVED_u32(5, 0x1A0, 0x1C4);

	BT_u32	CLK_621_TRUE;

	BT_STRUCT_RESERVED_u32(6, 0x1C4, 0x200);

	BT_u32	PSS_RST_CTRL;
	BT_u32	DDR_RST_CTRL;
	BT_u32	TOPSW_RST_CTRL;
	BT_u32	DMAC_RST_CTRL;
	BT_u32	USB_RST_CTRL;
	BT_u32	GEM_RST_CTRL;
	BT_u32	SDIO_RST_CTRL;
	BT_u32	SPI_RST_CTRL;
	BT_u32	CAN_RST_CTRL;
	BT_u32	I2C_RST_CTRL;
	BT_u32	UART_RST_CTRL;
	BT_u32	GPIO_RST_CTRL;
	BT_u32	LQSPI_RST_CTRL;
	BT_u32	SMC_RST_CTRL;
	BT_u32	OCM_RST_CTRL;
	BT_u32	DEVCI_RST_CTRL;
	BT_u32	FPGA_RST_CTRL;
	BT_u32	A9_CPU_RST_CTRL;
	#define SLCR_A9_CPU_CLKSTOP	0x10
	#define SLCR_A9_CPU_RST		0x01

	BT_STRUCT_RESERVED_u32(7, 0x244, 0x24C);

	BT_u32	RS_AWDT_CTRL;

	BT_STRUCT_RESERVED_u32(8, 0x24C, 0x258);

	BT_u32	REBOOT_STATUS;
	BT_u32	BOOT_MODE;

#define ZYNQ_SLCR_BOOT_MODE_ARM_PLL_BYPASS 		0x00000010
#define ZYNQ_SLCR_BOOT_MODE_IO_PLL_BYPASS		0x00000010
#define ZYNQ_SLCR_BOOT_MODE_BOOT_MODE 			0x0000000F


	BT_STRUCT_RESERVED_u32(9, 0x25C, 0x300);

	BT_u32	APU_CTRL;
	BT_u32	WDT_CLK_SEL;

	BT_STRUCT_RESERVED_u32(10, 0x304, 0x530);

	BT_u32	PSS_IDCODE;

	BT_STRUCT_RESERVED_u32(11, 0x530, 0x600);

	BT_u32	DDR_URGENT;

	BT_STRUCT_RESERVED_u32(12, 0x600, 0x60C);

	BT_u32	DDR_CAL_START;

	BT_STRUCT_RESERVED_u32(13, 0x60C, 0x614);

	BT_u32	DDR_REF_START;
	BT_u32	DDR_CMD_STA;
	BT_u32	DDR_URGENT_SEL;
	BT_u32	DDR_DFI_STATUS;

	BT_STRUCT_RESERVED_u32(14, 0x620, 0x700);

	BT_u32	MIO_PIN_00;
	BT_u32	MIO_PIN_01;
	BT_u32	MIO_PIN_02;
	BT_u32	MIO_PIN_03;
	BT_u32	MIO_PIN_04;
	BT_u32	MIO_PIN_05;
	BT_u32	MIO_PIN_06;
	BT_u32	MIO_PIN_07;
	BT_u32	MIO_PIN_08;
	BT_u32	MIO_PIN_09;

	BT_u32	MIO_PIN_10;
	BT_u32	MIO_PIN_11;
	BT_u32	MIO_PIN_12;
	BT_u32	MIO_PIN_13;
	BT_u32	MIO_PIN_14;
	BT_u32	MIO_PIN_15;
	BT_u32	MIO_PIN_16;
	BT_u32	MIO_PIN_17;
	BT_u32	MIO_PIN_18;
	BT_u32	MIO_PIN_19;

	BT_u32	MIO_PIN_20;
	BT_u32	MIO_PIN_21;
	BT_u32	MIO_PIN_22;
	BT_u32	MIO_PIN_23;
	BT_u32	MIO_PIN_24;
	BT_u32	MIO_PIN_25;
	BT_u32	MIO_PIN_26;
	BT_u32	MIO_PIN_27;
	BT_u32	MIO_PIN_28;
	BT_u32	MIO_PIN_29;

	BT_u32	MIO_PIN_30;
	BT_u32	MIO_PIN_31;
	BT_u32	MIO_PIN_32;
	BT_u32	MIO_PIN_33;
	BT_u32	MIO_PIN_34;
	BT_u32	MIO_PIN_35;
	BT_u32	MIO_PIN_36;
	BT_u32	MIO_PIN_37;
	BT_u32	MIO_PIN_38;
	BT_u32	MIO_PIN_39;

	BT_u32	MIO_PIN_40;
	BT_u32	MIO_PIN_41;
	BT_u32	MIO_PIN_42;
	BT_u32	MIO_PIN_43;
	BT_u32	MIO_PIN_44;
	BT_u32	MIO_PIN_45;
	BT_u32	MIO_PIN_46;
	BT_u32	MIO_PIN_47;
	BT_u32	MIO_PIN_48;
	BT_u32	MIO_PIN_49;

	BT_u32	MIO_PIN_50;
	BT_u32	MIO_PIN_51;
	BT_u32	MIO_PIN_52;
	BT_u32	MIO_PIN_53;

	BT_STRUCT_RESERVED_u32(15, 0x7D4, 0x800);

	BT_u32	MIO_FMIO_GEM_SEL;
	BT_u32	MIO_LOOPBACK;

	BT_STRUCT_RESERVED_u32(16, 0x804, 0x80C);

	BT_u32	MIO_MST_TRI0;
	BT_u32	MIO_MST_TRI1;

	BT_STRUCT_RESERVED_u32(17, 0x810, 0x830);

	BT_u32	SD0_WP_CD_SEL;
	BT_u32	SD1_WP_CD_SEL;

	BT_STRUCT_RESERVED_u32(18, 0x834, 0x900);

	BT_u32	LVL_SHFTR_EN;

	BT_STRUCT_RESERVED_u32(19, 0x900, 0x910);

	BT_u32	OCM_CFG;

	BT_STRUCT_RESERVED_u32(20, 0x910, 0xB00);

	BT_u32	GPIOB_CTRL;
	BT_u32	GPIOB_CFG_CMOS18;
	BT_u32	GPIOB_CFG_CMOS25;
	BT_u32	GPIOB_CFG_CMOS33;
	BT_u32	GPIOB_CFG_LVTTL;
	BT_u32	GPIOB_CFG_HSTL;
	BT_u32	GPIOB_DRVR_BIAS_C_TRL;

	BT_STRUCT_RESERVED_u32(21, 0xB18, 0xB40);

	BT_u32	DDRIOB_ADDR0;
	BT_u32	DDRIOB_ADDR1;
	BT_u32	DDRIOB_DATA0;
	BT_u32	DDRIOB_DATA1;
	BT_u32	DDRIOB_DIFF0;
	BT_u32	DDRIOB_DIFF1;
	BT_u32	DDRIOB_CLOCK;
	BT_u32	DDRIOB_DRIVE_SLEW_ADDR;
	BT_u32	DDRIOB_DRIVE_SLEW_DATA;
	BT_u32	DDRIOB_DRIVER_SLEW_DIFF;
	BT_u32	DDRIOB_DRIVER_SLEW_CLOCK;
	BT_u32	DDRIOB_DDR_CTRL;
	BT_u32	DDRIOB_DCI_CTRL;
	BT_u32	DDRIOB_DCI_STATUS;

} ZYNQ_SLCR_REGS;


#define ZYNQ_SLCR_BASE	0xF8000000

#define	ZYNQ_SLCR	((volatile ZYNQ_SLCR_REGS *) ZYNQ_SLCR_BASE)


BT_u32 BT_ZYNQ_GetArmPLLFrequency();
BT_u32 BT_ZYNQ_GetIOPLLFrequency();
BT_u32 BT_ZYNQ_GetDDRPLLFrequency();

BT_u32 BT_ZYNQ_GetCpuFrequency();
BT_u32 BT_ZYNQ_GetCpu1xFrequency();

void zynq_slcr_unlock(volatile ZYNQ_SLCR_REGS *pRegs);
void zynq_slcr_lock(volatile ZYNQ_SLCR_REGS *pRegs);

void zynq_slcr_cpu_start(BT_u32 ulCoreID);
void zynq_slcr_cpu_stop(BT_u32 ulCoreID);

void zynq_slcr_preload_fpga(volatile ZYNQ_SLCR_REGS *pSLCR);
void zynq_slcr_postload_fpga(volatile ZYNQ_SLCR_REGS *pSLCR);

#endif
