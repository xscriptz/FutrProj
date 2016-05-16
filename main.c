/******************************************************************************
 *  FILE
 *      main.c
 *
 *  DESCRIPTION
 *      This file implements a minimal CSR uEnergy application.
 *
 ******************************************************************************/

/*============================================================================*
 *  SDK Header Files
 *============================================================================*/

#include <main.h>           /* Functions relating to powering up the device */
#include <ls_app_if.h>      /* Link Supervisor application interface */
#include <debug.h>          /* Simple host interface to the UART driver */


#include <gatt.h>
#include <gatt_prim.h>
#include <gatt_uuid.h>
#include <ls_app_if.h>
#include <gap_app_if.h>
#include <config_store.h>
/*============================================================================*
 *  Private Function Prototypes
 *============================================================================*/
#include "app_gatt.h"
#include "app_procedure_interface.h"

/* UART Receive callback */



typedef struct _APP_DATA_T
{
    /* Connected device address */
    TYPED_BD_ADDR_T           conn_address;

    /* GATT connection indentifier */
    uint16                    cid;

    /* HCI connection handle */
    hci_connection_handle_t   hciHandle;

    /* Stores if the device was bonded */
    bool                      bonded;

    /* Bonded device address */
    TYPED_BD_ADDR_T           bonded_address;

    /* Pairing Key information */
    SM_KEYSET_T               keys;

    /* New keys are requested. Set TRUE when the other device was previously
     * bonded, but has since changed its pairing data
     */
    bool                      requestNewKeys;

    /* Set TRUE to request re-pairing if the is bonded */
    bool                      encryptAgain;

    /* Application state for the connected device */

    /* Application timer ID */
   /* timer_id                   app_timer;*/

    /* Application bonding ID */
   /* timer_id                   bonding_timer; */

    /* Timer to control LEDs */
 /*   timer_id                   led_timer_tid; */

    /* Timer to track scan duration */
   /* timer_id                   scan_timer_tid; */

    /* Variabe to store the attribute handle value which is being 
     * written or read. 
     */
    uint16                     temp_handle;

    /* Application  preferred parameters */
    ble_con_params             pref_conn_param;
    
    /* Boolean flag to indicate whether the discovered handles are present in 
     * NVM or not
     */
    bool                       remote_gatt_handles_present;

} APP_DATA_T;


static void appGattSignalLmAdvertisingReport(
                    LM_EV_ADVERTISING_REPORT_T *p_event_data);

/*============================================================================*
 *  Private Function Implementations
 *============================================================================*/

/*----------------------------------------------------------------------------*
 *  NAME
 *      uartRxDataCallback
 *
 *  DESCRIPTION
 *      This is an internal callback function (of type uart_data_in_fn) that
 *      will be called by the UART driver when any data is received over UART.
 *      See DebugInit in the Firmware Library documentation for details.
 *
 *  PARAMETERS
 *      p_rx_buffer [in]   Pointer to the receive buffer (uint8 if 'unpacked'
 *                         or uint16 if 'packed' depending on the chosen UART
 *                         data mode - this application uses 'unpacked')
 *
 *      length [in]        Number of bytes ('unpacked') or words ('packed')
 *                         received
 *
 *      p_additional_req_data_length [out]
 *                         Number of additional bytes ('unpacked') or words
 *                         ('packed') this application wishes to receive
 *
 *  RETURNS
 *      The number of bytes ('unpacked') or words ('packed') that have been
 *      processed out of the available data.
 *----------------------------------------------------------------------------*/
/*static uint16 uartRxDataCallback(void   *p_rx_buffer,
                                 uint16  length,
                                 uint16 *p_additional_req_data_length)
{*/
    /* Inform the UART driver that we'd like to receive another byte when it
     * becomes available
     */
    /**p_additional_req_data_length = 1;*/
    
    /* Return the number of bytes that have been processed */
   /* return length;
}*/


/*static APP_DATA_T g_app_data;*/

/*============================================================================*
 *  Public Function Implementations
 *============================================================================*/

/*----------------------------------------------------------------------------*
 *  NAME
 *      AppPowerOnReset
 *
 *  DESCRIPTION
 *      This user application function is called just after a power-on reset
 *      (including after a firmware panic), or after a wakeup from Hibernate or
 *      Dormant sleep states.
 *
 *      At the time this function is called, the last sleep state is not yet
 *      known.
 *
 *      NOTE: this function should only contain code to be executed after a
 *      power-on reset or panic. Code that should also be executed after an
 *      HCI_RESET should instead be placed in the AppInit() function.
 *
 *  PARAMETERS
 *      None
 *
 *  RETURNS
 *      Nothing
 *----------------------------------------------------------------------------*/
void AppPowerOnReset(void)
{
    /* Code that is only executed after a power-on reset or firmware panic
     * should be implemented here - e.g. configuring application constants
     */
}



/*----------------------------------------------------------------------------*
 *  NAME
 *      appGattSignalLmAdvertisingReport
 *
 *  DESCRIPTION
 *      This function handles the advertising report.
 *
 *  RETURNS
 *      Nothing
 *----------------------------------------------------------------------------*/
static void appGattSignalLmAdvertisingReport(
                                       LM_EV_ADVERTISING_REPORT_T *p_event_data)
{
   /* bool        service_found = FALSE;*/
    uint16      adv_data[ADVSCAN_MAX_PAYLOAD] = {0};
    uint8       size = 0;
 /*   uint8       num_uuids = 0;
    uint8       num_uuid_found;
    TYPED_BD_ADDR_T device_address;*/

    /* Handle the event as per application state. */
        /* The application shall be entertained only in scanning state. It 
         * shall be ignored in any other state.
         */
       
            /* Extract advertisement data from the event data and see if the 
             * desired service UUID is present. We are interested only in 128 
             * bit UUIDs.
             */

            /* Check if the advertisement data contains any 128 bit UUID list */
            size = GapLsFindAdType(&p_event_data->data,
                               AD_TYPE_SERVICE_UUID_128BIT_LIST,
                               adv_data,
                               ADVSCAN_MAX_PAYLOAD);

            /*if(size != 0)
            { */
                /* Yes, it contains 128 bit UUID list.
                 * Calculate the total number of 128 bit long UUIDs.
                 */
              /* num_uuids = (size/SIZEOF_GATT_UUID128_IN_BYTES);*/

                /* Search for the required UUID one by one. */
               /* for(num_uuid_found = 0; 
                    num_uuid_found < num_uuids && !service_found;
                    num_uuid_found++)
                {
                    uint8 uuid_start_index = 0;
                    uuid_start_index = num_uuid_found * 
                                            (SIZEOF_GATT_UUID128_IN_BYTES / 2); */

                 /* Compare if the UUID is same as supported one. Advertisement 
                  * data is in LSB first order, compare accordingly.
                  */
                   /* if(adv_data[uuid_start_index++] == g_scan_uuids.uuid[7] &&
                       adv_data[uuid_start_index++] == g_scan_uuids.uuid[6] &&
                       adv_data[uuid_start_index++] == g_scan_uuids.uuid[5] &&
                       adv_data[uuid_start_index++] == g_scan_uuids.uuid[4] &&
                       adv_data[uuid_start_index++] == g_scan_uuids.uuid[3] &&
                       adv_data[uuid_start_index++] == g_scan_uuids.uuid[2] &&
                       adv_data[uuid_start_index++] == g_scan_uuids.uuid[1] &&
                       adv_data[uuid_start_index++] == g_scan_uuids.uuid[0])
                    {
                        service_found = TRUE;
                    }
                }
            }*/
            /*else
            {*/
              /* check if the advertisement data contains single 128 bit UUID */
                /*size = GapLsFindAdType(&p_event_data->data,
                                           AD_TYPE_SERVICE_UUID_128BIT,
                                           adv_data,
                                           ADVSCAN_MAX_PAYLOAD);*/

                /*if(size != 0)
                {*/
                    /* Yes it contains 128 bit UUID. */
                    /* Compare if the UUID is same as supported one. */
                    /*if(adv_data[0] == g_scan_uuids.uuid[7] &&
                       adv_data[1] == g_scan_uuids.uuid[6] &&
                       adv_data[2] == g_scan_uuids.uuid[5] &&
                       adv_data[3] == g_scan_uuids.uuid[4] &&
                       adv_data[4] == g_scan_uuids.uuid[3] &&
                       adv_data[5] == g_scan_uuids.uuid[2] &&
                       adv_data[6] == g_scan_uuids.uuid[1] &&
                       adv_data[7] == g_scan_uuids.uuid[0])
                    {
                        service_found = TRUE;
                    }

                }
                else
                {*/
                    /* No 128 bit service supported. */
                   /* service_found = FALSE;
                }
            }*/     

           /* if (service_found == TRUE)
            {*/
             /* Copy the advertising device address into the device structure */
              /*  MemCopy(&device_address.addr,
                        &p_event_data->data.address,
                        sizeof(BD_ADDR_T));
                device_address.type = p_event_data->data.address_type;*/

             /* Notify the application that a compatible device
              * has been found
              */
               /* DeviceFound(&device_address);
            }*/
        
        
}
/*----------------------------------------------------------------------------*
 *  NAME
 *      AppInit
 *
 *  DESCRIPTION
 *      This user application function is called after a power-on reset
 *      (including after a firmware panic), after a wakeup from Hibernate or
 *      Dormant sleep states, or after an HCI Reset has been requested.
 *
 *      NOTE: In the case of a power-on reset, this function is called
 *      after AppPowerOnReset().
 *
 *  PARAMETERS
 *      last_sleep_state [in]   Last sleep state
 *
 *  RETURNS
 *      Nothing
 *----------------------------------------------------------------------------*/
void AppInit(sleep_state last_sleep_state)
{
    /* Initialise communications */
GattInit();
GapSetMode(gap_role_central,
               gap_mode_discover_no,
               gap_mode_connect_no,
               gap_mode_bond_yes,
               gap_mode_security_none);
            GapSetScanType(ls_scan_type_active);
           
            LsStartStopScan(TRUE,
                    whitelist_disabled,
                    ls_addr_type_public); /* Scan using public address */


         
}

/*----------------------------------------------------------------------------*
 *  NAME
 *      AppProcesSystemEvent
 *
 *  DESCRIPTION
 *      This user application function is called whenever a system event, such
 *      as a battery low notification, is received by the system.
 *
 *  PARAMETERS
 *      id   [in]               System event ID
 *      data [in]               Event data
 *
 *  RETURNS
 *      Nothing
 *----------------------------------------------------------------------------*/
void AppProcessSystemEvent(sys_event_id id, void *data)
{
    /* This application does not process any system events */
}

/*----------------------------------------------------------------------------*
 *  NAME
 *      AppProcessLmEvent
 *
 *  DESCRIPTION
 *      This user application function is called whenever a LM-specific event
 *      is received by the system.
 *
 *  PARAMETERS
 *      event_code [in]         LM event ID
 *      p_event_data [in]       LM event data
 *
 *  RETURNS
 *      Always returns TRUE. See the Application module in the Firmware Library
 *      documentation for more information.
 *----------------------------------------------------------------------------*/
bool AppProcessLmEvent(lm_event_code event_code, LM_EVENT_T *p_event_data)
{
    /* This application does not process any LM-specific events */
    switch (event_code)
    {
        
        case LM_EV_ADVERTISING_REPORT:
        {
            /* This event is raised when an advertisement or scan response is
             * received
             */
            appGattSignalLmAdvertisingReport(
                                    (LM_EV_ADVERTISING_REPORT_T *)p_event_data);
        }
        break;


        default:
        break;
    }
    return TRUE;

}
