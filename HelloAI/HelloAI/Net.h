#pragma once

#include <vector>

class Net
{
public:
	Net(topology);
	void feedForward(const std::vector<double> &inputVals);
	void backProp(targetVals);
	void getResults(resultVals) const;
	~Net();
};

