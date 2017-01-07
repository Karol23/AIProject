#pragma once

#include <vector>
#include <cstdlib>
#include <cmath>

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
	Neuron(unsigned numOutputs, unsigned myIndex);
	~Neuron();

	void setOutputVal(double val);
	double getOutputVal() const;
	void feedForward(const Layer &prevLayer);
	void calcOutputGradients(double targetVal);
	void calcHiddenGradients(const Layer &nextLayer);
	void updateInputWeight(Layer &prevLayer);

	unsigned m_myIndex;

private:
	static double eta; // [0.0...1.0]
	static double alpha;

	static double transferFunction(double x);
	static double transferFunctionDerivative(double x);
	static double randomWeight(void);
	double sumDOW(const Layer &nextLayer) const;

	double m_outputVal;
	std::vector<Connection> m_outputWeights;
	double m_gradient;
};


