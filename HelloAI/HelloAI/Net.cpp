#include "stdafx.h"
#include "Net.h"


Net::Net(const std::vector<unsigned> &topology)
{
	unsigned numLayers = topology.size();
	for (auto layerNum = 0; layerNum < numLayers; ++layerNum)
	{
		m_layers.push_back(Layer());

		//Add nurons
		//Loop will go +1 for bias neuron
		for (auto neuronNum = 0; neuronNum <= topology[layerNum]; ++neuronNum)
		{
			m_layers.back().push_back(Neuron());
			std::cout << "Made a Neuron!" << std::endl;
		}
	}
}

void Net::feedForward(const std::vector<double> &inputVals)
{
}

void Net::backProp(const std::vector<double> &targetVals)
{
}

void Net::getResults(std::vector<double> &resultVals) const
{
}

Net::~Net()
{
}
