#pragma once

#include <iostream>
#include <vector>

#include "Neuron.h"

typedef std::vector<Neuron> Layer;

class Net
{
public:
	Net(const std::vector<unsigned> &topology);
	void feedForward(const std::vector<double> &inputVals);
	void backProp(const std::vector<double> &targetVals);
	void getResults(std::vector<double> &resultVals) const;
	~Net();

private:
	std::vector<Layer> m_layers; // m_layers[layerNum][pneuronNum]
};

