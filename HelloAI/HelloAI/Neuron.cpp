#include "stdafx.h"
#include "Neuron.h"


Neuron::Neuron(unsigned numOutputs, unsigned myIndex)
{
	for (unsigned c = 0; c < numOutputs; ++c)
	{
		m_outputWeights.push_back(Connection());
		//TODO can be change to self Connection init with random numbers
		m_outputWeights.back().weight = randomWeight();
	}

	m_myIndex = myIndex;
}


Neuron::~Neuron()
{
}

void Neuron::setOutputVal(double val)
{
	m_outputVal = val;
}

double Neuron::getOutputVal () const
{
	return m_outputVal;
}

void Neuron::feedForward(const Layer & prevLayer)
{
	double sum = 0.0;

	// Sum the previous layer's outputs (which are out inputs)
	// Include the bias node from the previous layer.

	for (unsigned n = 0; n < prevLayer.size(); ++n)
	{
		sum += prevLayer[n].getOutputVal() * prevLayer[n].m_outputWeights[m_myIndex].weight;
	}

	m_outputVal = Neuron::transferFunction(sum);
}

double Neuron::transferFunction(double x)
{
	// tanh - output range [-1.0..1.0]
	return tanh(x);
}

double Neuron::transferFunctionDerivative(double x)
{
	// tanh derivative
	return 1.0 - x * x;
}

double Neuron::randomWeight(void)
{
	//TODO change it to C++11 proper rand
	return rand() / double(RAND_MAX);
}
