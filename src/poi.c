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


#include <location/location.h>
#include <location/location-map-service.h>
#include <poi.h>
#include <poi_private.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlog.h>

#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG "TIZEN_N_POI"

#define POI_CHECK_CONDITION(condition,error,msg)	\
		do{ \
			if( !(condition) ){	\
				LOGE("[%s] %s(0x%08x)",__FUNCTION__, msg,error); return error;	\
			} \
		}while(0)

#define POI_PRINT_ERROR_CODE_RETURN(code) \
	do{\
		LOGE("[%s] %s(0x%08x)",__FUNCTION__, #code,code); return code;	\
	}while(0)


#define POI_NULL_ARG_CHECK(arg)	\
	POI_CHECK_CONDITION( (arg !=NULL),POI_ERROR_INVALID_PARAMETER,"POI_ERROR_INVALID_PARAMETER")


typedef struct {
	void *data;
	poi_service_search_cb callback;
}__callback_data;

/*
* Internal Implementation
*/
static int _convert_error_code(int code, const char* func_name)
{
	int ret;
	char* msg = "POI_ERROR_NONE";
	switch(code)
	{
		case LOCATION_ERROR_NONE:
			ret = POI_ERROR_NONE;
			msg = "POI_ERROR_NONE";
			break;
		case LOCATION_ERROR_NETWORK_FAILED:
		case LOCATION_ERROR_NETWORK_NOT_CONNECTED:
			ret = POI_ERROR_NETWORK_FAILED;
			msg = "POI_ERROR_NETWORK_FAILED";
			break;
		case LOCATION_ERROR_PARAMETER:
			ret = POI_ERROR_INVALID_PARAMETER;
			msg = "POI_ERROR_INVALID_PARAMETER";
			break;
		case LOCATION_ERROR_NOT_FOUND:
			ret = POI_ERROR_RESULT_NOT_FOUND;
			msg = "POI_ERROR_RESULT_NOT_FOUND";
			break;			
		case LOCATION_ERROR_NOT_ALLOWED:
		case LOCATION_ERROR_NOT_AVAILABLE:
		case LOCATION_ERROR_CONFIGURATION:
		case LOCATION_ERROR_UNKNOWN:
		default:
			msg = "POI_ERROR_SERVICE_NOT_AVAILABLE";
			ret = POI_ERROR_SERVICE_NOT_AVAILABLE;	
	}
	LOGE("[%s] %s(0x%08x) : core fw error(0x%x)",func_name,msg, ret, code);
	return ret;	
}

static void __LocationPOICB(LocationError error, guint req_id, GList * landmark_list, gchar * error_code, gchar * error_msg, gpointer userdata)
{
	__callback_data * callback = (__callback_data*)userdata;
	if( callback == NULL || callback->callback == NULL)
		return ;
	
	int ret = _convert_error_code(error,"search_callback");
	GList *mark_list = landmark_list;
	int length = 0;
	int index = 0;
	
	if( mark_list == NULL || ret != 0){
		callback->callback(ret , req_id, index, length, NULL, callback->data);
		free(callback);
		return;
	}
	
	length = g_list_length(mark_list);
	while( mark_list) {
		LocationLandmark *mark = mark_list->data;
		if( callback->callback(ret, req_id, index++, length, mark, callback->data) == false )
			break;
		mark_list = mark_list->next;
	}

	free(callback);
		
}



int poi_service_create( poi_service_h *poi)
{
	if( poi == NULL)
		POI_PRINT_ERROR_CODE_RETURN(POI_ERROR_INVALID_PARAMETER);

	if( location_init() != LOCATION_ERROR_NONE )
	{
		LOGE("[%s] POI_ERROR_SERVICE_NOT_AVAILABLE(0x%08x) : fail to location_init", __FUNCTION__, POI_ERROR_SERVICE_NOT_AVAILABLE);
		return POI_ERROR_SERVICE_NOT_AVAILABLE;
	}
	
	poi_service_s *handle = (poi_service_s*)malloc(sizeof(poi_service_s));
	if( handle == NULL)
		POI_PRINT_ERROR_CODE_RETURN(POI_ERROR_OUT_OF_MEMORY);

	memset(handle, 0 , sizeof(poi_service_s));

	if( POI_ERROR_NONE != poi_preference_create(&handle->preference ) ){
		free(handle);
		POI_PRINT_ERROR_CODE_RETURN(POI_ERROR_OUT_OF_MEMORY);
	}

	handle->object = location_map_new(NULL);
	if(handle->object  == NULL)
	{
		free(handle);
		LOGE("[%s] POI_ERROR_SERVICE_NOT_AVAILABLE(0x%08x) : fail to location_map_new", __FUNCTION__, POI_ERROR_SERVICE_NOT_AVAILABLE);
		return POI_ERROR_SERVICE_NOT_AVAILABLE;
	}	

	*poi = (poi_service_h)handle;
	return POI_ERROR_NONE;
}


int poi_service_destroy(poi_service_h poi)
{
	if( poi == NULL)
		POI_PRINT_ERROR_CODE_RETURN(POI_ERROR_INVALID_PARAMETER);

	poi_service_s *handle = (poi_service_s*)poi;

	if( handle->preference ){
		poi_preference_destroy(handle->preference);
		handle->preference = NULL;
	}

	int ret = location_map_free(handle->object);
	if(ret!= POI_ERROR_NONE)
	{
		return _convert_error_code(ret,__FUNCTION__);
	}
	free(handle);
	return POI_ERROR_NONE;

}

int poi_service_set_preference(poi_service_h poi , poi_preference_h preference)
{
	POI_NULL_ARG_CHECK(poi);
	POI_NULL_ARG_CHECK(preference);	
	
	poi_service_s *handle = (poi_service_s*)poi;

	if( handle->preference ){
		poi_preference_destroy(handle->preference);
		handle->preference = (poi_preference_h)location_poi_pref_copy((LocationPOIPreference*)preference);
	}
	return POI_ERROR_NONE;
}

int poi_service_get_preference(poi_service_h poi , poi_preference_h *preference)
{
	POI_NULL_ARG_CHECK(poi);
	POI_NULL_ARG_CHECK(preference);	
	poi_service_s *handle = (poi_service_s*)poi;

	if( handle->preference == NULL ){
		poi_preference_create(&handle->preference );
	}	
	*preference = (poi_preference_h)location_poi_pref_copy((LocationPOIPreference*)handle->preference);
	return POI_ERROR_NONE;
}

int poi_service_search(poi_service_h poi, location_coords_s position, int distance , poi_filter_h filter, poi_service_search_cb callback, void * user_data, int * request_id)
{
	POI_NULL_ARG_CHECK(poi);
	POI_NULL_ARG_CHECK(callback);
	POI_CHECK_CONDITION(distance >= 0 , POI_ERROR_INVALID_PARAMETER, "distance value is negative");
	POI_CHECK_CONDITION(position.latitude>=-90 && position.latitude<=90 ,POI_ERROR_INVALID_PARAMETER,"latitude should be -90 <= latitude <= 90");
	POI_CHECK_CONDITION(position.longitude>=-180 && position.longitude<=180,POI_ERROR_INVALID_PARAMETER,"longitude should be -180 <= latitude <= 180");


	LocationPosition pos;
	unsigned int reqid;	
	int ret;

	poi_service_s *handle = (poi_service_s*)poi;
	pos.latitude = position.latitude;
	pos.longitude = position.longitude;
	pos.altitude = 0;
	pos.status = LOCATION_STATUS_2D_FIX;


	__callback_data * calldata = (__callback_data *)malloc(sizeof(__callback_data));
	if( calldata == NULL)
		POI_PRINT_ERROR_CODE_RETURN(POI_ERROR_OUT_OF_MEMORY);

	calldata->callback = callback;
	calldata->data = user_data;

	if( distance != 0 ){
		char distance_str[255];
		snprintf(distance_str, 255, "%d", distance);
		poi_preference_set(handle->preference, "Distance", distance_str);
	}else{
		poi_preference_set(handle->preference, "Distance", NULL);
	}


	ret = location_map_search_poi (handle->object , (LocationPOIFilter*)filter , &pos, (LocationPOIPreference *)handle->preference, __LocationPOICB, calldata, &reqid);
	if( ret != 0 ){
		free(calldata);
		return _convert_error_code(ret, __func__);
	}

	if( request_id )
		*request_id = reqid;	
	return POI_ERROR_NONE;

}


int poi_service_search_by_area (poi_service_h poi, location_bounds_h boundary , poi_filter_h filter, poi_service_search_cb callback, void * user_data, int * request_id)
{
	POI_NULL_ARG_CHECK(poi);
	POI_NULL_ARG_CHECK(callback);
	POI_NULL_ARG_CHECK(boundary);
	
	unsigned int reqid;	
	int ret;
	poi_service_s *handle = (poi_service_s*)poi;
	location_bounds_type_e bound_type;
	location_bounds_get_type(boundary, &bound_type);
	
	if( bound_type == LOCATION_BOUNDS_RECT ){
		if( !location_map_is_supported_provider_capability(handle->object , MAP_SERVICE_POI_SEARCH_BY_RECT_BOUNDARY) )
			return POI_ERROR_SERVICE_NOT_AVAILABLE;
	}else if(bound_type == LOCATION_BOUNDS_CIRCLE){
		if( !location_map_is_supported_provider_capability(handle->object , MAP_SERVICE_POI_SEARCH_BY_CIRCLE_BOUNDARY) )
			return POI_ERROR_SERVICE_NOT_AVAILABLE;	
	}else if(bound_type == LOCATION_BOUNDS_CIRCLE){
		if( !location_map_is_supported_provider_capability(handle->object , MAP_SERVICE_POI_SEARCH_BY_POLYGON_BOUNDARY) )
			return POI_ERROR_SERVICE_NOT_AVAILABLE;		
	}
	
	__callback_data * calldata = (__callback_data *)malloc(sizeof(__callback_data));
	if( calldata == NULL)
		POI_PRINT_ERROR_CODE_RETURN(POI_ERROR_OUT_OF_MEMORY);

	calldata->callback = callback;
	calldata->data = user_data;

	poi_preference_set(handle->preference, "Distance", NULL);

	ret = location_map_search_poi_by_area (handle->object , (LocationPOIFilter*)filter , (LocationBoundary *)boundary, (LocationPOIPreference *)handle->preference, __LocationPOICB, calldata, &reqid);
	if( ret != 0 ){
		free(calldata);
		return _convert_error_code(ret, __func__);
	}
	
	if( request_id )
		*request_id = reqid;	
	return POI_ERROR_NONE;

}

int poi_service_search_by_address(poi_service_h poi, const char* address, int distance, poi_filter_h filter, poi_service_search_cb callback, void * user_data, int * request_id)
{
	POI_NULL_ARG_CHECK(poi);
	POI_NULL_ARG_CHECK(callback);
	POI_CHECK_CONDITION(distance >= 0 , POI_ERROR_INVALID_PARAMETER, "distance value is negative");

	
	unsigned int reqid;	
	int ret;
	poi_service_s *handle = (poi_service_s*)poi;

		__callback_data * calldata = (__callback_data *)malloc(sizeof(__callback_data));
	if( calldata == NULL)
		POI_PRINT_ERROR_CODE_RETURN(POI_ERROR_OUT_OF_MEMORY);

	calldata->callback = callback;
	calldata->data = user_data;

	if( distance != 0 ){
		char distance_str[255];
		snprintf(distance_str, 255, "%d", distance);
		poi_preference_set(handle->preference, "Distance", distance_str);
	}else{
		poi_preference_set(handle->preference, "Distance", NULL);
	}	

	ret = location_map_search_poi_by_freeformed_address (handle->object , (LocationPOIFilter*)filter , address, (LocationPOIPreference *)handle->preference, __LocationPOICB, calldata, &reqid);

	if( ret != 0 ){
		free(calldata);
		return _convert_error_code(ret, __func__);
	}
	
	if( request_id )
		*request_id = reqid;	
	return POI_ERROR_NONE;

}

int poi_service_cancel(poi_service_h service, int request_id)
{
	POI_NULL_ARG_CHECK(service);

	poi_service_s *handle = (poi_service_s*)service;
	return _convert_error_code(location_map_cancel_poi_request(handle->object, request_id), __func__);
}

int poi_filter_create(poi_filter_h *filter)
{
	POI_NULL_ARG_CHECK(filter);
	
	LocationPOIFilter *native_filter = location_poi_filter_new();
	POI_CHECK_CONDITION( (native_filter != NULL) , POI_ERROR_OUT_OF_MEMORY, "POI_ERROR_OUT_OF_MEMORY");
	*filter = (void*)native_filter;
	return POI_ERROR_NONE;	
}
int poi_filter_destroy(poi_filter_h filter)
{
	POI_NULL_ARG_CHECK(filter);
	location_poi_filter_free((LocationPOIFilter*)filter);
	return POI_ERROR_NONE;
}
int poi_filter_set(poi_filter_h filter, const char* key, const char* value)
{
	POI_NULL_ARG_CHECK(filter);
	POI_NULL_ARG_CHECK(key);
	int ret = location_poi_filter_set((LocationPOIFilter*)filter , key, value);
	if( !ret )
		return POI_ERROR_INVALID_KEY;
	return POI_ERROR_NONE;	
}
int poi_filter_get(poi_filter_h filter, const char* key, char** value)
{
	POI_NULL_ARG_CHECK(filter);
	POI_NULL_ARG_CHECK(key);
	POI_NULL_ARG_CHECK(value);
	char *v = (char*)location_poi_filter_get((LocationPOIFilter*)filter, key);
	if ( v  == NULL )
		POI_PRINT_ERROR_CODE_RETURN(POI_ERROR_INVALID_KEY);

	*value = strdup(v);
	return POI_ERROR_NONE;
}

int poi_filter_foreach_properties(poi_filter_h filter, poi_filter_properties_cb callback , void * user_data)
{
	POI_NULL_ARG_CHECK(filter);
	POI_NULL_ARG_CHECK(callback);

	GList *keys = location_poi_filter_get_key((LocationPOIFilter*)filter);
	while(keys){
		char *key = keys->data;
		char *value = location_poi_filter_get((LocationPOIFilter*)filter, key);
		if(!callback(key,value, user_data))
			break;
		keys = keys->next;
	}
	 g_list_free(keys);
	return POI_ERROR_NONE;	
}

int poi_filter_foreach_available_keys( poi_service_h poi, poi_filter_available_key_cb callback , void * user_data)
{
	POI_NULL_ARG_CHECK(poi);
	POI_NULL_ARG_CHECK(callback);

	GList *keys=NULL;
	location_map_get_provider_capability_key((LocationMapObject*)poi, MAP_SERVICE_POI_FILTER, &keys);
	if( keys == NULL )
		return POI_ERROR_RESULT_NOT_FOUND;

	while(keys){
		char *key = keys->data;
		if( !callback(key,user_data) )
			break;
		keys = keys->next;
	}
	g_list_free_full (keys, g_free);	
	return POI_ERROR_NONE;
}

int poi_filter_foreach_available_values( poi_service_h poi, const char *key, poi_filter_available_value_cb callback , void * user_data)
{
	//TODO. 
	// Available category
	return POI_ERROR_RESULT_NOT_FOUND;
}

int poi_preference_create(poi_preference_h *preference )
{
	POI_NULL_ARG_CHECK(preference);
	LocationPOIPreference *pref;
	pref = 	location_poi_pref_new();
	if( pref == NULL)
		POI_PRINT_ERROR_CODE_RETURN(POI_ERROR_OUT_OF_MEMORY);
	*preference = pref;

	return POI_ERROR_NONE;
}

int poi_preference_destroy(poi_preference_h preference )
{
	POI_NULL_ARG_CHECK(preference);
	location_poi_pref_free((LocationPOIPreference*)preference);
	return POI_ERROR_NONE;
}

int poi_preference_foreach_properties( poi_preference_h preference, poi_preference_properties_cb callback , void * user_data)
{
	POI_NULL_ARG_CHECK(preference);
	POI_NULL_ARG_CHECK(callback);

	GList *keys = location_poi_pref_get_property_key((LocationPOIPreference*)preference);
	while(keys){
		char *key = keys->data;
		char *value = location_poi_pref_get_property((LocationPOIPreference*)preference, key);
		if(!callback(key,value, user_data))
			break;
		keys = keys->next;
	}
	 g_list_free(keys);
	return POI_ERROR_NONE;	
}

int poi_preference_foreach_available_keys( poi_service_h poi,  poi_preference_available_key_cb callback , void * user_data)
{
	POI_NULL_ARG_CHECK(poi);
	POI_NULL_ARG_CHECK(callback);

	GList *keys=NULL;
	location_map_get_provider_capability_key((LocationMapObject*)poi, MAP_SERVICE_POI_PREF_PROPERTY, &keys);
	if( keys == NULL )
		return POI_ERROR_RESULT_NOT_FOUND;

	while(keys){
		char *key = keys->data;
		if( !callback(key,user_data) )
			break;
		keys = keys->next;
	}
	g_list_free_full (keys, g_free);	
	return POI_ERROR_NONE;
}

int poi_preference_foreach_available_values( poi_service_h poi, const char *key,  poi_preference_available_value_cb callback , void * user_data)
{
	//TODO. impl..
	// Availiable LandmarkType 
	// Availiable LandmarkName 	
	return POI_ERROR_RESULT_NOT_FOUND;
}

int poi_preference_get(poi_preference_h preference, const char *key, char **value)
{
	POI_NULL_ARG_CHECK(preference);
	POI_NULL_ARG_CHECK(key);
	POI_NULL_ARG_CHECK(value);
	char *v = (char*)location_poi_pref_get_property((LocationPOIPreference*)preference, key);
	if( v == NULL )
		POI_PRINT_ERROR_CODE_RETURN(POI_ERROR_INVALID_KEY);
	*value = strdup(v);
	return POI_ERROR_NONE;
}

int poi_preference_set(poi_preference_h preference, const char *key, const char *value)
{
	POI_NULL_ARG_CHECK(preference);
	POI_NULL_ARG_CHECK(key);

	int ret = location_poi_pref_set_property((LocationPOIPreference*)preference,key, value);
	if( !ret )
		POI_PRINT_ERROR_CODE_RETURN(POI_ERROR_INVALID_KEY);
	return POI_ERROR_NONE;
}

int poi_preference_set_max_result(poi_preference_h preference, int max_result)
{
	POI_NULL_ARG_CHECK(preference);
	int ret = location_poi_pref_set_max_result((LocationPOIPreference*)preference, max_result);
	if( !ret )
		POI_PRINT_ERROR_CODE_RETURN(POI_ERROR_INVALID_PARAMETER);
	return POI_ERROR_NONE;	
}

int poi_preference_get_max_result(poi_preference_h preference, int* max_result)
{
	POI_NULL_ARG_CHECK(preference);
	POI_NULL_ARG_CHECK(max_result);
	int ret = location_poi_pref_get_max_result((LocationPOIPreference*)preference );
	if( ret == 0 )
		POI_PRINT_ERROR_CODE_RETURN(POI_ERROR_INVALID_PARAMETER);
	*max_result = ret;
	return POI_ERROR_NONE;	
}


int poi_preference_foreach_sortable_field( poi_service_h poi, poi_preference_sortable_field_cb callback , void * user_data)
{
	POI_NULL_ARG_CHECK(poi);
	POI_NULL_ARG_CHECK(callback);

	GList *keys=NULL;
	location_map_get_provider_capability_key((LocationMapObject*)poi, MAP_SERVICE_POI_PREF_SORT_BY, &keys);
	if( keys == NULL )
		return POI_ERROR_RESULT_NOT_FOUND;

	while(keys){
		char *key = keys->data;
		if( !callback(key,user_data) )
			break;
		keys = keys->next;
	}
	g_list_free_full (keys, g_free);	
	return POI_ERROR_NONE;
}

int poi_preference_set_sort(poi_preference_h preference , const char* field , poi_sort_order_e order)
{
	POI_NULL_ARG_CHECK(preference);
	POI_NULL_ARG_CHECK(field);
	int ret = location_poi_pref_set_sort_by((LocationPOIPreference*)preference, field);
	if( !ret )
		POI_PRINT_ERROR_CODE_RETURN(POI_ERROR_INVALID_PARAMETER);
	ret = location_poi_pref_set_sort_order ((LocationPOIPreference*)preference , order);
	if( !ret )
		POI_PRINT_ERROR_CODE_RETURN(POI_ERROR_INVALID_PARAMETER);

	return POI_ERROR_NONE;
}

int poi_preference_get_sort(poi_preference_h preference , char** field,  poi_sort_order_e *order)
{
	POI_NULL_ARG_CHECK(preference);
	POI_NULL_ARG_CHECK(field);
	POI_NULL_ARG_CHECK(order);
	char *sort_by = (char*)location_poi_pref_get_sort_by((LocationPOIPreference*)preference);
	if( sort_by )
		*field = strdup(sort_by);
	else
		*field = NULL;
	
	*order  = location_poi_pref_get_sort_order((LocationPOIPreference*)preference);
	return POI_ERROR_NONE;
}

int poi_create(poi_h *poi)
{
	POI_NULL_ARG_CHECK(poi);
	LocationLandmark* landmark = location_landmark_new();
	if( landmark == NULL)
		POI_PRINT_ERROR_CODE_RETURN(POI_ERROR_OUT_OF_MEMORY);

	*poi = landmark;
	return POI_ERROR_NONE;
}

int poi_destroy(poi_h poi)
{
	POI_NULL_ARG_CHECK(poi);
	location_landmark_free((LocationLandmark*)poi);
	return POI_ERROR_NONE;
}

int poi_clone(poi_h* cloned, poi_h origin)
{
	POI_NULL_ARG_CHECK(cloned);
	POI_NULL_ARG_CHECK(origin);
	
	LocationLandmark * landmark = location_landmark_copy ((LocationLandmark*)origin);
	if( landmark == NULL)
		POI_PRINT_ERROR_CODE_RETURN(POI_ERROR_OUT_OF_MEMORY);
	*cloned = landmark;
	return POI_ERROR_NONE;	
}

int poi_get_id(poi_h poi, int *id)
{
	POI_NULL_ARG_CHECK(poi);
	POI_NULL_ARG_CHECK(id);
	*id = location_landmark_get_id((LocationLandmark*)poi);
	return POI_ERROR_NONE;
}

int poi_get_name(poi_h poi, char **name)
{
	POI_NULL_ARG_CHECK(poi);
	POI_NULL_ARG_CHECK(name);
	char *poi_name = (char*)location_landmark_get_name((LocationLandmark*)poi);
	if( poi_name == NULL)
		*name = NULL;
	else
		*name = strdup(poi_name);
	return POI_ERROR_NONE;	
}

int poi_get_position(poi_h poi, location_coords_s *position)
{
	POI_NULL_ARG_CHECK(poi);
	POI_NULL_ARG_CHECK(position);
	const LocationPosition *pos = location_landmark_get_position((LocationLandmark*)poi);
	if( pos == NULL)
		POI_PRINT_ERROR_CODE_RETURN(POI_ERROR_INVALID_PARAMETER);

	position->latitude = pos->latitude;
	position->longitude = pos->longitude;
	return POI_ERROR_NONE;	
}

int poi_get_address(poi_h poi, char **building_number, char **postal_code, char **street, char **city, char **district, char **state, char **country_code)
{
	POI_NULL_ARG_CHECK(poi);
	const LocationAddress * addr = location_landmark_get_address((LocationLandmark*)poi);
	if( addr == NULL )
		return POI_ERROR_RESULT_NOT_FOUND;
	if( building_number && addr->building_number)
		*building_number = strdup(addr->building_number);

	if( postal_code && addr->postal_code)
		*postal_code = strdup(addr->postal_code);

	if( street && addr->street)
		*street = strdup(addr->street);

	if( city && addr->city)
		*city = strdup(addr->city);

	if( district && addr->district)
		*district = strdup(addr->district);

	if( state && addr->state)
		*state = strdup(addr->state);
	
	if( country_code && addr->country_code)
		*country_code = strdup(addr->country_code);

	return POI_ERROR_NONE;
	
}

int poi_get_description(poi_h poi, char** description)
{
	POI_NULL_ARG_CHECK(poi);
	POI_NULL_ARG_CHECK(description);
	
	char * desc = (char*)location_landmark_get_description((LocationLandmark*)poi);
	if( desc  == NULL)
		*description = NULL;
	else
		*description = strdup(desc);
	return POI_ERROR_NONE;
}

int poi_get_timestamp(poi_h poi , time_t *timestamp)
{
	POI_NULL_ARG_CHECK(poi);
	POI_NULL_ARG_CHECK(timestamp);
	*timestamp = location_landmark_get_timestamp((LocationLandmark*)poi);
	return POI_ERROR_NONE;
}

int poi_get_bounding_rect(poi_h poi , location_coords_s *top_left, location_coords_s *bottom_right)
{
	POI_NULL_ARG_CHECK(poi);
	POI_NULL_ARG_CHECK(top_left);
	POI_NULL_ARG_CHECK(bottom_right);	

	const LocationBoundary *bound = location_landmark_get_bounding_box((LocationLandmark*)poi);
	if( bound == NULL )
		return POI_ERROR_RESULT_NOT_FOUND;
	top_left->latitude = bound->rect.left_top->latitude;
	top_left->longitude = bound->rect.left_top->longitude;	
	bottom_right->latitude = bound->rect.right_bottom->latitude;
	bottom_right->longitude = bound->rect.right_bottom->longitude;
	
	return POI_ERROR_NONE;
}

int poi_get_author(poi_h poi , char** author)
{
	POI_NULL_ARG_CHECK(poi);
	POI_NULL_ARG_CHECK(author);
	char *auth = (char*)location_landmark_get_author((LocationLandmark*)poi);
	if( auth == NULL )
		*author = NULL;
	else
		*author = strdup(auth);
	return POI_ERROR_NONE;
}

int poi_get_phone_number(poi_h poi , char** phone_number)
{
	POI_NULL_ARG_CHECK(poi);
	POI_NULL_ARG_CHECK(phone_number);
	char *number = (char*)location_landmark_get_phone_number((LocationLandmark*)poi);
	if( number == NULL )
		*phone_number = NULL;
	else
		*phone_number = strdup(number);
	return POI_ERROR_NONE;
}

int poi_foreach_urls(poi_h poi, poi_urls_cb callback , void * user_data)
{
	POI_NULL_ARG_CHECK(poi);
	POI_NULL_ARG_CHECK(callback);

	GList *url_list = (GList*)location_landmark_get_url((LocationLandmark*)poi);

	while( url_list ){
		LocationLandmarkUrl *url = url_list->data;
		if(url != NULL && !callback(location_landmark_url_get_url_path(url), location_landmark_url_get_description(url), user_data) )
			break;
		url_list = url_list->next;	
	}
	return POI_ERROR_NONE;	
}

int poi_foreach_properties(poi_h poi, poi_properties_cb callback, void * user_data)
{
	POI_NULL_ARG_CHECK(poi);
	POI_NULL_ARG_CHECK(callback);
	GList *key_list = (GList*)location_landmark_get_property_key((LocationLandmark*)poi);
	
	while( key_list ){
		char *key = key_list->data;
		char *value = NULL;		
		if( key != NULL && (value = (char*)location_landmark_get_property((LocationLandmark*)poi, key)) != NULL){
			if( callback(key, value, user_data) == false)
				break;			
		}
		key_list = key_list->next;	
	}
	return POI_ERROR_NONE;	
}

int poi_foreach_categories(poi_h poi , poi_categories_cb callback , void * user_data)
{
	POI_NULL_ARG_CHECK(poi);
	POI_NULL_ARG_CHECK(callback);
	GList *category_list = (GList*)location_landmark_get_category((LocationLandmark*)poi);
	
	while( category_list ){
		char *category = category_list->data;
		if( false == callback(category, user_data) )
			break;
		category_list = category_list->next;	
	}
	return POI_ERROR_NONE;
}
