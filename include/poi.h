/*
 * Copyright (c) 2011-2013 Samsung Electronics Co., Ltd All Rights Reserved
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


#ifndef __TIZEN_LOCATOIN_POI_H__
#define __TIZEN_LOCATOIN_POI_H__

#include <tizen.h>
#include <time.h>
#include <location_bounds.h>


#ifdef __cplusplus
extern "C"
{
#endif

#define POI_ERROR_CLASS TIZEN_ERROR_LOCATION_CLASS | 0x50

/**
 * @brief The POI service handle
 * @ingroup CAPI_LOCATION_POI_MODULE
 */
typedef void * poi_service_h;

/**
 * @brief The POI preference handle
 * @ingroup CAPI_LOCATION_POI_PREFERENCE_MODULE
 */
typedef void * poi_preference_h;

/**
 * @brief The POI filter handle
 * @ingroup CAPI_LOCATION_POI_FILTER_MODULE
 */
typedef void * poi_filter_h;

/**
 * @brief The POI handle
 * @ingroup CAPI_LOCATION_POI_POI_MODULE
 */
typedef void * poi_h;


/**
 * @brief Enumerations of sort order
 * @ingroup CAPI_LOCATION_POI_PREFERENCE_MODULE
 */
typedef enum {
	POI_SORTORDER_NONE,	 /**< None of sorting the results in order.*/
	POI_SORTORDER_ASC,	/**< A constant for sorting the results in ascending order */
	POI_SORTORDER_DESC	/**< A constant for sorting the results in descending order */
} poi_sort_order_e;



/**
 * @brief Enumerations of error code for POI
 * @ingroup CAPI_LOCATION_POI_MODULE
 */
typedef enum
{
    POI_ERROR_NONE = TIZEN_ERROR_NONE,                             /**< Successful */
    POI_ERROR_OUT_OF_MEMORY = TIZEN_ERROR_OUT_OF_MEMORY,           /**< Out of memory */
    POI_ERROR_INVALID_PARAMETER = TIZEN_ERROR_INVALID_PARAMETER,                   /**< Invalid parameter */
    POI_ERROR_NETWORK_FAILED = POI_ERROR_CLASS | 0x02,                  /**< Network unavailable*/
    POI_ERROR_SERVICE_NOT_AVAILABLE = POI_ERROR_CLASS | 0x03,   /**< Service unavailable */
    POI_ERROR_INVALID_KEY = POI_ERROR_CLASS | 0x04,   /**< Invalid key */
    POI_ERROR_RESULT_NOT_FOUND = POI_ERROR_CLASS | 0x05,   /**< Result not found */
} poi_error_e;


/**
 * @brief The result of POI search
 * @ingroup CAPI_LOCATION_POI_MODULE
 * @remarks @a poi is valid only in this function. To use the @a poi outside this function, copy the handle with poi_clone() function.\nIf failed to search, lenght is 0 and poi is NULL
 * @param [in] error The result of request
 * @param [in] request_id The request id
 * @param [in] index	The index of POI data in result set, start from 0
 * @param [in] length The number of result
 * @param [in] poi	The result data
 * @param [in] uesr_data  The user data passed from the request function
 * @return @c true to continue with the next iteration of the loop, \n @c false to break outsp of the loop.
 * @see	poi_service_search_by_position()
 * @see	poi_service_search_by_area()
 * @see	poi_service_search_by_address()
 */
typedef bool (*poi_service_search_cb)(poi_error_e error, int request_id , int index, int length , poi_h poi , void * user_data);

/**
 * @brief Called once for each properties
 * @ingroup CAPI_LOCATION_POI_PREFERENCE_MODULE
 * @remarks @a key and value are valid only in this function.
 * @param   [in] key  The key string
 * @param   [in] value  The value string 
 * @param   [in] uesr_data  The user data passed from the foreach function
 * @return @c true to continue with the next iteration of the loop, \n @c false to break outsp of the loop.
 * @see	poi_preference_foreach_properties()
 */
typedef bool (*poi_preference_properties_cb)(const char *key , const char *value,  void *user_data);

/**
 * @brief Called once for each available keys
 * @ingroup CAPI_LOCATION_POI_PREFERENCE_MODULE
 * @remarks @a key is valid only in this function.
 * @param   [in] key  The key string
 * @param   [in] uesr_data  The user data passed from the foreach function
 * @return @c true to continue with the next iteration of the loop, \n @c false to break outsp of the loop.
 * @see	poi_preference_foreach_available_keys()
 */
typedef bool (*poi_preference_available_key_cb)(const char *key , void *user_data);

/**
 * @brief Called once for each available values
 * @ingroup CAPI_LOCATION_POI_PREFERENCE_MODULE
 * @remarks @a value is valid only in this function.
 * @param   [in] value  The value string
 * @param   [in] uesr_data  The user data passed from the foreach function
 * @return @c true to continue with the next iteration of the loop, \n @c false to break outsp of the loop.
 * @see	poi_preference_foreach_available_values()
 */
typedef bool (*poi_preference_available_value_cb)(const char *value , void *user_data);


/**
 * @brief Called once for each sortable field
 * @ingroup CAPI_LOCATION_POI_PREFERENCE_MODULE
 * @remarks @a field is valid only in this function.
 * @param   [in] field  The field string
 * @param   [in] uesr_data  The user data passed from the foreach function
 * @return @c true to continue with the next iteration of the loop, \n @c false to break outsp of the loop.
 * @see	poi_preference_foreach_sortable_field()
 */
typedef bool (*poi_preference_sortable_field_cb)(const char *field , void *user_data);

/**
 * @brief Called once for each properties
 * @ingroup CAPI_LOCATION_POI_FILTER_MODULE
 * @remarks @a key and value are valid only in this function.
 * @param   [in] key  The key string
 * @param   [in] value  The value string 
 * @param   [in] uesr_data  The user data passed from the foreach function
 * @return @c true to continue with the next iteration of the loop, \n @c false to break outsp of the loop.
 * @see	poi_filter_foreach_available_keys()
 */
typedef bool (*poi_filter_properties_cb)(const char *key , const char *value , void *user_data);


/**
 * @brief Called once for each available keys
 * @ingroup CAPI_LOCATION_POI_FILTER_MODULE
 * @remarks @a key is valid only in this function.
 * @param   [in] key  The key string
 * @param   [in] uesr_data  The user data passed from the foreach function
 * @return @c true to continue with the next iteration of the loop, \n @c false to break outsp of the loop.
 * @see	poi_filter_foreach_available_keys()
 */
typedef bool (*poi_filter_available_key_cb)(const char *key , void *user_data);

/**
 * @brief Called once for each available values
 * @ingroup CAPI_LOCATION_POI_FILTER_MODULE
 * @remarks @a value is valid only in this function.
 * @param   [in] value  The value string
 * @param   [in] uesr_data  The user data passed from the foreach function
 * @return @c true to continue with the next iteration of the loop, \n @c false to break outsp of the loop.
 * @see	poi_filter_foreach_available_values()
 */
typedef bool (*poi_filter_available_value_cb)(const char *value , void *user_data);


/**
 * @brief Called once for each urls
 * @ingroup CAPI_LOCATION_POI_POI_MODULE
 * @remarks @a url and description are valid only in this function.
 * @param   [in] url  The url
 * @param   [in] description  The description
 * @param   [in] uesr_data  The user data passed from the foreach function
 * @return @c true to continue with the next iteration of the loop, \n @c false to break outsp of the loop.
 * @see	poi_foreach_urls()
 */
typedef bool (*poi_urls_cb)(const char *url , const char *description, void *user_data);

/**
 * @brief Called once for each properties
 * @ingroup CAPI_LOCATION_POI_POI_MODULE
 * @remarks @a key and value are valid only in this function.
 * @param   [in] key  The key of property
 * @param   [in] value  The value of property
 * @param   [in] uesr_data  The user data passed from the foreach function
 * @return @c true to continue with the next iteration of the loop, \n @c false to break outsp of the loop.
 * @see	poi_foreach_properties()
 */
typedef bool (*poi_properties_cb)(const char *key, const char* value, void *user_data);

/**
 * @brief Called once for each categories
 * @ingroup CAPI_LOCATION_POI_POI_MODULE
 * @remarks @a category is valid only in this function.
 * @param   [in] category The category
 * @param   [in] uesr_data  The user data passed from the foreach function
 * @return @c true to continue with the next iteration of the loop, \n @c false to break outsp of the loop.
 * @see	poi_foreach_categories()
 */
typedef bool (*poi_categories_cb)(const char *category, void *user_data);



/**
 * @brief Creates a new POI service handle.
 * @ingroup CAPI_LOCATION_POI_MODULE
 * @remarks @a service must be released poi_service_destroy() by you.
 * @param   [out] service  A handle of a new POI service handle on success
 * @return 0 on success, otherwise a negative error value.
 * @retval #POI_ERROR_NONE Successful
 * @retval #POI_ERROR_OUT_OF_MEMORY Out of memory
 * @retval #POI_ERROR_INVALID_PARAMETER	Invalid parameter
 * @retval #POI_ERROR_SERVICE_NOT_AVAILABLE Service not available
 * @see	poi_service_destroy()
 */
int poi_service_create(poi_service_h *service);


/**
 * @brief	Destroys the POI service handle and releases all its resources.
 * @ingroup CAPI_LOCATION_POI_MODULE
 * @param   [in] service	The POI service handle to destroy
 * @return  0 on success, otherwise a negative error value.
 * @retval #POI_ERROR_NONE Successful
 * @retval #POI_ERROR_INVALID_PARAMETER	Invalid parameter
 * @see	poi_service_create()
 */
int poi_service_destroy(poi_service_h service);

/**
 * @brief	Gets POI preference
 * @ingroup CAPI_LOCATION_POI_MODULE
 * @remarks @a preference must be released poi_preference_destroy() by you.
 * @param [in] service The POI service handle
 * @param [out] preference The POI preference handle
 * @return  0 on success, otherwise a negative error value.
 * @retval #POI_ERROR_NONE Successful
 * @retval #POI_ERROR_INVALID_PARAMETER	Invalid parameter
 * @see	poi_service_set_preference()
 */
int poi_service_get_preference(poi_service_h service , poi_preference_h *preference);

/**
 * @brief	Sets POI preference
 * @ingroup CAPI_LOCATION_POI_MODULE
 * @remarks @a preference handle is copied by frameworks
 * @param [in] service The POI service handle
 * @param [in] preference The POI preference handle
 * @return  0 on success, otherwise a negative error value.
 * @retval #POI_ERROR_NONE Successful
 * @retval #POI_ERROR_INVALID_PARAMETER	Invalid parameter
 * @see	poi_service_set_preference()
 */
int poi_service_set_preference(poi_service_h service , poi_preference_h preference);



/**
 * @brief Request a search
 * @ingroup CAPI_LOCATION_POI_MODULE
 * @param [in] service The POI service handle
 * @param [in] position The interested position
 * @param [in] distance The search area distance
 * @param [in] filter The filter handle
 * @param [in] callback The result callback
 * @param [in] user_data The user data to be passed to the callback function
 * @param [out] request_id A Request id, can be set to NULL if does not required operation cancel
 * @return 0 on success, otherwise a negative error value.
 * @retval #POI_ERROR_NONE Successful
 * @retval #POI_ERROR_OUT_OF_MEMORY Out of memory
 * @retval #POI_ERROR_INVALID_PARAMETER	Invalid parameter
 * @retval #POI_ERROR_SERVICE_NOT_AVAILABLE Service not available
 * @see	poi_service_search_by_area()
 * @see	poi_service_search_by_address()
 * @see	poi_service_search_cancel() 
 * @see	poi_service_search_cb()
 */ 
int poi_service_search (poi_service_h service, location_coords_s position, int distance , poi_filter_h filter, poi_service_search_cb callback, void * user_data, int * request_id);

/**
 * @brief Request a search by area
 * @ingroup CAPI_LOCATION_POI_MODULE
 * @remarks boundary is supporting only circle type bounds for search.
 * @param [in] service The POI service handle
 * @param [in] boundary The interested area
 * @param [in] filter The filter handle
 * @param [in] callback The result callback
 * @param [in] user_data The user data to be passed to the callback function
 * @param [out] request_id A Request id, can be set to NULL if does not required operation cancel
 * @return 0 on success, otherwise a negative error value.
 * @retval #POI_ERROR_NONE Successful
 * @retval #POI_ERROR_OUT_OF_MEMORY Out of memory
 * @retval #POI_ERROR_INVALID_PARAMETER	Invalid parameter
 * @retval #POI_ERROR_SERVICE_NOT_AVAILABLE Service not available
 * @see	poi_service_search_by_position()
 * @see	poi_service_search_by_address()
 * @see	poi_service_search_cancel() 
 * @see	poi_service_search_cb() 
 */ 
int poi_service_search_by_area (poi_service_h service, location_bounds_h boundary , poi_filter_h filter, poi_service_search_cb callback, void * user_data, int * request_id);

/**
 * @brief Request a search by area
 * @ingroup CAPI_LOCATION_POI_MODULE
 * @param [in] service The POI service handle
 * @param [in] address The interested address
 * @param [in] distance The search area distance 
 * @param [in] filter The filter handle
 * @param [in] callback The result callback
 * @param [in] user_data The user data to be passed to the callback function
 * @param [out] request_id A Request id, can be set to NULL if does not required operation cancel
 * @return 0 on success, otherwise a negative error value.
 * @retval #POI_ERROR_NONE Successful
 * @retval #POI_ERROR_OUT_OF_MEMORY Out of memory
 * @retval #POI_ERROR_INVALID_PARAMETER	Invalid parameter
 * @retval #POI_ERROR_SERVICE_NOT_AVAILABLE Service not available
 * @see	poi_service_search_by_area()
 * @see	poi_service_search_by_position()
 * @see	poi_service_search_cancel() 
 * @see	poi_service_search_cb() 
 */ 
int poi_service_search_by_address(poi_service_h service, const char* address, int distance, poi_filter_h filter, poi_service_search_cb callback, void * user_data, int * request_id);

/**
 * @brief Cancel the search request
 * @ingroup CAPI_LOCATION_POI_MODULE
 * @param [in] service The POI service handle
 * @param [in] request_id The request id to cancel
 * @return 0 on success, otherwise a negative error value.
 * @retval #POI_ERROR_NONE Successful
 * @retval #POI_ERROR_INVALID_PARAMETER	Invalid parameter
 * @pre poi_service_search_by_area() or poi_service_search_by_position() or poi_service_search_by_address() should be called before.
 * @see	poi_service_search_by_area()
 * @see	poi_service_search_by_position()
 * @see	poi_service_search_by_address() 
 */ 
int poi_service_cancel(poi_service_h service, int request_id);



/**
 * @brief Creates a new POI preference handle.
 * @ingroup CAPI_LOCATION_POI_PREFERENCE_MODULE
 * @remarks @a preference must be released poi_preference_destroy() by you.
 * @param   [out] preference  A handle of a new POI preference handle on success
 * @return 0 on success, otherwise a negative error value.
 * @retval #POI_ERROR_NONE Successful
 * @retval #POI_ERROR_OUT_OF_MEMORY Out of memory
 * @retval #POI_ERROR_INVALID_PARAMETER	Invalid parameter
 * @see	poi_preference_destroy()
 */
int poi_preference_create(poi_preference_h *preference );

/**
 * @brief	Destroys the POI preference handle and releases all its resources.
 * @ingroup CAPI_LOCATION_POI_PREFERENCE_MODULE
 * @param   [in] preference	The POI preference handle to destroy
 * @return  0 on success, otherwise a negative error value.
 * @retval #POI_ERROR_NONE Successful
 * @retval #POI_ERROR_INVALID_PARAMETER	Invalid parameter
 * @see	poi_service_create()
 */
int poi_preference_destroy(poi_preference_h preference );

/**
 * @brief Gets the preference value
 * @ingroup CAPI_LOCATION_POI_PREFERENCE_MODULE
 *
 * @param[in] preference	The handle to the POI preference
 * @param[in] key	The key of preference
 * @param[out] value The preference value
 * @return	  0 on success, otherwise a negative error value.
 * @retval #POI_ERROR_NONE Successful
 * @retval #POI_ERROR_INVALID_PARAMETER	Invalid parameter
 * @retval #POI_ERROR_INVALID_KEY	Invalid key
 *
 * @see	poi_preference_set()
 */
int poi_preference_get(poi_preference_h preference, const char *key, char **value);

/**
 * @brief Sets the preference value
 * @ingroup CAPI_LOCATION_POI_PREFERENCE_MODULE
 *
 * @param[in] preference	The handle to the POI preference
 * @param[in] key	The key of preference
 * @param[in] value The preference value to set , could be NULL if want remove value
 * @return	  0 on success, otherwise a negative error value.
 * @retval #POI_ERROR_NONE Successful
 * @retval #POI_ERROR_INVALID_PARAMETER	Invalid parameter
 * @retval #POI_ERROR_INVALID_KEY	Invalid key
 *
 * @see	poi_preference_get()
 */
int poi_preference_set(poi_preference_h preference, const char *key, const char *value);

/**
 * @brief Sets the number of maximum result
 * @ingroup CAPI_LOCATION_POI_PREFERENCE_MODULE
 *
 * @param[in] preference	The handle to the POI preference
 * @param[in] max_result	The number of maximum result
 * @return	  0 on success, otherwise a negative error value.
 * @retval #POI_ERROR_NONE Successful
 * @retval #POI_ERROR_INVALID_PARAMETER	Invalid parameter
 *
 * @see	poi_preference_get_max_result()
 */
int poi_preference_set_max_result(poi_preference_h preference, int max_result);

/**
 * @brief Gets the number of maximum result
 * @ingroup CAPI_LOCATION_POI_PREFERENCE_MODULE
 *
 * @param[in] preference	The handle to the POI preference
 * @param[out] max_result	The number of maximum result
 * @return	  0 on success, otherwise a negative error value.
 * @retval #POI_ERROR_NONE Successful
 * @retval #POI_ERROR_INVALID_PARAMETER	Invalid parameter
 *
 * @see	poi_preference_set_max_result()
 */
int poi_preference_get_max_result(poi_preference_h preference, int* max_result);

/**
 * @brief Sets the sort option
 * @ingroup CAPI_LOCATION_POI_PREFERENCE_MODULE
 *
 * @param[in] preference	The handle to the POI preference
 * @param[in] field		The field name for sorting
 * @param[in] order	 The sort order
 * @return	  0 on success, otherwise a negative error value.
 * @retval #POI_ERROR_NONE Successful
 * @retval #POI_ERROR_INVALID_PARAMETER	Invalid parameter
 *
 * @see	poi_preference_get_sort()
 */
int poi_preference_set_sort(poi_preference_h preference , const char* field , poi_sort_order_e order);

/**
 * @brief Gets the sort option
 * @ingroup CAPI_LOCATION_POI_PREFERENCE_MODULE
 *
 * @remarks @a field must be released @c free() by you.
 * @param[in] preference	The handle to the POI preference
 * @param[out] field		The field name for sorting 
 * @param[out] order	 The sort order
 * @return	  0 on success, otherwise a negative error value.
 * @retval #POI_ERROR_NONE Successful
 * @retval #POI_ERROR_INVALID_PARAMETER	Invalid parameter
 *
 * @see	poi_preference_set_sort()
 */
int poi_preference_get_sort(poi_preference_h preference , char** field,  poi_sort_order_e *order);

/**
 * @brief Retrieves all properties in preference
 * @ingroup CAPI_LOCATION_POI_PREFERENCE_MODULE
 *
 * @param[in] preference	The handle to the POI preference
 * @param[in] callback	The callback function to invoke
 * @param[in] user_data	The user data to be passed to the callback function
 * @return	  0 on success, otherwise a negative error value.
 * @retval #POI_ERROR_NONE Successful
 * @retval #POI_ERROR_INVALID_PARAMETER	Invalid parameter
 * @post	This function invokes poi_preference_properties_cb() repeatdly to retrieve each preference properties.
 *
 * @see	poi_preference_properties_cb()
 */
int poi_preference_foreach_properties( poi_preference_h preference, poi_preference_properties_cb callback , void * user_data);

/**
 * @brief Retrieves all available preference keys 
 * @ingroup CAPI_LOCATION_POI_PREFERENCE_MODULE
 *
 * @param[in] service The POI service handle
 * @param[in] callback	The callback function to invoke
 * @param[in] user_data	The user data to be passed to the callback function
 * @return	  0 on success, otherwise a negative error value.
 * @retval #POI_ERROR_NONE Successful
 * @retval #POI_ERROR_INVALID_PARAMETER	Invalid parameter
 * @post	This function invokes poi_preference_available_key_cb() repeatdly to retrieve each available preference keys.
 *
 * @see	poi_preference_available_key_cb()
 */
int poi_preference_foreach_available_keys( poi_service_h service,  poi_preference_available_key_cb callback , void * user_data);

/**
 * @brief Retrieves all available preference values
 * @ingroup CAPI_LOCATION_POI_PREFERENCE_MODULE
 *
 * @param[in] service The POI service handle
 * @param[in] key	The key string
 * @param[in] callback	The callback function to invoke
 * @param[in] user_data	The user data to be passed to the callback function
 * @return	  0 on success, otherwise a negative error value.
 * @retval #POI_ERROR_NONE Successful
 * @retval #POI_ERROR_INVALID_PARAMETER	Invalid parameter
 * @retval #POI_ERROR_INVALID_KEY	Invalid key
 * @post	This function invokes poi_preference_available_value_cb() repeatdly to retrieve each available preference values.
 *
 * @see	poi_preference_available_value_cb()
 */
int poi_preference_foreach_available_values( poi_service_h service, const char *key,  poi_preference_available_value_cb callback , void * user_data);

/**
 * @brief Retrieves all sortable fields
 * @ingroup CAPI_LOCATION_POI_PREFERENCE_MODULE
 *
 * @param[in] service The POI service handle
 * @param[in] callback	The callback function to invoke
 * @param[in] user_data	The user data to be passed to the callback function
 * @return	  0 on success, otherwise a negative error value.
 * @retval #POI_ERROR_NONE Successful
 * @retval #POI_ERROR_INVALID_PARAMETER	Invalid parameter
 * @post	This function invokes poi_preference_sortable_field_cb() repeatdly to retrieve each sortable fields.
 *
 * @see	poi_preference_sortable_field_cb()
 * @see	poi_preference_set_sort()
 * @see 	poi_preference_get_sort()
 */
int poi_preference_foreach_sortable_field( poi_service_h service , poi_preference_sortable_field_cb callback , void * user_data);


/**
 * @brief Creates a new POI filter handle.
 * @ingroup CAPI_LOCATION_POI_FILTER_MODULE
 * @remarks @a filter must be released poi_filter_destroy() by you.
 * @param   [out] filter  A handle of a new POI filter handle on success
 * @return 0 on success, otherwise a negative error value.
 * @retval #POI_ERROR_NONE Successful
 * @retval #POI_ERROR_OUT_OF_MEMORY Out of memory
 * @retval #POI_ERROR_INVALID_PARAMETER	Invalid parameter
 * @see	poi_filter_destroy()
 */
int poi_filter_create(poi_filter_h *filter);


/**
 * @brief	Destroys the POI filter handle and releases all its resources.
 * @ingroup CAPI_LOCATION_POI_FILTER_MODULE
 * @param   [in] filter	The POI filter handle to destroy
 * @return  0 on success, otherwise a negative error value.
 * @retval #POI_ERROR_NONE Successful
 * @retval #POI_ERROR_INVALID_PARAMETER	Invalid parameter
 * @see	poi_filter_create()
 */
int poi_filter_destroy(poi_filter_h filter);

/**
 * @brief	Sets the filter value
 * @ingroup CAPI_LOCATION_POI_FILTER_MODULE
 * @param  [in] filter	The handle to the POI filter
 * @param	[in] key	The key of filter
 * @param	[in] value The filter value to set , could be NULL if want remove value
 * @return  0 on success, otherwise a negative error value.
 * @retval #POI_ERROR_NONE Successful
 * @retval #POI_ERROR_INVALID_PARAMETER	Invalid parameter
 * @see	poi_filter_get()
 * @see	poi_filter_foreach_available_keys() 
 */
int poi_filter_set(poi_filter_h filter, const char* key, const char* value);

/**
 * @brief	Gets the filter value
 * @ingroup CAPI_LOCATION_POI_FILTER_MODULE
 * @remarks @a value must be released @c free() by you.
 * @param  [in] filter	The handle to the POI filter
 * @param	[in] key	The key of filter
 * @param	[out] value The filter value
 * @return  0 on success, otherwise a negative error value.
 * @retval #POI_ERROR_NONE Successful
 * @retval #POI_ERROR_INVALID_PARAMETER	Invalid parameter
 * @see	poi_filter_set()
 * @see	poi_filter_foreach_available_keys()
 */
int poi_filter_get(poi_filter_h filter, const char* key, char** value);

/**
 * @brief Retrieves all filter properties
 * @ingroup CAPI_LOCATION_POI_FILTER_MODULE
 *
 * @param[in] filter	The handle to the POI filter
 * @param[in] callback	The callback function to invoke
 * @param[in] user_data	The user data to be passed to the callback function
 * @return	  0 on success, otherwise a negative error value.
 * @retval #POI_ERROR_NONE Successful
 * @retval #POI_ERROR_INVALID_PARAMETER	Invalid parameter
 * @post	This function invokes poi_filter_available_key_cb() repeatdly to retrieve each available filter keys.
 *
 * @see	poi_filter_properties_cb()
 * @see	poi_filter_get()
 * @see	poi_filter_set() 
 */
int poi_filter_foreach_properties(poi_filter_h filter, poi_filter_properties_cb callback , void * user_data);

/**
 * @brief Retrieves all available filter keys 
 * @ingroup CAPI_LOCATION_POI_FILTER_MODULE
 *
 * @param[in] service The POI service handle
 * @param[in] callback	The callback function to invoke
 * @param[in] user_data	The user data to be passed to the callback function
 * @return	  0 on success, otherwise a negative error value.
 * @retval #POI_ERROR_NONE Successful
 * @retval #POI_ERROR_INVALID_PARAMETER	Invalid parameter
 * @post	This function invokes poi_filter_available_key_cb() repeatdly to retrieve each available filter keys.
 *
 * @see	poi_preference_available_key_cb()
 * @see	poi_filter_get()
 * @see	poi_filter_set() 
 */
int poi_filter_foreach_available_keys( poi_service_h service, poi_filter_available_key_cb callback , void * user_data);

/**
 * @brief Retrieves all available filter values 
 * @ingroup CAPI_LOCATION_POI_FILTER_MODULE
 *
 * @param[in] service The POI service handle
 * @param[in] key	The key string
 * @param[in] callback	The callback function to invoke
 * @param[in] user_data	The user data to be passed to the callback function
 * @return	  0 on success, otherwise a negative error value.
 * @retval #POI_ERROR_NONE Successful
 * @retval #POI_ERROR_INVALID_PARAMETER	Invalid parameter
 * @retval #POI_ERROR_INVALID_KEY	Invalid key 
 * @post	This function invokes poi_filter_available_value_cb() repeatdly to retrieve each available filter values.
 *
 * @see	poi_filter_available_value_cb()
 * @see	poi_filter_get()
 * @see	poi_filter_set() 
 */
int poi_filter_foreach_available_values( poi_service_h service, const char *key, poi_filter_available_value_cb callback , void * user_data);


/**
 * @brief Creates a new POI handle.
 * @ingroup CAPI_LOCATION_POI_POI_MODULE
 * @remarks @a poi must be released poi_destroy() by you.
 * @param   [out] poi  A handle of a new POI handle on success
 * @return 0 on success, otherwise a negative error value.
 * @retval #POI_ERROR_NONE Successful
 * @retval #POI_ERROR_OUT_OF_MEMORY Out of memory
 * @retval #POI_ERROR_INVALID_PARAMETER	Invalid parameter
 * @see	poi_destroy()
 * @see	poi_clone() 
 */
int poi_create(poi_h *poi);

/**
 * @brief	Destroys the POI handle and releases all its resources.
 * @ingroup CAPI_LOCATION_POI_POI_MODULE
 * @param   [in] poi The POI handle to destroy
 * @return  0 on success, otherwise a negative error value.
 * @retval #POI_ERROR_NONE Successful
 * @retval #POI_ERROR_INVALID_PARAMETER	Invalid parameter
 * @see	poi_create()
 * @see	poi_clone()  
 */
int poi_destroy(poi_h poi);

/**
 * @brief	Clones the POI handle
 * @ingroup CAPI_LOCATION_POI_POI_MODULE
 * @remarks @a cloned must be released poi_destroy() by you.
 * @param  [out] cloned	A cloned POI handle
 * @param	[in] origin	The original POI handle
 * @return  0 on success, otherwise a negative error value.
 * @retval #POI_ERROR_NONE Successful
 * @retval #POI_ERROR_OUT_OF_MEMORY Out of memory
 * @retval #POI_ERROR_INVALID_PARAMETER	Invalid parameter
 * @see	poi_create()
 * @see	poi_destroy()
 */
int poi_clone(poi_h* cloned, poi_h origin);

/**
 * @brief	Gets the POI id
 * @ingroup CAPI_LOCATION_POI_POI_MODULE
 * @param  [in] poi		The handle to POI
 * @param	[out] id	The POI id
 * @return  0 on success, otherwise a negative error value.
 * @retval #POI_ERROR_NONE Successful
 * @retval #POI_ERROR_INVALID_PARAMETER	Invalid parameter
 */
int poi_get_id(poi_h poi, int *id);

/**
 * @brief	Gets the POI name
 * @ingroup CAPI_LOCATION_POI_POI_MODULE
 * @remarks @a name must be released with @c free() by you.
 * @param  [in] poi		The handle to POI
 * @param	[out] name	The POI name
 * @return  0 on success, otherwise a negative error value.
 * @retval #POI_ERROR_NONE Successful
 * @retval #POI_ERROR_INVALID_PARAMETER	Invalid parameter
 */
int poi_get_name(poi_h poi, char **name);

/**
 * @brief	Gets the POI position
 * @ingroup CAPI_LOCATION_POI_POI_MODULE
 * @param  [in] poi		The handle to POI
 * @param	[out] position	The POI position
 * @return  0 on success, otherwise a negative error value.
 * @retval #POI_ERROR_NONE Successful
 * @retval #POI_ERROR_INVALID_PARAMETER	Invalid parameter
 */
int poi_get_position(poi_h poi, location_coords_s *position);

/**
 * @brief	Gets the POI address
 * @ingroup CAPI_LOCATION_POI_POI_MODULE
 * @remarks All output values must be released with @c free() by you.
 * @param  [in] poi		The handle to POI
 * @param	[out] building_number	 The building number
 * @param	[out] postal_code	The postal delivery code
 * @param	[out] street	The full street name
 * @param	[out] city	The city name
 * @param	[out] district	The municipal district name
 * @param	[out] state	The state or province region of a nation
 * @param	[out] country_code	The country code
 * @return  0 on success, otherwise a negative error value.
 * @retval #POI_ERROR_NONE Successful
 * @retval #POI_ERROR_INVALID_PARAMETER	Invalid parameter
 */
int poi_get_address(poi_h poi, char **building_number, char **postal_code, char **street, char **city, char **district, char **state, char **country_code);

/**
 * @brief	Gets the POI description
 * @ingroup CAPI_LOCATION_POI_POI_MODULE
 * @remarks @a description must be released with @c free() by you.
 * @param  [in] poi		The handle to POI
 * @param	[out] description	The POI description
 * @return  0 on success, otherwise a negative error value.
 * @retval #POI_ERROR_NONE Successful
 * @retval #POI_ERROR_INVALID_PARAMETER	Invalid parameter
 */
int poi_get_description(poi_h poi, char** description);

/**
 * @brief	Gets the POI timestamp
 * @ingroup CAPI_LOCATION_POI_POI_MODULE
 * @param  [in] poi		The handle to POI
 * @param	[out] timestamp	The POI timestamp
 * @return  0 on success, otherwise a negative error value.
 * @retval #POI_ERROR_NONE Successful
 * @retval #POI_ERROR_INVALID_PARAMETER	Invalid parameter
 */
int poi_get_timestamp(poi_h poi , time_t *timestamp);

/**
 * @brief	Gets the POI bounding rect
 * @ingroup CAPI_LOCATION_POI_POI_MODULE
 * @param  [in] poi		The handle to POI
 * @param	[out] top_left	The top left position
 * @param	[out] bottom_right The bottom right position
 * @return  0 on success, otherwise a negative error value.
 * @retval #POI_ERROR_NONE Successful
 * @retval #POI_ERROR_INVALID_PARAMETER	Invalid parameter
 */
int poi_get_bounding_rect(poi_h poi , location_coords_s *top_left, location_coords_s *bottom_right);

/**
 * @brief	Gets the POI author
 * @ingroup CAPI_LOCATION_POI_POI_MODULE
 * @remarks @a author must be released with @c free() by you. 
 * @param  [in] poi		The handle to POI
 * @param	[out] author		The POI author
 * @return  0 on success, otherwise a negative error value.
 * @retval #POI_ERROR_NONE Successful
 * @retval #POI_ERROR_INVALID_PARAMETER	Invalid parameter
 */
int poi_get_author(poi_h poi , char** author);

/**
 * @brief	Gets the POI phone number
 * @ingroup CAPI_LOCATION_POI_POI_MODULE
 * @remarks @a phone_number must be released with @c free() by you. 
 * @param  [in] poi		The handle to POI
 * @param	[out] phone_number		The POI phone number
 * @return  0 on success, otherwise a negative error value.
 * @retval #POI_ERROR_NONE Successful
 * @retval #POI_ERROR_INVALID_PARAMETER	Invalid parameter
 */
int poi_get_phone_number(poi_h poi , char **phone_number);

/**
 * @brief	Retrieves all urls 
 * @ingroup CAPI_LOCATION_POI_POI_MODULE
 * @param  [in] poi		The handle to POI
 * @param	[in] callback	The callback function to invoke
 * @param	[in] user_data	The user data to be passed to the callback function
 * @return  0 on success, otherwise a negative error value.
 * @retval #POI_ERROR_NONE Successful
 * @retval #POI_ERROR_INVALID_PARAMETER	Invalid parameter
 * @post	This function invokes poi_urls_cb() repeatdly to retrieve each urls.
 * @see poi_urls_cb()
 */
int poi_foreach_urls(poi_h poi, poi_urls_cb callback , void * user_data);

/**
 * @brief	Retrieves all properties 
 * @ingroup CAPI_LOCATION_POI_POI_MODULE
 * @param  [in] poi		The handle to POI
 * @param	[in] callback	The callback function to invoke
 * @param	[in] user_data	The user data to be passed to the callback function
 * @return  0 on success, otherwise a negative error value.
 * @retval #POI_ERROR_NONE Successful
 * @retval #POI_ERROR_INVALID_PARAMETER	Invalid parameter
 * @post	This function invokes poi_properties_cb() repeatdly to retrieve each properties.
 * @see poi_properties_cb()
 */
int poi_foreach_properties(poi_h poi, poi_properties_cb callback, void * user_data);

/**
 * @brief	Retrieves all categories 
 * @ingroup CAPI_LOCATION_POI_POI_MODULE
 * @param  [in] poi		The handle to POI
 * @param	[in] callback	The callback function to invoke
 * @param	[in] user_data	The user data to be passed to the callback function
 * @return  0 on success, otherwise a negative error value.
 * @retval #POI_ERROR_NONE Successful
 * @retval #POI_ERROR_INVALID_PARAMETER	Invalid parameter
 * @post	This function invokes poi_categories_cb() repeatdly to retrieve each categories.
 * @see poi_categories_cb()
 */
int poi_foreach_categories(poi_h poi , poi_categories_cb callback , void * user_data);


#ifdef __cplusplus
}
#endif

#endif /* __TIZEN_LOCATION_POI_H__ */

