/*
* Copyright (c) 2022 - 2025 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
*
* NVIDIA CORPORATION, its affiliates and licensors retain all intellectual
* property and proprietary rights in and to this material, related
* documentation and any modifications thereto. Any use, reproduction,
* disclosure or distribution of this material and related documentation
* without an express license agreement from NVIDIA CORPORATION or
* its affiliates is strictly prohibited.
*/
#pragma once

#include "Modules/ModuleManager.h"


class FStreamlineViewExtension;
class FStreamlineMaxTickRateHandler;
class FStreamlineLatencyMarkers;

enum class EStreamlineSupport : uint8;
class FStreamlineRHI;

namespace Streamline
{
	enum class EStreamlineFeature
	{
		DLSSG,
		Reflex,
		DeepDVC,
		Latewarp, // TODO see where that is used
		NumValues
	};

	enum class EStreamlineFeatureSupport
	{
		Supported,
		NotSupported,

		NotSupportedIncompatibleHardware,
		NotSupportedHardwareSchedulingDisabled,
		NotSupportedOperatingSystemOutOfDate,
		NotSupportedDriverOutOfDate,

		NotSupportedIncompatibleRHI,

		NumValues
	};
};


class IStreamlineModuleInterface : public IModuleInterface
{
public:

	virtual EStreamlineSupport QueryStreamlineSupport() const = 0;
	virtual Streamline::EStreamlineFeatureSupport QueryDLSSGSupport() const = 0;
	virtual Streamline::EStreamlineFeatureSupport QueryLatewarpSupport() const = 0;
	virtual Streamline::EStreamlineFeatureSupport QueryDeepDVCSupport() const = 0;
	virtual Streamline::EStreamlineFeatureSupport QueryReflexSupport() const = 0;
};

class FStreamlineCoreModule final: public IStreamlineModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule();
	virtual void ShutdownModule();
	virtual EStreamlineSupport QueryStreamlineSupport() const override;
	virtual Streamline::EStreamlineFeatureSupport QueryDLSSGSupport() const override;
	virtual Streamline::EStreamlineFeatureSupport QueryLatewarpSupport() const override;
	virtual Streamline::EStreamlineFeatureSupport QueryDeepDVCSupport() const override;
	virtual Streamline::EStreamlineFeatureSupport QueryReflexSupport() const override;

	static FStreamlineRHI* GetStreamlineRHI();
private:

	TSharedPtr< FStreamlineViewExtension, ESPMode::ThreadSafe> StreamlineViewExtension;
};
