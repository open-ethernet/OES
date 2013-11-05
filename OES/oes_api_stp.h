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

#ifndef __OES_API_STP_H__
#define __OES_API_STP_H__


/************************************************
 *  API functions
 ***********************************************/

/**
 * This function sets the log verbosity level of STP MODULE
 * @param[in]  verbosity_level  - stp module verbosity level
 *
 * @return oes_status_t:
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_ERROR - Unexpected SDK error
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level
 */
oes_status_e
oes_api_stp_log_verbosity_level_set(int   verbosity_level);

/**
 * This function gets the log verbosity level of STP MODULE
 * @param[out]  verbosity_level_p  - stp module verbosity level
 *
 * 
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_ERROR - Unexpected SDK error
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level
 */
oes_status_e
oes_api_stp_log_verbosity_level_get(int   * verbosity_level_p);

/**
 *******This function Sets the Switch STP Activation mode (RSTP/MSTP) in the SDK 
 *
 * @param[in] br_id 
 * @param[in] mode - STP Activation mode.
 * 			Can take any of the following:
 **         OES_STP_MODE_MSTP,	(default) OES_STP_MODE_RST
 * @param[in.out] stp_mode_vs_ext - STP mode vendor extensions
 **      pointer
 * 
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Parameters out of range
 * @return OES_STATUS_ERROR - Unexpected SDK error
 */
oes_status_e
oes_api_stp_mode_set(
                     int br_id, 
                     enum oes_stp_mode mode, 
                     void * stp_mode_vs_ext
                     );

/**
 *  	This function Retrieves the Switch STP Activation state (RSTP/MSTP) from the SDK.
******************************
 *
 * @param[in] br_id 
 * @param[out] mode_p - STP Activation state.
 * @param[in.out] stp_mode_vs_ext - STP mode vendor extensions
 **      pointer
 * 
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Parameter error
 * @return OES_STATUS_ERROR - Unexpected SDK error
 */
oes_status_e
oes_api_stp_mode_get(
                     int br_id, 
                     enum oes_stp_mode *mode_p, 
                     void * stp_mode_vs_ext
                     );

/**
 *  	This function Adds/Deletes an MSTP Instance to/from the Switch in the SDK.
******************************
 *
 * @param[in] br_id 
 * @param[in] access_cmd - ADD/DELETE
 * @param[in] swid_id - Switch ID.
 * @param[in] inst_id - MSTP Instance ID to add/delete. Ranges <1-64>.
***@param[in.out] stp_mst	i_vs_ext - STP mode vendor 
***      extensions pointer
 *
 * 
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Parameter error
 * @return OES_STATUS_ERROR - Unexpected SDK error
 */
oes_status_e
oes_api_stp_msti_set(
                     int br_id, 
                     enum oes_access_cmd access_cmd, 
                     unsigned short inst_id, 
                     void * stp_msti_vs_ext
                     );

/**
 *  	This function Adds/Deletes a mapping between a list of VLANs to the MSTP Instance in the SDK.
******************************
 *
 * @param[in] br_id 
 * @param[in] access_cmd - ADD/DELTE
 * @param[in] inst_id - MSTP Instance ID. Ranges <1-64>.
 * @param[in] vlan_list - List of VLANs to Map/Unmap.
 * @param[in] vlan_num - Number of VLANs to Map/Unmap. Ranges <1-4094>.
 * @param[in.out] stp_msti_vlan_vs_ext - STP mode vendor******* 
 ********extensions pointer* 
 *
 * 
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Parameter error
 * @return OES_STATUS_ERROR - Unexpected SDK error
 */
oes_status_e
oes_api_stp_msti_vlan_list_set(
                               int br_id, 
                               enum oes_access_cmd access_cmd, 
                               unsigned char inst_id, 
                               unsigned short vlan_list[],
                               unsigned short vlan_num, 
                               void * stp_msti_vlan_vs_ext
                               );

/**
 *  	This function Retrieves a list of VLANs in the MSTP Instance from the SDK.
 *  If the list (array) is NULL, only the number of VLANs is retrieved.
******************************
 *
 * @param[in] br_id 
 * @param[in] inst_id - MSTP Instance ID. Ranges <1-64>.
 * @param[in.out] vlan_list - VLANs array.
 * @param[in.out] vlan_num_p - In: Size of VLANs array.****** 
 ********     Ranges****** <1-4094>. Out: Number of VLANs
 ********     retrieved successfully.
 * @param[in.out] stp_msti_vlan_vs_ext - STP vlan vendor******* 
 ********extensions pointer* 
 *
 * 
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Parameter error
 * @return OES_STATUS_ERROR - Unexpected SDK error
 */
oes_status_e
oes_api_stp_msti_vlan_list_get(
                               int br_id, 
                               unsigned char inst_id, 
                               unsigned short vlan_list[],
                               unsigned short *vlan_num_p, 
                               void * stp_msti_vlan_vs_ext
                               );

/**
 *  	This function Sets the MSTP Port State for a given Instance in the SDK.
******************************
 *
 * @param[in] br_id 
 * @param[in] inst_id - MSTP Instance ID. Ranges <1-64>. MSTI***** 
 *  0 refers to the common istance/ RSTP mode
 * @param[in] port_id - Port ID (whose STP state to set).
 * @param[in] port_state - MSTP Port State.
 * 			   Can take any of the following:
 * 			   OES_MSTP_INST_PORT_STATE_DISCARDING,
 * 			   OES_MSTP_INST_PORT_STATE_LEARNING,
 *			   OES_MSTP_INST_PORT_STATE_FORWARDING,
 **@param[in.out] stp_msti_port_vs_ext - STP port state**** 
 ******  vendor extension pointer*
 *
 * 
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Parameter error
 * @return OES_STATUS_ERROR - Unexpected SDK error
 */
oes_status_e
oes_api_stp_msti_port_state_set(
                                int br_id, 
                                unsigned char inst_id, 
                                oes_port_id_t port_id,
                        		enum oes_mstp_inst_port_state port_state,
                                void * stp_msti_port_vs_ext
                        		);

/**
 *  	This function Retrieves the MSTP Port State for a given Instance from the SDK.
******************************
 *
 * @param[in] swid_id - Switch ID.
 * @param[in] inst_id - MSTP Instance ID. Ranges <1-64>.
 * @param[in] port_id - Port ID (whose STP state to retrieve).
 * @param[out] port_state_p - MSTP Port State.
 * @param[in.out] stp_msti_port_vs_ext - STP port state**** 
 ******  vendor extension pointer*
 * 
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Parameter error
 * @return OES_STATUS_ERROR - Unexpected SDK error
 */
oes_status_e
oes_api_stp_msti_port_state_get(
                                int br_id, 
                                unsigned char inst_id, 
                                oes_port_id_t port_id,
                                oes_mstp_inst_port_state_e* port_state_p,
                                void * stp_msti_port_vs_ext
                                );



#endif /* __OES_API_STP_H__ */
