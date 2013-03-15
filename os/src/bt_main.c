/**
 *	This is the operating system main entry point, from where it will boot and load
 *	kernel modules.
 *
 *	Once all kernel modules are loaded and initialised, we shall look user application
 *	processes to be loaded.
 *
 **/

#include <bitthunder.h>
#include <mm/bt_heap.h>
#include <string.h>
#include <bt_kernel.h>

extern int main(int argc, char **argv);

struct _BT_OPAQUE_HANDLE {
	BT_HANDLE_HEADER h;
};

static void idle_task(void *pParam) {

	//BT_BOOL bState = BT_TRUE;
	BT_GpioSetDirection(7, BT_GPIO_DIR_OUTPUT);

	BT_TICK ticks = BT_kTickCount();
	BT_TICK ticks_a = ticks;

	while(1) {
		ticks_a = BT_kTickCount();
		BT_GpioSet(7, BT_TRUE);
		BT_kTaskDelayUntil(&ticks_a, 10);
		BT_GpioSet(7, BT_FALSE);
		BT_kTaskDelayUntil(&ticks_a, 50);
		BT_GpioSet(7, BT_TRUE);
		BT_kTaskDelayUntil(&ticks_a, 10);
		BT_GpioSet(7, BT_FALSE);

		BT_kTaskDelayUntil(&ticks, 1000);
	}

	BT_kTaskDelete(NULL);
}

/**
 *	@ Note: argc and argv may be used for kernel booting parameters at a later date.
 *
 *
 **/
int bt_main(int argc, char **argv) {

	BT_ERROR Error;

	// Get Machine Description.
	BT_MACHINE_DESCRIPTION *pMachine = BT_GetMachineDescription(&Error);
	if(pMachine->szpName) {
		Error = 0;
	}

	if (pMachine->pfnMachineInit) pMachine->pfnMachineInit(pMachine);

	BT_HANDLE hUart = NULL;

	if (pMachine->pBootLogger)
	{
		pDriver = BT_GetIntegratedDriverByName(pMachine->pBootLogger->name);
		if(pDriver) {
			hUart = pDriver->pfnProbe(pMachine->pBootLogger, &Error);
		}
	}

	BT_UART_CONFIG oConfig;
	//BT_SetPowerState(hUart, BT_POWER_STATE_AWAKE);

	oConfig.eMode 		= BT_UART_MODE_POLLED;
	oConfig.ucDataBits 	= 8;
	oConfig.ulBaudrate 	= 115200;

	BT_UartSetConfiguration(hUart, &oConfig);

	BT_UartEnable(hUart);

	char *string = BT_VERSION_STRING"\r\n";
	BT_CharDeviceWrite(hUart, 0, strlen(string), (BT_u8 *)string);

	string = "Start Loading kernel modules...\r\n";
	BT_CharDeviceWrite(hUart, 0, strlen(string), (BT_u8 *)string);

	string = "Initialise interrupt controller...\r\n";
	BT_CharDeviceWrite(hUart, 0, strlen(string), (BT_u8 *)string);


	BT_INTEGRATED_DRIVER *pDriver = BT_GetIntegratedDriverByName(pMachine->pInterruptController->name);
	if(pDriver) {
		pDriver->pfnProbe(pMachine->pInterruptController, &Error);
	}

	string = "Enumerate integrated devices\r\n";
	BT_CharDeviceWrite(hUart, 0, strlen(string), (BT_u8 *)string);


	// Go through the module initialisation routines!
	Error = BT_InitialiseKernelModules(hUart);


	Error = BT_ProbeIntegratedDevices(hUart);

	string = "Enter user-mode, and start user-space application...\r\n";
	BT_CharDeviceWrite(hUart, 0, strlen(string), (BT_u8 *)string);

	string = "Relinquish control of the boot UART device...(Goodbye)\r\n";
	BT_CharDeviceWrite(hUart, 0, strlen(string), (BT_u8 *)string);

	if (hUart)
	{
		BT_CloseHandle(hUart);
	}

	//int retval = main(argc, argv);

	BT_THREAD_CONFIG oThreadConfig = {
		.ulStackDepth 	= 128,
		.ulPriority		= 0,
	};

	BT_kTaskCreate(idle_task, "BT_IDLE", &oThreadConfig, &Error);
	BT_kTaskCreate((BT_FN_TASK_ENTRY) main, "MAIN", &oThreadConfig, &Error);

	BT_kStartScheduler();
	//vTaskStartScheduler();

	// Write a debug message to the debugger port,
	//	The main application has quit on us!

	return BT_ERR_NONE;
}
