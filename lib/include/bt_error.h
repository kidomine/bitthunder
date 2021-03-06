#ifndef _BT_ERROR_H_
#define _BT_ERROR_H_

#include "bt_types.h"

#define BT_ERR_FLAG						0x80000000
#define BT_ERR_DEF_GLOBAL(x)			(x | BT_ERR_FLAG)

#define BT_ERR_NONE						0

#define BT_ERR_GENERIC					BT_ERR_DEF_GLOBAL(1)
#define BT_ERR_NULL_POINTER				BT_ERR_DEF_GLOBAL(2)
#define BT_ERR_NO_MEMORY 				BT_ERR_DEF_GLOBAL(3)
#define BT_ERR_UNIMPLEMENTED			BT_ERR_DEF_GLOBAL(4)
#define BT_ERR_INVALID_HANDLE			BT_ERR_DEF_GLOBAL(5)
#define BT_ERR_INVALID_HANDLE_TYPE		BT_ERR_DEF_GLOBAL(6)
#define BT_ERR_INVALID_RESOURCE			BT_ERR_DEF_GLOBAL(7)
#define BT_ERR_UNSUPPORTED_INTERFACE	BT_ERR_DEF_GLOBAL(8)
#define BT_ERR_UNSUPPORTED_FLAG			BT_ERR_DEF_GLOBAL(9)
#define BT_ERR_BUSY						BT_ERR_DEF_GLOBAL(10)
#define BT_ERR_INVALID_VALUE			BT_ERR_DEF_GLOBAL(11)
#define BT_ERR_NO_DATA					BT_ERR_DEF_GLOBAL(12)

#endif
