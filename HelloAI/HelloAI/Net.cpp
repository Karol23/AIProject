#include "stdafx.h"
#include "Net.h"


Net::Net(const std::vector<unsigned> &topology)
{
	unsigned numLayers = topology.size();
	for (auto layerNum = 0; layerNum < numLayers; ++layerNum)
	{
		m_layers.push_back(Layer());
		unsigned numOutputs = layerNum == topology.size() - 1 ? 0 : topology[layerNum + 1];

		//Add nurons
		//Loop will go +1 for bias neuron
		for (auto neuronNum = 0; neuronNum <= topology[layerNum]; ++neuronNum)
		{
			m_layers.back().push_back(Neuron(numOutputs, neuronNum));
			std::cout << "Made a Neuron!" << std::endl;
		}
	}
}

void Net::feedForward(const std::vector<double> &inputVals)
{
	assert(inputVals.size() == m_layers[0].size() - 1);

	//Assign (latch) the input values int o the input neurons
	for (unsigned i = 0; i < inputVals.size(); ++i)
	{
		m_layers[0][i].setOutputVal(inputVals[i]);
	}

	// Forward propagate
	for (unsigned layerNum = 1; layerNum < m_layers.size(); ++layerNum)
	{
		Layer &prevLayer = m_layers[layerNum - 1];
		for (unsigned n = 0; n < m_layers[layerNum].size() - 1; ++n)
		{
			m_layers[layerNum][n].feedForward(prevLayer);
		}
	}
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
