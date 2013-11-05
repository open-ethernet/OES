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

#ifndef __EOS_API_SPAN_H__
#define __EOS_API_SPAN_H__

#include <oes_types.h>

/************************************************
 *  API functions
 ***********************************************/


/**
 * This function sets the span verbosity level of span MODULE
 * @param[in]  verbosity_level  - span module verbosity level
 *
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_fdb_span_verbosity_level_set(
                                int   verbosity_level
                                );

/**
 * This function gets the span verbosity level of span MODULE
 * @param[out]  verbosity_level_p  -span module verbosity level
 *
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_span_log_verbosity_level_get(
                                    int   * verbosity_level_p
                                    );


/**
 *  This function sets the SPAN session.
 *
 * @param[in] br_id - Bridge id  
 * @param[in] access_cmd - CREATE / EDIT / DESTROY 
 * @param[in] span_session_params - SPAN session params 
 * @param[in,out] span_session_id - SPAN session ID  
 * @param[in,out] span_session_vs_ext - vendor specific 
 *       extention
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level
 * @return EOS_STATUS_NO_RESOURCES if pool cannot provide object 
 * @return OES_STATUS_ERROR general error.  
 */
oes_status_e 
oes_api_span_session_set(
                         int br_id,
                         enum oes_access_cmd	access_cmd,
                         struct oes_span_session_params 	* span_session_params,
                         unsigned char  *	span_session_id,
                         void *  span_session_vs_ext
	                    );


/**
 *  This function gets the SPAN session
 *
 * @param[in] br_id - Bridge id  
 * @param[in] access_cmd - CREATE / EDIT / DESTROY 
 * @param[out] span_session_params - SPAN session params 
 * @param[in] span_session_id - SPAN session ID  
 * @param[in,out] span_session_vs_ext - vendor specific 
 *       extention
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level
 * @return EOS_STATUS_NO_RESOURCES if pool cannot provide object 
 * @return OES_STATUS_ERROR general error.  
 */
oes_status_e
oes_api_span_session_get(
                        int br_id,
                        struct oes_span_session_params	* span_session_params,
                        unsigned char  	span_session_id,
                        void *  span_session_vs_ext
	                    );


/**
 *  This function sets the SPAN mirror ports.
 *
 * @param[in] br_id - Bridge id 
 * @param[in] access_cmd - ADD / DELETE 
 * @param[in] log_port -  port to mirror
 * @param[in] mirror_direction - egrees or ingress mirrorin 
 * @param[in] span_session_id - SPAN session ID 
 * @param[in,out] span_mirror_vs_ext - vendor specific 
 *
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level 
 * @return OES_STATUS_ERROR general error.  
 */
oes_status_e 
oes_api_span_mirror_set(
                       int br_id,
	                   enum oes_access_cmd access_cmd,
                       unsigned long log_port,
	                   enum oes_mirror_direction * mirror_direction,
	                   unsigned char span_session_id,
                       void *  span_mirror_vs_ext
	                   );


/**
 *  This function get the SPAN session id and direction by
 *  mirror port .
 *  
 * @param[in] br_id - Bridge id 
 * @param[in] log_port -  port to mirror
 * @param[out] mirror_direction - egrees or ingress mirroring 
 * @param[in] span_session_id - SPAN session ID  
 * @param[in,out] span_mirror_vs_ext - vendor specific 
 *
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level 
 * @return OES_STATUS_ERROR general error.  
 */
oes_status_e 
oes_api_span_mirror_get(
                       int br_id,
                       unsigned long log_port,
	                   enum oes_mirror_direction * mirror_direction,
	                   unsigned char * span_session_id,
                       void *  span_mirror_vs_ext
	                   );




/**
 *  This function sets the SPAN analyzer port.
 *  
 * @param[in] br_id - Bridge id 
 * @param[in] access_cmd - ADD / DELETE 
 * @param[in] log_port - analyzer port which added to SPAN
 * @param[in] span_session_id - SPAN session ID 
 * @param[in,out] span_analyzer_vs_ext -vendor specific 
 * extention @@return OES_STATUS_SUCCESS - Operation completes 
 * successfully 
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level 
 * @return OES_STATUS_ERROR general error.  
 */
oes_status_e
oes_api_span_analyzer_set(
	                     int br_id,
	                     enum oes_access_cmd cmd,
                         unsigned long log_port,
                         unsigned char	span_session_id,
                         void *  span_analyzer_vs_ext
                         );


/**
 *  This function geets the SPAN analyzer port.
 *  
 * @param[in] br_id - Bridge id 
 * @param[out] log_port - analyzer port which added to SPAN
 * @param[in] span_session_id - SPAN session ID 
 * @param[in,out] span_analyzer_vs_ext -vendor specific 
 * extention @@return OES_STATUS_SUCCESS - Operation completes 
 * successfully 
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level 
 * @return OES_STATUS_ERROR general error.  
 */
oes_status_e 
oes_api_span_analyzer_get(
	                     int br_id
                         unsigned long  *	log_port_p,
                         unsigned char	span_session_id,
                         void *  span_analyzer_vs_ext
                         );



#endif /* __EOS_API_PORT_MIRROR_H__ */

