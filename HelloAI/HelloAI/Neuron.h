#pragma once

#include <vector>
#include <cstdlib>

struct Connection
{
	double weight;
	double deltaWeight;
};

class Neuron;

typedef std::vector<Neuron> Layer;

class Neuron
{
public:
	Neuron(unsigned numOutputs);
	~Neuron();

	void setOutputVal(double val);
	double getOutputVal() const;
	void feedForward(const Layer &prevLayer);

private:
	static double randomWeight(void);

	double m_outputVal;
	std::vector<Connection> m_outputWeights;
};

