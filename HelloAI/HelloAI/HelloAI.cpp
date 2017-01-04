// HelloAI.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"

#include <iostream>
#include <vector>

#include "Net.h"


int main()
{
	Net myNet(topology);

	std::vector<double> inputVals;
	myNet.feedForward(inputVals);
	myNet.backProp(targetVals);
	myNet.getResults(resultVals);

    return 0;
}

