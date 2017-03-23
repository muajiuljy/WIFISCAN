#include "comm.h"
#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

void send_data_curl(double Leq[]){
	char postdata[200]="data=",temp[30];
	int i;
	CURL *curl;
	CURLcode res;

	for(i=0;i<8;i++){  //this for loop prepare the post string
		//in the sprintf function there is a ternary operator
		sprintf(temp,(i==7)?"%.2f":"%.2f;",Leq[i]);
		strcat(postdata, temp);   //append temp to postdata
	}
	//printf("%s\n",postdata);
	//postdata is ready
 	curl_global_init(CURL_GLOBAL_ALL);   //globally initiate curl
        curl = curl_easy_init();   //make a curl handler
        if(curl){
		//set URL of server page
                curl_easy_setopt(curl, CURLOPT_URL, URL);
		//set POST data
                curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postdata);
		//perrm a submit
                res = curl_easy_perform(curl);
                if(res != CURLE_OK ){  //if the server side is negative

                        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                        curl_easy_strerror(res));  //output error
                }
                curl_easy_cleanup(curl);   //clean up handler
        }
        curl_global_cleanup();    //globally ending curl
	printf("Data sent\n");
}
