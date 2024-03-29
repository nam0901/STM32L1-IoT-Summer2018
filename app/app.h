/**
 ******************************************************************************
 * @author: ThanNT
 * @date:   13/08/2016
 ******************************************************************************
**/

#ifndef __APP_H__
#define __APP_H__

#ifdef __cplusplus
extern "C"
{
#endif
#include "ak.h"

#include "nrf_nwk_sig.h"

#include "app_if.h"
#include "app_eeprom.h"
#include "app_data.h"

/*****************************************************************************/
/* FIRMWARE task define
 */
/*****************************************************************************/
/* define timer */
#define FW_PACKED_TIMEOUT_INTERVAL			(5000)
#define FW_CHECKING_INTERVAL				(500)

/* define signal */
enum {
	FW_CRENT_APP_FW_INFO_REQ = AK_USER_DEFINE_SIG,
	FW_CRENT_BOOT_FW_INFO_REQ,
	FW_UPDATE_REQ,
	FW_UPDATE_SM_OK,
	FW_TRANSFER_REQ,
	FW_INTERNAL_UPDATE_APP_RES_OK,
	FW_INTERNAL_UPDATE_BOOT_RES_OK,
	FW_SAFE_MODE_RES_OK,
	FW_UPDATE_SM_BUSY,
	FW_PACKED_TIMEOUT,
	FW_CHECKING_REQ
};

/*****************************************************************************/
/*  LIFE task define
 */
/*****************************************************************************/
/* define timer */
#define AC_LIFE_TASK_TIMER_LED_LIFE_INTERVAL		(1000)

/* define signal */
enum {
	AC_LIFE_SYSTEM_CHECK = AK_USER_DEFINE_SIG,
};

/*****************************************************************************/
/*  SHELL task define
 */
/*****************************************************************************/
/* define timer */

/* define signal */
enum {
	AC_SHELL_LOGIN_CMD = AK_USER_DEFINE_SIG,
	AC_SHELL_REMOTE_CMD,
};

/*****************************************************************************/
/*  RF24 task define
 */
/*****************************************************************************/
/* private define */
/* define timer */
/* define signal */
enum {
	AC_RF24_IF_INIT_NETWORK = AK_USER_DEFINE_SIG,
	AC_RF24_IF_PURE_MSG_OUT,
	AC_RF24_IF_COMMON_MSG_OUT,
	AC_RF24_IF_PURE_MSG_IN,
	AC_RF24_IF_COMMON_MSG_IN,
};

/*****************************************************************************/
/* IF task define
 */
/*****************************************************************************/
/* define timer */
#define AC_IF_TIMER_PACKET_TIMEOUT_INTERVAL			(500)

/* define signal */
enum {
	AC_IF_PURE_MSG_IN = AK_USER_DEFINE_SIG,
	AC_IF_PURE_MSG_OUT,
	AC_IF_COMMON_MSG_IN,
	AC_IF_COMMON_MSG_OUT,
	AC_IF_DYNAMIC_MSG_IN,
	AC_IF_DYNAMIC_MSG_OUT,
};

/*****************************************************************************/
/* UART_IF task define
 */
/*****************************************************************************/
/* timer signal */
/* define signal */

enum {
	AC_UART_IF_INIT = AK_USER_DEFINE_SIG,
	AC_UART_IF_PURE_MSG_OUT,
	AC_UART_IF_COMMON_MSG_OUT,
	AC_UART_IF_DYNAMIC_MSG_OUT,
	AC_UART_IF_PURE_MSG_IN,
	AC_UART_IF_COMMON_MSG_IN,
	AC_UART_IF_DYNAMIC_MSG_IN,
};
/*****************************************************************************/
/*  Tetris group task define
 */
/*****************************************************************************/

/* Task TETRIS_SM */
/* define signal */
enum
{
	GAME_SM_INIT_REQ = AK_USER_DEFINE_SIG,
	GAME_SM_INIT_RES_OK,
	GAME_SM_INIT_RES_ERR,
	GAME_SM_START_GAME_REQ,
	GAME_SM_START_GAME_RES_OK,
	GAME_SM_START_GAME_RES_ERR,
	INPUT_SM_BUTTON_MODE_PRESSED,
	INPUT_SM_BUTTON_MODE_RELEASED,
	INPUT_SM_BUTTON_LEFT_PRESSED,
	INPUT_SM_BUTTON_LEFT_RELEASED,
	INPUT_SM_BUTTON_RIGHT_PRESSED,
	INPUT_SM_BUTTON_RIGHT_RELEASED,
	GAME_SM_CONTROL_ON_TIME,
	GAME_SM_CONTROL_TIME_OUT,
	GAME_SM_GAME_OVER
};

/* Task TETRIS_GC */
/* define signal */
enum
{
	TETRIS_GC_INIT_REQ = AK_USER_DEFINE_SIG,
	TETRIS_GC_START_GAME_REQ,
	TETRIS_GC_GO_LEFT,
	TETRIS_GC_GO_RIGHT,
	TETRIS_GC_ROTATE,
	TETRIS_GC_GO_DOWN,
};

/* Task TETRIS_UI */
/* define signal */
enum
{
	TETRIS_UI_INIT_REQ,
	TETRIS_UI_GAME_START,
	TETRIS_UI_UPDATE,
	TETRIS_UI_GAME_OVER
};

/*****************************************************************************/
/*  LIFE task define
 */
/*****************************************************************************/
///* define timer */
//#define AC_DISPLAY_LOGO_INTERVAL			(10000)

///* define signal */
//enum {
//	AC_DISPLAY_INITIAL = AK_USER_DEFINE_SIG,
//	AC_DISPLAY_SHOW_ON_LOGO,
//	AC_DISPLAY_SHOW_OFF,
//};

/*****************************************************************************/
/* DBG task define
 */
/*****************************************************************************/
/* define timer */
/* define signal */
enum {
	AC_DBG_TEST_1 = AK_USER_DEFINE_SIG,
	AC_DBG_TEST_2,
	AC_DBG_TEST_3,
	AC_DBG_TEST_4,
	AC_DBG_TEST_5,
	AC_DBG_TEST_6,
	AC_DBG_TEST_7,
};

/*****************************************************************************/
/*  global define variable
 */
/*****************************************************************************/
#define APP_OK									(0x00)
#define APP_NG									(0x01)

#define APP_FLAG_OFF							(0x00)
#define APP_FLAG_ON								(0x01)

/*****************************************************************************/
/*  app function declare
 */
/*****************************************************************************/
#define APP_MAGIC_NUMBER	0xAABBCCDD
#define APP_VER				{0, 0, 0, 1}

typedef struct {
	uint32_t magic_number;
	uint8_t version[4];
} app_info_t;

extern const app_info_t app_info;

extern void* app_get_boot_share_data();
extern int  main_app();

#ifdef __cplusplus
}
#endif

#endif //__APP_H__
