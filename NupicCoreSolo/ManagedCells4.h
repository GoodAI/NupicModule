#pragma once


#include "nupic/algorithms/Cells4.hpp"

namespace nupic {
	namespace algorithms {
		namespace Cells4
		{
			public ref class ManagedCells4
			{
			public:
				ManagedCells4(UInt nColumns,
					UInt nCellsPerCol,
					UInt activationThreshold,
					UInt minThreshold,
					UInt newSynapseCount,
					UInt segUpdateValidDuration,
					Real permInitial,
					Real permConnected,
					Real permMax,
					Real permDec,
					Real permInc,
					Real globalDecay,
					bool doPooling,
					int seed,
					bool initFromCpp,
					bool checkSynapseConsistency);

				void compute(System::IntPtr input, System::IntPtr output, bool doInference, bool doLearning);

				// Deallocate the native object on a destructor
				~ManagedCells4();

			protected:
				// Deallocate the native object on the finalizer just in case no destructor is called
				!ManagedCells4();

			//public:
			//	void setMaxInfBacktrack(UInt t);
			//	void setMaxLrnBacktrack(UInt t);
			//	void setVerbosity(UInt v);
			//	void setMaxAge(UInt a);
			//	void setMaxSeqLength(UInt v);
			//	void setCheckSynapseConsistency(bool val);
			//	void setMaxSegmentsPerCell(int maxSegs);
			//	void setMaxSynapsesPerCell(int maxSyns);
			//	void setPamLength(UInt pl);


			private:
				Cells4 * m_Impl;

			}; // ManagedCells4 class
		} // Cells4 namespace
	} // algorithms namespace
} // nupic namespace
