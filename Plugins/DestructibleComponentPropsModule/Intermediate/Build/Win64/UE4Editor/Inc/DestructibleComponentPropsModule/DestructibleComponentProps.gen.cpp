// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DestructibleComponentPropsModule/Public/DestructibleComponentProps.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDestructibleComponentProps() {}
// Cross Module References
	DESTRUCTIBLECOMPONENTPROPSMODULE_API UClass* Z_Construct_UClass_ADestructibleComponentProps_NoRegister();
	DESTRUCTIBLECOMPONENTPROPSMODULE_API UClass* Z_Construct_UClass_ADestructibleComponentProps();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_DestructibleComponentPropsModule();
	ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
	APEXDESTRUCTION_API UClass* Z_Construct_UClass_UDestructibleComponent_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(ADestructibleComponentProps::execDestroy)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_Damage);
		P_GET_STRUCT(FVector,Z_Param_HitLocation);
		P_GET_STRUCT(FVector,Z_Param_ImpulseDir);
		P_GET_PROPERTY(FFloatProperty,Z_Param_Impulse);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Destroy(Z_Param_Damage,Z_Param_HitLocation,Z_Param_ImpulseDir,Z_Param_Impulse);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ADestructibleComponentProps::execTrigger)
	{
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent);
		P_GET_OBJECT(AActor,Z_Param_OtherActor);
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp);
		P_GET_PROPERTY(FIntProperty,Z_Param_OtherBodyIndex);
		P_GET_UBOOL(Z_Param_bFromSweep);
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Trigger(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ADestructibleComponentProps::execDamage)
	{
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComponent);
		P_GET_OBJECT(AActor,Z_Param_OtherActor);
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp);
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse);
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Damage(Z_Param_HitComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_NormalImpulse,Z_Param_Out_Hit);
		P_NATIVE_END;
	}
	void ADestructibleComponentProps::StaticRegisterNativesADestructibleComponentProps()
	{
		UClass* Class = ADestructibleComponentProps::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Damage", &ADestructibleComponentProps::execDamage },
			{ "Destroy", &ADestructibleComponentProps::execDestroy },
			{ "Trigger", &ADestructibleComponentProps::execTrigger },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ADestructibleComponentProps_Damage_Statics
	{
		struct DestructibleComponentProps_eventDamage_Parms
		{
			UPrimitiveComponent* HitComponent;
			AActor* OtherActor;
			UPrimitiveComponent* OtherComp;
			FVector NormalImpulse;
			FHitResult Hit;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HitComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_HitComponent;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OtherComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherComp;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_NormalImpulse;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Hit_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Hit;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ADestructibleComponentProps_Damage_Statics::NewProp_HitComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ADestructibleComponentProps_Damage_Statics::NewProp_HitComponent = { "HitComponent", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DestructibleComponentProps_eventDamage_Parms, HitComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ADestructibleComponentProps_Damage_Statics::NewProp_HitComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ADestructibleComponentProps_Damage_Statics::NewProp_HitComponent_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ADestructibleComponentProps_Damage_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DestructibleComponentProps_eventDamage_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ADestructibleComponentProps_Damage_Statics::NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ADestructibleComponentProps_Damage_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DestructibleComponentProps_eventDamage_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ADestructibleComponentProps_Damage_Statics::NewProp_OtherComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ADestructibleComponentProps_Damage_Statics::NewProp_OtherComp_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ADestructibleComponentProps_Damage_Statics::NewProp_NormalImpulse = { "NormalImpulse", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DestructibleComponentProps_eventDamage_Parms, NormalImpulse), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ADestructibleComponentProps_Damage_Statics::NewProp_Hit_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ADestructibleComponentProps_Damage_Statics::NewProp_Hit = { "Hit", nullptr, (EPropertyFlags)0x0010008008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DestructibleComponentProps_eventDamage_Parms, Hit), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(Z_Construct_UFunction_ADestructibleComponentProps_Damage_Statics::NewProp_Hit_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ADestructibleComponentProps_Damage_Statics::NewProp_Hit_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADestructibleComponentProps_Damage_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADestructibleComponentProps_Damage_Statics::NewProp_HitComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADestructibleComponentProps_Damage_Statics::NewProp_OtherActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADestructibleComponentProps_Damage_Statics::NewProp_OtherComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADestructibleComponentProps_Damage_Statics::NewProp_NormalImpulse,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADestructibleComponentProps_Damage_Statics::NewProp_Hit,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ADestructibleComponentProps_Damage_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DestructibleComponentProps.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ADestructibleComponentProps_Damage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADestructibleComponentProps, nullptr, "Damage", nullptr, nullptr, sizeof(DestructibleComponentProps_eventDamage_Parms), Z_Construct_UFunction_ADestructibleComponentProps_Damage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADestructibleComponentProps_Damage_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C20401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ADestructibleComponentProps_Damage_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ADestructibleComponentProps_Damage_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ADestructibleComponentProps_Damage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ADestructibleComponentProps_Damage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ADestructibleComponentProps_Destroy_Statics
	{
		struct DestructibleComponentProps_eventDestroy_Parms
		{
			float Damage;
			FVector HitLocation;
			FVector ImpulseDir;
			float Impulse;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Damage;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_HitLocation;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ImpulseDir;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Impulse;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ADestructibleComponentProps_Destroy_Statics::NewProp_Damage = { "Damage", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DestructibleComponentProps_eventDestroy_Parms, Damage), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ADestructibleComponentProps_Destroy_Statics::NewProp_HitLocation = { "HitLocation", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DestructibleComponentProps_eventDestroy_Parms, HitLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ADestructibleComponentProps_Destroy_Statics::NewProp_ImpulseDir = { "ImpulseDir", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DestructibleComponentProps_eventDestroy_Parms, ImpulseDir), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ADestructibleComponentProps_Destroy_Statics::NewProp_Impulse = { "Impulse", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DestructibleComponentProps_eventDestroy_Parms, Impulse), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADestructibleComponentProps_Destroy_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADestructibleComponentProps_Destroy_Statics::NewProp_Damage,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADestructibleComponentProps_Destroy_Statics::NewProp_HitLocation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADestructibleComponentProps_Destroy_Statics::NewProp_ImpulseDir,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADestructibleComponentProps_Destroy_Statics::NewProp_Impulse,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ADestructibleComponentProps_Destroy_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DestructibleComponentProps.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ADestructibleComponentProps_Destroy_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADestructibleComponentProps, nullptr, "Destroy", nullptr, nullptr, sizeof(DestructibleComponentProps_eventDestroy_Parms), Z_Construct_UFunction_ADestructibleComponentProps_Destroy_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADestructibleComponentProps_Destroy_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ADestructibleComponentProps_Destroy_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ADestructibleComponentProps_Destroy_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ADestructibleComponentProps_Destroy()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ADestructibleComponentProps_Destroy_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ADestructibleComponentProps_Trigger_Statics
	{
		struct DestructibleComponentProps_eventTrigger_Parms
		{
			UPrimitiveComponent* OverlappedComponent;
			AActor* OtherActor;
			UPrimitiveComponent* OtherComp;
			int32 OtherBodyIndex;
			bool bFromSweep;
			FHitResult SweepResult;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OverlappedComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OverlappedComponent;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OtherComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherComp;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_OtherBodyIndex;
		static void NewProp_bFromSweep_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bFromSweep;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SweepResult_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_SweepResult;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ADestructibleComponentProps_Trigger_Statics::NewProp_OverlappedComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ADestructibleComponentProps_Trigger_Statics::NewProp_OverlappedComponent = { "OverlappedComponent", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DestructibleComponentProps_eventTrigger_Parms, OverlappedComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ADestructibleComponentProps_Trigger_Statics::NewProp_OverlappedComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ADestructibleComponentProps_Trigger_Statics::NewProp_OverlappedComponent_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ADestructibleComponentProps_Trigger_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DestructibleComponentProps_eventTrigger_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ADestructibleComponentProps_Trigger_Statics::NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ADestructibleComponentProps_Trigger_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DestructibleComponentProps_eventTrigger_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ADestructibleComponentProps_Trigger_Statics::NewProp_OtherComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ADestructibleComponentProps_Trigger_Statics::NewProp_OtherComp_MetaData)) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ADestructibleComponentProps_Trigger_Statics::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DestructibleComponentProps_eventTrigger_Parms, OtherBodyIndex), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_ADestructibleComponentProps_Trigger_Statics::NewProp_bFromSweep_SetBit(void* Obj)
	{
		((DestructibleComponentProps_eventTrigger_Parms*)Obj)->bFromSweep = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ADestructibleComponentProps_Trigger_Statics::NewProp_bFromSweep = { "bFromSweep", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(DestructibleComponentProps_eventTrigger_Parms), &Z_Construct_UFunction_ADestructibleComponentProps_Trigger_Statics::NewProp_bFromSweep_SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ADestructibleComponentProps_Trigger_Statics::NewProp_SweepResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ADestructibleComponentProps_Trigger_Statics::NewProp_SweepResult = { "SweepResult", nullptr, (EPropertyFlags)0x0010008008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DestructibleComponentProps_eventTrigger_Parms, SweepResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(Z_Construct_UFunction_ADestructibleComponentProps_Trigger_Statics::NewProp_SweepResult_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ADestructibleComponentProps_Trigger_Statics::NewProp_SweepResult_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADestructibleComponentProps_Trigger_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADestructibleComponentProps_Trigger_Statics::NewProp_OverlappedComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADestructibleComponentProps_Trigger_Statics::NewProp_OtherActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADestructibleComponentProps_Trigger_Statics::NewProp_OtherComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADestructibleComponentProps_Trigger_Statics::NewProp_OtherBodyIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADestructibleComponentProps_Trigger_Statics::NewProp_bFromSweep,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADestructibleComponentProps_Trigger_Statics::NewProp_SweepResult,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ADestructibleComponentProps_Trigger_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DestructibleComponentProps.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ADestructibleComponentProps_Trigger_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADestructibleComponentProps, nullptr, "Trigger", nullptr, nullptr, sizeof(DestructibleComponentProps_eventTrigger_Parms), Z_Construct_UFunction_ADestructibleComponentProps_Trigger_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADestructibleComponentProps_Trigger_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ADestructibleComponentProps_Trigger_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ADestructibleComponentProps_Trigger_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ADestructibleComponentProps_Trigger()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ADestructibleComponentProps_Trigger_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ADestructibleComponentProps_NoRegister()
	{
		return ADestructibleComponentProps::StaticClass();
	}
	struct Z_Construct_UClass_ADestructibleComponentProps_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TriggerComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_TriggerComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DestructibleComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DestructibleComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsTriggerEnabled_MetaData[];
#endif
		static void NewProp_IsTriggerEnabled_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsTriggerEnabled;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsDestroyed_MetaData[];
#endif
		static void NewProp_IsDestroyed_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsDestroyed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxHealth_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MaxHealth;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CurrentHealth_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_CurrentHealth;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DefaultDamage_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DefaultDamage;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DefaultImpulse_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DefaultImpulse;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ADestructibleComponentProps_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_DestructibleComponentPropsModule,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ADestructibleComponentProps_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ADestructibleComponentProps_Damage, "Damage" }, // 1510362785
		{ &Z_Construct_UFunction_ADestructibleComponentProps_Destroy, "Destroy" }, // 1778329581
		{ &Z_Construct_UFunction_ADestructibleComponentProps_Trigger, "Trigger" }, // 117751702
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADestructibleComponentProps_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "DestructibleComponentProps.h" },
		{ "ModuleRelativePath", "Public/DestructibleComponentProps.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADestructibleComponentProps_Statics::NewProp_TriggerComponent_MetaData[] = {
		{ "Category", "Destractible" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DestructibleComponentProps.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADestructibleComponentProps_Statics::NewProp_TriggerComponent = { "TriggerComponent", nullptr, (EPropertyFlags)0x00100000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ADestructibleComponentProps, TriggerComponent), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ADestructibleComponentProps_Statics::NewProp_TriggerComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADestructibleComponentProps_Statics::NewProp_TriggerComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADestructibleComponentProps_Statics::NewProp_DestructibleComponent_MetaData[] = {
		{ "Category", "Destractible" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DestructibleComponentProps.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADestructibleComponentProps_Statics::NewProp_DestructibleComponent = { "DestructibleComponent", nullptr, (EPropertyFlags)0x00100000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ADestructibleComponentProps, DestructibleComponent), Z_Construct_UClass_UDestructibleComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ADestructibleComponentProps_Statics::NewProp_DestructibleComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADestructibleComponentProps_Statics::NewProp_DestructibleComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADestructibleComponentProps_Statics::NewProp_IsTriggerEnabled_MetaData[] = {
		{ "Category", "Destractible" },
		{ "ModuleRelativePath", "Public/DestructibleComponentProps.h" },
	};
#endif
	void Z_Construct_UClass_ADestructibleComponentProps_Statics::NewProp_IsTriggerEnabled_SetBit(void* Obj)
	{
		((ADestructibleComponentProps*)Obj)->IsTriggerEnabled = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ADestructibleComponentProps_Statics::NewProp_IsTriggerEnabled = { "IsTriggerEnabled", nullptr, (EPropertyFlags)0x0010000000010015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ADestructibleComponentProps), &Z_Construct_UClass_ADestructibleComponentProps_Statics::NewProp_IsTriggerEnabled_SetBit, METADATA_PARAMS(Z_Construct_UClass_ADestructibleComponentProps_Statics::NewProp_IsTriggerEnabled_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADestructibleComponentProps_Statics::NewProp_IsTriggerEnabled_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADestructibleComponentProps_Statics::NewProp_IsDestroyed_MetaData[] = {
		{ "Category", "Destractible" },
		{ "ModuleRelativePath", "Public/DestructibleComponentProps.h" },
	};
#endif
	void Z_Construct_UClass_ADestructibleComponentProps_Statics::NewProp_IsDestroyed_SetBit(void* Obj)
	{
		((ADestructibleComponentProps*)Obj)->IsDestroyed = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ADestructibleComponentProps_Statics::NewProp_IsDestroyed = { "IsDestroyed", nullptr, (EPropertyFlags)0x0010000000010015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ADestructibleComponentProps), &Z_Construct_UClass_ADestructibleComponentProps_Statics::NewProp_IsDestroyed_SetBit, METADATA_PARAMS(Z_Construct_UClass_ADestructibleComponentProps_Statics::NewProp_IsDestroyed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADestructibleComponentProps_Statics::NewProp_IsDestroyed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADestructibleComponentProps_Statics::NewProp_MaxHealth_MetaData[] = {
		{ "Category", "Destractible" },
		{ "ModuleRelativePath", "Public/DestructibleComponentProps.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ADestructibleComponentProps_Statics::NewProp_MaxHealth = { "MaxHealth", nullptr, (EPropertyFlags)0x0010000000010015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ADestructibleComponentProps, MaxHealth), METADATA_PARAMS(Z_Construct_UClass_ADestructibleComponentProps_Statics::NewProp_MaxHealth_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADestructibleComponentProps_Statics::NewProp_MaxHealth_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADestructibleComponentProps_Statics::NewProp_CurrentHealth_MetaData[] = {
		{ "Category", "Destractible" },
		{ "ModuleRelativePath", "Public/DestructibleComponentProps.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ADestructibleComponentProps_Statics::NewProp_CurrentHealth = { "CurrentHealth", nullptr, (EPropertyFlags)0x0010000000010015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ADestructibleComponentProps, CurrentHealth), METADATA_PARAMS(Z_Construct_UClass_ADestructibleComponentProps_Statics::NewProp_CurrentHealth_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADestructibleComponentProps_Statics::NewProp_CurrentHealth_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADestructibleComponentProps_Statics::NewProp_DefaultDamage_MetaData[] = {
		{ "Category", "Destractible" },
		{ "ModuleRelativePath", "Public/DestructibleComponentProps.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ADestructibleComponentProps_Statics::NewProp_DefaultDamage = { "DefaultDamage", nullptr, (EPropertyFlags)0x0010000000010015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ADestructibleComponentProps, DefaultDamage), METADATA_PARAMS(Z_Construct_UClass_ADestructibleComponentProps_Statics::NewProp_DefaultDamage_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADestructibleComponentProps_Statics::NewProp_DefaultDamage_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADestructibleComponentProps_Statics::NewProp_DefaultImpulse_MetaData[] = {
		{ "Category", "Destractible" },
		{ "ModuleRelativePath", "Public/DestructibleComponentProps.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ADestructibleComponentProps_Statics::NewProp_DefaultImpulse = { "DefaultImpulse", nullptr, (EPropertyFlags)0x0010000000010015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ADestructibleComponentProps, DefaultImpulse), METADATA_PARAMS(Z_Construct_UClass_ADestructibleComponentProps_Statics::NewProp_DefaultImpulse_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADestructibleComponentProps_Statics::NewProp_DefaultImpulse_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ADestructibleComponentProps_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADestructibleComponentProps_Statics::NewProp_TriggerComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADestructibleComponentProps_Statics::NewProp_DestructibleComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADestructibleComponentProps_Statics::NewProp_IsTriggerEnabled,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADestructibleComponentProps_Statics::NewProp_IsDestroyed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADestructibleComponentProps_Statics::NewProp_MaxHealth,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADestructibleComponentProps_Statics::NewProp_CurrentHealth,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADestructibleComponentProps_Statics::NewProp_DefaultDamage,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADestructibleComponentProps_Statics::NewProp_DefaultImpulse,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ADestructibleComponentProps_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADestructibleComponentProps>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ADestructibleComponentProps_Statics::ClassParams = {
		&ADestructibleComponentProps::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ADestructibleComponentProps_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ADestructibleComponentProps_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ADestructibleComponentProps_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ADestructibleComponentProps_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ADestructibleComponentProps()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ADestructibleComponentProps_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ADestructibleComponentProps, 3964951014);
	template<> DESTRUCTIBLECOMPONENTPROPSMODULE_API UClass* StaticClass<ADestructibleComponentProps>()
	{
		return ADestructibleComponentProps::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ADestructibleComponentProps(Z_Construct_UClass_ADestructibleComponentProps, &ADestructibleComponentProps::StaticClass, TEXT("/Script/DestructibleComponentPropsModule"), TEXT("ADestructibleComponentProps"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ADestructibleComponentProps);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
