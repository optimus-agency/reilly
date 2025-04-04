/*
* Copyright (c) 2020 - 2025 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
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

DECLARE_LOG_CATEGORY_EXTERN(LogDLSSEditor, Log, All);

class FDLSSEditorModule final : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() final;
	virtual void ShutdownModule() final;

private:
	bool bIsDLSSAvailable = false;
};


