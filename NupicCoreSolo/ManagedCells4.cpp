#pragma once


#include "ManagedCells4.h"

namespace nupic {
	namespace algorithms {
		namespace Cells4
		{
			ManagedCells4::ManagedCells4(UInt nColumns,
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
					bool checkSynapseConsistency)
				{
					m_Impl = new Cells4(nColumns,
						nCellsPerCol,
						activationThreshold,
						minThreshold,
						newSynapseCount,
						segUpdateValidDuration,
						permInitial,
						permConnected,
						permMax,
						permDec,
						permInc,
						globalDecay,
						doPooling,
						seed,
						initFromCpp,
						checkSynapseConsistency);
				}

				void ManagedCells4::compute(System::IntPtr input, System::IntPtr output, bool doInference, bool doLearning)
				{
					m_Impl->compute((nupic::Real*)(input.ToPointer()), (nupic::Real*)(output.ToPointer()), doInference, doLearning);
				}

				// Deallocate the native object on a destructor
				ManagedCells4::~ManagedCells4() {
					delete m_Impl;
				}

				// Deallocate the native object on the finalizer just in case no destructor is called
				ManagedCells4::!ManagedCells4() {
					delete m_Impl;
				}

		} // Cells4 namespace
	} // algorithms namespace
} // nupic namespace
