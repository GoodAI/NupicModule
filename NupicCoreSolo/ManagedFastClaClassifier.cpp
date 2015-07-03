#pragma once

#include "ManagedFastClaClassifier.h"
#include "nupic/algorithms/ClassifierResult.hpp"

#include <vector>
#include <algorithm>

using namespace System::Collections::Generic;

namespace nupic {
	namespace algorithms {
		namespace cla_classifier
		{
			ManagedFastClaClassifier::ManagedFastClaClassifier(cli::array<System::Int32> ^steps, double alpha, double actValueAlpha, UInt verbosity)
			{
				std::vector<UInt> stepsStdVector(steps->Length);
				{
					pin_ptr<System::Int32> pin(&steps[0]);
					System::Int32 *first(pin), *last(pin + steps->Length);
					std::copy(first, last, stepsStdVector.begin());
				}

				m_Impl = new FastCLAClassifier(stepsStdVector, alpha, actValueAlpha, verbosity);
			}


			SortedDictionary<System::Int32, cli::array<double>^ >^ ManagedFastClaClassifier::fastCompute(
				UInt recordNum, cli::array<UInt> ^patternNZ, UInt bucketIdx,
				Real64 actValue, bool category, bool learn, bool infer)
			{
				std::vector<UInt> patternNZStdVector(patternNZ->Length);
				if (patternNZ->Length > 0)
				{
					pin_ptr<UInt> pin(&patternNZ[0]);
					UInt *first(pin), *last(pin + patternNZ->Length);
					std::copy(first, last, patternNZStdVector.begin());
				}
				ClassifierResult  classifierResult;
				m_Impl->fastCompute(recordNum, patternNZStdVector, bucketIdx, actValue, category, learn, infer, &classifierResult);



				// transformation from unmanaged ClassifierResult into managed SortedDictionary
				int numBuckets = classifierResult.begin()->second->size();
				SortedDictionary<System::Int32, cli::array<double>^ >^ ret = gcnew SortedDictionary<System::Int32, cli::array<double>^ >();
				for (auto it = classifierResult.begin(); it != classifierResult.end(); ++it)
				{
					cli::array<double>^ percentages = gcnew cli::array<double>(numBuckets);
					for (int i = 0; i < numBuckets; i++)
					{
						percentages[i] = it->second->at(i);
					}
					System::Int32 key = it->first;
					ret->Add(key, percentages);
				}
				return ret;
			}

			// Deallocate the native object on a destructor
			ManagedFastClaClassifier::~ManagedFastClaClassifier() {
				delete m_Impl;
			}

			// Deallocate the native object on the finalizer just in case no destructor is called
			ManagedFastClaClassifier::!ManagedFastClaClassifier() {
				delete m_Impl;
			}

		} // cla_classifier namespace
	} // algorithms namespace
} // nupic namespace
