#pragma once
#include <vector>

class Model {
public:
    virtual ~Model() = default;

    // Predict output given input vector
    virtual std::vector<double> predict(const std::vector<double>& input) = 0;

    // Train model on input-output pairs
    virtual void train(const std::vector<std::vector<double>>& inputs,
                       const std::vector<std::vector<double>>& outputs) = 0;

    // Save model to file
    virtual bool saveModel(const std::string& filepath) = 0;

    // Load model from file
    virtual bool loadModel(const std::string& filepath) = 0;
};
