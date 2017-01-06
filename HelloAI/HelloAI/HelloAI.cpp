// HelloAI.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"

#include <iostream>
#include <vector>

#include "Net.h"

#include <curl/curl.h>

int main()
{
	// CURL Test
	CURL *curl;
	CURLcode res;
	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, "http://www.google.co.uk/");
		res = curl_easy_perform(curl);

		curl_easy_cleanup(curl);
	}
	// END OF TEST

	std::vector<unsigned> topology;

	topology.push_back(3);
	topology.push_back(2);
	topology.push_back(1);

	Net myNet(topology);

	std::vector<double> inputVals;
	myNet.feedForward(inputVals);

	std::vector<double> targetVals;
	myNet.backProp(targetVals);

	std::vector<double> resultVals;
	myNet.getResults(resultVals);

    return 0;
}

