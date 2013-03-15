/*
* Copyright (c) 2011 Samsung Electronics Co., Ltd All Rights Reserved
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#ifndef __TIZEN_LOCATION_POI_PRIVATE_H__
#define	__TIZEN_LOCATION_POI_PRIVATE_H__

#include <location/location.h>
#include <poi.h>
#include <dlog.h>

#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG "CAPI_LOCATION_POI"

#define POI_LOGD(fmt,args...)  LOGD(fmt, ##args)
#define POI_LOGW(fmt,args...)  LOGW(fmt, ##args)
#define POI_LOGI(fmt,args...)  LOGI(fmt, ##args)
#define POI_LOGE(fmt,args...)  LOGE(fmt, ##args)

#define POI_CHECK_CONDITION(condition, error, msg)	\
	do { \
		if( !(condition) ){	\
			POI_LOGE("%s(0x%08x)", msg, error); \
			return error;	\
		} \
	} while (0)

#define POI_PRINT_ERROR_CODE_RETURN(code) \
	do{ \
		POI_LOGE("%s(0x%08x)", #code, code); \
		return code;	\
	} while (0)


#define POI_NULL_ARG_CHECK(arg)	\
	POI_CHECK_CONDITION( (arg !=NULL),POI_ERROR_INVALID_PARAMETER,"POI_ERROR_INVALID_PARAMETER")

#ifdef __cplusplus
extern "C" {
#endif


typedef struct _poi_service_s{
	LocationMapObject* object;
	poi_preference_h preference;

} poi_service_s;

#ifdef __cplusplus
}
#endif

#endif //__TIZEN_LOCATION_POI_PRIVATE_H__

