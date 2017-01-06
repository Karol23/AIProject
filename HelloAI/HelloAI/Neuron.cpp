#include "stdafx.h"
#include "Neuron.h"


Neuron::Neuron(unsigned numOutputs)
{
	for (unsigned c = 0; c < numOutputs; ++c)
	{
		m_outputWeights.push_back(Connection());
		//TODO can be change to self Connection init with random numbers
		m_outputWeights.back().weight = randomWeight();
	}
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
}

double Neuron::randomWeight(void)
{
	//TODO change it to C++11 proper rand
	return rand() / double(RAND_MAX);
}
