/****************************************************************************
 *
 * Copyright 2018 Samsung Electronics All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 *
 ****************************************************************************/
/**
 * @file
 * Additional SNMPv3 functionality RFC3414 and RFC3826 (internal API, do not use in client code).
 */

/*
 * Copyright (c) 2016 Elias Oenal.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 *
 * Author: Elias Oenal <lwip@eliasoenal.com>
 */

#ifndef LWIP_HDR_APPS_SNMP_V3_PRIV_H
#define LWIP_HDR_APPS_SNMP_V3_PRIV_H

#include "lwip/apps/snmp_opts.h"

#if LWIP_SNMP && LWIP_SNMP_V3

#include "snmp_pbuf_stream.h"

/* According to RFC 3411 */
#define SNMP_V3_MAX_ENGINE_ID_LENGTH  32
#define SNMP_V3_MAX_USER_LENGTH       32

#define SNMP_V3_MAX_AUTH_PARAM_LENGTH  12
#define SNMP_V3_MAX_PRIV_PARAM_LENGTH  8

#define SNMP_V3_AUTH_FLAG      0x01
#define SNMP_V3_PRIV_FLAG      0x02

#define SNMP_V3_MD5_LEN        16
#define SNMP_V3_SHA_LEN        20

u32_t snmpv3_get_engine_boots_internal(void);
u32_t snmpv3_get_engine_time_internal(void);
err_t snmpv3_auth(struct snmp_pbuf_stream *stream, u16_t length, const u8_t *key, u8_t algo, u8_t *hmac_out);
err_t snmpv3_crypt(struct snmp_pbuf_stream *stream, u16_t length, const u8_t *key, const u8_t *priv_param, const u32_t engine_boots, const u32_t engine_time, u8_t algo, u8_t mode);
err_t snmpv3_build_priv_param(u8_t *priv_param);

#endif

#endif							/* LWIP_HDR_APPS_SNMP_V3_PRIV_H */
