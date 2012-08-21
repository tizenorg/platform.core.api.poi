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

#include <tet_api.h>
#include <poi.h>
#include <glib.h>
#include <location/location.h>

enum {
	POSITIVE_TC_IDX = 0x01,
	NEGATIVE_TC_IDX,
};

static void startup(void);
static void cleanup(void);

void (*tet_startup)(void) = startup;
void (*tet_cleanup)(void) = cleanup;

static void utc_poi_service_create_p(void);
static void utc_poi_service_create_n(void);
static void utc_poi_service_destroy_p(void);
static void utc_poi_service_destroy_n(void);
static void utc_poi_service_get_preference_p(void);
static void utc_poi_service_get_preference_n(void);
static void utc_poi_service_get_preference_n_02(void);
static void utc_poi_service_set_preference_p(void);
static void utc_poi_service_set_preference_n(void);
static void utc_poi_service_set_preference_n_02(void);
static void utc_poi_service_search_p(void);
static void utc_poi_service_search_n(void);
static void utc_poi_service_search_n_02(void);
static void utc_poi_service_search_n_03(void);
static void utc_poi_service_search_n_04(void);
static void utc_poi_service_search_n_05(void);
static void utc_poi_service_search_by_area_p(void);
static void utc_poi_service_search_by_area_n(void);
static void utc_poi_service_search_by_area_n_02(void);
static void utc_poi_service_search_by_area_n_03(void);
static void utc_poi_service_search_by_area_n_04(void);
static void utc_poi_service_search_by_address_p(void);
static void utc_poi_service_search_by_address_n(void);
static void utc_poi_service_search_by_address_n_02(void);
static void utc_poi_service_search_by_address_n_03(void);
static void utc_poi_service_search_by_address_n_04(void);
static void utc_poi_service_cancel_p(void);
static void utc_poi_service_cancel_n(void);
static void utc_poi_service_cancel_n_02(void);
static void utc_poi_preference_create_p(void);
static void utc_poi_preference_create_n(void);
static void utc_poi_preference_destroy_p(void);
static void utc_poi_preference_destroy_n(void);
static void utc_poi_preference_get_p(void);
static void utc_poi_preference_get_n(void);
static void utc_poi_preference_get_n_02(void);
static void utc_poi_preference_get_n_03(void);
static void utc_poi_preference_set_p(void);
static void utc_poi_preference_set_n(void);
static void utc_poi_preference_set_n_02(void);
static void utc_poi_preference_set_n_03(void);
static void utc_poi_preference_set_max_result_p(void);
static void utc_poi_preference_set_max_result_n(void);
static void utc_poi_preference_set_max_result_n_02(void);
static void utc_poi_preference_get_max_result_p(void);
static void utc_poi_preference_get_max_result_n(void);
static void utc_poi_preference_get_max_result_n_02(void);
static void utc_poi_preference_foreach_sortable_field_p(void);
static void utc_poi_preference_foreach_sortable_field_n(void);
static void utc_poi_preference_foreach_sortable_field_n_02(void);
static void utc_poi_preference_set_sort_p(void);
static void utc_poi_preference_set_sort_n(void);
static void utc_poi_preference_set_sort_n_02(void);
static void utc_poi_preference_set_sort_n_03(void);
static void utc_poi_preference_get_sort_p(void);
static void utc_poi_preference_get_sort_n(void);
static void utc_poi_preference_get_sort_n_02(void);
static void utc_poi_preference_get_sort_n_03(void);
static void utc_poi_preference_foreach_properties_p(void);
static void utc_poi_preference_foreach_properties_n(void);
static void utc_poi_preference_foreach_properties_n_02(void);
static void utc_poi_preference_foreach_available_keys_p(void);
static void utc_poi_preference_foreach_available_keys_n(void);
static void utc_poi_preference_foreach_available_keys_n_02(void);
static void utc_poi_preference_foreach_available_values_p(void);
static void utc_poi_preference_foreach_available_values_n(void);
static void utc_poi_preference_foreach_available_values_n_02(void);
static void utc_poi_preference_foreach_available_values_n_03(void);
static void utc_poi_filter_create_p(void);
static void utc_poi_filter_create_n(void);
static void utc_poi_filter_destroy_p(void);
static void utc_poi_filter_destroy_n(void);
static void utc_poi_filter_set_p(void);
static void utc_poi_filter_set_n(void);
static void utc_poi_filter_set_n_02(void);
static void utc_poi_filter_set_n_03(void);
static void utc_poi_filter_get_p(void);
static void utc_poi_filter_get_n(void);
static void utc_poi_filter_get_n_02(void);
static void utc_poi_filter_get_n_03(void);
static void utc_poi_filter_foreach_properties_p(void);
static void utc_poi_filter_foreach_properties_n(void);
static void utc_poi_filter_foreach_properties_n_02(void);
static void utc_poi_filter_foreach_available_keys_p(void);
static void utc_poi_filter_foreach_available_keys_n(void);
static void utc_poi_filter_foreach_available_keys_n_02(void);
static void utc_poi_filter_foreach_available_values_p(void);
static void utc_poi_filter_foreach_available_values_n(void);
static void utc_poi_filter_foreach_available_values_n_02(void);
static void utc_poi_filter_foreach_available_values_n_03(void);

struct tet_testlist tet_testlist[] = {
	{ utc_poi_service_create_p, POSITIVE_TC_IDX },
	{ utc_poi_service_create_n, NEGATIVE_TC_IDX },
	{ utc_poi_service_destroy_p, POSITIVE_TC_IDX },
	{ utc_poi_service_destroy_n, NEGATIVE_TC_IDX },
	{ utc_poi_service_get_preference_p, POSITIVE_TC_IDX },
	{ utc_poi_service_get_preference_n, NEGATIVE_TC_IDX },
	{ utc_poi_service_get_preference_n_02, NEGATIVE_TC_IDX },
	{ utc_poi_service_set_preference_p, POSITIVE_TC_IDX },
	{ utc_poi_service_set_preference_n, NEGATIVE_TC_IDX },
	{ utc_poi_service_set_preference_n_02, NEGATIVE_TC_IDX },
	{ utc_poi_service_search_p, POSITIVE_TC_IDX },
	{ utc_poi_service_search_n, NEGATIVE_TC_IDX },
	{ utc_poi_service_search_n_02, NEGATIVE_TC_IDX },
	{ utc_poi_service_search_n_03, NEGATIVE_TC_IDX },
	{ utc_poi_service_search_n_04, NEGATIVE_TC_IDX },
	//{ utc_poi_service_search_n_05, NEGATIVE_TC_IDX }, // It is not a negative TC.
	{ utc_poi_service_search_by_area_p, POSITIVE_TC_IDX },
	{ utc_poi_service_search_by_area_n, NEGATIVE_TC_IDX },
	{ utc_poi_service_search_by_area_n_02, NEGATIVE_TC_IDX },
	{ utc_poi_service_search_by_area_n_03, NEGATIVE_TC_IDX },
	//{ utc_poi_service_search_by_area_n_04, NEGATIVE_TC_IDX }, // It is not a negative TC.
	{ utc_poi_service_search_by_address_p, POSITIVE_TC_IDX },
	{ utc_poi_service_search_by_address_n, NEGATIVE_TC_IDX },
	{ utc_poi_service_search_by_address_n_02, NEGATIVE_TC_IDX },
	{ utc_poi_service_search_by_address_n_03, NEGATIVE_TC_IDX },
	//{ utc_poi_service_search_by_address_n_04, NEGATIVE_TC_IDX }, // It is not a negative TC.
	{ utc_poi_service_cancel_p, POSITIVE_TC_IDX },
	{ utc_poi_service_cancel_n, NEGATIVE_TC_IDX },
	//{ utc_poi_service_cancel_n_02, NEGATIVE_TC_IDX }, 	// It is not a negative TC.
	{ utc_poi_preference_create_p, POSITIVE_TC_IDX },
	{ utc_poi_preference_create_n, NEGATIVE_TC_IDX },
	{ utc_poi_preference_destroy_p, POSITIVE_TC_IDX },
	{ utc_poi_preference_destroy_n, NEGATIVE_TC_IDX },
	{ utc_poi_preference_get_p, POSITIVE_TC_IDX },
	{ utc_poi_preference_get_n, NEGATIVE_TC_IDX },
	{ utc_poi_preference_get_n_02, NEGATIVE_TC_IDX },
	{ utc_poi_preference_get_n_03, NEGATIVE_TC_IDX },
	{ utc_poi_preference_set_p, POSITIVE_TC_IDX },
	{ utc_poi_preference_set_n, NEGATIVE_TC_IDX },
	{ utc_poi_preference_set_n_02, NEGATIVE_TC_IDX },
//	{ utc_poi_preference_set_n_03, NEGATIVE_TC_IDX },		// TODO: Check
	{ utc_poi_preference_set_max_result_p, POSITIVE_TC_IDX },
	{ utc_poi_preference_set_max_result_n, NEGATIVE_TC_IDX },
//	{ utc_poi_preference_set_max_result_n_02, NEGATIVE_TC_IDX },	//TODO: Check range
	{ utc_poi_preference_get_max_result_p, POSITIVE_TC_IDX },
	{ utc_poi_preference_get_max_result_n, NEGATIVE_TC_IDX },
	{ utc_poi_preference_get_max_result_n_02, NEGATIVE_TC_IDX },
	{ utc_poi_preference_foreach_sortable_field_p, POSITIVE_TC_IDX },
	{ utc_poi_preference_foreach_sortable_field_n, NEGATIVE_TC_IDX },
	{ utc_poi_preference_foreach_sortable_field_n_02, NEGATIVE_TC_IDX },
	{ utc_poi_preference_set_sort_p, POSITIVE_TC_IDX },
	{ utc_poi_preference_set_sort_n, NEGATIVE_TC_IDX },
	{ utc_poi_preference_set_sort_n_02, NEGATIVE_TC_IDX },
//	{ utc_poi_preference_set_sort_n_03, NEGATIVE_TC_IDX },		//TODO: Check range
	{ utc_poi_preference_get_sort_p, POSITIVE_TC_IDX },
	{ utc_poi_preference_get_sort_n, NEGATIVE_TC_IDX },
	{ utc_poi_preference_get_sort_n_02, NEGATIVE_TC_IDX },
	{ utc_poi_preference_get_sort_n_03, NEGATIVE_TC_IDX },
	{ utc_poi_preference_foreach_properties_p, POSITIVE_TC_IDX },
	{ utc_poi_preference_foreach_properties_n, NEGATIVE_TC_IDX },
	{ utc_poi_preference_foreach_properties_n_02, NEGATIVE_TC_IDX },
	{ utc_poi_preference_foreach_available_keys_p, POSITIVE_TC_IDX },
	{ utc_poi_preference_foreach_available_keys_n, NEGATIVE_TC_IDX },
	{ utc_poi_preference_foreach_available_keys_n_02, NEGATIVE_TC_IDX },
	//{ utc_poi_preference_foreach_available_values_p, POSITIVE_TC_IDX }, // It is not a negative TC. value can be NULL.
	//{ utc_poi_preference_foreach_available_values_n, NEGATIVE_TC_IDX },
	//{ utc_poi_preference_foreach_available_values_n_02, NEGATIVE_TC_IDX },
	//{ utc_poi_preference_foreach_available_values_n_03, NEGATIVE_TC_IDX },
	{ utc_poi_filter_create_p, POSITIVE_TC_IDX },
	{ utc_poi_filter_create_n, NEGATIVE_TC_IDX },
	{ utc_poi_filter_destroy_p, POSITIVE_TC_IDX },
	{ utc_poi_filter_destroy_n, NEGATIVE_TC_IDX },
	{ utc_poi_filter_set_p, POSITIVE_TC_IDX },
	{ utc_poi_filter_set_n, NEGATIVE_TC_IDX },
	{ utc_poi_filter_set_n_02, NEGATIVE_TC_IDX },
	//{ utc_poi_filter_set_n_03, NEGATIVE_TC_IDX }, // It is not a negative TC. value can be NULL.
	{ utc_poi_filter_get_p, POSITIVE_TC_IDX },
	{ utc_poi_filter_get_n, NEGATIVE_TC_IDX },
	{ utc_poi_filter_get_n_02, NEGATIVE_TC_IDX },
	{ utc_poi_filter_get_n_03, NEGATIVE_TC_IDX },
	{ utc_poi_filter_foreach_properties_p, POSITIVE_TC_IDX },
	{ utc_poi_filter_foreach_properties_n, NEGATIVE_TC_IDX },
	{ utc_poi_filter_foreach_properties_n_02, NEGATIVE_TC_IDX },
	{ utc_poi_filter_foreach_available_keys_p, POSITIVE_TC_IDX },
	{ utc_poi_filter_foreach_available_keys_n, NEGATIVE_TC_IDX },
	{ utc_poi_filter_foreach_available_keys_n_02, NEGATIVE_TC_IDX }, 
	//{ utc_poi_filter_foreach_available_values_p, POSITIVE_TC_IDX }, //It is not implemented yet.
	//{ utc_poi_filter_foreach_available_values_n, NEGATIVE_TC_IDX },
	//{ utc_poi_filter_foreach_available_values_n_02, NEGATIVE_TC_IDX },
	//{ utc_poi_filter_foreach_available_values_n_03, NEGATIVE_TC_IDX },
	{ NULL, 0 },
};


static GMainLoop *g_mainloop = NULL;
static GThread *event_thread;

gpointer GmainThread(gpointer data){
	g_mainloop = g_main_loop_new (NULL, 0);
	g_main_loop_run (g_mainloop);

	return NULL;
}


static void validate_and_next(char* api_name,int act_ret, int ext_ret, char* fail_msg)
{
	dts_message(api_name, "Actual Result : %d, Expected Result : %d", act_ret,ext_ret);
	if (act_ret != ext_ret)
	{
		dts_message(api_name, "Fail Message: %s", fail_msg);
		dts_fail(api_name);
	}
}

static void validate_eq(char* api_name,int act_ret, int ext_ret)
{
	dts_message(api_name, "Actual Result : %d, Expected Result : %d", act_ret,ext_ret);
	if (act_ret == ext_ret) {
		dts_pass(api_name);
	} else {
		dts_fail(api_name);
	}
}


static void startup(void)
{
	g_setenv("PKG_NAME", "org.tizen.capi-location-poi-test", 1);
	g_setenv("LOCATION_TEST_ENABLE", "1", 1);

#if !GLIB_CHECK_VERSION (2, 31, 0)
	if( !g_thread_supported() )
	{
		g_thread_init(NULL);
	}
#endif

	GError *gerr = NULL;
	event_thread = g_thread_create(GmainThread, NULL, 1, &gerr);
}

static void cleanup(void)
{

	g_main_loop_quit (g_mainloop);
	g_thread_join(event_thread);
}

static void utc_poi_service_create_p(void)
{
	int ret = POI_ERROR_NONE;

	poi_service_h poi_manager ;
	ret = poi_service_create(&poi_manager);

	if (poi_manager) {
		poi_service_destroy(poi_manager);
	}

	validate_eq(__func__, ret, POI_ERROR_NONE);
}

static void utc_poi_service_create_n(void)
{
	int ret = POI_ERROR_NONE;

	ret = poi_service_create(NULL);
	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_service_destroy_p(void)
{
	int ret = POI_ERROR_NONE;

	poi_service_h poi_manager ;
	ret = poi_service_create(&poi_manager);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_create() is failed");

	ret = poi_service_destroy(poi_manager);
	validate_eq(__func__, ret, POI_ERROR_NONE);
}

static void utc_poi_service_destroy_n(void)
{
	int ret = POI_ERROR_NONE;

	ret = poi_service_destroy(NULL);
	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_service_get_preference_p(void)
{
	int ret = POI_ERROR_NONE;

	poi_service_h poi_manager ;
	ret = poi_service_create(&poi_manager);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_create() is failed");

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");

	ret = poi_preference_set_max_result(pref, 5);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_max_result() is failed");

	ret = poi_service_set_preference(poi_manager, pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_set_preference() is failed");

	poi_preference_h preference;
	ret = poi_service_get_preference(poi_manager, &preference);

	if (poi_manager) {
		// free pref also
		poi_service_destroy(poi_manager);
	}


	validate_eq(__func__, ret, POI_ERROR_NONE);
}

static void utc_poi_service_get_preference_n(void)
{
	int ret = POI_ERROR_NONE;

	poi_preference_h preference;
	ret = poi_service_get_preference(NULL, &preference);
	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_service_get_preference_n_02(void)
{
	int ret = POI_ERROR_NONE;

	poi_service_h poi_manager ;
	ret = poi_service_create(&poi_manager);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_create() is failed");

	ret = poi_service_get_preference(poi_manager, NULL);

	if (poi_manager) {
		poi_service_destroy(poi_manager);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}


static void utc_poi_service_set_preference_p(void)
{
	int ret = POI_ERROR_NONE;

	poi_service_h poi_manager ;
	ret = poi_service_create(&poi_manager);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_create() is failed");

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");

	ret = poi_preference_set_max_result(pref, 5);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_max_result() is failed");

	ret = poi_service_set_preference(poi_manager, pref);

	if (poi_manager) {
		poi_service_destroy(poi_manager);
	}


	validate_eq(__func__, ret, POI_ERROR_NONE);
}

static void utc_poi_service_set_preference_n(void)
{
	int ret = POI_ERROR_NONE;

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");

	ret = poi_preference_set_max_result(pref, 5);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_max_result() is failed");

	ret = poi_service_set_preference(NULL, pref);

	if (pref) {
		poi_preference_destroy(pref);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_service_set_preference_n_02(void)
{
	int ret = POI_ERROR_NONE;

	poi_service_h poi_manager ;
	ret = poi_service_create(&poi_manager);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_create() is failed");

	ret = poi_service_set_preference(poi_manager, NULL);

	if (poi_manager) {
		poi_service_destroy(poi_manager);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}


static bool capi_service_search_cb(poi_error_e error, int request_id , int index, int length , poi_h poi , void * user_data)
{
	dts_message(__func__, "capi_service_search_cb : error %d, index : %d", error, index);

	return true;
}

static void utc_poi_service_search_p(void)
{
	int ret = POI_ERROR_NONE;

	poi_service_h poi_manager ;
	ret = poi_service_create(&poi_manager);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_create() is failed");

	poi_filter_h filter;
	ret = poi_filter_create(&filter);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_filter_create() is failed");
	ret = poi_filter_set(filter, "CATEGORY", "restaurant");
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_filter_set() is failed");

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");
	ret = poi_preference_set_max_result(pref, 5);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_max_result() is failed");
	ret = poi_preference_set_sort(pref, "Distance", POI_SORTORDER_ASC);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_sort() is failed");
	ret = poi_service_set_preference(poi_manager, pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_set_preference() is failed");
	location_coords_s pos = {37.771008, -122.41175};

	ret = poi_service_search(poi_manager, pos, 100, filter, capi_service_search_cb , NULL, NULL);

	if (filter) {
		poi_filter_destroy(filter);
	}
	if (poi_manager) {
		poi_service_destroy(poi_manager);
	}

	validate_eq(__func__, ret, POI_ERROR_NONE);
}

static void utc_poi_service_search_n(void)
{
	int ret = POI_ERROR_NONE;

	poi_service_h poi_manager ;
	ret = poi_service_create(&poi_manager);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_create() is failed");

	poi_filter_h filter;
	ret = poi_filter_create(&filter);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_filter_create() is failed");
	ret = poi_filter_set(filter, "CATEGORY", "restaurant");
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_filter_set() is failed");

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");
	ret = poi_preference_set_max_result(pref, 5);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_max_result() is failed");
	ret = poi_preference_set_sort(pref, "Distance", POI_SORTORDER_ASC);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_sort() is failed");
	ret = poi_service_set_preference(poi_manager, pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_set_preference() is failed");
	location_coords_s pos = {37.771008, -122.41175};

	ret = poi_service_search(NULL, pos, 100, filter, capi_service_search_cb , NULL, NULL);

	if (filter) {
		poi_filter_destroy(filter);
	}
	if (poi_manager) {
		poi_service_destroy(poi_manager);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_service_search_n_02(void)
{
	int ret = POI_ERROR_NONE;

	poi_service_h poi_manager ;
	ret = poi_service_create(&poi_manager);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_create() is failed");

	poi_filter_h filter;
	ret = poi_filter_create(&filter);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_filter_create() is failed");
	ret = poi_filter_set(filter, "CATEGORY", "restaurant");
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_filter_set() is failed");

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");
	ret = poi_preference_set_max_result(pref, 5);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_max_result() is failed");
	ret = poi_preference_set_sort(pref, "Distance", POI_SORTORDER_ASC);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_sort() is failed");
	ret = poi_service_set_preference(poi_manager, pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_set_preference() is failed");
	location_coords_s pos = {91, 181};

	ret = poi_service_search(poi_manager, pos, 100, filter, capi_service_search_cb , NULL, NULL);

	if (filter) {
		poi_filter_destroy(filter);
	}
	if (poi_manager) {
		poi_service_destroy(poi_manager);
	}



	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_service_search_n_03(void)
{
	int ret = POI_ERROR_NONE;

	poi_service_h poi_manager ;
	ret = poi_service_create(&poi_manager);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_create() is failed");

	poi_filter_h filter;
	ret = poi_filter_create(&filter);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_filter_create() is failed");
	ret = poi_filter_set(filter, "CATEGORY", "restaurant");
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_filter_set() is failed");

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");
	ret = poi_preference_set_max_result(pref, 5);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_max_result() is failed");
	ret = poi_preference_set_sort(pref, "Distance", POI_SORTORDER_ASC);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_sort() is failed");
	ret = poi_service_set_preference(poi_manager, pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_set_preference() is failed");
	location_coords_s pos = {37.771008, -122.41175};

	ret = poi_service_search(poi_manager, pos, -1, filter, capi_service_search_cb , NULL, NULL);

	if (filter) {
		poi_filter_destroy(filter);
	}
	if (poi_manager) {
		poi_service_destroy(poi_manager);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_service_search_n_04(void)
{
	int ret = POI_ERROR_NONE;

	poi_service_h poi_manager ;
	ret = poi_service_create(&poi_manager);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_create() is failed");

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");
	ret = poi_preference_set_max_result(pref, 5);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_max_result() is failed");
	ret = poi_preference_set_sort(pref, "Distance", POI_SORTORDER_ASC);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_sort() is failed");
	ret = poi_service_set_preference(poi_manager, pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_set_preference() is failed");
	location_coords_s pos = {37.771008, -122.41175};

	ret = poi_service_search(poi_manager, pos, 100, NULL, capi_service_search_cb , NULL, NULL);

	if (poi_manager) {
		poi_service_destroy(poi_manager);
	}


	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_service_search_n_05(void)
{
	int ret = POI_ERROR_NONE;

	poi_service_h poi_manager ;
	ret = poi_service_create(&poi_manager);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_create() is failed");

	poi_filter_h filter;
	ret = poi_filter_create(&filter);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_filter_create() is failed");
	ret = poi_filter_set(filter, "CATEGORY", "restaurant");
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_filter_set() is failed");

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");
	ret = poi_preference_set_max_result(pref, 5);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_max_result() is failed");
	ret = poi_preference_set_sort(pref, "Distance", POI_SORTORDER_ASC);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_sort() is failed");
	ret = poi_service_set_preference(poi_manager, pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_set_preference() is failed");
	location_coords_s pos = {37.771008, -122.41175};

	ret = poi_service_search(poi_manager, pos, 100, filter, NULL , NULL, NULL);

	if (filter) {
		poi_filter_destroy(filter);
	}
	if (poi_manager) {
		poi_service_destroy(poi_manager);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}



static void utc_poi_service_search_by_area_p(void)
{
	int ret = POI_ERROR_NONE;

	poi_service_h poi_manager ;
	ret = poi_service_create(&poi_manager);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_create() is failed");

	poi_filter_h filter;
	ret = poi_filter_create(&filter);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_filter_create() is failed");
	ret = poi_filter_set(filter, "CATEGORY", "restaurant");
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_filter_set() is failed");

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");
	ret = poi_preference_set_max_result(pref, 5);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_max_result() is failed");
	ret = poi_preference_set_sort(pref, "Distance", POI_SORTORDER_ASC);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_sort() is failed");
	ret = poi_service_set_preference(poi_manager, pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_set_preference() is failed");

	location_coords_s center;
	center.latitude = 37.336723;
	center.longitude = -121.889555;
	double radius = 30;
	location_bounds_h bounds_circle = NULL;
	ret = location_bounds_create_circle(center, radius, &bounds_circle);
	validate_and_next(__func__, ret, LOCATION_BOUNDS_ERROR_NONE, "location_bounds_create_circle() is failed");

	ret = poi_service_search_by_area(poi_manager, bounds_circle, filter, capi_service_search_cb, NULL, NULL);

	if (filter) {
		poi_filter_destroy(filter);
	}
	if (poi_manager) {
		poi_service_destroy(poi_manager);
	}
	if (bounds_circle) {
		location_bounds_destroy(bounds_circle);
	}

	validate_eq(__func__, ret, POI_ERROR_NONE);
}

static void utc_poi_service_search_by_area_n(void)
{
	int ret = POI_ERROR_NONE;

	poi_service_h poi_manager ;
	ret = poi_service_create(&poi_manager);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_create() is failed");

	poi_filter_h filter;
	ret = poi_filter_create(&filter);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_filter_create() is failed");
	ret = poi_filter_set(filter, "CATEGORY", "restaurant");
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_filter_set() is failed");

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");
	ret = poi_preference_set_max_result(pref, 5);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_max_result() is failed");
	ret = poi_preference_set_sort(pref, "Distance", POI_SORTORDER_ASC);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_sort() is failed");
	ret = poi_service_set_preference(poi_manager, pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_set_preference() is failed");

	location_coords_s center;
	center.latitude = 37.336723;
	center.longitude = -121.889555;
	double radius = 30;
	location_bounds_h bounds_circle;
	ret = location_bounds_create_circle(center, radius, &bounds_circle);
	validate_and_next(__func__, ret, LOCATION_BOUNDS_ERROR_NONE, "location_bounds_create_circle() is failed");

	ret = poi_service_search_by_area(NULL, bounds_circle, filter, capi_service_search_cb, NULL, NULL);

	if (filter) {
		poi_filter_destroy(filter);
	}
	if (poi_manager) {
		poi_service_destroy(poi_manager);
	}
	if (bounds_circle) {
		location_bounds_destroy(bounds_circle);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_service_search_by_area_n_02(void)
{
	int ret = POI_ERROR_NONE;

	poi_service_h poi_manager ;
	ret = poi_service_create(&poi_manager);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_create() is failed");

	poi_filter_h filter;
	ret = poi_filter_create(&filter);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_filter_create() is failed");
	ret = poi_filter_set(filter, "CATEGORY", "restaurant");
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_filter_set() is failed");

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");
	ret = poi_preference_set_max_result(pref, 5);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_max_result() is failed");
	ret = poi_preference_set_sort(pref, "Distance", POI_SORTORDER_ASC);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_sort() is failed");
	ret = poi_service_set_preference(poi_manager, pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_set_preference() is failed");

	ret = poi_service_search_by_area(poi_manager, NULL, filter, capi_service_search_cb, NULL, NULL);

	if (filter) {
		poi_filter_destroy(filter);
	}
	if (poi_manager) {
		poi_service_destroy(poi_manager);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_service_search_by_area_n_03(void)
{
	int ret = POI_ERROR_NONE;

	poi_service_h poi_manager ;
	ret = poi_service_create(&poi_manager);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_create() is failed");

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");
	ret = poi_preference_set_max_result(pref, 5);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_max_result() is failed");
	ret = poi_preference_set_sort(pref, "Distance", POI_SORTORDER_ASC);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_sort() is failed");
	ret = poi_service_set_preference(poi_manager, pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_set_preference() is failed");

	location_coords_s center;
	center.latitude = 37.336723;
	center.longitude = -121.889555;
	double radius = 30;
	location_bounds_h bounds_circle;
	ret = location_bounds_create_circle(center, radius, &bounds_circle);
	validate_and_next(__func__, ret, LOCATION_BOUNDS_ERROR_NONE, "location_bounds_create_circle() is failed");

	ret = poi_service_search_by_area(poi_manager, bounds_circle, NULL, capi_service_search_cb, NULL, NULL);

	if (poi_manager) {
		poi_service_destroy(poi_manager);
	}
	if (bounds_circle) {
		location_bounds_destroy(bounds_circle);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_service_search_by_area_n_04(void)
{
	int ret = POI_ERROR_NONE;

	poi_service_h poi_manager ;
	ret = poi_service_create(&poi_manager);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_create() is failed");

	poi_filter_h filter;
	ret = poi_filter_create(&filter);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_filter_create() is failed");
	ret = poi_filter_set(filter, "CATEGORY", "restaurant");
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_filter_set() is failed");

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");
	ret = poi_preference_set_max_result(pref, 5);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_max_result() is failed");
	ret = poi_preference_set_sort(pref, "Distance", POI_SORTORDER_ASC);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_sort() is failed");
	ret = poi_service_set_preference(poi_manager, pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_set_preference() is failed");

	location_coords_s center;
	center.latitude = 37.336723;
	center.longitude = -121.889555;
	double radius = 30;
	location_bounds_h bounds_circle;
	ret = location_bounds_create_circle(center, radius, &bounds_circle);
	validate_and_next(__func__, ret, LOCATION_BOUNDS_ERROR_NONE, "location_bounds_create_circle() is failed");

	ret = poi_service_search_by_area(poi_manager, bounds_circle, filter, NULL, NULL, NULL);

	if (filter) {
		poi_filter_destroy(filter);
	}
	if (poi_manager) {
		poi_service_destroy(poi_manager);
	}
	if (bounds_circle) {
		location_bounds_destroy(bounds_circle);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_service_search_by_address_p(void)
{
	int ret = POI_ERROR_NONE;

	poi_service_h poi_manager ;
	ret = poi_service_create(&poi_manager);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_create() is failed");

	poi_filter_h filter;
	ret = poi_filter_create(&filter);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_filter_create() is failed");
	ret = poi_filter_set(filter, "KEYWORD", "restaurant");
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_filter_set() is failed");

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");
	ret = poi_preference_set_max_result(pref, 5);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_max_result() is failed");
	ret = poi_preference_set_sort(pref, "Distance", POI_SORTORDER_ASC);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_sort() is failed");
	ret = poi_service_set_preference(poi_manager, pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_set_preference() is failed");

	char *addr = strdup("North Second St.");
	ret = poi_service_search_by_address(poi_manager, addr, NULL, filter, capi_service_search_cb, NULL, NULL);

	if (filter) {
		poi_filter_destroy(filter);
	}
	if (poi_manager) {
		poi_service_destroy(poi_manager);
	}

	validate_eq(__func__, ret, POI_ERROR_NONE);
}

static void utc_poi_service_search_by_address_n(void)
{
	int ret = POI_ERROR_NONE;

	poi_service_h poi_manager ;
	ret = poi_service_create(&poi_manager);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_create() is failed");

	poi_filter_h filter;
	ret = poi_filter_create(&filter);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_filter_create() is failed");
	ret = poi_filter_set(filter, "KEYWORD", "restaurant");
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_filter_set() is failed");

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");
	ret = poi_preference_set_max_result(pref, 5);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_max_result() is failed");
	ret = poi_preference_set_sort(pref, "Distance", POI_SORTORDER_ASC);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_sort() is failed");
	ret = poi_service_set_preference(poi_manager, pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_set_preference() is failed");

	char *addr = strdup("North Second St.");
	ret = poi_service_search_by_address(NULL, addr, NULL, filter, capi_service_search_cb, NULL, NULL);

	if (filter) {
		poi_filter_destroy(filter);
	}
	if (poi_manager) {
		poi_service_destroy(poi_manager);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_service_search_by_address_n_02(void)
{
	int ret = POI_ERROR_NONE;

	poi_service_h poi_manager ;
	ret = poi_service_create(&poi_manager);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_create() is failed");

	poi_filter_h filter;
	ret = poi_filter_create(&filter);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_filter_create() is failed");
	ret = poi_filter_set(filter, "KEYWORD", "restaurant");
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_filter_set() is failed");

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");
	ret = poi_preference_set_max_result(pref, 5);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_max_result() is failed");
	ret = poi_preference_set_sort(pref, "Distance", POI_SORTORDER_ASC);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_sort() is failed");
	ret = poi_service_set_preference(poi_manager, pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_set_preference() is failed");

	ret = poi_service_search_by_address(poi_manager, NULL, NULL, filter, capi_service_search_cb, NULL, NULL);

	if (filter) {
		poi_filter_destroy(filter);
	}
	if (poi_manager) {
		poi_service_destroy(poi_manager);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}


static void utc_poi_service_search_by_address_n_03(void)
{
	int ret = POI_ERROR_NONE;

	poi_service_h poi_manager ;
	ret = poi_service_create(&poi_manager);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_create() is failed");

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");
	ret = poi_preference_set_max_result(pref, 5);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_max_result() is failed");
	ret = poi_preference_set_sort(pref, "Distance", POI_SORTORDER_ASC);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_sort() is failed");
	ret = poi_service_set_preference(poi_manager, pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_set_preference() is failed");

	char *addr = strdup("North Second St.");
	ret = poi_service_search_by_address(poi_manager, addr, NULL, NULL, capi_service_search_cb, NULL, NULL);

	if (poi_manager) {
		poi_service_destroy(poi_manager);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_service_search_by_address_n_04(void)
{
	int ret = POI_ERROR_NONE;

	poi_service_h poi_manager ;
	ret = poi_service_create(&poi_manager);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_create() is failed");

	poi_filter_h filter;
	ret = poi_filter_create(&filter);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_filter_create() is failed");
	ret = poi_filter_set(filter, "KEYWORD", "restaurant");
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_filter_set() is failed");

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");
	ret = poi_preference_set_max_result(pref, 5);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_max_result() is failed");
	ret = poi_preference_set_sort(pref, "Distance", POI_SORTORDER_ASC);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_sort() is failed");
	ret = poi_service_set_preference(poi_manager, pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_set_preference() is failed");

	char *addr = strdup("North Second St.");
	ret = poi_service_search_by_address(poi_manager, addr, NULL, filter, NULL, NULL, NULL);

	if (filter) {
		poi_filter_destroy(filter);
	}
	if (poi_manager) {
		poi_service_destroy(poi_manager);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_service_cancel_p(void)
{
	int ret = POI_ERROR_NONE;

	poi_service_h poi_manager ;
	ret = poi_service_create(&poi_manager);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_create() is failed");

	int request_id = 1;
	ret = poi_service_cancel(poi_manager, request_id);

	if (poi_manager) {
		poi_service_destroy(poi_manager);
	}

	validate_eq(__func__, ret, POI_ERROR_NONE);
}

static void utc_poi_service_cancel_n(void)
{
	int ret = POI_ERROR_NONE;

	int request_id = 1;
	ret = poi_service_cancel(NULL, request_id);

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);

}

static void utc_poi_service_cancel_n_02(void)
{
	int ret = POI_ERROR_NONE;

	poi_service_h poi_manager ;
	ret = poi_service_create(&poi_manager);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_create() is failed");

	ret = poi_service_cancel(poi_manager, -1);

	if (poi_manager) {
		poi_service_destroy(poi_manager);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);

}

static void utc_poi_preference_create_p(void)
{
	int ret = POI_ERROR_NONE;

	poi_preference_h pref;
	ret = poi_preference_create(&pref);

	if (pref) {
		poi_preference_destroy(pref);
	}

	validate_eq(__func__, ret, POI_ERROR_NONE);

}

static void utc_poi_preference_create_n(void)
{
	int ret = POI_ERROR_NONE;

	ret = poi_preference_create(NULL);
	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);

}



static void utc_poi_preference_destroy_p(void)
{
	int ret = POI_ERROR_NONE;

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");

	ret = poi_preference_destroy(pref);

	validate_eq(__func__, ret, POI_ERROR_NONE);
}

static void utc_poi_preference_destroy_n(void)
{
	int ret = POI_ERROR_NONE;

	ret = poi_preference_destroy(NULL);
	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);

}

static void utc_poi_preference_get_p(void)
{
	int ret = POI_ERROR_NONE;

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");

	ret = poi_preference_set(pref, "LandmarkName", "cafe");
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set() is failed");

	char *value;
	ret = poi_preference_get(pref, "LandmarkName", &value);

	if (pref) {
		poi_preference_destroy(pref);
	}

	validate_eq(__func__, ret, POI_ERROR_NONE);
}

static void utc_poi_preference_get_n(void)
{
	int ret = POI_ERROR_NONE;

	char *value;
	ret = poi_preference_get(NULL, "LandmarkName", &value);
	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);

}

static void utc_poi_preference_get_n_02(void)
{
	int ret = POI_ERROR_NONE;

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");

	ret = poi_preference_set(pref, "LandmarkName", "cafe");
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set() is failed");

	char *value;
	ret = poi_preference_get(pref, NULL, &value);

	if (pref) {
		poi_preference_destroy(pref);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);

}

static void utc_poi_preference_get_n_03(void)
{
	int ret = POI_ERROR_NONE;

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");

	ret = poi_preference_set(pref, "LandmarkName", "cafe");
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set() is failed");

	ret = poi_preference_get(pref, "LandmarkName", NULL);

	if (pref) {
		poi_preference_destroy(pref);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);

}


static void utc_poi_preference_set_p(void)
{
	int ret = POI_ERROR_NONE;

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");

	ret = poi_preference_set(pref, "LandmarkName", "cafe");

	if (pref) {
		poi_preference_destroy(pref);
	}

	validate_eq(__func__, ret, POI_ERROR_NONE);
}

static void utc_poi_preference_set_n(void)
{
	int ret = POI_ERROR_NONE;

	char *value;
	ret = poi_preference_set(NULL, "LandmarkName", "cafe");
	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);

}

static void utc_poi_preference_set_n_02(void)
{
	int ret = POI_ERROR_NONE;

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");

	ret = poi_preference_set(pref, NULL, "cafe");

	if (pref) {
		poi_preference_destroy(pref);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);

}

static void utc_poi_preference_set_n_03(void)
{
	int ret = POI_ERROR_NONE;

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");

	ret = poi_preference_set(pref, "LandmarkName", NULL);

	if (pref) {
		poi_preference_destroy(pref);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);

}

static void utc_poi_preference_set_max_result_p(void)
{
	int ret = POI_ERROR_NONE;

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");

	ret = poi_preference_set_max_result(pref, 5);

	if (pref) {
		poi_preference_destroy(pref);
	}

	validate_eq(__func__, ret, POI_ERROR_NONE);
}

static void utc_poi_preference_set_max_result_n(void)
{
	int ret = POI_ERROR_NONE;

	ret = poi_preference_set_max_result(NULL, 5);
	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);

}

static void utc_poi_preference_set_max_result_n_02(void)
{
	int ret = POI_ERROR_NONE;

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");

	ret = poi_preference_set_max_result(pref, -1);

	if (pref) {
		poi_preference_destroy(pref);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);

}

static void utc_poi_preference_get_max_result_p(void)
{
	int ret = POI_ERROR_NONE;

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");

	ret = poi_preference_set_max_result(pref, 5);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_max_result() is failed");

	int max_result;
	ret = poi_preference_get_max_result(pref, &max_result);

	if (pref) {
		poi_preference_destroy(pref);
	}

	validate_eq(__func__, ret, POI_ERROR_NONE);
}

static void utc_poi_preference_get_max_result_n(void)
{
	int ret = POI_ERROR_NONE;

	int max_result;
	ret = poi_preference_get_max_result(NULL, &max_result);
	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);

}

static void utc_poi_preference_get_max_result_n_02(void)
{
	int ret = POI_ERROR_NONE;


	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");

	ret = poi_preference_set_max_result(pref, 5);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_max_result() is failed");

	ret = poi_preference_get_max_result(pref, NULL);

	if (pref) {
		poi_preference_destroy(pref);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);

}

static bool capi_poi_preference_sortable_field_cb(const char *field , void *user_data)
{
	return true;
}

static void utc_poi_preference_foreach_sortable_field_p(void)
{
	int ret = POI_ERROR_NONE;

	poi_service_h poi_manager ;
	ret = poi_service_create(&poi_manager);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_create() is failed");

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");
	ret = poi_preference_set_max_result(pref, 5);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_max_result() is failed");
	ret = poi_preference_set_sort(pref, "Distance", POI_SORTORDER_ASC);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_sort() is failed");
	ret = poi_service_set_preference(poi_manager, pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_set_preference() is failed");

	ret = poi_preference_foreach_sortable_field(poi_manager, capi_poi_preference_sortable_field_cb, NULL);

	if (poi_manager) {
		poi_service_destroy(poi_manager);
	}

	validate_eq(__func__, ret, POI_ERROR_NONE);
}

static void utc_poi_preference_foreach_sortable_field_n(void)
{
	int ret = POI_ERROR_NONE;

	ret = poi_preference_foreach_sortable_field(NULL, capi_poi_preference_sortable_field_cb, NULL);
	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);

}


static void utc_poi_preference_foreach_sortable_field_n_02(void)
{
	int ret = POI_ERROR_NONE;

	poi_service_h poi_manager ;
	ret = poi_service_create(&poi_manager);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_create() is failed");

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");
	ret = poi_preference_set_max_result(pref, 5);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_max_result() is failed");
	ret = poi_preference_set_sort(pref, "Distance", POI_SORTORDER_ASC);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_sort() is failed");
	ret = poi_service_set_preference(poi_manager, pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_set_preference() is failed");

	ret = poi_preference_foreach_sortable_field(poi_manager, NULL, NULL);

	if (poi_manager) {
		poi_service_destroy(poi_manager);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);

}

static void utc_poi_preference_set_sort_p(void)
{
	int ret = POI_ERROR_NONE;

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");

	ret = poi_preference_set_sort(pref, "Distance", POI_SORTORDER_ASC);

	if (pref) {
		poi_preference_destroy(pref);
	}

	validate_eq(__func__, ret, POI_ERROR_NONE);
}

static void utc_poi_preference_set_sort_n(void)
{
	int ret = POI_ERROR_NONE;

	ret = poi_preference_set_sort(NULL, "Distance", POI_SORTORDER_ASC);
	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);

}


static void utc_poi_preference_set_sort_n_02(void)
{
	int ret = POI_ERROR_NONE;

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");

	ret = poi_preference_set_sort(pref, NULL, POI_SORTORDER_ASC);

	if (pref) {
		poi_preference_destroy(pref);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);

}

static void utc_poi_preference_set_sort_n_03(void)
{
	int ret = POI_ERROR_NONE;

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");

	ret = poi_preference_set_sort(pref, "Distance", (poi_sort_order_e)5);

	if (pref) {
		poi_preference_destroy(pref);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);

}

static void utc_poi_preference_get_sort_p(void)
{
	int ret = POI_ERROR_NONE;

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");

	ret = poi_preference_set_sort(pref, "Distance", POI_SORTORDER_ASC);

	poi_sort_order_e order;
	char *sort_item = NULL;
	ret = poi_preference_get_sort(pref, &sort_item, &order);

	if (pref) {
		poi_preference_destroy(pref);
	}
	if (sort_item) free(sort_item);

	validate_eq(__func__, ret, POI_ERROR_NONE);
}

static void utc_poi_preference_get_sort_n(void)
{
	int ret = POI_ERROR_NONE;

	poi_sort_order_e order;
	char *sort_item = NULL;
	ret = poi_preference_get_sort(NULL, &sort_item, &order);
	if (sort_item) free(sort_item);

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);

}

static void utc_poi_preference_get_sort_n_02(void)
{
	int ret = POI_ERROR_NONE;

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");

	ret = poi_preference_set_sort(pref, "Distance", POI_SORTORDER_ASC);

	poi_sort_order_e order;
	ret = poi_preference_get_sort(pref, NULL, &order);

	if (pref) {
		poi_preference_destroy(pref);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);

}

static void utc_poi_preference_get_sort_n_03(void)
{
	int ret = POI_ERROR_NONE;

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");

	ret = poi_preference_set_sort(pref, "Distance", POI_SORTORDER_ASC);

	poi_sort_order_e order;
	char *sort_item = NULL;
	ret = poi_preference_get_sort(pref, &sort_item, NULL);

	if (pref) {
		poi_preference_destroy(pref);
	}

	if (sort_item) free(sort_item);

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);

}

static bool capi_poi_preference_properties_cb(const char *key , const char *value,  void *user_data)
{
	return true;
}

static void utc_poi_preference_foreach_properties_p(void)
{
	int ret = POI_ERROR_NONE;

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");

	ret = poi_preference_set(pref, "LandmarkName", "cafe");
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set() is failed");

	ret = poi_preference_set(pref, "LandmarkType", "restaurant");
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set() is failed");

	ret = poi_preference_foreach_properties(pref, capi_poi_preference_properties_cb, NULL);

	if (pref) {
		poi_preference_destroy(pref);
	}

	validate_eq(__func__, ret, POI_ERROR_NONE);
}

static void utc_poi_preference_foreach_properties_n(void)
{
	int ret = POI_ERROR_NONE;

	ret = poi_preference_foreach_properties(NULL, capi_poi_preference_properties_cb, NULL);
	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);

}

static void utc_poi_preference_foreach_properties_n_02(void)
{
	int ret = POI_ERROR_NONE;

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");

	ret = poi_preference_set(pref, "LandmarkName", "cafe");
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set() is failed");

	ret = poi_preference_set(pref, "LandmarkType", "restaurant");
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set() is failed");

	ret = poi_preference_foreach_properties(pref, NULL, NULL);

	if (pref) {
		poi_preference_destroy(pref);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);

}

static bool capi_poi_preference_available_key_cb(const char *key , void *user_data)
{
	return true;
}

static void utc_poi_preference_foreach_available_keys_p(void)
{
	int ret = POI_ERROR_NONE;

	poi_service_h poi_manager ;
	ret = poi_service_create(&poi_manager);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_create() is failed");

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");
	ret = poi_preference_set_max_result(pref, 5);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_max_result() is failed");
	ret = poi_preference_set_sort(pref, "Distance", POI_SORTORDER_ASC);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_sort() is failed");
	ret = poi_service_set_preference(poi_manager, pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_set_preference() is failed");

	ret = poi_preference_foreach_available_keys(poi_manager, capi_poi_preference_available_key_cb, NULL);

	if (poi_manager) {
		poi_service_destroy(poi_manager);
	}

	validate_eq(__func__, ret, POI_ERROR_NONE);
}

static void utc_poi_preference_foreach_available_keys_n(void)
{
	int ret = POI_ERROR_NONE;

	ret = poi_preference_foreach_available_keys(NULL, capi_poi_preference_available_key_cb, NULL);
	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);

}

static void utc_poi_preference_foreach_available_keys_n_02(void)
{
	int ret = POI_ERROR_NONE;

	poi_service_h poi_manager ;
	ret = poi_service_create(&poi_manager);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_create() is failed");

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");
	ret = poi_preference_set_max_result(pref, 5);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_max_result() is failed");
	ret = poi_preference_set_sort(pref, "Distance", POI_SORTORDER_ASC);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_sort() is failed");
	ret = poi_service_set_preference(poi_manager, pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_set_preference() is failed");

	ret = poi_preference_foreach_available_keys(poi_manager, NULL, NULL);

	if (poi_manager) {
		poi_service_destroy(poi_manager);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);

}


static bool capi_poi_preference_available_value_cb(const char *value , void *user_data)
{
	return true;
}

static void utc_poi_preference_foreach_available_values_p(void)
{
	int ret = POI_ERROR_NONE;

	poi_service_h poi_manager ;
	ret = poi_service_create(&poi_manager);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_create() is failed");

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");
	ret = poi_preference_set_max_result(pref, 5);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_max_result() is failed");
	ret = poi_preference_set_sort(pref, "Distance", POI_SORTORDER_ASC);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_sort() is failed");
	ret = poi_service_set_preference(poi_manager, pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_set_preference() is failed");

	ret = poi_preference_foreach_available_values(poi_manager, "KEYWORD", capi_poi_preference_available_value_cb, NULL);

	if (poi_manager) {
		poi_service_destroy(poi_manager);
	}

	validate_eq(__func__, ret, POI_ERROR_NONE);
}

static void utc_poi_preference_foreach_available_values_n(void)
{
	int ret = POI_ERROR_NONE;

	ret = poi_preference_foreach_available_values(NULL, "KEYWORD", capi_poi_preference_available_value_cb, NULL);

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);

}

static void utc_poi_preference_foreach_available_values_n_02(void)
{
	int ret = POI_ERROR_NONE;

	poi_service_h poi_manager ;
	ret = poi_service_create(&poi_manager);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_create() is failed");

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");
	ret = poi_preference_set_max_result(pref, 5);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_max_result() is failed");
	ret = poi_preference_set_sort(pref, "Distance", POI_SORTORDER_ASC);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_sort() is failed");
	ret = poi_service_set_preference(poi_manager, pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_set_preference() is failed");

	ret = poi_preference_foreach_available_values(poi_manager, NULL, capi_poi_preference_available_value_cb, NULL);

	if (poi_manager) {
		poi_service_destroy(poi_manager);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);

}

static void utc_poi_preference_foreach_available_values_n_03(void)
{
	int ret = POI_ERROR_NONE;

	poi_service_h poi_manager ;
	ret = poi_service_create(&poi_manager);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_create() is failed");

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");
	ret = poi_preference_set_max_result(pref, 5);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_max_result() is failed");
	ret = poi_preference_set_sort(pref, "Distance", POI_SORTORDER_ASC);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_sort() is failed");
	ret = poi_service_set_preference(poi_manager, pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_set_preference() is failed");

	ret = poi_preference_foreach_available_values(poi_manager, "KEYWORD", NULL, NULL);

	if (poi_manager) {
		poi_service_destroy(poi_manager);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);

}


static void utc_poi_filter_create_p(void)
{
	int ret = POI_ERROR_NONE;

	poi_filter_h filter;
	ret = poi_filter_create(&filter);

	if (filter) {
		poi_filter_destroy(filter);
	}

	validate_eq(__func__, ret, POI_ERROR_NONE);
}

static void utc_poi_filter_create_n(void)
{
	int ret = POI_ERROR_NONE;

	ret = poi_filter_create(NULL);
	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_filter_destroy_p(void)
{
	int ret = POI_ERROR_NONE;

	poi_filter_h filter;
	ret = poi_filter_create(&filter);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_filter_create() is failed");

	ret = poi_filter_destroy(filter);
	validate_eq(__func__, ret, POI_ERROR_NONE);
}

static void utc_poi_filter_destroy_n(void)
{
	int ret = POI_ERROR_NONE;

	ret = poi_filter_destroy(NULL);
	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_filter_set_p(void)
{
	int ret = POI_ERROR_NONE;

	poi_filter_h filter;
	ret = poi_filter_create(&filter);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_filter_create() is failed");

	// "CATEGORY", "KEYWORD", "POINAME"
	ret = poi_filter_set(filter, "KEYWORD", "cafe");

	if (filter) {
		poi_filter_destroy(filter);
	}

	validate_eq(__func__, ret, POI_ERROR_NONE);
}

static void utc_poi_filter_set_n(void)
{
	int ret = POI_ERROR_NONE;

	ret = poi_filter_set(NULL, "KEYWORD", "cafe");
	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_filter_set_n_02(void)
{
	int ret = POI_ERROR_NONE;

	poi_filter_h filter;
	ret = poi_filter_create(&filter);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_filter_create() is failed");

	ret = poi_filter_set(filter, NULL, "cafe");

	if (filter) {
		poi_filter_destroy(filter);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_filter_set_n_03(void)
{
	int ret = POI_ERROR_NONE;

	poi_filter_h filter;
	ret = poi_filter_create(&filter);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_filter_create() is failed");

	ret = poi_filter_set(filter, "KEYWORD", NULL);

	if (filter) {
		poi_filter_destroy(filter);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_filter_get_p(void)
{
	int ret = POI_ERROR_NONE;

	poi_filter_h filter;
	ret = poi_filter_create(&filter);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_filter_create() is failed");

	// "CATEGORY", "KEYWORD", "POINAME"
	ret = poi_filter_set(filter, "KEYWORD", "cafe");
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_filter_set() is failed");

	char *value;
	ret = poi_filter_get(filter, "KEYWORD", &value);

	if (filter) {
		poi_filter_destroy(filter);
	}

	validate_eq(__func__, ret, POI_ERROR_NONE);
}

static void utc_poi_filter_get_n(void)
{
	int ret = POI_ERROR_NONE;

	char *value;
	ret = poi_filter_get(NULL, "KEYWORD", &value);
	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_filter_get_n_02(void)
{
	int ret = POI_ERROR_NONE;

	poi_filter_h filter;
	ret = poi_filter_create(&filter);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_filter_create() is failed");

	// "CATEGORY", "KEYWORD", "POINAME"
	ret = poi_filter_set(filter, "KEYWORD", "cafe");
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_filter_set() is failed");

	char *value;
	ret = poi_filter_get(filter, NULL, &value);

	if (filter) {
		poi_filter_destroy(filter);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_filter_get_n_03(void)
{
	int ret = POI_ERROR_NONE;

	poi_filter_h filter;
	ret = poi_filter_create(&filter);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_filter_create() is failed");

	// "CATEGORY", "KEYWORD", "POINAME"
	ret = poi_filter_set(filter, "KEYWORD", "cafe");
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_filter_set() is failed");

	char *value;
	ret = poi_filter_get(filter, "KEYWORD", NULL);

	if (filter) {
		poi_filter_destroy(filter);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static bool capi_poi_filter_properties_cb(const char *key , const char *value , void *user_data)
{
	return true;
}

static void utc_poi_filter_foreach_properties_p(void)
{
	int ret = POI_ERROR_NONE;

	poi_filter_h filter;
	ret = poi_filter_create(&filter);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_filter_create() is failed");

	// "CATEGORY", "KEYWORD", "POINAME"
	ret = poi_filter_set(filter, "KEYWORD", "cafe");
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_filter_set() is failed");

	ret = poi_filter_set(filter, "CATEGORY", "restaurant");
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_filter_set() is failed");

	ret = poi_filter_foreach_properties(filter, capi_poi_filter_properties_cb, NULL);

	if (filter) {
		poi_filter_destroy(filter);
	}

	validate_eq(__func__, ret, POI_ERROR_NONE);
}

static void utc_poi_filter_foreach_properties_n(void)
{
	int ret = POI_ERROR_NONE;

	ret = poi_filter_foreach_properties(NULL, capi_poi_filter_properties_cb, NULL);
	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_filter_foreach_properties_n_02(void)
{
	int ret = POI_ERROR_NONE;

	poi_filter_h filter;
	ret = poi_filter_create(&filter);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_filter_create() is failed");

	// "CATEGORY", "KEYWORD", "POINAME"
	ret = poi_filter_set(filter, "KEYWORD", "cafe");
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_filter_set() is failed");

	ret = poi_filter_set(filter, "CATEGORY", "restaurant");
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_filter_set() is failed");

	ret = poi_filter_foreach_properties(filter, NULL, NULL);

	if (filter) {
		poi_filter_destroy(filter);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static bool capi_poi_filter_available_key_cb(const char *key , void *user_data)
{
	return true;
}

static void utc_poi_filter_foreach_available_keys_p(void)
{
	int ret = POI_ERROR_NONE;

	poi_service_h poi_manager ;
	ret = poi_service_create(&poi_manager);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_create() is failed");

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");
	ret = poi_preference_set_max_result(pref, 5);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_max_result() is failed");
	ret = poi_preference_set_sort(pref, "Distance", POI_SORTORDER_ASC);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_sort() is failed");
	ret = poi_service_set_preference(poi_manager, pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_set_preference() is failed");

	ret = poi_filter_foreach_available_keys(poi_manager, capi_poi_filter_available_key_cb, NULL);

	if (poi_manager) {
		poi_service_destroy(poi_manager);
	}

	validate_eq(__func__, ret, POI_ERROR_NONE);
}

static void utc_poi_filter_foreach_available_keys_n(void)
{
	int ret = POI_ERROR_NONE;

	poi_service_h poi_manager ;
	ret = poi_service_create(&poi_manager);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_create() is failed");

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");
	ret = poi_preference_set_max_result(pref, 5);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_max_result() is failed");
	ret = poi_preference_set_sort(pref, "Distance", POI_SORTORDER_ASC);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_sort() is failed");
	ret = poi_service_set_preference(poi_manager, pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_set_preference() is failed");

	ret = poi_filter_foreach_available_keys(poi_manager, NULL, NULL);

	if (poi_manager) {
		poi_service_destroy(poi_manager);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_filter_foreach_available_keys_n_02(void)
{
	int ret = POI_ERROR_NONE;

	ret = poi_filter_foreach_available_keys(NULL, capi_poi_filter_available_key_cb, NULL);

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}


static bool capi_poi_filter_available_value_cb(const char *value , void *user_data)
{
	return true;
}

static void utc_poi_filter_foreach_available_values_p(void)
{
	int ret = POI_ERROR_NONE;

	poi_service_h poi_manager ;
	ret = poi_service_create(&poi_manager);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_create() is failed");

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");
	ret = poi_preference_set_max_result(pref, 5);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_max_result() is failed");
	ret = poi_preference_set_sort(pref, "Distance", POI_SORTORDER_ASC);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_sort() is failed");
	ret = poi_service_set_preference(poi_manager, pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_set_preference() is failed");

	ret = poi_filter_foreach_available_values(poi_manager, "KEYWORD", capi_poi_filter_available_value_cb, NULL);

	if (poi_manager) {
		poi_service_destroy(poi_manager);
	}

	validate_eq(__func__, ret, POI_ERROR_NONE);
}

static void utc_poi_filter_foreach_available_values_n(void)
{
	int ret = POI_ERROR_NONE;

	poi_service_h poi_manager ;
	ret = poi_service_create(&poi_manager);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_create() is failed");

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");
	ret = poi_preference_set_max_result(pref, 5);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_max_result() is failed");
	ret = poi_preference_set_sort(pref, "Distance", POI_SORTORDER_ASC);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_sort() is failed");
	ret = poi_service_set_preference(poi_manager, pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_set_preference() is failed");

	ret = poi_filter_foreach_available_values(poi_manager, NULL, capi_poi_filter_available_value_cb, NULL);

	if (poi_manager) {
		poi_service_destroy(poi_manager);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_filter_foreach_available_values_n_02(void)
{
	int ret = POI_ERROR_NONE;

	poi_service_h poi_manager ;
	ret = poi_service_create(&poi_manager);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_create() is failed");

	poi_preference_h pref;
	ret = poi_preference_create(&pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_create() is failed");
	ret = poi_preference_set_max_result(pref, 5);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_max_result() is failed");
	ret = poi_preference_set_sort(pref, "Distance", POI_SORTORDER_ASC);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_preference_set_sort() is failed");
	ret = poi_service_set_preference(poi_manager, pref);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_set_preference() is failed");

	ret = poi_filter_foreach_available_values(poi_manager, "KEYWORD", NULL, NULL);

	if (poi_manager) {
		poi_service_destroy(poi_manager);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_filter_foreach_available_values_n_03(void)
{
	int ret = POI_ERROR_NONE;

	ret = poi_filter_foreach_available_values(NULL, "KEYWORD", capi_poi_filter_available_value_cb, NULL);

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}



