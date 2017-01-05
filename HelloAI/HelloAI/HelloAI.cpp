// HelloAI.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"

#include <iostream>
#include <vector>

#include "Net.h"


int main()
{
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

