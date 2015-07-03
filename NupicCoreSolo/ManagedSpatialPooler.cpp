#include "ManagedSpatialPooler.h"
#include "helpers.h"

#include <iostream>
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include <cmath> 		// pow

#include <vector>
#include <algorithm>
#include <cliext/vector>
#include <cliext/algorithm>

using namespace System;
using System::Runtime::InteropServices::Marshal;

namespace nupic {
	namespace algorithms {
		namespace spatial_pooler {

			ManagedSpatialPooler::ManagedSpatialPooler(
				Collections::Generic::List<UInt> ^inputDimensions,
				Collections::Generic::List<UInt> ^columnDimensions,
				nupic::UInt potentialRadius)
			{
				std::vector<UInt> inputDimensionsStdVec;
				inputDimensionsStdVec.swap(marshalAsStdVector<UInt>(inputDimensions));
				std::vector<UInt> columnDimensionsStdVec;
				columnDimensionsStdVec.swap(marshalAsStdVector<UInt>(columnDimensions));

				m_Impl = new SpatialPooler(inputDimensionsStdVec, columnDimensionsStdVec, potentialRadius,
					0.5, true, -1.0, 10, 0, 0.01, 0.1, 0.1, 0.001, 0.001, 1000, 10.0, 1, 0, true);
			}

		ManagedSpatialPooler::ManagedSpatialPooler(
				cli::array<UInt> ^inputDimensions,
				cli::array<UInt> ^columnDimensions)
			{
				std::vector<UInt> inputDimensionsStdVec;
				inputDimensionsStdVec.swap(marshalArrayAsStdVector<UInt>(inputDimensions));

				std::vector<UInt> columnDimensionsStdVec;
				columnDimensionsStdVec.swap(marshalArrayAsStdVector<UInt>(columnDimensions));

				m_Impl = new SpatialPooler(
					inputDimensionsStdVec,
					columnDimensionsStdVec,
					16,
					0.5,
					true,
					-1.0,
					10,
					0,
					0.01,
					0.1,
					0.1,
					0.001,
					0.001,
					1000,
					10.0,
					1,
					0,
					true);
			}

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
				bool wrapAround)
			{
				std::vector<UInt> inputDimensionsStdVec;
				inputDimensionsStdVec.swap(marshalArrayAsStdVector<UInt>(inputDimensions));

				std::vector<UInt> columnDimensionsStdVec;
				columnDimensionsStdVec.swap(marshalArrayAsStdVector<UInt>(columnDimensions));

				m_Impl = new SpatialPooler(
					inputDimensionsStdVec,
					columnDimensionsStdVec,
					potentialRadius,
					potentialPct,
					globalInhibition,
					localAreaDensity,
					numActiveColumnsPerInhArea,
					stimulusThreshold,
					synPermInactiveDec,
					synPermActiveInc,
					synPermConnected,
					minPctOverlapDutyCycles,
					minPctActiveDutyCycles,
					dutyCyclePeriod,
					maxBoost,
					seed,
					spVerbosity,
					wrapAround);
			}

			ManagedSpatialPooler::~ManagedSpatialPooler()
			{
				delete m_Impl;
			}

			ManagedSpatialPooler::!ManagedSpatialPooler() {
				delete m_Impl;
			}

			void ManagedSpatialPooler::compute(
				System::IntPtr inputVector,bool learn, System::IntPtr  activeVector)
			{
				m_Impl->compute((nupic::UInt*)(inputVector.ToPointer()),
					learn, (nupic::UInt*)(activeVector.ToPointer()));
			}

			void ManagedSpatialPooler::setPotentialRadius(UInt potentialRadius)
			{
				m_Impl->setPotentialRadius(potentialRadius);
			}

			void ManagedSpatialPooler::setPotentialPct(Real potentialPct)
			{
				m_Impl->setPotentialPct(potentialPct);
			}

			void ManagedSpatialPooler::setGlobalInhibition(bool globalInhibition)
			{
				m_Impl->setGlobalInhibition(globalInhibition);
			}

			void ManagedSpatialPooler::setNumActiveColumnsPerInhArea(UInt numActiveColumnsPerInhArea)
			{
				m_Impl->setNumActiveColumnsPerInhArea(numActiveColumnsPerInhArea);
			}

			void ManagedSpatialPooler::setLocalAreaDensity(Real localAreaDensity)
			{
				m_Impl->setLocalAreaDensity(localAreaDensity);
			}

			void ManagedSpatialPooler::setStimulusThreshold(UInt stimulusThreshold)
			{
				m_Impl->setStimulusThreshold(stimulusThreshold);
			}

			void ManagedSpatialPooler::setInhibitionRadius(UInt inhibitionRadius)
			{
				m_Impl->setInhibitionRadius(inhibitionRadius);
			}

			void ManagedSpatialPooler::setDutyCyclePeriod(UInt dutyCyclePeriod)
			{
				m_Impl->setDutyCyclePeriod(dutyCyclePeriod);
			}

			void ManagedSpatialPooler::setMaxBoost(Real maxBoost)
			{
				m_Impl->setMaxBoost(maxBoost);
			}

			void ManagedSpatialPooler::setIterationNum(UInt iterationNum)
			{
				m_Impl->setIterationNum(iterationNum);
			}

			void ManagedSpatialPooler::setIterationLearnNum(UInt iterationLearnNum)
			{
				m_Impl->setIterationLearnNum(iterationLearnNum);
			}

			void ManagedSpatialPooler::setSpVerbosity(UInt spVerbosity)
			{
				m_Impl->setSpVerbosity(spVerbosity);
			}

			void ManagedSpatialPooler::setWrapAround(bool wrapAround)
			{
				m_Impl->setWrapAround(wrapAround);
			}

			void ManagedSpatialPooler::setUpdatePeriod(UInt updatePeriod)
			{
				m_Impl->setUpdatePeriod(updatePeriod);
			}

			void ManagedSpatialPooler::setSynPermTrimThreshold(Real synPermTrimThreshold)
			{
				m_Impl->setSynPermTrimThreshold(synPermTrimThreshold);
			}

			void ManagedSpatialPooler::setSynPermActiveInc(Real synPermActiveInc)
			{
				m_Impl->setSynPermActiveInc(synPermActiveInc);
			}

			void ManagedSpatialPooler::setSynPermInactiveDec(Real synPermInactiveDec)
			{
				m_Impl->setSynPermInactiveDec(synPermInactiveDec);
			}

			void ManagedSpatialPooler::setSynPermBelowStimulusInc(Real synPermBelowStimulusInc)
			{
				m_Impl->setSynPermBelowStimulusInc(synPermBelowStimulusInc);
			}

			void ManagedSpatialPooler::setSynPermConnected(Real setSynPermConnected)
			{
				m_Impl->setSynPermConnected(setSynPermConnected);
			}

			void ManagedSpatialPooler::setMinPctOverlapDutyCycles(Real minPctOverlapDutyCycles)
			{
				m_Impl->setMinPctOverlapDutyCycles(minPctOverlapDutyCycles);
			}

			void ManagedSpatialPooler::setMinPctActiveDutyCycles(Real minPctActiveDutyCycles)
			{
				m_Impl->setMinPctActiveDutyCycles(minPctActiveDutyCycles);
			}

			void ManagedSpatialPooler::setBoostFactors(cli::array<Real> ^boostFactors)
			{
				std::vector<Real> boostFactorsStdVec;
				boostFactorsStdVec.swap(marshalArrayAsStdVector(boostFactors));
				//prevest na pointer ne na std::vector
				//m_Impl->setBoostFactors(boostFactorsStdVec);
			}

			void ManagedSpatialPooler::setOverlapDutyCycles(cli::array<Real> ^ overlapDutyCycles)
			{
				std::vector<Real> overlapDutyCyclesStdVec;
				overlapDutyCyclesStdVec.swap(marshalArrayAsStdVector(overlapDutyCycles));
				//m_Impl->
			}

			void ManagedSpatialPooler::setActiveDutyCycles(cli::array<Real> ^ activeDutyCycles)
			{
				std::vector<Real> activeDutyCyclesStdVec;
				activeDutyCyclesStdVec.swap(marshalArrayAsStdVector(activeDutyCycles));
				//m_Impl->
			}

			void ManagedSpatialPooler::setMinOverlapDutyCycles(cli::array<Real> ^ minOverlapDutyCycles)
			{
				std::vector<Real> minOverlapDutyCyclesStdVec;
				minOverlapDutyCyclesStdVec.swap(marshalArrayAsStdVector(minOverlapDutyCycles));
				//m_Impl->
			}

			void ManagedSpatialPooler::setMinActiveDutyCycles(cli::array<Real> ^ minActiveDutyCycles)
			{
				std::vector<Real> minActiveDutyCyclesStdVec;
				minActiveDutyCyclesStdVec.swap(marshalArrayAsStdVector(minActiveDutyCycles));
				//m_Impl->
			}

		} // spatial_pooler namespace
	} // algorithms namespace
} // nupic namespace