// nupic_core_solo_wrapper.h

/*
C++/CLI wrapper that allows to use the nupic_core_solo.dll from the C# program.
DLL is generated from this source file that can be set as an reference in a C# program.
This DLL uses the nupic_core_simple.dll (therefore both DLLs have to be found in the
path by the using application).

Not all functions implemented in the nupic_core_solo are provided through this wrapper yet.
To use more public functions provided by the nupic_core_solo, it is needed
to export them by adding NUPICCOREDLL_API before function declaration in the respective
*.hpp file and rebuild the DLLs.
*/

#include "nupic/algorithms/SpatialPooler.hpp"

#include <msclr\marshal_cppstd.h>

#pragma once

using namespace System;

namespace nupic {
	namespace algorithms {
		namespace spatial_pooler {

			public ref class ManagedSpatialPooler
			{
			public:

				// this constructor is left here just to show other way to marshal C# collection generics to std::vector
				ManagedSpatialPooler(
					Collections::Generic::List<UInt> ^inputDimensions,
					Collections::Generic::List<UInt> ^columnDimensions,
					nupic::UInt potentialRadius);

				ManagedSpatialPooler(
					cli::array<UInt> ^inputDimensions,
					cli::array<UInt> ^columnDimensions);

				ManagedSpatialPooler::ManagedSpatialPooler(
					cli::array<UInt32> ^inputDimensions,
					cli::array<UInt32> ^columnDimensions,
					UInt32 potentialRadius,
					float potentialPct,
					bool globalInhibition,
					float localAreaDensity,
					UInt32 numActiveColumnsPerInhArea,
					UInt32 stimulusThreshold,
					float synPermInactiveDec,
					float synPermActiveInc,
					float synPermConnected,
					float minPctOverlapDutyCycles,
					float minPctActiveDutyCycles,
					UInt32 dutyCyclePeriod,
					float maxBoost,
					int seed,
					UInt32 spVerbosity,
					bool wrapAround);

				// Deallocate the native object on a destructor
				~ManagedSpatialPooler();

			protected:
				// Deallocate the native object on the finalizer just in case no destructor is called
				!ManagedSpatialPooler();

			public:
				virtual void compute(System::IntPtr inputVector, bool learn, System::IntPtr  activeVector);
				void setPotentialRadius(UInt potentialRadius);
				void setPotentialPct(Real potentialPct);
				void setGlobalInhibition(bool globalInhibition);
				void setNumActiveColumnsPerInhArea(UInt numActiveColumnsPerInhArea);
				void setLocalAreaDensity(Real localAreaDensity);
				void setStimulusThreshold(UInt stimulusThreshold);
				void setInhibitionRadius(UInt inhibitionRadius);
				void setDutyCyclePeriod(UInt dutyCyclePeriod);
				void setMaxBoost(Real maxBoost);
				void setIterationNum(UInt iterationNum);
				void setIterationLearnNum(UInt iterationLearnNum);
				void setSpVerbosity(UInt spVerbosity);
				void setWrapAround(bool wrapAround);
				void setUpdatePeriod(UInt updatePeriod);
				void setSynPermTrimThreshold(Real synPermTrimThreshold);
				void setSynPermActiveInc(Real synPermActiveInc);
				void setSynPermInactiveDec(Real synPermInactiveDec);
				void setSynPermBelowStimulusInc(Real synPermBelowStimulusInc);
				void setSynPermConnected(Real setSynPermConnected);
				void setMinPctOverlapDutyCycles(Real minPctOverlapDutyCycles);
				void setMinPctActiveDutyCycles(Real minPctActiveDutyCycles);
				void setBoostFactors(cli::array<Real> ^ boostFactors);
				void setOverlapDutyCycles(cli::array<Real> ^ overlapDutyCycles);
				void setActiveDutyCycles(cli::array<Real> ^ activeDutyCycles);
				void setMinOverlapDutyCycles(cli::array<Real> ^ minOverlapDutyCycles);
				void setMinActiveDutyCycles(cli::array<Real> ^ minActiveDutyCycles);


			private:
				SpatialPooler * m_Impl;

			}; // ManagedSpatialPooler class

		} // spatial_pooler namespace
	} // algorithms namespace
} // nupic namespace
