#pragma once

#include <vector>

#include <random>

#include <memory>

#include <algorithm>

namespace htm {
	class AnythingEncoder {
	public:
		float sigmoid(float x) {
			return 1.0f / (1.0f + std::exp(-x));
		}

	private:
		struct Node {
			std::vector<float> _center;

			float _width;

			float _sum;
			float _activation;
			float _output;
			float _dutyCycle;

			Node()
				: _sum(0.0f), _activation(0.0f), _output(0.0f), _dutyCycle(1.0f)
			{}
		};

		struct Recon {
			std::vector<float> _reconWeights;
		};

		int _sdrSize;
		int _inputSize;

		std::vector<Node> _nodes;
		std::vector<Recon> _recons;

		static float boostFunction(float dutyCycle, float threshold, float intensity) {
			return std::min<float>(1.0f, std::max<float>(0.0f, threshold - dutyCycle) / threshold);
		}

	public:
		void create(int sdrSize, int inputSize, float minInitCenter, float maxInitCenter, float minInitWidth, float maxInitWidth, float minInitWeight, float maxInitWeight, std::mt19937 &generator);

		void encode(const std::vector<float> &input, std::vector<float> &sdr, float localActivity, float outputIntensity, float dutyCycleDecay);
		void learn(const std::vector<float> &input, const std::vector<float> &recon, float centerAlpha, float widthAlpha, float widthScalar, float minWidth, float reconAlpha, float boostThreshold, float boostIntensity);
		void decode(const std::vector<float> &sdr, std::vector<float> &recon);
	};
}