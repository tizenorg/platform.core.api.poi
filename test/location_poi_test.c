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
#include <glib.h>
#include <poi.h>

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

	poi_filter_create(&filter);
	//poi_filter_set(filter, "KEYWORD", "pizza");
	poi_filter_set(filter, "CATEGORY", "restaurant");
	poi_preference_create(&pref);
	poi_preference_set_max_result(pref, 5);
	poi_preference_set_sort(pref, "Distance", POI_SORTORDER_ASC);
	poi_service_set_preference(poi_manager, pref);
	location_coords_s pos = {37.771008, -122.41175};

	 int ret;
	//printf("request search!!!\n");
	ret = poi_service_search(poi_manager,pos , 100, filter, _service_search_cb , NULL, NULL);
	printf("ret = %d\n", ret);


	//ret = poi_service_search_by_address(poi_manager,"Seoul, Korea", 100, filter, _service_search_cb , NULL, NULL);
	//printf("ret = %d\n", ret);


	return 0;
}

int main(){
	GError *gerr = NULL;

	// If application is executed by AUL, this is not needed.
	g_setenv("PKG_NAME", "com.samsung.location-api-test", 1);

	if( !g_thread_supported() )
	{
		g_thread_init(NULL);
	}

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

