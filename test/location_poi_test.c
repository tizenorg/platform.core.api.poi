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
#include <stdio.h>
#include <unistd.h>
#include <glib.h>
#include <poi.h>
#include <location_bounds.h>

static GMainLoop *g_mainloop = NULL;

static gpointer GmainThread(gpointer data)
{
	g_mainloop = g_main_loop_new (NULL, FALSE);
	printf("\n...Entering GMain Loop to Receive Notifications....\n");
	g_main_loop_run (g_mainloop);
	g_main_loop_unref (g_mainloop);
	g_mainloop = NULL;
	return NULL;
}

bool _service_search_cb(poi_error_e error, int request_id , int index, int length , poi_h poi , void * user_data)
{
	printf("error %d %d)-------------\n",error,  index);
	char * name=NULL ;
	char *description=NULL;
	poi_get_name(poi , &name);
	int ret = poi_get_description(poi, &description);
	printf("get description ret = %d\n", ret);
	printf("%s / %s\n", name , description);
	
	
	return true;
}


int poi_test(){
	poi_service_h poi_manager ;
	poi_filter_h filter;
	poi_preference_h pref;
	poi_service_create(&poi_manager);

	location_bounds_h bound;

	location_coords_s pos = {37.336723, -121.889555};
	location_bounds_create_circle(pos, 400, &bound);

	char * addr = "N SAN PEDRO ST CA SANTA CLARA SAN JOSE 95110";

	poi_filter_create(&filter);
	//poi_filter_set(filter, "KEYWORD", "pizza");
	poi_filter_set(filter, "CATEGORY", "restaurant");
	poi_preference_create(&pref);
	poi_preference_set_max_result(pref, 5);
	poi_preference_set_sort(pref, "Distance", POI_SORTORDER_ASC);
	poi_service_set_preference(poi_manager, pref);

	 int ret;
	//printf("request search!!!\n");
	ret = poi_service_search(poi_manager,pos , 100, filter, _service_search_cb , NULL, NULL);
	printf("ret = category, poi_service_search : %d\n", ret);

	sleep(3);

	poi_filter_create(&filter);
	poi_filter_set(filter, "KEYWORD", "pizza");
	poi_preference_create(&pref);
	poi_preference_set_max_result(pref, 5);
	poi_preference_set_sort(pref, "Distance", POI_SORTORDER_DESC);
	poi_service_set_preference(poi_manager, pref);

	ret = poi_service_search(poi_manager,pos , 100, filter, _service_search_cb , NULL, NULL);
	printf("ret = keyword, poi_service_search : %d\n", ret);


	sleep(3);

	poi_filter_create(&filter);
	poi_filter_set(filter, "POIName", "pizza");
	poi_preference_create(&pref);
	poi_preference_set_max_result(pref, 5);
	poi_preference_set_sort(pref, "Distance", POI_SORTORDER_DESC);
	poi_service_set_preference(poi_manager, pref);

	ret = poi_service_search(poi_manager,pos , 100, filter, _service_search_cb , NULL, NULL);
	printf("ret = POIName, poi_service_search : %d\n", ret);

	sleep(3);

	poi_filter_create(&filter);
	poi_filter_set(filter, "CATEGORY", "restaurant");
	poi_preference_create(&pref);
	poi_preference_set_max_result(pref, 5);
	poi_preference_set_sort(pref, "Distance", POI_SORTORDER_DESC);
	poi_service_set_preference(poi_manager, pref);

	ret = poi_service_search_by_area(poi_manager, bound, filter, _service_search_cb , NULL, NULL);
	printf("ret = category, poi_service_search_by_area : %d\n", ret);


	sleep(3);

	poi_filter_create(&filter);
	poi_filter_set(filter, "KEYWORD", "pizza");
	poi_preference_create(&pref);
	poi_preference_set_max_result(pref, 5);
	poi_preference_set_sort(pref, "Distance", POI_SORTORDER_DESC);
	poi_service_set_preference(poi_manager, pref);

	ret = poi_service_search_by_area(poi_manager, bound, filter, _service_search_cb , NULL, NULL);
	printf("ret = keyword, poi_service_search_by_area : %d\n", ret);

	sleep(3);

	poi_filter_create(&filter);
	poi_preference_create(&pref);
	poi_filter_set(filter, "POIName", "pizza");
	poi_preference_set_max_result(pref, 5);
	poi_preference_set_sort(pref, "Distance", POI_SORTORDER_DESC);
	poi_service_set_preference(poi_manager, pref);

	ret = poi_service_search_by_area(poi_manager, bound, filter, _service_search_cb , NULL, NULL);
	printf("ret = poi name, poi_service_search_by_area : %d\n", ret);

	sleep(3);

	poi_filter_create(&filter);
	poi_filter_set(filter, "CATEGORY", "restaurant");
	poi_preference_create(&pref);
	poi_preference_set_max_result(pref, 5);
	poi_preference_set_sort(pref, "Distance", POI_SORTORDER_DESC);
	poi_service_set_preference(poi_manager, pref);

	ret = poi_service_search_by_address(poi_manager, addr, 100, filter, _service_search_cb , NULL, NULL);
	printf("ret = category, poi_service_search_by_address : %d\n", ret);


	sleep(10);

	poi_filter_create(&filter);
	poi_filter_set(filter, "KEYWORD", "cafe");
	poi_preference_create(&pref);
	poi_preference_set_max_result(pref, 5);
	poi_preference_set_sort(pref, "Distance", POI_SORTORDER_DESC);
	poi_service_set_preference(poi_manager, pref);

	ret = poi_service_search_by_address(poi_manager, addr, 400, filter, _service_search_cb , NULL, NULL);
	printf("ret = keyword, poi_service_search_by_address : %d\n", ret);

	sleep(10);

	poi_filter_create(&filter);
	poi_filter_set(filter, "POIName", "cafe");
	poi_preference_create(&pref);
	poi_preference_set_max_result(pref, 5);
	poi_preference_set_sort(pref, "Distance", POI_SORTORDER_DESC);
	poi_service_set_preference(poi_manager, pref);

	ret = poi_service_search_by_address(poi_manager, addr, 400, filter, _service_search_cb , NULL, NULL);
	printf("ret = POIName, poi_service_search_by_address : %d\n", ret);

	sleep(10);
	return 0;
}

int main(){
	GError *gerr = NULL;

	// If application is executed by AUL, this is not needed.
	g_setenv("PKG_NAME", "com.samsung.location-api-test", 1);

#if !GLIB_CHECK_VERSION (2, 31, 0)
	if( !g_thread_supported() )
	{
		g_thread_init(NULL);
	}
#endif

	GThread *g_main;
	g_main = g_thread_create(GmainThread, NULL, TRUE, &gerr);
	if (!g_main) {
		g_debug("Error create gmain thread: Err domain[%d] Err code[%d] Err msg[%s]",
			gerr->domain, gerr->code, gerr->message);
		g_error_free(gerr);
		return 0;
	}

	poi_test();

	getchar();
	
	return 0;


}

