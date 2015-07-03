#pragma once

#include "nupic/algorithms/FastClaClassifier.hpp"

using namespace System::Collections::Generic;

namespace nupic {
	namespace algorithms {
		namespace cla_classifier
		{
			public ref class ManagedFastClaClassifier
			{
			public:
				ManagedFastClaClassifier(cli::array<System::Int32> ^steps, double alpha,
					double actValueAlpha, UInt verbosity);

				SortedDictionary<System::Int32, cli::array<double>^ >^ fastCompute(
					UInt recordNum, cli::array<UInt> ^patternNZ, UInt bucketIdx,
					Real64 actValue, bool category, bool learn, bool infer);

				// Deallocate the native object on a destructor
				~ManagedFastClaClassifier();

			protected:
				// Deallocate the native object on the finalizer just in case no destructor is called
				!ManagedFastClaClassifier();

			private:
				FastCLAClassifier * m_Impl;

			}; // ManagedFastCLAClassifier class
		} // cla_classifier namespace
	} // algorithms namespace
} // nupic namespace
