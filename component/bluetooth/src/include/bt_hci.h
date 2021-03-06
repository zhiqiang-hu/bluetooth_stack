/******************************************************************************
  * @file           bt_hci.h
  * @author         Yu-ZhongJun(124756828@qq.com)
  * @Taobao link    https://shop220811498.taobao.com/
  * @version        V0.0.1
  * @date           2020-4-15
  * @brief          bt hci header file
******************************************************************************/

#ifndef BT_HCI_H_H_H
#define BT_HCI_H_H_H


#include "bt_common.h"
#include "bt_pbuf.h"
#include "bt_vendor_manager.h"

struct hci_pcb_t;
struct hci_link_t;
struct hci_inq_res_t;

#define HCI_RESET_TIMEOUT	10


#define HCI_EVENT_HDR_LEN 2
#define HCI_ACL_HDR_LEN 4
#define HCI_SCO_HDR_LEN 3
#define HCI_CMD_HDR_LEN 3

/* Opcode Group Field (OGF) values */
#define HCI_LINK_CONTROL 0x01   /* Link Control Commands */
#define HCI_LINK_POLICY 0x02    /* Link Policy Commands */
#define HCI_HOST_C_N_BB 0x03    /* Host Controller & Baseband Commands */
#define HCI_INFO_PARAM 0x04     /* Informational Parameters */
#define HCI_STATUS_PARAM 0x05   /* Status Parameters */
#define HCI_TESTING 0x06        /* Testing Commands */
#define HCI_LE	0x08 /* BLE cmd */
#define HCI_VENDOR_OGF 0x3F /* vendor Commands */

/* Opcode Command Field (OCF) values */
/* Link control commands */
#define HCI_INQUIRY 0x01
#define HCI_INQUIRY_CANCEL 0x02
#define HCI_PERIODIC_INQUIRY 0x03
#define HCI_EXIT_PERIODIC_INQUIRY 0x04
#define HCI_CREATE_CONNECTION 0x05
#define HCI_DISCONNECT 0x06
#define HCI_CREATE_CON_CANCEL 0x08
#define HCI_ACCEPT_CONNECTION_REQUEST 0x09
#define HCI_REJECT_CONNECTION_REQUEST 0x0A
#define HCI_LINKKEY_REQ_REPLY 0x0B
#define HCI_LINKKEY_REQ_NEG_REPLY 0x0C
#define HCI_PIN_CODE_REQ_REP 0x0D
#define HCI_PIN_CODE_REQ_NEG_REP 0x0E
#define HCI_CHANGE_CON_PTYPE 0x0F
#define HCI_AUTH_REQ 0x11
#define HCI_SET_CONN_ENCRYPT 0x13
#define HCI_CHANGE_CON_LINKKEY 0x15
#define HCI_MASTER_LINKKEY 0x17
#define HCI_REMOTE_NAME_REQ 0x19
#define HCI_REMOTE_NAME_REQ_CANCEL 0x1A
#define HCI_READ_REMOTE_SUPPORT_FEATURE 0x1B
#define HCI_READ_REMOTE_EXR_FEATURE 0x1C
#define HCI_READ_REMOTE_VER_INFO 0x1D
#define HCI_READ_CLK_OFFSET 0x1F
#define HCI_READ_LMP_HANDLE 0x20
#define HCI_CONNECT_SCO_REQ 0x28
#define HCI_ACCEP_SCO_REQ 0x29
#define HCI_REJECT_SCO_REQ 0x2A
#define HCI_IOCAP_REQ_REPLY 0x2B
#define HCI_USER_CONFIRM_REQ_REPLY 0x2C
#define HCI_USER_CONFIRM_REQ_NEG_REPLY 0x2D
#define HCI_USER_PASSKEY_REQ_REPLY 0x2E
#define HCI_USER_PASSKEY_REQ_NEG_REPLY 0x2F
#define HCI_REMOTE_OOB_REQ_REPLY 0x30
#define HCI_REMOTE_OOB_REQ_NEG_REPLY 0x33
#define HCI_IOCAP_REQ_NEG_REPLY 0x34

/* Link Policy commands */
#define HCI_HOLD_MODE 0x01
#define HCI_SNIFF_MODE 0x03
#define HCI_EXIT_SNIFF_MODE 0x04
#define HCI_PARK_MODE 0x05
#define HCI_EXIT_PARK_MODE 0x06
#define HCI_QOS_SETUP 0x07
#define HCI_ROLE_DISCOVERY 0x09
#define HCI_SWITCH_ROLE 0x0B
#define HCI_R_LINK_POLICY 0x0C
#define HCI_W_LINK_POLICY 0x0D
#define HCI_R_DEFAULT_LINK_POLICY 0x0E
#define HCI_W_DEFAULT_LINK_POLICY 0x0F
#define HCI_FLOW_SPEC 0x10
#define HCI_SNIFF_SUBRATING 0x11

/* Host-Controller and Baseband Commands */
#define HCI_SET_EVENT_MASK 0x01
#define HCI_RESET 0x03
#define HCI_SET_EVENT_FILTER 0x05
#define HCI_FLUSH 0x08
#define HCI_READ_PINCODE_TYPE 0x09
#define HCI_WRITE_PINCODE_TYPE 0x0A
#define HCI_READ_STORED_LINK_KEY 0x0D
#define HCI_WRITE_STORED_LINK_KEY 0x11
#define HCI_DELETE_STORED_LINK_KEY 0x12
#define HCI_WRITE_LOCAL_NAME 0x13
#define HCI_READ_LOCAL_NAME 0x14
#define HCI_READ_CONN_ACCEPT_TIMEOUT 0x15
#define HCI_WRITE_CONN_ACCEPT_TIMEOUT 0x16
#define HCI_READ_PAGE_TIMEOUT 0x17
#define HCI_WRITE_PAGE_TIMEOUT 0x18
#define HCI_READ_SCAN_ENABLE 0x19
#define HCI_WRITE_SCAN_ENABLE 0x1A
#define HCI_READ_PAGE_SCAN_ACTIVITY 0x1B
#define HCI_WRITE_PAGE_SCAN_ACTIVITY 0x1C
#define HCI_READ_INQ_SCAN_ACTIVITY 0x1D
#define HCI_WRITE_INQ_SCAN_ACTIVITY 0x1E
#define HCI_READ_AUTH_ENABLE 0x1F
#define HCI_WRITE_AUTH_ENABLE 0x20
#define HCI_READ_COD 0x23
#define HCI_WRITE_COD 0x24
#define HCI_READ_VOICE_SETTING 0x25
#define HCI_WRITE_VOICE_SETTING 0x26
#define HCI_READ_AUTO_FLUSH_TIMEOUT 0x27
#define HCI_WRITE_FLUSHTO 0x28
#define HCI_READ_NUM_BROADCAST_RETRA 0x29
#define HCI_WRITE_NUM_BROADCAST_RETRA 0x2A
#define HCI_READ_HOLD_MODE_ACTIVITY 0x2B
#define HCI_WRITE_HOLD_MODE_ACTIVITY 0x2C
#define HCI_READ_TRANSMIT_POWER_LEVEL 0x2D
#define HCI_READ_SCO_FLOW_CONTROL_ENABLE 0x2E
#define HCI_WRITE_SCO_FLOW_CONTROL_ENABLE 0x2F
#define HCI_SET_HC_TO_H_FC 0x31
#define HCI_HOST_BUFF_SIZE 0x33
#define HCI_HOST_NUM_COMPL 0x35
#define HCI_READ_LINK_SUPERVISION_TIMEOUT 0x36
#define HCI_WRITE_LINK_SUPERVISION_TIMEOUT 0x37
#define HCI_READ_NUM_SUPPORT_IAC 0x38
#define HCI_READ_CURRENT_IAC 0x39
#define HCI_WRITE_CURRENT_IAC 0x3A
#define HCI_SET_AFG_HOST_CHANNEL_CLASSIFICATION 0x3F
#define HCI_READ_INQUIRY_SCAN_TYPE 0x42
#define HCI_WRITE_INQUIRY_SCAN_TYPE 0x43
#define HCI_READ_INQUIRY_MODE 0x44
#define HCI_WRITE_INQUIRY_MODE 0x45
#define HCI_READ_PAGE_SCAN_MODE 0x46
#define HCI_WRITE_PAGE_SCAN_MODE 0x47
#define HCI_READ_EIR 0x51
#define HCI_WRITE_EIR 0x52
#define HCI_WRITE_SSP_MODE 0x56
#define HCI_READ_LE_SUPPORT 0x6C
#define HCI_WRITE_LE_SUPPORT 0x6D

/* Informational Parameters */
#define HCI_READ_LOCAL_VER_INFO 0x01
#define HCI_READ_LOCAL_SUPPORT_CMD 0x02
#define HCI_RAED_LOCAL_SUPPORT_FEATURE 0x03
#define HCI_READ_LOCAL_EXTEND_FEATURE 0x04
#define HCI_READ_BUFFER_SIZE 0x05
#define HCI_READ_BD_ADDR 0x09
#define HCI_READ_DATA_BLOCK_SIZE  0x0A

/* Status Parameters */
#define HCI_READ_FAILED_CONTACT_COUNTER 0x01
#define HCI_RESET_FAILED_CONTACT_COUNTER 0x02
#define HCI_READ_LINK_QUALITY 0x03
#define HCI_READ_RSSI 0x05
#define HCI_READ_AFH_CHANNEL_MAP 0x06
#define HCI_READ_CLOCK 0x07
#define HCI_READ_ENC_KEY_SIZE 0x08
#define HCI_READ_LOCAL_AMP_INFO 0x09
#define HCI_READ_LOCAL_AMP_ASSOC 0x0A
#define HCI_WRITE_LOCAL_AMP_ASSOC 0x0B

/* Testing commands */
#define HCI_READ_LOOPBACK_MODE 0x01
#define HCI_WRITE_LOOPBACK_MODE 0x02
#define HCI_ENABLE_DUT_MODE 0x03
#define HCI_WRITE_SP_DEBUG_MODE 0x04
#define HCI_ENABLE_AMP_REV_REPORT 0x07
#define HCI_AMP_TEST_END 0x08
#define HCI_AMP_TEST 0x09
#define HCI_WRITE_S_CONN_TEST_MODE 0x0A


/* LE commands */
#define HCI_SET_SCAN_PARAM 0x0b
#define HCI_SET_SCAN 0x0c


/* Possible event codes */
#define HCI_INQUIRY_COMPLETE 0x01
#define HCI_INQUIRY_RESULT 0x02
#define HCI_CONNECTION_COMPLETE 0x03
#define HCI_CONNECTION_REQUEST 0x04
#define HCI_DISCONNECTION_COMPLETE 0x05
#define HCI_AUTH_COMPLETE 0x06
#define HCI_GET_REMOTE_NAME_COMPLETE 0x07
#define HCI_ENCRYPTION_CHANGE 0x08
#define HCI_CHANGE_CONN_LINKKEY_COMPLETE 0x09
#define HCI_MASTER_LINKKEY_COMPLETE 0x0A
#define HCI_READ_REMOTE_SUPPORT_FEATURE_COMPLETE 0x0B
#define HCI_READ_REMOTE_VERSION_INFO_COMPLETE 0x0C
#define HCI_QOS_SETUP_COMPLETE 0x0D
#define HCI_COMMAND_COMPLETE 0x0E
#define HCI_COMMAND_STATUS 0x0F
#define HCI_HARDWARE_ERROR 0x10
#define HCI_FLUSH_OCCURRED 0x11
#define HCI_ROLE_CHANGE 0x12
#define HCI_NBR_OF_COMPLETED_PACKETS 0x13
#define HCI_MODE_CHANGE 0x14
#define HCI_RETURN_LINKKEY 0x15
#define HCI_PIN_CODE_REQUEST 0x16
#define HCI_LINK_KEY_REQUEST 0x17
#define HCI_LINK_KEY_NOTIFICATION 0x18
#define HCI_LOOPBACK 0x19
#define HCI_DATA_BUFFER_OVERFLOW 0x1A
#define HCI_MAX_SLOTS_CHANGE 0x1B
#define HCI_READ_CLK_OFFSET_COMPLETE 0x1C
#define HCI_CONN_PACK_TYPE_CHANGE 0x1D
#define HCI_QOS_VIOLATION 0x1E
#define HCI_PS_REPETITION_MODE_CHANGE 0x20
#define HCI_FLOW_SPEC_COMPLETE 0x21
#define HCI_INQ_RESULT_RSSI 0x22
#define HCI_READ_REMOTE_EXT_FEATURE_COMPLETE 0x23
#define HCI_SCO_CONNECTION_COMPLETE 0x2C
#define HCI_SCO_CONN_CHANGE 0x2D
#define HCI_EVT_SNIFF_SUBRATING 0x2E
#define HCI_EXT_INQ_RESULT 0x2F
#define HCI_ENC_KEY_REFRESH_COMPLETE 0x30
#define HCI_IO_CAP_REQ 0x31
#define HCI_IO_CAP_RESPONSE 0x32
#define HCI_USER_CONF_REQ 0x33
#define HCI_USER_PASSKEY_REQ 0x34
#define HCI_REMOTE_OOB_DATA_REQ 0x35
#define HCI_SP_COMPLETE 0x36
#define HCI_LINK_SUPERVISION_TIMEOUT_CHANGE 0x38
#define HCI_EFLUSH_COMPLETE 0x39
#define HCI_USER_PASSKEY_NOTIFICATION 0x3B
#define HCI_KEYPRESS_NOTIFICATION 0x3C
#define HCI_REMOTE_HOST_SUPPORT_FEATURE_NOTIFICATION 0x3D
#define HCI_LE_META 0x3e
#define HCI_VENDOR_SPEC 0xFF

/* Success code */
#define HCI_SUCCESS 0x00
/* Possible error codes */
#define HCI_UNKNOWN_HCI_COMMAND 0x01
#define HCI_NO_CONNECTION 0x02
#define HCI_HW_FAILURE 0x03
#define HCI_PAGE_TIMEOUT 0x04
#define HCI_AUTHENTICATION_FAILURE 0x05
#define HCI_KEY_MISSING 0x06
#define HCI_MEMORY_FULL 0x07
#define HCI_CONN_TIMEOUT 0x08
#define HCI_MAX_NUMBER_OF_CONNECTIONS 0x09
#define HCI_MAX_NUMBER_OF_SCO_CONNECTIONS_TO_DEVICE 0x0A
#define HCI_ACL_CONNECTION_EXISTS 0x0B
#define HCI_COMMAND_DISSALLOWED 0x0C
#define HCI_HOST_REJECTED_DUE_TO_LIMITED_RESOURCES 0x0D
#define HCI_HOST_REJECTED_DUE_TO_SECURITY_REASONS 0x0E
#define HCI_HOST_REJECTED_DUE_TO_REMOTE_DEVICE_ONLY_PERSONAL_SERVICE 0x0F
#define HCI_HOST_TIMEOUT 0x10
#define HCI_UNSUPPORTED_FEATURE_OR_PARAMETER_VALUE 0x11
#define HCI_INVALID_HCI_COMMAND_PARAMETERS 0x12
#define HCI_OTHER_END_TERMINATED_CONN_USER_ENDED 0x13
#define HCI_OTHER_END_TERMINATED_CONN_LOW_RESOURCES 0x14
#define HCI_OTHER_END_TERMINATED_CONN_ABOUT_TO_POWER_OFF 0x15
#define HCI_CONN_TERMINATED_BY_LOCAL_HOST 0x16
#define HCI_REPETED_ATTEMPTS 0x17
#define HCI_PAIRING_NOT_ALLOWED 0x18
#define HCI_UNKNOWN_LMP_PDU 0x19
#define HCI_UNSUPPORTED_REMOTE_FEATURE 0x1A
#define HCI_SCO_OFFSET_REJECTED 0x1B
#define HCI_SCO_INTERVAL_REJECTED 0x1C
#define HCI_SCO_AIR_MODE_REJECTED 0x1D
#define HCI_INVALID_LMP_PARAMETERS 0x1E
#define HCI_UNSPECIFIED_ERROR 0x1F
#define HCI_UNSUPPORTED_LMP_PARAMETER_VALUE 0x20
#define HCI_ROLE_CHANGE_NOT_ALLOWED 0x21
#define HCI_LMP_RESPONSE_TIMEOUT 0x22
#define HCI_LMP_ERROR_TRANSACTION_COLLISION 0x23
#define HCI_LMP_PDU_NOT_ALLOWED 0x24
#define HCI_ENCRYPTION_MODE_NOT_ACCEPTABLE 0x25
#define HCI_UNIT_KEY_USED 0x26
#define HCI_QOS_NOT_SUPPORTED 0x27
#define HCI_INSTANT_PASSED 0x28
#define HCI_PAIRING_UNIT_KEY_NOT_SUPPORTED 0x29

/* Specification specific parameters */
#define HCI_BD_ADDR_LEN 6
#define HCI_LMP_FEATURES_LEN 8
#define HCI_LINK_KEY_LEN 16
#define HCI_LMP_FEAT_LEN 8

/* Command packet length (including ACL header)*/
#define HCI_INQUIRY_PLEN 8
#define  HCI_CANCEL_INQUIRY_PLEN 3
#define HCI_PERIDIC_INQUIRY 12
#define HCI_CANCEL_PERIDIC_INQYIRY 3
#define HCI_CREATE_CONN_PLEN 16
#define HCI_DISCONN_PLEN 6
#define HCI_ACCEPT_CON_REQ_PLEN 10
#define HCI_REJECT_CONN_REQ_PLEN 10
#define HCI_LINK_KEY_REQ_REPLAY_PLEN 25
#define HCI_LINK_KEY_REQ_NG_REPLAY_PLEN 9
#define HCI_PIN_CODE_REQ_REP_PLEN 26
#define HCI_PIN_CODE_REQ_NEG_REP_PLEN 9
#define HCI_GET_REMOTE_NAME_PLEN 13
#define HCI_CANCEL_GET_REMOTE_NAME_PLEN 9
#define HCI_GET_REMOTE_FEATURE_PLEN 5
#define HCI_CONNECT_SCO_REQ_PLEN 20
#define HCI_ACCEPT_SCO_REQ_PLEN 24
#define HCI_REJECT_SCO_REQ_PLEN 10
#define HCI_IOCAP_REQ_REPLY_PLEN 12
#define HCI_USER_CONFIRM_REQ_REPLY_PLEN 9
#define HCI_USER_CONFIRM_REQ_NEG_REPLY_PLEN 9
#define HCI_USER_PASSKEY_REQ_REPLY_PLEN 13
#define HCI_USER_PASSKEY_REQ_NEG_REPLY_PLEN 9
#define HCI_IOCAP_REQ_NEG_REPLY_PLEN 10
#define HCI_SET_CONN_ENCRYPT_PLEN 6
#define HCI_WRITE_STORED_LINK_KEY_PLEN 26
#define HCI_CHANGE_LOCAL_NAME_PLEN 251
#define HCI_READ_LOCAL_NAME_PLEN 3
#define HCI_SET_EV_MASK_PLEN 11
#define HCI_HOLD_PLEN 9
#define HCI_SNIFF_PLEN 13
#define HCI_EXIT_SNIFF_PLEN 5
#define HCI_ROLE_DISCOVERY_PLEN 5
#define HCI_SWITCH_ROLE_PLEN 10
#define HCI_R_LINK_POLICY_PLEN 5
#define HCI_W_LINK_POLICY_PLEN 7
#define HCI_R_DEFAULT_LINK_POLICY_PLEN 3
#define HCI_W_DEFAULT_LINK_POLICY_PLEN 5
#define HCI_SET_EVENT_MASK_PLEN 11
#define HCI_RESET_PLEN 3
#define HCI_SET_EV_FILTER_PLEN 5
#define HCI_W_PAGE_TIMEOUT_PLEN 5
#define HCI_W_SCAN_EN_PLEN 4
#define HCI_R_COD_PLEN 3
#define HCI_W_COD_PLEN 6
#define HCI_R_VOICE_SETTING_PLEN 3
#define HCI_W_VOICE_SETTING_PLEN 5
#define HCI_W_FLUSHTO_PLEN 6
#define HCI_SET_HC_TO_H_FC_PLEN 4
#define HCI_WRITE_EIR_PLEN 244
#define HCI_WRITE_SSP_MODE_PLEN 4
#define HCI_WRITE_LE_SUPPORT_PLEN 5
#define HCI_SET_LE_SCAN_PLEN 5
#define HCI_SET_LE_SCAN_PARAM_PLEN 10
#define HCI_H_BUF_SIZE_PLEN 6
#define HCI_H_NUM_COMPL_PLEN 6
#define HCI_R_LOCOL_VER_INFO_PLEN 3
#define HCI_R_BUF_SIZE_PLEN 3
#define HCI_R_BD_ADDR_PLEN 3
#define HCI_READ_RSSI_PLEN 5
#define HCI_ENABLE_DUT_PLEN 3


/* Set Event Filter params */
#define HCI_SET_EV_FILTER_CLEAR 0
#define HCI_SET_EV_FILTER_INQUIRY 1
#define HCI_SET_EV_FILTER_CONNECTION 2

#define HCI_SET_EV_FILTER_ALLDEV 0
#define HCI_SET_EV_FILTER_COD 1
#define HCI_SET_EV_FILTER_BDADDR 2

#define HCI_SET_EV_FILTER_AUTOACC_OFF 1
#define HCI_SET_EV_FILTER_AUTOACC_NOROLESW 2
#define HCI_SET_EV_FILTER_AUTOACC_ROLESW 3

/* Write Scan Enable params */
#define HCI_SCAN_EN_INQUIRY 1
#define HCI_SCAN_EN_PAGE 2


#define hci_num_cmd(pcb) ((pcb)->numcmd)
#define hci_num_acl(pcb) ((pcb)->hc_num_acl)
#define hci_maxsize(pcb) ((pcb)->maxsize)


#define IO_CAP_DISPLAY_ONLY 0x00
#define IO_CAP_DISPLAY_YES_NO 0x01
#define IO_CAP_KEYBOARD_ONLY 0x02
#define IO_CAP_NOINPUT_OUTPUT 0x03

/**
 * SSP Authentication Requirements, see IO Capability Request Reply Commmand 
 */

// Numeric comparison with automatic accept allowed.
#define SSP_IO_AUTHREQ_MITM_PROTECTION_NOT_REQUIRED_NO_BONDING 0x00

// Use IO Capabilities to deter- mine authentication procedure
#define SSP_IO_AUTHREQ_MITM_PROTECTION_REQUIRED_NO_BONDING 0x01

// Numeric compar- ison with automatic accept allowed.
#define SSP_IO_AUTHREQ_MITM_PROTECTION_NOT_REQUIRED_DEDICATED_BONDING 0x02

// Use IO Capabilities to determine authentication procedure
#define SSP_IO_AUTHREQ_MITM_PROTECTION_REQUIRED_DEDICATED_BONDING 0x03

// Numeric Compari- son with automatic accept allowed.
#define SSP_IO_AUTHREQ_MITM_PROTECTION_NOT_REQUIRED_GENERAL_BONDING 0x04

// Use IO capabilities to determine authentication procedure.
#define SSP_IO_AUTHREQ_MITM_PROTECTION_REQUIRED_GENERAL_BONDING 0x05



struct hci_event_hdr_t
{
    uint8_t code; /* Event code */
    uint8_t len;  /* Parameter total length */
} BT_PACK_END;

struct hci_acl_hdr_t
{
    uint16_t conhdl_pb_bc; /* Connection handle, packet boundary and broadcast flag
			 flag */
    uint16_t len; /* length of data */
} BT_PACK_END;

struct hci_inq_res_t
{
    struct hci_inq_res_t *next; /* For the linked list */

    struct bd_addr_t bdaddr; /* Bluetooth address of a device found in an inquiry */
    uint8_t cod[3]; /* Class of the remote device */
    uint8_t psrm; /* Page scan repetition mode */
    uint8_t psm; /* Page scan mode */
    uint16_t co; /* Clock offset */
};

/**
 * Connection State
 */
typedef enum
{
    SEND_CREATE_CONNECTION = 0,
    SEND_CANCEL_CONNECTION,
    RECEIVED_CONNECTION_REQUEST,
    ACCEPTED_CONNECTION_REQUEST,
    REJECTED_CONNECTION_REQUEST,
    OPEN,
    SEND_DISCONNECT,
    RECEIVED_DISCONNECTION_COMPLETE
} CONNECTION_STATE;

/* HCI role */
#define HCI_ROLE_MASTER 0
#define HCI_ROLE_SLAVE  1

#define HCI_LINK_TYPE_SCO 0
#define HCI_LINK_TYPE_ACL 1
#define HCI_LINK_TYPE_ESCO 2

struct hci_link_t
{
    struct hci_link_t *next; /* For the linked list */

    struct bd_addr_t bdaddr; /* The remote peers Bluetooth address for this connection */
    uint32_t cod;

    uint8_t role; /* role: 0 - master, 1 - slave */
    uint16_t conhdl; /* Connection handle */
    uint16_t sco_connhdl;
    CONNECTION_STATE state;
#if HCI_FLOW_QUEUEING
    struct bt_pbuf_t *p;
    uint16_t len;
    uint8_t pb;
#endif
};

typedef enum hci_init_status
{
    BLUETOOTH_INITING = 0,
    BLUETOOTH_WORKING = 1,
} hci_init_status_e;

typedef enum hci_vendor_init_status
{
    VENDOR_NOT_INIT = 0,
    VENDOR_INITED = 1,
} hci_vendor_init_status_e;


struct hci_pcb_t
{
    void *callback_arg;

    /* hci cmd timer */
    uint32_t timer;
    /* init status */
    hci_init_status_e init_status;
    hci_vendor_init_status_e vendor_init_status;
    chip_mgr_t *chip_mgr;
    struct bd_addr_t local_bd_addr;
    uint8_t ssp_enable;
	uint8_t ssp_io_cap;
    uint32_t class_of_device;
    const uint8_t *local_name;
    uint8_t *pincode;
    /* Host to host controller flow control */
    uint8_t numcmd; /* Number of command packets that the host controller (Bluetooth module)
		  can buffer */
    uint16_t maxsize; /* Maximum length of the data portion of each HCI ACL data packet that the
		   Host Controller is able to accept */
    uint16_t hc_num_acl; /* Number of ACL packets that the Bluetooth module can buffer */

    /* Host controller to host flow control */
    uint8_t flow; /* Indicates if host controller to host flow control is on */
    uint16_t host_num_acl; /* Number of ACL packets that we (the host) can buffer */

    struct hci_inq_res_t *ires; /* Results of an inquiry */

    err_t (* pin_req)(void *arg, struct bd_addr_t *bdaddr);
    err_t (* bt_working)(void *arg);
    err_t (* sco_req)(void *arg, struct bd_addr_t *bdaddr);
    err_t (*sco_conn_complete)(void *arg, uint8_t status,struct bd_addr_t *bdaddr);
    err_t (*sco_disconn_complete)(void *arg, uint8_t status,struct bd_addr_t *bdaddr);
    err_t (*inq_result)(struct hci_pcb_t *pcb,struct hci_inq_res_t *inqres);
    err_t (* inq_complete)(struct hci_pcb_t *pcb,uint16_t result);
    err_t (*name_req_complete)(struct hci_pcb_t *pcb,struct bd_addr_t *bdaddr,uint8_t * name);
    err_t (* rbd_complete)(void *arg, struct bd_addr_t *bdaddr);
    err_t (* link_key_not)(void *arg, struct bd_addr_t *bdaddr, uint8_t *key,uint8_t key_type);
    err_t (*link_key_req)(void *arg,struct bd_addr_t *bdaddr );
    err_t (* wlp_complete)(void *arg, struct bd_addr_t *bdaddr);
    err_t (* conn_complete)(void *arg, struct bd_addr_t *bdaddr);
    err_t (* cmd_complete)(void *arg, struct hci_pcb_t *pcb, uint8_t ogf, uint8_t ocf, uint8_t result);
};

#define HCI_EVENT_PIN_REQ(pcb,bdaddr,ret) \
                         if((pcb)->pin_req != NULL) { \
                           (ret = (pcb)->pin_req((pcb)->callback_arg,(bdaddr))); \
                         } else { \
                           ret = hci_pin_code_request_neg_reply(bdaddr); \
			 }
#define HCI_BT_WORKING(pcb) \
                              if((pcb)->bt_working != NULL) \
                              ((pcb)->bt_working((pcb)->callback_arg))
#define HCI_EVENT_SCO_REQ(pcb,bdaddr,ret) \
                              if((pcb)->sco_req != NULL) \
                              (ret = (pcb)->sco_req((pcb)->callback_arg,(bdaddr)))
#define HCI_EVENT_SCO_CONN_COMPLETE(pcb,status,bdaddr,ret) \
                              if((pcb)->sco_conn_complete != NULL) \
                              (ret = (pcb)->sco_conn_complete((pcb)->callback_arg,status,(bdaddr)))
#define HCI_EVENT_SCO_DISCONN_COMPLETE(pcb,status,bdaddr,ret) \
                              if((pcb)->sco_disconn_complete != NULL) \
                              (ret = (pcb)->sco_disconn_complete((pcb)->callback_arg,status,(bdaddr)))
#define HCI_EVENT_LINK_REQ(pcb,bdaddr,ret) \
                              if((pcb)->link_key_req != NULL) { \
                                (ret = (pcb)->link_key_req((pcb)->callback_arg,(bdaddr))); \
                              	}
#define HCI_EVENT_LINK_KEY_NOT(pcb,bdaddr,key,key_type,ret) \
                              if((pcb)->link_key_not != NULL) { \
                                (ret = (pcb)->link_key_not((pcb)->callback_arg,(bdaddr),(key),(key_type))); \
                              }
#define HCI_EVENT_INQ_RESULT(pcb,result,ret)\
					if((pcb)->inq_result != NULL) \
                              (ret = (pcb)->inq_result((pcb),(result)))
#define HCI_EVENT_INQ_COMPLETE(pcb,result,ret) \
                              if((pcb)->inq_complete != NULL) \
                              (ret = (pcb)->inq_complete((pcb),(result)))
#define HCI_EVENT_REMOTE_NAME_REQ_COMPLETE(pcb,bdaddr,name,ret) \
                              if((pcb)->name_req_complete != NULL) \
                              (ret = (pcb)->name_req_complete((pcb),(bdaddr),(name)))
#define HCI_EVENT_RBD_COMPLETE(pcb,bdaddr,ret) \
                              if((pcb)->rbd_complete != NULL) \
                              (ret = (pcb)->rbd_complete((pcb)->callback_arg,(bdaddr)));
#define HCI_EVENT_WLP_COMPLETE(pcb,bdaddr,ret) \
                               if((pcb)->wlp_complete != NULL) \
                               (ret = (pcb)->wlp_complete((pcb)->callback_arg,(bdaddr)));
#define HCI_EVENT_CONN_COMPLETE(pcb,bdaddr,ret) \
                               if((pcb)->conn_complete != NULL) \
                               (ret = (pcb)->conn_complete((pcb)->callback_arg,(bdaddr)));
#define HCI_EVENT_CMD_COMPLETE(pcb,ogf,ocf,result,ret) \
                              if((pcb)->cmd_complete != NULL) \
                              (ret = (pcb)->cmd_complete((pcb)->callback_arg,(pcb),(ogf),(ocf),(result)))

/* The HCI LINK lists. */
extern struct hci_link_t *hci_active_links; /* List of all active HCI LINKs */
extern struct hci_link_t *hci_tmp_link; /* Only used for temporary storage. */

#define HCI_REG(links, nlink) do { \
                            nlink->next = *links; \
                            *links = nlink; \
                            } while(0)
#define HCI_RMV(links, nlink) do { \
                            if(*links == nlink) { \
                               *links = (*links)->next; \
                            } else for(hci_tmp_link = *links; hci_tmp_link != NULL; hci_tmp_link = hci_tmp_link->next) { \
                               if(hci_tmp_link->next != NULL && hci_tmp_link->next == nlink) { \
                                  hci_tmp_link->next = nlink->next; \
                                  break; \
                               } \
                            } \
                            nlink->next = NULL; \
                            } while(0)


/*-------------------- common api ----------------------------------------*/
/*  Functions for interfacing with HCI */
err_t hci_init(void);
err_t hci_close(struct hci_link_t *link);
void hci_reset_all(void);
void hci_arg(void *arg);
void hci_cmd_complete(err_t (* cmd_complete)(void *arg, struct hci_pcb_t *pcb,uint8_t ogf, uint8_t ocf, uint8_t result));
void hci_pin_req(err_t (* pin_req)(void *arg, struct bd_addr_t *bdaddr));
void hci_bt_working(err_t (* bt_working)(void *arg));
void hci_sco_req(err_t (* sco_req)(void *arg, struct bd_addr_t *bdaddr));
void hci_sco_conn_complete(err_t (* sco_conn_complete)(void *arg, uint8_t status,struct bd_addr_t *bdaddr));
void hci_sco_disconn_complete(err_t (* sco_disconn_complete)(void *arg, uint8_t status,struct bd_addr_t *bdaddr));
void hci_link_key_req(err_t (* link_key_req)(void *arg,struct bd_addr_t *bdaddr));
void hci_link_key_not(err_t (* link_key_not)(void *arg, struct bd_addr_t *bdaddr, uint8_t *key,uint8_t key_type));
void  hci_wlp_complete(err_t (* wlp_complete)(void *arg, struct bd_addr_t *bdaddr));
void hci_connection_complete(err_t (* conn_complete)(void *arg, struct bd_addr_t *bdaddr));
err_t hci_acl_write(struct bd_addr_t *bdaddr, struct bt_pbuf_t *p, uint16_t len, uint8_t pb);
uint8_t hci_is_connected(struct bd_addr_t *bdaddr);
uint16_t hci_pdu_maxsize(void);
void hci_acl_input(struct bt_pbuf_t *p);
void hci_event_input(struct bt_pbuf_t *p);

/*-------------------- hci command ----------------------------------------*/
/* OGF = 0x01 LINK CONTROL COMMANDS */
err_t hci_inquiry(uint32_t lap, uint8_t inq_len, uint8_t num_resp,
                  err_t (*inq_result)(struct hci_pcb_t *pcb,struct hci_inq_res_t *inqres),
                  err_t (* inq_complete)(struct hci_pcb_t *pcb,uint16_t result));
err_t hci_cancel_inquiry(void);
err_t hci_periodic_inquiry(uint16_t min_periodic,uint16_t max_periodic,uint32_t lap, uint8_t inq_len, uint8_t num_resp,
                           err_t (*inq_result)(struct hci_pcb_t *pcb,struct hci_inq_res_t *inqres),
                           err_t (* inq_complete)(struct hci_pcb_t *pcb,uint16_t result));
err_t hci_cancel_periodic_inquiry(void);
err_t hci_connect_req(struct bd_addr_t *bdaddr, uint8_t allow_role_switch);
err_t hci_disconnect_acl(struct bd_addr_t *bdaddr, uint8_t reason);
err_t hci_disconnect_sco(struct bd_addr_t *bdaddr, uint8_t reason);
err_t hci_accept_connection_request(struct bd_addr_t *bdaddr, uint8_t role);
err_t hci_reject_connection_request(struct bd_addr_t *bdaddr, uint8_t reason);
err_t hci_link_key_request_reply(struct bd_addr_t *bdaddr, uint8_t *link_key);
err_t hci_link_key_request_negative_reply(struct bd_addr_t *bdaddr);
err_t hci_pin_code_request_reply(struct bd_addr_t *bdaddr, uint8_t pinlen, uint8_t *pincode);
err_t hci_pin_code_request_neg_reply(struct bd_addr_t *bdaddr);
err_t hci_get_remote_name(struct bd_addr_t *bdaddr,err_t (*name_req_complete)(struct hci_pcb_t *pcb,struct bd_addr_t *bdaddr,uint8_t * name));
err_t hci_cancel_get_remote_name(struct bd_addr_t *bdaddr);
err_t hci_get_remote_feature(struct bd_addr_t *bdaddr);
err_t hci_connect_sco(struct bd_addr_t *bdaddr,uint32_t transmit_bandwidth,uint32_t receive_bandwidth,
                      uint16_t max_latency,uint16_t voice_setting,uint8_t retransmission_effort,uint16_t packet_type);
err_t hci_accept_sco_req(struct bd_addr_t *bdaddr,uint32_t transmit_bandwidth,uint32_t receive_bandwidth,
                         uint16_t max_latency,uint16_t voice_setting,uint8_t retransmission_effort,uint16_t packet_type);
err_t hci_reject_sco_req(struct bd_addr_t *bdaddr,uint8_t reason);
err_t hci_io_cap_req_replay(struct bd_addr_t *bdaddr,uint8_t io_cap,uint8_t oob,uint8_t auth_req);
err_t hci_user_confirm_req_reply(struct bd_addr_t *bdaddr);
err_t hci_user_confirm_req_neg_reply(struct bd_addr_t *bdaddr);
err_t hci_user_passkey_req_repy(struct bd_addr_t *bdaddr,uint32_t num_value);
err_t hci_user_passkey_req_neg_repy(struct bd_addr_t *bdaddr);
err_t hci_io_cap_req_neg_reply(struct bd_addr_t *bdaddr,uint8_t reason);
/* OGF = 0x02 LINK POLICY COMMANDS */
err_t hci_hold_mode(struct bd_addr_t *bdaddr, uint16_t max_interval, uint16_t min_interval);
err_t hci_sniff_mode(struct bd_addr_t *bdaddr, uint16_t max_interval, uint16_t min_interval,  uint16_t attempt,uint16_t timeout);
err_t hci_exit_sniff_mode(struct bd_addr_t *bdaddr);
err_t hci_role_discovery(struct bd_addr_t *bdaddr);
err_t hci_switch_role(struct bd_addr_t *bdaddr,uint8_t role);
err_t hci_read_link_policy(struct bd_addr_t *bdaddr);
err_t hci_write_link_policy(struct bd_addr_t *bdaddr, uint16_t link_policy);
err_t hci_read_default_link_policy(void);
err_t hci_write_default_link_policy(uint16_t link_policy);
/* OGF = 0x03 CONTROLLER & BASEBAND COMMANDS */
err_t hci_set_event_mask(uint32_t mask_lo,uint32_t mask_hi);
err_t hci_reset(void);
err_t hci_set_event_filter(uint8_t filter_type, uint8_t filter_cond_type, uint8_t* cond);
err_t hci_write_stored_link_key(struct bd_addr_t *bdaddr, uint8_t *key);
err_t hci_write_local_name(uint8_t *name, uint8_t len);
err_t hci_read_local_name(void);
err_t hci_write_page_timeout(uint16_t page_timeout);
err_t hci_write_scan_enable(uint8_t scan_enable);
err_t hci_write_cod(uint8_t *cod);
err_t hci_read_voice_setting(void);
err_t hci_write_voice_setting(uint16_t voice_setting);
err_t hci_write_flush_timeout(struct bd_addr_t *bdaddr, uint16_t flushto);
err_t hci_set_hc_to_h_fc(void);
err_t hci_host_buffer_size(void);
err_t hci_host_num_comp_packets(uint16_t conhdl, uint16_t num_complete);
err_t hci_write_eir(uint8_t *eir_data);
err_t hci_write_ssp_mode(uint8_t ssp_mode);
err_t hci_write_le_enable(uint8_t le_support,uint8_t simultaneous);
/* OGF = 0x04 INFORMATIONAL PARAMETERS */
err_t hci_read_local_version_info(void);
err_t hci_read_buffer_size(void);
err_t hci_read_bd_addr(err_t (* rbd_complete)(void *arg, struct bd_addr_t *bdaddr));
/* OGF = 0x05 STATUS PARAMETERS */
err_t hci_read_rssi(struct bd_addr_t *bdaddr);
/* OGF = 0x06 TESTING COMMANDS */
err_t hci_enable_dut_mode(void);
/* OGF = 0x08 LE CONTROLLER COMMANDS */
err_t hci_set_le_scan_param(uint8_t scan_type,uint16_t scan_interval,uint16_t scan_window,uint8_t own_type,uint8_t scan_filter);
err_t hci_set_le_scan_enable(uint8_t scan_enable,uint8_t filter_duplicates);

#endif


