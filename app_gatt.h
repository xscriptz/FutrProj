/******************************************************************************
 *  Copyright (c) 2014 - 2016 Qualcomm Technologies International, Ltd.
 *  Part of CSR uEnergy SDK 2.6.0
 *  Application version 2.6.0.0
 *
 *  FILE
 *      app_gatt.h
 *
 *  DESCRIPTION
 *      Header definitions for common application attributes
 *
 *
 ******************************************************************************/

#ifndef __APP_GATT_H__
#define __APP_GATT_H__


/*============================================================================*
 *  SDK Header Files
 *============================================================================*/
#include <bluetooth.h>
#include <bt_event_types.h>


/*============================================================================*
 *  SDK Header Files
 *============================================================================*/
#include "app_procedure_interface.h"

/*============================================================================*
 *  Public Data Types
 *============================================================================*/
/* Structure to store service UUID to which the device wants to connect. */
typedef struct
{
    GATT_UUID_T     uuid_type;      /* UUID type 16-bit or 128-bit */
    uint16          uuid[8];        /* UUID array */
}UUID_T;


/*============================================================================*
 *  Public Definitions
 *============================================================================*/

/* Invalid UCID indicating we are not currently connected */
#define GATT_INVALID_UCID                    (0xFFFF)

/* Invalid UUID */
#define GATT_INVALID_UUID                    (0x0000)

/* Invalid Attribute Handle */
#define INVALID_ATT_HANDLE                   (0x0000)

/* UUID for client configuration descriptor */
#define UUID_CLIENT_CHARACTERISTIC_CONFIGURATION_DESC \
                                            (0x2902)

/*============================================================================*
 *  Public Function Prototypes
 *============================================================================*/

/* This function returns the connection indentifier. */
extern uint16 GetConnectionIdentifier(void);

/* This function sets the temporary handle to the parameter value. */
extern void SetTempReadWriteHandle(uint16 handle);

/* This function the temporary handle which the application maintains 
 * while performing reads and writes.
 */
extern uint16 GetTempReadWriteHandle(void);

#endif /* __APP_GATT_H__ */

