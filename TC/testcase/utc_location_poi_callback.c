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


static void utc_poi_create_p(void);
static void utc_poi_create_n(void);
static void utc_poi_destroy_p(void);
static void utc_poi_destroy_n(void);
static void utc_poi_clone_p(void);
static void utc_poi_clone_n(void);
static void utc_poi_clone_n_02(void);
static void utc_poi_get_id_p(void);
static void utc_poi_get_id_n(void);
static void utc_poi_get_id_n_02(void);
static void utc_poi_get_name_p(void);
static void utc_poi_get_name_n(void);
static void utc_poi_get_name_n_02(void);
static void utc_poi_get_position_p(void);
static void utc_poi_get_position_n(void);
static void utc_poi_get_position_n_02(void);
static void utc_poi_get_address_p(void);
static void utc_poi_get_address_n(void);
static void utc_poi_get_address_n_02(void);
static void utc_poi_get_address_n_03(void);
static void utc_poi_get_address_n_04(void);
static void utc_poi_get_address_n_05(void);
static void utc_poi_get_address_n_06(void);
static void utc_poi_get_address_n_07(void);
static void utc_poi_get_address_n_08(void);
static void utc_poi_get_description_p(void);
static void utc_poi_get_description_n(void);
static void utc_poi_get_description_n_02(void);
static void utc_poi_get_timestamp_p(void);
static void utc_poi_get_timestamp_n(void);
static void utc_poi_get_timestamp_n_02(void);
static void utc_poi_get_bounding_rect_p(void);
static void utc_poi_get_bounding_rect_n(void);
static void utc_poi_get_bounding_rect_n_02(void);
static void utc_poi_get_bounding_rect_n_03(void);
static void utc_poi_get_author_p(void);
static void utc_poi_get_author_n(void);
static void utc_poi_get_author_n_02(void);
static void utc_poi_get_phone_number_p(void);
static void utc_poi_get_phone_number_n(void);
static void utc_poi_get_phone_number_n_02(void);
static void utc_poi_foreach_urls_p(void);
static void utc_poi_foreach_urls_n(void);
static void utc_poi_foreach_urls_n_02(void);
static void utc_poi_foreach_properties_p(void);
static void utc_poi_foreach_properties_n(void);
static void utc_poi_foreach_properties_n_02(void);
static void utc_poi_foreach_categories_p(void);
static void utc_poi_foreach_categories_n(void);
static void utc_poi_foreach_categories_n_02(void);


struct tet_testlist tet_testlist[] = {

	{ utc_poi_create_p, POSITIVE_TC_IDX },
	{ utc_poi_create_n, NEGATIVE_TC_IDX },
	{ utc_poi_destroy_p, POSITIVE_TC_IDX },
	{ utc_poi_destroy_n, NEGATIVE_TC_IDX },
	{ utc_poi_clone_p, POSITIVE_TC_IDX },
	{ utc_poi_clone_n, NEGATIVE_TC_IDX },
	{ utc_poi_clone_n_02, NEGATIVE_TC_IDX },
	{ utc_poi_get_id_p, POSITIVE_TC_IDX },
	{ utc_poi_get_id_n, NEGATIVE_TC_IDX },
	{ utc_poi_get_id_n_02, NEGATIVE_TC_IDX },
	{ utc_poi_get_name_p, POSITIVE_TC_IDX },
	{ utc_poi_get_name_n, NEGATIVE_TC_IDX },
	{ utc_poi_get_name_n_02, NEGATIVE_TC_IDX },
	{ utc_poi_get_position_p, POSITIVE_TC_IDX },
	{ utc_poi_get_position_n, NEGATIVE_TC_IDX },
	{ utc_poi_get_position_n_02, NEGATIVE_TC_IDX },
	{ utc_poi_get_address_p, POSITIVE_TC_IDX },
	{ utc_poi_get_address_n, NEGATIVE_TC_IDX },
//	{ utc_poi_get_address_n_02, NEGATIVE_TC_IDX },	 // Not negative case
//	{ utc_poi_get_address_n_03, NEGATIVE_TC_IDX },	// Not negative case
//	{ utc_poi_get_address_n_04, NEGATIVE_TC_IDX },
//	{ utc_poi_get_address_n_05, NEGATIVE_TC_IDX },
//	{ utc_poi_get_address_n_06, NEGATIVE_TC_IDX },
//	{ utc_poi_get_address_n_07, NEGATIVE_TC_IDX },
//	{ utc_poi_get_address_n_08, NEGATIVE_TC_IDX },
	{ utc_poi_get_description_p, POSITIVE_TC_IDX },
	{ utc_poi_get_description_n, NEGATIVE_TC_IDX },
	{ utc_poi_get_description_n_02, NEGATIVE_TC_IDX },
	{ utc_poi_get_timestamp_p, POSITIVE_TC_IDX },
	{ utc_poi_get_timestamp_n, NEGATIVE_TC_IDX },
	{ utc_poi_get_timestamp_n_02, NEGATIVE_TC_IDX },
//	{ utc_poi_get_bounding_rect_p, POSITIVE_TC_IDX },	// bbox is not supported yet in provider
	{ utc_poi_get_bounding_rect_n, NEGATIVE_TC_IDX },
	{ utc_poi_get_bounding_rect_n_02, NEGATIVE_TC_IDX },
	{ utc_poi_get_bounding_rect_n_03, NEGATIVE_TC_IDX },
	{ utc_poi_get_author_p, POSITIVE_TC_IDX },
	{ utc_poi_get_author_n, NEGATIVE_TC_IDX },
	{ utc_poi_get_author_n_02, NEGATIVE_TC_IDX },
	{ utc_poi_get_phone_number_p, POSITIVE_TC_IDX },
	{ utc_poi_get_phone_number_n, NEGATIVE_TC_IDX },
	{ utc_poi_get_phone_number_n_02, NEGATIVE_TC_IDX },
	{ utc_poi_foreach_urls_p, POSITIVE_TC_IDX },
	{ utc_poi_foreach_urls_n, NEGATIVE_TC_IDX },
	{ utc_poi_foreach_urls_n_02, NEGATIVE_TC_IDX },
	{ utc_poi_foreach_properties_p, POSITIVE_TC_IDX },
	{ utc_poi_foreach_properties_n, NEGATIVE_TC_IDX },
	{ utc_poi_foreach_properties_n_02, NEGATIVE_TC_IDX },
	{ utc_poi_foreach_categories_p, POSITIVE_TC_IDX },
	{ utc_poi_foreach_categories_n, NEGATIVE_TC_IDX },
	{ utc_poi_foreach_categories_n_02, NEGATIVE_TC_IDX },

	{ NULL, 0 },
};

static GMainLoop *g_mainloop = NULL;
static GThread *event_thread;

gpointer GmainThread(gpointer data){
	g_mainloop = g_main_loop_new (NULL, 0);
	g_main_loop_run (g_mainloop);

	return NULL;
}

static bool poi_service_search_cb_called = false;

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

static void wait_for_poi_service_search(char* api_name)
{
	dts_message(api_name, "wait for poi service search");
	int timeout = 0;
	for (timeout ; timeout < 60 * 10; timeout++)
	{
		if(poi_service_search_cb_called)
		{
				dts_message(api_name, "POI service search callback called!!!!");
				break;
		}
		else
		{
			dts_message(api_name, "No POI service search callback!!!!");
			sleep(1);
		}
	}
}


static void startup(void)
{
	g_setenv("PKG_NAME", "org.tizen.capi-location-poi-callback-test", 1);
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


static void utc_poi_create_p(void)
{
	int ret = POI_ERROR_NONE;

	poi_h poi;
	ret = poi_create(&poi);

	if (poi) {
		poi_destroy(poi);
	}

	validate_eq(__func__, ret, POI_ERROR_NONE);
}

static void utc_poi_create_n(void)
{
	int ret = POI_ERROR_NONE;

	ret = poi_create(NULL);
	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_destroy_p(void)
{
	int ret = POI_ERROR_NONE;

	poi_h poi;
	ret = poi_create(&poi);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_create() is failed");

	ret = poi_destroy(poi);
	validate_eq(__func__, ret, POI_ERROR_NONE);
}

static void utc_poi_destroy_n(void)
{
	int ret = POI_ERROR_NONE;

	ret = poi_destroy(NULL);
	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_clone_p(void)
{
	int ret = POI_ERROR_NONE;

	poi_h poi;
	ret = poi_create(&poi);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_create() is failed");

	poi_h poi_02;
	ret = poi_clone(&poi_02, poi);

	if (poi) {
		poi_destroy(poi);
	}
	if (poi_02) {
		poi_destroy(poi);
	}

	validate_eq(__func__, ret, POI_ERROR_NONE);
}

static void utc_poi_clone_n(void)
{
	int ret = POI_ERROR_NONE;

	poi_h poi;
	ret = poi_create(&poi);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_create() is failed");

	ret = poi_clone(NULL, poi);

	if (poi) {
		poi_destroy(poi);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_clone_n_02(void)
{
	int ret = POI_ERROR_NONE;

	poi_h poi_02;
	ret = poi_clone(&poi_02, NULL);
	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static bool poi_get_id_success = false;

static bool capi_poi_get_id_cb(poi_error_e error, int request_id , int index, int length , poi_h poi , void * user_data)
{
	dts_message(__func__, "capi_poi_get_id_cb : error %d, index : %d", error, index);
	poi_service_search_cb_called = true;

	int ret = POI_ERROR_NONE;
	int id;
	ret = poi_get_id(poi, &id);
	if (ret == POI_ERROR_NONE) {
		poi_get_id_success = true;
	}

	return true;
}

static void utc_poi_get_id_p(void)
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

	poi_service_search_cb_called = false;
	poi_get_id_success = false;
	ret = poi_service_search(poi_manager, pos, 100, filter, capi_poi_get_id_cb , NULL, NULL);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_search() is failed");

	wait_for_poi_service_search(__func__);
	validate_and_next(__func__, poi_service_search_cb_called, true, "capi_poi_get_id_cb() is NOT called!");

	if (filter) {
		poi_filter_destroy(filter);
	}
	if (poi_manager) {
		//free pref also
		poi_service_destroy(poi_manager);
	}

	validate_eq(__func__, poi_get_id_success, true);
}

static void utc_poi_get_id_n(void)
{
	int ret = POI_ERROR_NONE;

	int id;
	ret = poi_get_id(NULL, &id);
	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_get_id_n_02(void)
{
	int ret = POI_ERROR_NONE;

	poi_h poi;
	ret = poi_create(&poi);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_create() is failed");

	ret = poi_get_id(poi, NULL);

	if (poi) {
		poi_destroy(poi);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}


static bool poi_get_name_success = false;

static bool capi_poi_get_name_cb(poi_error_e error, int request_id , int index, int length , poi_h poi , void * user_data)
{
	dts_message(__func__, "capi_poi_get_name_cb : error %d, index : %d", error, index);
	poi_service_search_cb_called = true;

	int ret = POI_ERROR_NONE;
	char *name = NULL;
	ret = poi_get_name(poi, &name);
	if (ret == POI_ERROR_NONE) {
		poi_get_name_success = true;
	}

	if (name) {
		free(name);
	}

	return true;
}

static void utc_poi_get_name_p(void)
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

	poi_service_search_cb_called = false;
	poi_get_name_success = false;
	ret = poi_service_search(poi_manager, pos, 100, filter, capi_poi_get_name_cb , NULL, NULL);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_search() is failed");

	wait_for_poi_service_search(__func__);
	validate_and_next(__func__, poi_service_search_cb_called, true, "capi_poi_get_name_cb() is NOT called!");

	if (filter) {
		poi_filter_destroy(filter);
	}
	if (poi_manager) {
		poi_service_destroy(poi_manager);
	}

	validate_eq(__func__, poi_get_name_success, true);
}

static void utc_poi_get_name_n(void)
{
	int ret = POI_ERROR_NONE;

	char *name = NULL;
	ret = poi_get_name(NULL, &name);
	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_get_name_n_02(void)
{
	int ret = POI_ERROR_NONE;

	poi_h poi;
	ret = poi_create(&poi);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_create() is failed");

	ret = poi_get_name(poi, NULL);

	if (poi) {
		poi_destroy(poi);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static bool poi_get_position_success = false;

static bool capi_poi_get_position_cb(poi_error_e error, int request_id , int index, int length , poi_h poi , void * user_data)
{
	dts_message(__func__, "capi_poi_get_position_cb : error %d, index : %d", error, index);
	poi_service_search_cb_called = true;

	int ret = POI_ERROR_NONE;
	location_coords_s coords;
	ret = poi_get_position(poi, &coords);
	if (ret == POI_ERROR_NONE) {
		poi_get_position_success = true;
	}

	return true;
}

static void utc_poi_get_position_p(void)
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

	poi_service_search_cb_called = false;
	poi_get_position_success = false;
	ret = poi_service_search(poi_manager, pos, 100, filter, capi_poi_get_position_cb , NULL, NULL);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_search() is failed");

	wait_for_poi_service_search(__func__);
	validate_and_next(__func__, poi_service_search_cb_called, true, "capi_poi_get_position_cb() is NOT called!");

	if (filter) {
		poi_filter_destroy(filter);
	}
	if (poi_manager) {
		poi_service_destroy(poi_manager);
	}

	validate_eq(__func__, poi_get_position_success, true);
}

static void utc_poi_get_position_n(void)
{
	int ret = POI_ERROR_NONE;

	location_coords_s *coords;
	ret = poi_get_position(NULL, &coords);
	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_get_position_n_02(void)
{
	int ret = POI_ERROR_NONE;

	poi_h poi;
	ret = poi_create(&poi);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_create() is failed");

	ret = poi_get_position(poi, NULL);

	if (poi) {
		poi_destroy(poi);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static bool poi_get_address_success = false;

static bool capi_poi_get_address_cb(poi_error_e error, int request_id , int index, int length , poi_h poi , void * user_data)
{
	dts_message(__func__, "capi_poi_get_address_cb : error %d, index : %d", error, index);
	poi_service_search_cb_called = true;
	poi_service_h poi_manager = (poi_service_h) user_data;

	int ret = POI_ERROR_NONE;
	char *building_number = NULL;
	char *postal_code = NULL;
	char *street = NULL;
	char *city = NULL;
	char *district = NULL;
	char *state = NULL;
	char *country_code = NULL;
	ret = poi_get_address(poi, &building_number, &postal_code, &street, &city, &district, &state, &country_code);
	if (ret == POI_ERROR_NONE) {
		poi_get_address_success = true;
	}

	if (building_number) {
		free(building_number);
	}
	if (postal_code) {
		free(postal_code);
	}
	if (street) {
		free(street);
	}
	if (city) {
		free(city);
	}
	if (district) {
		free(district);
	}
	if (state) {
		free(state);
	}
	if (country_code) {
		free(country_code);
	}

	if (poi_manager) {
		poi_service_destroy(poi_manager);
	}

	return false;
}

static void utc_poi_get_address_p(void)
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

	poi_service_search_cb_called = false;
	poi_get_address_success = false;
	ret = poi_service_search(poi_manager, pos, 100, filter, capi_poi_get_address_cb , poi_manager, NULL);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_search() is failed");

	wait_for_poi_service_search(__func__);
	validate_and_next(__func__, poi_service_search_cb_called, true, "capi_poi_get_address_cb() is NOT called!");

	if (filter) {
		poi_filter_destroy(filter);
	}

	validate_eq(__func__, poi_get_address_success, true);
}

static void utc_poi_get_address_n(void)
{
	int ret = POI_ERROR_NONE;

	char *building_number = NULL;
	char *postal_code = NULL;
	char *street = NULL;
	char *city = NULL;
	char *district = NULL;
	char *state = NULL;
	char *country_code = NULL;
	ret = poi_get_address(NULL, &building_number, &postal_code, &street, &city, &district, &state, &country_code);
	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_get_address_n_02(void)
{
	int ret = POI_ERROR_NONE;

	poi_h poi;
	ret = poi_create(&poi);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_create() is failed");

	char *postal_code = NULL;
	char *street = NULL;
	char *city = NULL;
	char *district = NULL;
	char *state = NULL;
	char *country_code = NULL;
	ret = poi_get_address(poi, NULL, &postal_code, &street, &city, &district, &state, &country_code);

	if (poi) {
		poi_destroy(poi);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_get_address_n_03(void)
{
	int ret = POI_ERROR_NONE;

	poi_h poi;
	ret = poi_create(&poi);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_create() is failed");

	char *building_number = NULL;
	char *street = NULL;
	char *city = NULL;
	char *district = NULL;
	char *state = NULL;
	char *country_code = NULL;
	ret = poi_get_address(poi, &building_number, NULL, &street, &city, &district, &state, &country_code);

	if (poi) {
		poi_destroy(poi);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_get_address_n_04(void)
{
	int ret = POI_ERROR_NONE;

	poi_h poi;
	ret = poi_create(&poi);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_create() is failed");

	char *building_number = NULL;
	char *postal_code = NULL;
	char *city = NULL;
	char *district = NULL;
	char *state = NULL;
	char *country_code = NULL;
	ret = poi_get_address(poi, &building_number, &postal_code, NULL, &city, &district, &state, &country_code);

	if (poi) {
		poi_destroy(poi);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_get_address_n_05(void)
{
	int ret = POI_ERROR_NONE;

	poi_h poi;
	ret = poi_create(&poi);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_create() is failed");

	char *building_number = NULL;
	char *postal_code = NULL;
	char *street = NULL;
	char *district = NULL;
	char *state = NULL;
	char *country_code = NULL;
	ret = poi_get_address(poi, &building_number, &postal_code, &street, NULL, &district, &state, &country_code);

	if (poi) {
		poi_destroy(poi);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_get_address_n_06(void)
{
	int ret = POI_ERROR_NONE;

	poi_h poi;
	ret = poi_create(&poi);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_create() is failed");

	char *building_number = NULL;
	char *postal_code = NULL;
	char *street = NULL;
	char *city = NULL;
	char *state = NULL;
	char *country_code = NULL;
	ret = poi_get_address(poi, &building_number, &postal_code, &street, &city, NULL, &state, &country_code);

	if (poi) {
		poi_destroy(poi);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_get_address_n_07(void)
{
	int ret = POI_ERROR_NONE;

	poi_h poi;
	ret = poi_create(&poi);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_create() is failed");

	char *building_number = NULL;
	char *postal_code = NULL;
	char *street = NULL;
	char *city = NULL;
	char *district = NULL;
	char *country_code = NULL;
	ret = poi_get_address(poi, &building_number, &postal_code, &street, &city, &district, NULL, &country_code);

	if (poi) {
		poi_destroy(poi);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_get_address_n_08(void)
{
	int ret = POI_ERROR_NONE;

	poi_h poi;
	ret = poi_create(&poi);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_create() is failed");

	char *building_number = NULL;
	char *postal_code = NULL;
	char *street = NULL;
	char *city = NULL;
	char *district = NULL;
	char *state = NULL;
	ret = poi_get_address(poi, &building_number, &postal_code, &street, &city, &district, &state, NULL);

	if (poi) {
		poi_destroy(poi);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static bool poi_get_description_success = false;

static bool capi_poi_get_description_cb(poi_error_e error, int request_id , int index, int length , poi_h poi , void * user_data)
{
	dts_message(__func__, "capi_poi_get_description_cb : error %d, index : %d", error, index);
	poi_service_search_cb_called = true;

	int ret = POI_ERROR_NONE;
	char *description = NULL;
	ret = poi_get_description(poi, &description);
	if (ret == POI_ERROR_NONE) {
		poi_get_description_success = true;
	}

	if (description) {
		free(description);
	}

	return true;
}

static void utc_poi_get_description_p(void)
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

	poi_service_search_cb_called = false;
	poi_get_description_success = false;
	ret = poi_service_search(poi_manager, pos, 100, filter, capi_poi_get_description_cb , NULL, NULL);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_search() is failed");

	wait_for_poi_service_search(__func__);
	validate_and_next(__func__, poi_service_search_cb_called, true, "capi_poi_get_description_cb() is NOT called!");

	if (filter) {
		poi_filter_destroy(filter);
	}
	if (poi_manager) {
		poi_service_destroy(poi_manager);
	}

	validate_eq(__func__, poi_get_description_success, true);
}

static void utc_poi_get_description_n(void)
{
	int ret = POI_ERROR_NONE;

	char *description = NULL;
	ret = poi_get_description(NULL, &description);
	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_get_description_n_02(void)
{
	int ret = POI_ERROR_NONE;

	poi_h poi;
	ret = poi_create(&poi);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_create() is failed");

	ret = poi_get_description(poi, NULL);

	if (poi) {
		poi_destroy(poi);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static bool poi_get_timestamp_success = false;

static bool capi_poi_get_timestamp_cb(poi_error_e error, int request_id , int index, int length , poi_h poi , void * user_data)
{
	dts_message(__func__, "capi_poi_get_timestamp_cb : error %d, index : %d", error, index);
	poi_service_search_cb_called = true;

	int ret = POI_ERROR_NONE;
	char *timestamp = NULL;
	ret = poi_get_timestamp(poi, &timestamp);
	if (ret == POI_ERROR_NONE) {
		poi_get_timestamp_success = true;
	}

	if (timestamp) {
		free(timestamp);
	}

	return true;
}

static void utc_poi_get_timestamp_p(void)
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

	poi_service_search_cb_called = false;
	poi_get_timestamp_success = false;
	ret = poi_service_search(poi_manager, pos, 100, filter, capi_poi_get_timestamp_cb , NULL, NULL);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_search() is failed");

	wait_for_poi_service_search(__func__);
	validate_and_next(__func__, poi_service_search_cb_called, true, "capi_poi_get_timestamp_cb() is NOT called!");

	if (filter) {
		poi_filter_destroy(filter);
	}
	if (poi_manager) {
		poi_service_destroy(poi_manager);
	}

	validate_eq(__func__, poi_get_timestamp_success, true);
}

static void utc_poi_get_timestamp_n(void)
{
	int ret = POI_ERROR_NONE;

	char *timestamp = NULL;
	ret = poi_get_timestamp(NULL, &timestamp);
	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_get_timestamp_n_02(void)
{
	int ret = POI_ERROR_NONE;

	poi_h poi;
	ret = poi_create(&poi);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_create() is failed");

	ret = poi_get_timestamp(poi, NULL);

	if (poi) {
		poi_destroy(poi);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static bool poi_get_bounding_rect_success = false;

static bool capi_poi_get_bounding_rect_cb(poi_error_e error, int request_id , int index, int length , poi_h poi , void * user_data)
{
	dts_message(__func__, "capi_poi_get_bounding_rect_cb : error %d, index : %d", error, index);
	poi_service_search_cb_called = true;

	int ret = POI_ERROR_NONE;
	location_coords_s left_top;
	location_coords_s right_bottom;
	ret = poi_get_bounding_rect(poi, &left_top, &right_bottom);
	if (ret == POI_ERROR_NONE) {
		poi_get_bounding_rect_success = true;
	}

	return true;
}

static void utc_poi_get_bounding_rect_p(void)
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

	poi_service_search_cb_called = false;
	poi_get_bounding_rect_success = false;
	ret = poi_service_search(poi_manager, pos, 100, filter, capi_poi_get_bounding_rect_cb , NULL, NULL);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_search() is failed");

	wait_for_poi_service_search(__func__);
	validate_and_next(__func__, poi_service_search_cb_called, true, "capi_poi_get_bounding_rect_cb() is NOT called!");

	if (filter) {
		poi_filter_destroy(filter);
	}
	if (poi_manager) {
		poi_service_destroy(poi_manager);
	}

	validate_eq(__func__, poi_get_bounding_rect_success, true);
}

static void utc_poi_get_bounding_rect_n(void)
{
	int ret = POI_ERROR_NONE;

	location_coords_s left_top;
	location_coords_s right_bottom;
	ret = poi_get_bounding_rect(NULL, &left_top, &right_bottom);
	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_get_bounding_rect_n_02(void)
{
	int ret = POI_ERROR_NONE;

	poi_h poi;
	ret = poi_create(&poi);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_create() is failed");

	location_coords_s right_bottom;
	ret = poi_get_bounding_rect(poi, NULL, &right_bottom);

	if (poi) {
		poi_destroy(poi);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_get_bounding_rect_n_03(void)
{
	int ret = POI_ERROR_NONE;

	poi_h poi;
	ret = poi_create(&poi);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_create() is failed");

	location_coords_s left_top;
	ret = poi_get_bounding_rect(poi, &left_top, NULL);

	if (poi) {
		poi_destroy(poi);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}


static bool poi_get_author_success = false;

static bool capi_poi_get_author_cb(poi_error_e error, int request_id , int index, int length , poi_h poi , void * user_data)
{
	dts_message(__func__, "capi_poi_get_author_cb : error %d, index : %d", error, index);
	poi_service_search_cb_called = true;

	int ret = POI_ERROR_NONE;
	char *author = NULL;
	ret = poi_get_author(poi, &author);
	if (ret == POI_ERROR_NONE) {
		poi_get_author_success = true;
	}

	if (author) {
		free(author);
	}

	return true;
}

static void utc_poi_get_author_p(void)
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

	poi_service_search_cb_called = false;
	poi_get_author_success = false;
	ret = poi_service_search(poi_manager, pos, 100, filter, capi_poi_get_author_cb , NULL, NULL);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_search() is failed");

	wait_for_poi_service_search(__func__);
	validate_and_next(__func__, poi_service_search_cb_called, true, "capi_poi_get_author_cb() is NOT called!");

	if (filter) {
		poi_filter_destroy(filter);
	}
	if (poi_manager) {
		poi_service_destroy(poi_manager);
	}

	validate_eq(__func__, poi_get_author_success, true);
}

static void utc_poi_get_author_n(void)
{
	int ret = POI_ERROR_NONE;

	char *author = NULL;
	ret = poi_get_author(NULL, &author);
	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_get_author_n_02(void)
{
	int ret = POI_ERROR_NONE;

	poi_h poi;
	ret = poi_create(&poi);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_create() is failed");

	ret = poi_get_author(poi, NULL);

	if (poi) {
		poi_destroy(poi);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static bool poi_get_phone_number_success = false;

static bool capi_poi_get_phone_number_cb(poi_error_e error, int request_id , int index, int length , poi_h poi , void * user_data)
{
	dts_message(__func__, "capi_poi_get_author_cb : error %d, index : %d", error, index);
	poi_service_search_cb_called = true;

	int ret = POI_ERROR_NONE;
	char *phone_number = NULL;
	ret = poi_get_phone_number(poi, &phone_number);
	if (ret == POI_ERROR_NONE) {
		poi_get_phone_number_success = true;
	}

	if (phone_number) {
		free(phone_number);
	}

	return true;
}

static void utc_poi_get_phone_number_p(void)
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

	poi_service_search_cb_called = false;
	poi_get_phone_number_success = false;
	ret = poi_service_search(poi_manager, pos, 100, filter, capi_poi_get_phone_number_cb , NULL, NULL);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_search() is failed");

	wait_for_poi_service_search(__func__);
	validate_and_next(__func__, poi_service_search_cb_called, true, "capi_poi_get_phone_number_cb() is NOT called!");

	if (filter) {
		poi_filter_destroy(filter);
	}
	if (poi_manager) {
		poi_service_destroy(poi_manager);
	}

	validate_eq(__func__, poi_get_phone_number_success, true);
}

static void utc_poi_get_phone_number_n(void)
{
	int ret = POI_ERROR_NONE;

	char *phone_number = NULL;
	ret = poi_get_phone_number(NULL, &phone_number);
	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_get_phone_number_n_02(void)
{
	int ret = POI_ERROR_NONE;

	poi_h poi;
	ret = poi_create(&poi);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_create() is failed");

	ret = poi_get_phone_number(poi, NULL);

	if (poi) {
		poi_destroy(poi);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static bool poi_foreach_urls_success = false;

static bool capi_poi_urls_cb(const char *url , const char *description, void *user_data)
{
	return true;
}

static bool capi_poi_foreach_urls_cb(poi_error_e error, int request_id , int index, int length , poi_h poi , void * user_data)
{
	dts_message(__func__, "capi_poi_foreach_urlsr_cb : error %d, index : %d", error, index);
	poi_service_search_cb_called = true;

	int ret = POI_ERROR_NONE;
	ret = poi_foreach_urls(poi, capi_poi_urls_cb , NULL);
	if (ret == POI_ERROR_NONE) {
		poi_foreach_urls_success = true;
	}

	return true;
}

static void utc_poi_foreach_urls_p(void)
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

	poi_service_search_cb_called = false;
	poi_foreach_urls_success = false;
	ret = poi_service_search(poi_manager, pos, 100, filter, capi_poi_foreach_urls_cb , NULL, NULL);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_search() is failed");

	wait_for_poi_service_search(__func__);
	validate_and_next(__func__, poi_service_search_cb_called, true, "capi_poi_foreach_urls_cb() is NOT called!");

	if (filter) {
		poi_filter_destroy(filter);
	}
	if (poi_manager) {
		poi_service_destroy(poi_manager);
	}

	validate_eq(__func__, poi_foreach_urls_success, true);
}

static void utc_poi_foreach_urls_n(void)
{
	int ret = POI_ERROR_NONE;

	ret = poi_foreach_urls(NULL, capi_poi_urls_cb , NULL);
	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_foreach_urls_n_02(void)
{
	int ret = POI_ERROR_NONE;

	poi_h poi;
	ret = poi_create(&poi);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_create() is failed");

	ret = poi_foreach_urls(poi, NULL , NULL);

	if (poi) {
		poi_destroy(poi);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static bool poi_foreach_properties_success = false;

static bool capi_poi_properties_cb(const char *key, const char* value, void *user_data)
{
	return true;
}

static bool capi_poi_foreach_properties_cb(poi_error_e error, int request_id , int index, int length , poi_h poi , void * user_data)
{
	dts_message(__func__, "capi_poi_foreach_properties_cb : error %d, index : %d", error, index);
	poi_service_search_cb_called = true;

	int ret = POI_ERROR_NONE;
	ret = poi_foreach_properties(poi, capi_poi_properties_cb , NULL);
	if (ret == POI_ERROR_NONE) {
		poi_foreach_properties_success = true;
	}

	return true;
}

static void utc_poi_foreach_properties_p(void)
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

	poi_service_search_cb_called = false;
	poi_foreach_properties_success = false;
	ret = poi_service_search(poi_manager, pos, 100, filter, capi_poi_foreach_properties_cb , NULL, NULL);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_search() is failed");

	wait_for_poi_service_search(__func__);
	validate_and_next(__func__, poi_service_search_cb_called, true, "capi_poi_foreach_properties_cb() is NOT called!");

	if (filter) {
		poi_filter_destroy(filter);
	}
	if (poi_manager) {
		poi_service_destroy(poi_manager);
	}

	validate_eq(__func__, poi_foreach_properties_success, true);
}

static void utc_poi_foreach_properties_n(void)
{
	int ret = POI_ERROR_NONE;

	ret = poi_foreach_properties(NULL, capi_poi_properties_cb , NULL);
	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_foreach_properties_n_02(void)
{
	int ret = POI_ERROR_NONE;

	poi_h poi;
	ret = poi_create(&poi);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_create() is failed");

	ret = poi_foreach_properties(poi, NULL , NULL);

	if (poi) {
		poi_destroy(poi);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static bool poi_foreach_categories_success = false;

static bool capi_poi_categories_cb(const char *category, void *user_data)
{
	return true;
}

static bool capi_poi_foreach_categories_cb(poi_error_e error, int request_id , int index, int length , poi_h poi , void * user_data)
{
	dts_message(__func__, "capi_poi_foreach_categories_cb : error %d, index : %d", error, index);
	poi_service_search_cb_called = true;

	int ret = POI_ERROR_NONE;
	ret = poi_foreach_categories(poi, capi_poi_categories_cb , NULL);
	if (ret == POI_ERROR_NONE) {
		poi_foreach_categories_success = true;
	}

	return true;
}

static void utc_poi_foreach_categories_p(void)
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

	poi_service_search_cb_called = false;
	poi_foreach_categories_success = false;
	ret = poi_service_search(poi_manager, pos, 100, filter, capi_poi_foreach_categories_cb , NULL, NULL);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_service_search() is failed");

	wait_for_poi_service_search(__func__);
	validate_and_next(__func__, poi_service_search_cb_called, true, "capi_poi_foreach_categories_cb() is NOT called!");

	if (filter) {
		poi_filter_destroy(filter);
	}
	if (poi_manager) {
		poi_service_destroy(poi_manager);
	}

	validate_eq(__func__, poi_foreach_categories_success, true);
}

static void utc_poi_foreach_categories_n(void)
{
	int ret = POI_ERROR_NONE;

	ret = poi_foreach_categories(NULL, capi_poi_categories_cb , NULL);
	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}

static void utc_poi_foreach_categories_n_02(void)
{
	int ret = POI_ERROR_NONE;

	poi_h poi;
	ret = poi_create(&poi);
	validate_and_next(__func__, ret, POI_ERROR_NONE, "poi_create() is failed");

	ret = poi_foreach_categories(poi, NULL , NULL);

	if (poi) {
		poi_destroy(poi);
	}

	validate_eq(__func__, ret, POI_ERROR_INVALID_PARAMETER);
}


