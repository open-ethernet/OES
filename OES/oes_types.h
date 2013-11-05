
/* This software is available to you under a choice of one of two
* licenses.  You may choose to be licensed under the terms of the GNU
* General Public License (GPL) Version 2, available from the file
* COPYING, or the Open Ethernet BSD license below:
*
*     Redistribution and use in source and binary forms, with or
*     without modification, are permitted provided that the following
*     conditions are met:
*
*      - Redistributions of source code must retain the above
*        copyright notice, this list of conditions and the following
*        disclaimer.
*
*      - Redistributions in binary form must reproduce the above
*        copyright notice, this list of conditions and the following
*        disclaimer in the documentation and/or other materials
*        provided with the distribution.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
* BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
* ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
* CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE. 
*/
/************************************************************************************************************/
/**************************** enum ************************************************************************/

enum oes_access_cmd {
	OES_ACCESS_CMD_ADD       	= 1,
	OES_ACCESS_CMD_EDIT      	= 2,
	OES_ACCESS_CMD_DELETE    	= 3,
	OES_ACCESS_CMD_DELETE_ALL	= 4,
	OES_ACCESS_CMD_TEST      	= 8,
	OES_ACCESS_CMD_APPLY     	= 9,
	OES_ACCESS_CMD_ENABLE    	= 10,
	OES_ACCESS_CMD_DISABLE   	= 11,
	OES_ACCESS_CMD_CREATE    	= 12,
	OES_ACCESS_CMD_DESTROY   	= 13,
};

enum oes_span_type {
	 OES_SPAN_TYPE_LOCAL = 1,
     OES_SPAN_TYPE_REMOTE_l2 = 2,
};

enum oes_distributor_mode {
	OES_DISTRIBUTOR_ENABLE,
	OES_DISTRIBUTOR_DISABLE
};

enum oes_collector_mode {
	OES_COLLECTOR_ENABLE,
	OES_COLLECTOR_DISABLE
};


enum oes_port_speed {
	OES_PORT_SPEED_NA			= 0,
	OES_PORT_SPEED_1GB_CX_SGMII  = 1,
	OES_PORT_SPEED_1GB_KX   		= 2,
	OES_PORT_SPEED_10GB_CX4_XAUI = 3,
	OES_PORT_SPEED_10GB_KX4 		= 4,
	OES_PORT_SPEED_10GB_KR  		= 5,
	OES_PORT_SPEED_20GB_KR2 		= 6,
	OES_PORT_SPEED_40GB_CR4 		= 7,
	OES_PORT_SPEED_40GB_KR4 		= 8,
	OES_PORT_SPEED_56GB_KR4 		= 9,
	OES_PORT_SPEED_56GB_KX4 		= 10,
};

enum oes_port_admin_state{
	OES_PORT_ADMIN_ENABLE,
    OES_PORT_ADMIN_DISABLE,
};

enum oes_port_oper_state{
    OES_PORT_UP,
    OES_PORT_DOWN,
};


enum oes_port_phys_loopback {
    OES_EXTERNAL_LOOPBACK, 
    OES_INTERNAL_LOOPBACK,
};


enum oes_flow_control_mode {
    OES_GLOBAL_PAUSE,
    OES_PFC,
};

enum oes_port_flow_ctrl_enable {
	 OES_PORT_FLOW_CTRL_MODE_TX_DIS_RX_DIS=0,
	 OES_PORT_FLOW_CTRL_MODE_TX_EN_RX_DIS,
	 OES_PORT_FLOW_CTRL_MODE_TX_DIS_RX_EN,
	 OES_PORT_FLOW_CTRL_MODE_TX_EN_RX_EN,
};

enum oes_port_loopback_filter_mode {
	OES_LOOPBACK_FILTER_MODE_DISABLED = 1,
	OES_LOOPBACK_FILTER_MODE_ENABLED = 2,
};

enum oes_mirror_direction {
	OES_SPAN_MIRROR_INGRESS = 1,
	OES_SPAN_MIRROR_EGRESS,
};


enum oes_cos_trust_level {
	OES_TRUST_LEVEL_PORT,
	OES_TRUST_LEVEL_PCP, 
	OES_TRUST_LEVEL_DSCP, 
	OES_TRUST_LEVEL_BOTH,
};

enum oes_cos_arbitration {
	OES_COS_ARBITRATION_DWRR, /**< DWRR arbiter */
    OES_COS_ARBITRATION_SP ,   /**< SP   arbiter */
};

/************************************************************************************************************/
/**************************** struct ************************************************************************/
union oes_span_type_format {
    struct oes_span_local_t		                  local_eth;	
    struct oes_span_remote_eth_l2_t               remote_eth_l2;	
};

struct  oes_span_remote_eth_l2{
	unsigned char  tclass;    /**< trafic class */
	unsigned short vid;      /**< Vlan ID */
	unsigned char  prio;    /**< Vlan pcp */
	struct ether_addr	mac; 
};

struct  oes_span_local{
	unsigned char  tclass;  /**< trafic class */
};

struct oes_span_session_params{
	oes_span_type_e					    span_type;												    
	union oes_span_type_format_t		span_type_format;	
};

struct oes_lag_hash_param {
	oes_lag_hash_type_t lag_hash_type;   /**< Hash type */
	oes_lag_hash_t lag_hash;             /**< bit field - oes_lag_hash_bit_number_t */
	oes_lag_seed_t lag_seed;             /**< LAG seed */
};

struct oes_fdb_uc_mac_addr_params {
	unsigned short   vid;                     /**< Filtering Identifier */
	struct ether_addr mac_addr;                 /**< MAC address */
    unsigned long log_port;                  /**< Logical port */
	oes_fdb_mac_entry_type_e entry_type;  /**< FDB Entry Type (dynamic/static)*/
};

struct oes_port_speed_capability {
	unsigned char enable_1GB_CX_SGMII;
	unsigned char enable_1GB_KX;
	unsigned char enable_10GB_CX4_XAUI;
	unsigned char enable_10GB_KX4;
	unsigned char enable_10GB_KR;
	unsigned char enable_20GB_KR2;
	unsigned char enable_40GB_CR4;
	unsigned char enable_40GB_KR4;
};

struct oes_port_flow_control_param {
     oes_flow_control_mode_e   fc_mode;     /**< low control mode  global pause or per prio pause(pfc) */
     unsigned char prio;                    /**< prio , valid only in pfc mode */
     oes_port_flow_ctrl_enable_e fc_enable; /**<enable rx, tx or both */
};

struct oes_cos_tc_ets_config_params {
	unsigned char tc; /**<! Traffic class ID (0-7) to be configured */
	unsigned char bw_allocation;	/**<! Bandwidth percentage guaranteed to traffic_class within its TCG. */
	unsigned int max_bw_value;		/**<! TC shaper configuration Maximal bandwidth allowed for the use traffic_class. */
	unsigned int max_bw_units;		/**<! TC shaper configuration Maximal bandwidth value units. */
};


struct oes_cos_port_ets_config_params {
    oes_cos_arbitration_e arbitration;        /**<! select arbitration for port DWRR or SP*/
    unsigned int max_bw_value;		/**<! port global shaper configuration Maximal bandwidth allowed for the use traffic_class. */
	unsigned int max_bw_units;		/**<! port global shaper configuration Maximal bandwidth value units. */
};

/**
