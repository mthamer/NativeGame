/// <summary>
/// Internals of the bindings between native and .NET code.
/// Game code shouldn't go here.
/// </summary>
/// <author>
/// Jackson Dunstan, 2017, http://JacksonDunstan.com
/// </author>
/// <license>
/// MIT
/// </license>

// Type definitions
#include "Bindings.h"

// Game type definitions
#include "GameScript.h"

// For assert()
#include <assert.h>

// For int32_t, etc.
#include <stdint.h>

// For malloc(), etc.
#include <stdlib.h>

// For memset(), etc.
#include <string.h>

#include <new>
void* operator new(size_t, void* p);

// Macro to put before functions that need to be exposed to C#
#ifdef _WIN32
	#define DLLEXPORT extern "C" __declspec(dllexport)
#else
	#define DLLEXPORT extern "C"
#endif

////////////////////////////////////////////////////////////////
// C# functions for C++ to call
////////////////////////////////////////////////////////////////

namespace Plugin
{
	void (*ReleaseObject)(int32_t handle);
	int32_t (*StringNew)(const char* chars);
	void (*SetException)(int32_t handle);
	int32_t (*ArrayGetLength)(int32_t handle);
	int32_t (*EnumerableGetEnumerator)(int32_t handle);
	
	/*BEGIN FUNCTION POINTERS*/
	void (*ReleaseSystemDecimal)(int32_t handle);
	int32_t (*SystemDecimalConstructorSystemDouble)(double value);
	int32_t (*SystemDecimalConstructorSystemUInt64)(uint64_t value);
	int32_t (*BoxDecimal)(int32_t valHandle);
	int32_t (*UnboxDecimal)(int32_t valHandle);
	UnityEngine::Vector3 (*UnityEngineVector3ConstructorSystemSingle_SystemSingle_SystemSingle)(float x, float y, float z);
	System::Single (*UnityEngineVector3PropertyGetMagnitude)(UnityEngine::Vector3* thiz);
	UnityEngine::Vector3 (*UnityEngineVector3Methodop_AdditionUnityEngineVector3_UnityEngineVector3)(UnityEngine::Vector3& a, UnityEngine::Vector3& b);
	UnityEngine::Vector3 (*UnityEngineVector3Methodop_SubtractionUnityEngineVector3_UnityEngineVector3)(UnityEngine::Vector3& a, UnityEngine::Vector3& b);
	UnityEngine::Vector3 (*UnityEngineVector3MethodNormalizeUnityEngineVector3)(UnityEngine::Vector3& value);
	System::Single (*UnityEngineVector3MethodDotUnityEngineVector3_UnityEngineVector3)(UnityEngine::Vector3& lhs, UnityEngine::Vector3& rhs);
	UnityEngine::Vector3 (*UnityEngineVector3MethodCrossUnityEngineVector3_UnityEngineVector3)(UnityEngine::Vector3& lhs, UnityEngine::Vector3& rhs);
	System::Single (*UnityEngineVector3MethodDistanceUnityEngineVector3_UnityEngineVector3)(UnityEngine::Vector3& a, UnityEngine::Vector3& b);
	int32_t (*BoxVector3)(UnityEngine::Vector3& val);
	UnityEngine::Vector3 (*UnboxVector3)(int32_t valHandle);
	int32_t (*UnityEngineObjectPropertyGetName)(int32_t thisHandle);
	void (*UnityEngineObjectPropertySetName)(int32_t thisHandle, int32_t valueHandle);
	void (*UnityEngineObjectMethodDestroyUnityEngineObject)(int32_t objHandle);
	int32_t (*UnityEngineComponentPropertyGetTransform)(int32_t thisHandle);
	int32_t (*UnityEngineComponentPropertyGetGameObject)(int32_t thisHandle);
	UnityEngine::Vector3 (*UnityEngineTransformPropertyGetPosition)(int32_t thisHandle);
	void (*UnityEngineTransformPropertySetPosition)(int32_t thisHandle, UnityEngine::Vector3& value);
	int32_t (*SystemCollectionsIEnumeratorPropertyGetCurrent)(int32_t thisHandle);
	int32_t (*SystemCollectionsIEnumeratorMethodMoveNext)(int32_t thisHandle);
	void (*ReleaseUnityEngineBounds)(int32_t handle);
	UnityEngine::Vector3 (*UnityEngineBoundsPropertyGetMax)(int32_t thisHandle);
	void (*UnityEngineBoundsPropertySetMax)(int32_t thisHandle, UnityEngine::Vector3& value);
	UnityEngine::Vector3 (*UnityEngineBoundsPropertyGetMin)(int32_t thisHandle);
	void (*UnityEngineBoundsPropertySetMin)(int32_t thisHandle, UnityEngine::Vector3& value);
	int32_t (*UnityEngineBoundsMethodIntersectsUnityEngineBounds)(int32_t thisHandle, int32_t boundsHandle);
	int32_t (*BoxBounds)(int32_t valHandle);
	int32_t (*UnboxBounds)(int32_t valHandle);
	int32_t (*UnityEngineGameObjectConstructor)();
	int32_t (*UnityEngineGameObjectConstructorSystemString)(int32_t nameHandle);
	int32_t (*UnityEngineGameObjectPropertyGetTransform)(int32_t thisHandle);
	int32_t (*UnityEngineGameObjectPropertyGetTag)(int32_t thisHandle);
	void (*UnityEngineGameObjectPropertySetTag)(int32_t thisHandle, int32_t valueHandle);
	int32_t (*UnityEngineGameObjectMethodAddComponentMyGameBaseGameScript)(int32_t thisHandle);
	int32_t (*UnityEngineGameObjectMethodAddComponentUnityEngineSpriteRenderer)(int32_t thisHandle);
	int32_t (*UnityEngineGameObjectMethodAddComponentUnityEngineAudioSource)(int32_t thisHandle);
	int32_t (*UnityEngineGameObjectMethodGetComponentUnityEngineSpriteRenderer)(int32_t thisHandle);
	int32_t (*UnityEngineGameObjectMethodGetComponentUnityEngineAudioSource)(int32_t thisHandle);
	int32_t (*UnityEngineGameObjectMethodCompareTagSystemString)(int32_t thisHandle, int32_t tagHandle);
	int32_t (*UnityEngineGameObjectMethodCreatePrimitiveUnityEnginePrimitiveType)(UnityEngine::PrimitiveType type);
	void (*UnityEngineDebugMethodLogSystemObject)(int32_t messageHandle);
	int32_t (*UnityEngineAudioClipConstructor)();
	int32_t (*UnityEngineAudioSourcePropertyGetLoop)(int32_t thisHandle);
	void (*UnityEngineAudioSourcePropertySetLoop)(int32_t thisHandle, uint32_t value);
	int32_t (*UnityEngineAudioSourcePropertyGetClip)(int32_t thisHandle);
	void (*UnityEngineAudioSourcePropertySetClip)(int32_t thisHandle, int32_t valueHandle);
	void (*UnityEngineAudioSourceMethodPlayOneShotUnityEngineAudioClip)(int32_t thisHandle, int32_t clipHandle);
	void (*UnityEngineAudioSourceMethodPlay)(int32_t thisHandle);
	void (*UnityEngineAudioSourceMethodStop)(int32_t thisHandle);
	System::Single (*UnityEngineInputMethodGetAxisSystemString)(int32_t axisNameHandle);
	System::Single (*UnityEngineInputMethodGetAxisRawSystemString)(int32_t axisNameHandle);
	int32_t (*UnityEngineInputMethodGetKeySystemString)(int32_t nameHandle);
	int32_t (*UnityEngineInputMethodGetKeyUpSystemString)(int32_t nameHandle);
	int32_t (*UnityEngineInputMethodGetKeyDownSystemString)(int32_t nameHandle);
	int32_t (*UnityEngineResourcesMethodLoadUnityEngineSpriteSystemString)(int32_t pathHandle);
	int32_t (*UnityEngineResourcesMethodLoadUnityEngineAudioClipSystemString)(int32_t pathHandle);
	int32_t (*UnityEngineMonoBehaviourPropertyGetTransform)(int32_t thisHandle);
	int32_t (*SystemExceptionConstructorSystemString)(int32_t messageHandle);
	int32_t (*BoxPrimitiveType)(UnityEngine::PrimitiveType val);
	UnityEngine::PrimitiveType (*UnboxPrimitiveType)(int32_t valHandle);
	int32_t (*UnityEngineSpriteConstructor)();
	int32_t (*UnityEngineSpritePropertyGetBounds)(int32_t thisHandle);
	int32_t (*UnityEngineSpriteRendererPropertyGetSprite)(int32_t thisHandle);
	void (*UnityEngineSpriteRendererPropertySetSprite)(int32_t thisHandle, int32_t valueHandle);
	int32_t (*UnityEngineSpriteRendererPropertyGetBounds)(int32_t thisHandle);
	System::Single (*UnityEngineTimePropertyGetDeltaTime)();
	void (*ReleaseBaseGameScript)(int32_t handle);
	void (*BaseGameScriptConstructor)(int32_t cppHandle, int32_t* handle);
	int32_t (*BoxBoolean)(uint32_t val);
	int32_t (*UnboxBoolean)(int32_t valHandle);
	int32_t (*BoxSByte)(int8_t val);
	System::SByte (*UnboxSByte)(int32_t valHandle);
	int32_t (*BoxByte)(uint8_t val);
	System::Byte (*UnboxByte)(int32_t valHandle);
	int32_t (*BoxInt16)(int16_t val);
	System::Int16 (*UnboxInt16)(int32_t valHandle);
	int32_t (*BoxUInt16)(uint16_t val);
	System::UInt16 (*UnboxUInt16)(int32_t valHandle);
	int32_t (*BoxInt32)(int32_t val);
	System::Int32 (*UnboxInt32)(int32_t valHandle);
	int32_t (*BoxUInt32)(uint32_t val);
	System::UInt32 (*UnboxUInt32)(int32_t valHandle);
	int32_t (*BoxInt64)(int64_t val);
	System::Int64 (*UnboxInt64)(int32_t valHandle);
	int32_t (*BoxUInt64)(uint64_t val);
	System::UInt64 (*UnboxUInt64)(int32_t valHandle);
	int32_t (*BoxChar)(uint16_t val);
	int16_t (*UnboxChar)(int32_t valHandle);
	int32_t (*BoxSingle)(float val);
	System::Single (*UnboxSingle)(int32_t valHandle);
	int32_t (*BoxDouble)(double val);
	System::Double (*UnboxDouble)(int32_t valHandle);
	/*END FUNCTION POINTERS*/
}

////////////////////////////////////////////////////////////////
// Global variables
////////////////////////////////////////////////////////////////

namespace Plugin
{
	System::String NullString(nullptr);
}

////////////////////////////////////////////////////////////////
// Plugin Types
////////////////////////////////////////////////////////////////

namespace Plugin
{
	ManagedType::ManagedType()
		: Handle(0)
	{
	}
	
	ManagedType::ManagedType(decltype(nullptr))
		: Handle(0)
	{
	}
	
	ManagedType::ManagedType(Plugin::InternalUse iu, int32_t handle)
		: Handle(handle)
	{
	}
}

////////////////////////////////////////////////////////////////
// C# Primitive Types
////////////////////////////////////////////////////////////////

namespace System
{
	Boolean::Boolean()
		: Value(0)
	{
	}
	
	Boolean::Boolean(bool value)
		: Value((int32_t)value)
	{
	}
	
	Boolean::Boolean(int32_t value)
		: Value(value)
	{
	}
	
	Boolean::Boolean(uint32_t value)
		: Value(value)
	{
	}
	
	Boolean::operator bool() const
	{
		return (bool)Value;
	}
	
	Boolean::operator int32_t() const
	{
		return Value;
	}
	
	Boolean::operator uint32_t() const
	{
		return Value;
	}
	
	Boolean::operator Object() const
	{
		return Object(Plugin::InternalUse::Only, Plugin::BoxBoolean(Value));
	}
	
	Boolean::operator ValueType() const
	{
		return ValueType(Plugin::InternalUse::Only, Plugin::BoxBoolean(Value));
	}
	
	Boolean::operator IComparable() const
	{
		return IComparable(Plugin::InternalUse::Only, Plugin::BoxBoolean(Value));
	}
	
	Boolean::operator IFormattable() const
	{
		return IFormattable(Plugin::InternalUse::Only, Plugin::BoxBoolean(Value));
	}
	
	Boolean::operator IConvertible() const
	{
		return IConvertible(Plugin::InternalUse::Only, Plugin::BoxBoolean(Value));
	}
	
	Boolean::operator IComparable_1<Boolean>() const
	{
		return IComparable_1<Boolean>(Plugin::InternalUse::Only, Plugin::BoxBoolean(Value));
	}
	
	Boolean::operator IEquatable_1<Boolean>() const
	{
		return IEquatable_1<Boolean>(Plugin::InternalUse::Only, Plugin::BoxBoolean(Value));
	}
	
	Char::Char()
		: Value(0)
	{
	}
	
	Char::Char(char value)
		: Value(value)
	{
	}
	
	Char::Char(int16_t value)
		: Value(value)
	{
	}
	
	Char::operator int16_t() const
	{
		return Value;
	}
	
	Char::operator Object() const
	{
		return Object(Plugin::InternalUse::Only, Plugin::BoxChar(Value));
	}
	
	Char::operator ValueType() const
	{
		return ValueType(Plugin::InternalUse::Only, Plugin::BoxChar(Value));
	}
	
	Char::operator IComparable() const
	{
		return IComparable(Plugin::InternalUse::Only, Plugin::BoxChar(Value));
	}
	
	Char::operator IFormattable() const
	{
		return IFormattable(Plugin::InternalUse::Only, Plugin::BoxChar(Value));
	}
	
	Char::operator IConvertible() const
	{
		return IConvertible(Plugin::InternalUse::Only, Plugin::BoxChar(Value));
	}
	
	Char::operator IComparable_1<Char>() const
	{
		return IComparable_1<Char>(Plugin::InternalUse::Only, Plugin::BoxChar(Value));
	}
	
	Char::operator IEquatable_1<Char>() const
	{
		return IEquatable_1<Char>(Plugin::InternalUse::Only, Plugin::BoxChar(Value));
	}

	SByte::SByte()
		: Value(0)
	{
	}
	
	SByte::SByte(int8_t val)
		: Value(val)
	{
	}
	
	SByte::operator int8_t() const
	{
		return Value;
	}
	
	SByte::operator Object() const
	{
		return Object(Plugin::InternalUse::Only, Plugin::BoxSByte(Value));
	}
	
	SByte::operator ValueType() const
	{
		return ValueType(Plugin::InternalUse::Only, Plugin::BoxSByte(Value));
	}
	
	SByte::operator IComparable() const
	{
		return IComparable(Plugin::InternalUse::Only, Plugin::BoxSByte(Value));
	}
	
	SByte::operator IFormattable() const
	{
		return IFormattable(Plugin::InternalUse::Only, Plugin::BoxSByte(Value));
	}
	
	SByte::operator IConvertible() const
	{
		return IConvertible(Plugin::InternalUse::Only, Plugin::BoxSByte(Value));
	}
	
	SByte::operator IComparable_1<SByte>() const
	{
		return IComparable_1<SByte>(Plugin::InternalUse::Only, Plugin::BoxSByte(Value));
	}
	
	SByte::operator IEquatable_1<SByte>() const
	{
		return IEquatable_1<SByte>(Plugin::InternalUse::Only, Plugin::BoxSByte(Value));
	}

	Byte::Byte()
		: Value(0)
	{
	}
	
	Byte::Byte(uint8_t value)
		: Value(value)
	{
	}
	
	Byte::operator uint8_t() const
	{
		return Value;
	}
	
	Byte::operator Object() const
	{
		return Object(Plugin::InternalUse::Only, Plugin::BoxByte(Value));
	}
	
	Byte::operator ValueType() const
	{
		return ValueType(Plugin::InternalUse::Only, Plugin::BoxByte(Value));
	}
	
	Byte::operator IComparable() const
	{
		return IComparable(Plugin::InternalUse::Only, Plugin::BoxByte(Value));
	}
	
	Byte::operator IFormattable() const
	{
		return IFormattable(Plugin::InternalUse::Only, Plugin::BoxByte(Value));
	}
	
	Byte::operator IConvertible() const
	{
		return IConvertible(Plugin::InternalUse::Only, Plugin::BoxByte(Value));
	}
	
	Byte::operator IComparable_1<Byte>() const
	{
		return IComparable_1<Byte>(Plugin::InternalUse::Only, Plugin::BoxByte(Value));
	}
	
	Byte::operator IEquatable_1<Byte>() const
	{
		return IEquatable_1<Byte>(Plugin::InternalUse::Only, Plugin::BoxByte(Value));
	}

	Int16::Int16()
		: Value(0)
	{
	}
	
	Int16::Int16(int16_t value)
		: Value(value)
	{
	}
	
	Int16::operator int16_t() const
	{
		return Value;
	}
	
	Int16::operator Object() const
	{
		return Object(Plugin::InternalUse::Only, Plugin::BoxInt16(Value));
	}
	
	Int16::operator ValueType() const
	{
		return ValueType(Plugin::InternalUse::Only, Plugin::BoxInt16(Value));
	}
	
	Int16::operator IComparable() const
	{
		return IComparable(Plugin::InternalUse::Only, Plugin::BoxInt16(Value));
	}
	
	Int16::operator IFormattable() const
	{
		return IFormattable(Plugin::InternalUse::Only, Plugin::BoxInt16(Value));
	}
	
	Int16::operator IConvertible() const
	{
		return IConvertible(Plugin::InternalUse::Only, Plugin::BoxInt16(Value));
	}
	
	Int16::operator IComparable_1<Int16>() const
	{
		return IComparable_1<Int16>(Plugin::InternalUse::Only, Plugin::BoxInt16(Value));
	}
	
	Int16::operator IEquatable_1<Int16>() const
	{
		return IEquatable_1<Int16>(Plugin::InternalUse::Only, Plugin::BoxInt16(Value));
	}

	UInt16::UInt16()
		: Value(0)
	{
	}
	
	UInt16::UInt16(uint16_t value)
		: Value(value)
	{
	}
	
	UInt16::operator uint16_t() const
	{
		return Value;
	}
	
	UInt16::operator Object() const
	{
		return Object(Plugin::InternalUse::Only, Plugin::BoxUInt16(Value));
	}
	
	UInt16::operator ValueType() const
	{
		return ValueType(Plugin::InternalUse::Only, Plugin::BoxUInt16(Value));
	}
	
	UInt16::operator IComparable() const
	{
		return IComparable(Plugin::InternalUse::Only, Plugin::BoxUInt16(Value));
	}
	
	UInt16::operator IFormattable() const
	{
		return IFormattable(Plugin::InternalUse::Only, Plugin::BoxUInt16(Value));
	}
	
	UInt16::operator IConvertible() const
	{
		return IConvertible(Plugin::InternalUse::Only, Plugin::BoxUInt16(Value));
	}
	
	UInt16::operator IComparable_1<UInt16>() const
	{
		return IComparable_1<UInt16>(Plugin::InternalUse::Only, Plugin::BoxUInt16(Value));
	}
	
	UInt16::operator IEquatable_1<UInt16>() const
	{
		return IEquatable_1<UInt16>(Plugin::InternalUse::Only, Plugin::BoxUInt16(Value));
	}

	Int32::Int32()
		: Value(0)
	{
	}
	
	Int32::Int32(int32_t value)
		: Value(value)
	{
	}
	
	Int32::operator int32_t() const
	{
		return Value;
	}
	
	Int32::operator Object() const
	{
		return Object(Plugin::InternalUse::Only, Plugin::BoxInt32(Value));
	}
	
	Int32::operator ValueType() const
	{
		return ValueType(Plugin::InternalUse::Only, Plugin::BoxInt32(Value));
	}
	
	Int32::operator IComparable() const
	{
		return IComparable(Plugin::InternalUse::Only, Plugin::BoxInt32(Value));
	}
	
	Int32::operator IFormattable() const
	{
		return IFormattable(Plugin::InternalUse::Only, Plugin::BoxInt32(Value));
	}
	
	Int32::operator IConvertible() const
	{
		return IConvertible(Plugin::InternalUse::Only, Plugin::BoxInt32(Value));
	}
	
	Int32::operator IComparable_1<Int32>() const
	{
		return IComparable_1<Int32>(Plugin::InternalUse::Only, Plugin::BoxInt32(Value));
	}
	
	Int32::operator IEquatable_1<Int32>() const
	{
		return IEquatable_1<Int32>(Plugin::InternalUse::Only, Plugin::BoxInt32(Value));
	}

	UInt32::UInt32()
		: Value(0)
	{
	}
	
	UInt32::UInt32(uint32_t value)
		: Value(value)
	{
	}
	
	UInt32::operator uint32_t() const
	{
		return Value;
	}
	
	UInt32::operator Object() const
	{
		return Object(Plugin::InternalUse::Only, Plugin::BoxUInt32(Value));
	}
	
	UInt32::operator ValueType() const
	{
		return ValueType(Plugin::InternalUse::Only, Plugin::BoxUInt32(Value));
	}
	
	UInt32::operator IComparable() const
	{
		return IComparable(Plugin::InternalUse::Only, Plugin::BoxUInt32(Value));
	}
	
	UInt32::operator IFormattable() const
	{
		return IFormattable(Plugin::InternalUse::Only, Plugin::BoxUInt32(Value));
	}
	
	UInt32::operator IConvertible() const
	{
		return IConvertible(Plugin::InternalUse::Only, Plugin::BoxUInt32(Value));
	}
	
	UInt32::operator IComparable_1<UInt32>() const
	{
		return IComparable_1<UInt32>(Plugin::InternalUse::Only, Plugin::BoxUInt32(Value));
	}
	
	UInt32::operator IEquatable_1<UInt32>() const
	{
		return IEquatable_1<UInt32>(Plugin::InternalUse::Only, Plugin::BoxUInt32(Value));
	}

	Int64::Int64()
		: Value(0)
	{
	}
	
	Int64::Int64(int64_t value)
		: Value(value)
	{
	}
	
	Int64::operator int64_t() const
	{
		return Value;
	}
	
	Int64::operator Object() const
	{
		return Object(Plugin::InternalUse::Only, Plugin::BoxInt64(Value));
	}
	
	Int64::operator ValueType() const
	{
		return ValueType(Plugin::InternalUse::Only, Plugin::BoxInt64(Value));
	}
	
	Int64::operator IComparable() const
	{
		return IComparable(Plugin::InternalUse::Only, Plugin::BoxInt64(Value));
	}
	
	Int64::operator IFormattable() const
	{
		return IFormattable(Plugin::InternalUse::Only, Plugin::BoxInt64(Value));
	}
	
	Int64::operator IConvertible() const
	{
		return IConvertible(Plugin::InternalUse::Only, Plugin::BoxInt64(Value));
	}
	
	Int64::operator IComparable_1<Int64>() const
	{
		return IComparable_1<Int64>(Plugin::InternalUse::Only, Plugin::BoxInt64(Value));
	}
	
	Int64::operator IEquatable_1<Int64>() const
	{
		return IEquatable_1<Int64>(Plugin::InternalUse::Only, Plugin::BoxInt64(Value));
	}

	UInt64::UInt64()
		: Value(0)
	{
	}
	
	UInt64::UInt64(uint64_t value)
		: Value(value)
	{
	}
	
	UInt64::operator uint64_t() const
	{
		return Value;
	}
	
	UInt64::operator Object() const
	{
		return Object(Plugin::InternalUse::Only, Plugin::BoxUInt64(Value));
	}
	
	UInt64::operator ValueType() const
	{
		return ValueType(Plugin::InternalUse::Only, Plugin::BoxUInt64(Value));
	}
	
	UInt64::operator IComparable() const
	{
		return IComparable(Plugin::InternalUse::Only, Plugin::BoxUInt64(Value));
	}
	
	UInt64::operator IFormattable() const
	{
		return IFormattable(Plugin::InternalUse::Only, Plugin::BoxUInt64(Value));
	}
	
	UInt64::operator IConvertible() const
	{
		return IConvertible(Plugin::InternalUse::Only, Plugin::BoxUInt64(Value));
	}
	
	UInt64::operator IComparable_1<UInt64>() const
	{
		return IComparable_1<UInt64>(Plugin::InternalUse::Only, Plugin::BoxUInt64(Value));
	}
	
	UInt64::operator IEquatable_1<UInt64>() const
	{
		return IEquatable_1<UInt64>(Plugin::InternalUse::Only, Plugin::BoxUInt64(Value));
	}

	Single::Single()
		: Value(0.0f)
	{
	}
	
	Single::Single(float value)
		: Value(value)
	{
	}
	
	Single::operator float() const
	{
		return Value;
	}
	
	Single::operator Object() const
	{
		return Object(Plugin::InternalUse::Only, Plugin::BoxSingle(Value));
	}
	
	Single::operator ValueType() const
	{
		return ValueType(Plugin::InternalUse::Only, Plugin::BoxSingle(Value));
	}
	
	Single::operator IComparable() const
	{
		return IComparable(Plugin::InternalUse::Only, Plugin::BoxSingle(Value));
	}
	
	Single::operator IFormattable() const
	{
		return IFormattable(Plugin::InternalUse::Only, Plugin::BoxSingle(Value));
	}
	
	Single::operator IConvertible() const
	{
		return IConvertible(Plugin::InternalUse::Only, Plugin::BoxSingle(Value));
	}
	
	Single::operator IComparable_1<Single>() const
	{
		return IComparable_1<Single>(Plugin::InternalUse::Only, Plugin::BoxSingle(Value));
	}
	
	Single::operator IEquatable_1<Single>() const
	{
		return IEquatable_1<Single>(Plugin::InternalUse::Only, Plugin::BoxSingle(Value));
	}

	Double::Double()
		: Value(0.0)
	{
	}
	
	Double::Double(double value)
		: Value(value)
	{
	}
	
	Double::operator double() const
	{
		return Value;
	}
	
	Double::operator Object() const
	{
		return Object(Plugin::InternalUse::Only, Plugin::BoxDouble(Value));
	}
	
	Double::operator ValueType() const
	{
		return ValueType(Plugin::InternalUse::Only, Plugin::BoxDouble(Value));
	}
	
	Double::operator IComparable() const
	{
		return IComparable(Plugin::InternalUse::Only, Plugin::BoxDouble(Value));
	}
	
	Double::operator IFormattable() const
	{
		return IFormattable(Plugin::InternalUse::Only, Plugin::BoxDouble(Value));
	}
	
	Double::operator IConvertible() const
	{
		return IConvertible(Plugin::InternalUse::Only, Plugin::BoxDouble(Value));
	}
	
	Double::operator IComparable_1<Double>() const
	{
		return IComparable_1<Double>(Plugin::InternalUse::Only, Plugin::BoxDouble(Value));
	}
	
	Double::operator IEquatable_1<Double>() const
	{
		return IEquatable_1<Double>(Plugin::InternalUse::Only, Plugin::BoxDouble(Value));
	}
}

////////////////////////////////////////////////////////////////
// Support for using IEnumerable with range for loops
////////////////////////////////////////////////////////////////

namespace Plugin
{
	// End iterators are dummies full of null
	EnumerableIterator::EnumerableIterator(decltype(nullptr))
		: enumerator(nullptr)
		, hasMore(false)
	{
	}
	
	// Begin iterators keep track of an IEnumerator
	EnumerableIterator::EnumerableIterator(
		System::Collections::IEnumerable& enumerable)
		: enumerator(enumerable.GetEnumerator())
	{
		hasMore = enumerator.MoveNext();
	}
	
	EnumerableIterator& EnumerableIterator::operator++()
	{
		hasMore = enumerator.MoveNext();
		return *this;
	}
	
	bool EnumerableIterator::operator!=(const EnumerableIterator& other)
	{
		return hasMore;
	}
	
	System::Object EnumerableIterator::operator*()
	{
		return enumerator.GetCurrent();
	}
}

////////////////////////////////////////////////////////////////
// User-defined literals for creating decimals (System.Decimal)
////////////////////////////////////////////////////////////////

System::Decimal operator"" _m(long double x)
{
	return System::Decimal((System::Double)x);
}

System::Decimal operator"" _m(unsigned long long x)
{
	return System::Decimal((System::UInt64)x);
}

////////////////////////////////////////////////////////////////
// Reference counting of managed objects
////////////////////////////////////////////////////////////////

namespace Plugin
{
	int32_t RefCountsLenClass;
	int32_t* RefCountsClass;

	void ReferenceManagedClass(int32_t handle)
	{
		assert(handle >= 0 && handle < RefCountsLenClass);
		if (handle != 0)
		{
			RefCountsClass[handle]++;
		}
	}

	void DereferenceManagedClass(int32_t handle)
	{
		assert(handle >= 0 && handle < RefCountsLenClass);
		if (handle != 0)
		{
			int32_t numRemain = --RefCountsClass[handle];
			if (numRemain == 0)
			{
				ReleaseObject(handle);
			}
		}
	}
	
	bool DereferenceManagedClassNoRelease(int32_t handle)
	{
		assert(handle >= 0 && handle < RefCountsLenClass);
		if (handle != 0)
		{
			int32_t numRemain = --RefCountsClass[handle];
			if (numRemain == 0)
			{
				return true;
			}
		}
		return false;
	}
	
	/*BEGIN GLOBAL STATE AND FUNCTIONS*/
	int32_t RefCountsLenSystemDecimal;
	int32_t* RefCountsSystemDecimal;
	
	void ReferenceManagedSystemDecimal(int32_t handle)
	{
		assert(handle >= 0 && handle < RefCountsLenSystemDecimal);
		if (handle != 0)
		{
			RefCountsSystemDecimal[handle]++;
		}
	}
	
	void DereferenceManagedSystemDecimal(int32_t handle)
	{
		assert(handle >= 0 && handle < RefCountsLenSystemDecimal);
		if (handle != 0)
		{
			int32_t numRemain = --RefCountsSystemDecimal[handle];
			if (numRemain == 0)
			{
				ReleaseSystemDecimal(handle);
			}
		}
	}
	
	int32_t RefCountsLenUnityEngineBounds;
	int32_t* RefCountsUnityEngineBounds;
	
	void ReferenceManagedUnityEngineBounds(int32_t handle)
	{
		assert(handle >= 0 && handle < RefCountsLenUnityEngineBounds);
		if (handle != 0)
		{
			RefCountsUnityEngineBounds[handle]++;
		}
	}
	
	void DereferenceManagedUnityEngineBounds(int32_t handle)
	{
		assert(handle >= 0 && handle < RefCountsLenUnityEngineBounds);
		if (handle != 0)
		{
			int32_t numRemain = --RefCountsUnityEngineBounds[handle];
			if (numRemain == 0)
			{
				ReleaseUnityEngineBounds(handle);
			}
		}
	}
	
	// Free list for MyGame::BaseGameScript pointers
	
	int32_t BaseGameScriptFreeListSize;
	MyGame::BaseGameScript** BaseGameScriptFreeList;
	MyGame::BaseGameScript** NextFreeBaseGameScript;
	
	int32_t StoreBaseGameScript(MyGame::BaseGameScript* del)
	{
		assert(NextFreeBaseGameScript != nullptr);
		MyGame::BaseGameScript** pNext = NextFreeBaseGameScript;
		NextFreeBaseGameScript = (MyGame::BaseGameScript**)*pNext;
		*pNext = del;
		return (int32_t)(pNext - BaseGameScriptFreeList);
	}
	
	MyGame::BaseGameScript* GetBaseGameScript(int32_t handle)
	{
		assert(handle >= 0 && handle < BaseGameScriptFreeListSize);
		return BaseGameScriptFreeList[handle];
	}
	
	void RemoveBaseGameScript(int32_t handle)
	{
		MyGame::BaseGameScript** pRelease = BaseGameScriptFreeList + handle;
		*pRelease = (MyGame::BaseGameScript*)NextFreeBaseGameScript;
		NextFreeBaseGameScript = pRelease;
	}
	
	// Free list for whole MyGame::BaseGameScript objects
	
	union BaseGameScriptFreeWholeListEntry
	{
		BaseGameScriptFreeWholeListEntry* Next;
		MyGame::BaseGameScript Value;
	};
	int32_t BaseGameScriptFreeWholeListSize;
	BaseGameScriptFreeWholeListEntry* BaseGameScriptFreeWholeList;
	BaseGameScriptFreeWholeListEntry* NextFreeWholeBaseGameScript;
	
	MyGame::BaseGameScript* StoreWholeBaseGameScript()
	{
		assert(NextFreeWholeBaseGameScript != nullptr);
		BaseGameScriptFreeWholeListEntry* pNext = NextFreeWholeBaseGameScript;
		NextFreeWholeBaseGameScript = pNext->Next;
		return &pNext->Value;
	}
	
	void RemoveWholeBaseGameScript(MyGame::BaseGameScript* instance)
	{
		BaseGameScriptFreeWholeListEntry* pRelease = (BaseGameScriptFreeWholeListEntry*)instance;
		if (pRelease >= BaseGameScriptFreeWholeList && pRelease < BaseGameScriptFreeWholeList + (BaseGameScriptFreeWholeListSize - 1))
		{
			pRelease->Next = NextFreeWholeBaseGameScript;
			NextFreeWholeBaseGameScript = pRelease->Next;
		}
	}
	/*END GLOBAL STATE AND FUNCTIONS*/
}

namespace Plugin
{
	// An unhandled exception caused by C++ calling into C#
	System::Exception* unhandledCsharpException = nullptr;
}

////////////////////////////////////////////////////////////////
// Mirrors of C# types. These wrap the C# functions to present
// a similiar API as in C#.
////////////////////////////////////////////////////////////////

namespace System
{
	Object::Object()
		: Plugin::ManagedType(nullptr)
	{
	}
	
	Object::Object(Plugin::InternalUse iu, int32_t handle)
		: ManagedType(Plugin::InternalUse::Only, handle)
	{
	}
	
	Object::Object(decltype(nullptr))
		: ManagedType(nullptr)
	{
	}
	
	bool Object::operator==(decltype(nullptr)) const
	{
		return Handle == 0;
	}
	
	bool Object::operator!=(decltype(nullptr)) const
	{
		return Handle != 0;
	}
	
	void Object::ThrowReferenceToThis()
	{
		throw *this;
	}
	
	ValueType::ValueType(Plugin::InternalUse iu, int32_t handle)
		: Object(iu, handle)
	{
	}
	
	ValueType::ValueType(decltype(nullptr))
		: Object(nullptr)
	{
	}
	
	Enum::Enum(Plugin::InternalUse iu, int32_t handle)
		: ValueType(iu, handle)
	{
	}
	
	Enum::Enum(decltype(nullptr))
		: ValueType(nullptr)
	{
	}
	
	String::String(decltype(nullptr))
		: Object(Plugin::InternalUse::Only, 0)
	{
	}
	
	String::String(Plugin::InternalUse iu, int32_t handle)
		: Object(iu, handle)
	{
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	String::String(const String& other)
		: Object(Plugin::InternalUse::Only, other.Handle)
	{
		if (Handle)
		{
			Plugin::ReferenceManagedClass(Handle);
		}
	}
	
	String::String(String&& other)
		: Object(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	String::~String()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	String& String::operator=(const String& other)
	{
		if (Handle != other.Handle)
		{
			if (Handle)
			{
				Plugin::DereferenceManagedClass(Handle);
			}
			Handle = other.Handle;
			if (Handle)
			{
				Plugin::ReferenceManagedClass(Handle);
			}
		}
		return *this;
	}
	
	String& String::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	String& String::operator=(String&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	String::String(const char* chars)
		: Object(Plugin::InternalUse::Only, Plugin::StringNew(chars))
	{
		Plugin::ReferenceManagedClass(Handle);
	}
	
	ICloneable::ICloneable(Plugin::InternalUse iu, int32_t handle)
		: Object(iu, handle)
	{
	}
	
	ICloneable::ICloneable(decltype(nullptr))
		: Object(nullptr)
	{
	}
	
	namespace Collections
	{
		IEnumerable::IEnumerable(Plugin::InternalUse iu, int32_t handle)
			: Object(iu, handle)
		{
		}
		
		IEnumerable::IEnumerable(decltype(nullptr))
			: Object(nullptr)
		{
		}
		
		IEnumerator IEnumerable::GetEnumerator()
		{
			return IEnumerator(
				Plugin::InternalUse::Only,
				Plugin::EnumerableGetEnumerator(Handle));
		}
		
		Plugin::EnumerableIterator begin(
			System::Collections::IEnumerable& enumerable)
		{
			return Plugin::EnumerableIterator(enumerable);
		}
		
		Plugin::EnumerableIterator end(
			System::Collections::IEnumerable& enumerable)
		{
			return Plugin::EnumerableIterator(nullptr);
		}
		
		ICollection::ICollection(Plugin::InternalUse iu, int32_t handle)
			: Object(iu, handle)
			, IEnumerable(nullptr)
		{
		}
		
		ICollection::ICollection(decltype(nullptr))
			: Object(nullptr)
			, IEnumerable(nullptr)
		{
		}
		
		IList::IList(Plugin::InternalUse iu, int32_t handle)
			: Object(iu, handle)
			, IEnumerable(nullptr)
			, ICollection(nullptr)
		{
		}
		
		IList::IList(decltype(nullptr))
			: Object(nullptr)
			, IEnumerable(nullptr)
			, ICollection(nullptr)
		{
		}
	}
	
	Array::Array(Plugin::InternalUse iu, int32_t handle)
		: Object(iu, handle)
		, ICloneable(nullptr)
		, Collections::IEnumerable(nullptr)
		, Collections::ICollection(nullptr)
		, Collections::IList(nullptr)
	{
	}
	
	Array::Array(decltype(nullptr))
		: Object(nullptr)
		, ICloneable(nullptr)
		, Collections::IEnumerable(nullptr)
		, Collections::ICollection(nullptr)
		, Collections::IList(nullptr)
	{
	}
	
	int32_t Array::GetLength()
	{
		return Plugin::ArrayGetLength(Handle);
	}
	
	int32_t Array::GetRank()
	{
		return 0;
	}
}

/*BEGIN METHOD DEFINITIONS*/
namespace System
{
	IFormattable::IFormattable(decltype(nullptr))
	{
	}
	
	IFormattable::IFormattable(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IFormattable::IFormattable(const IFormattable& other)
		: IFormattable(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IFormattable::IFormattable(IFormattable&& other)
		: IFormattable(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IFormattable::~IFormattable()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IFormattable& IFormattable::operator=(const IFormattable& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IFormattable& IFormattable::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IFormattable& IFormattable::operator=(IFormattable&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IFormattable::operator==(const IFormattable& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IFormattable::operator!=(const IFormattable& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IConvertible::IConvertible(decltype(nullptr))
	{
	}
	
	IConvertible::IConvertible(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IConvertible::IConvertible(const IConvertible& other)
		: IConvertible(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IConvertible::IConvertible(IConvertible&& other)
		: IConvertible(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IConvertible::~IConvertible()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IConvertible& IConvertible::operator=(const IConvertible& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IConvertible& IConvertible::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IConvertible& IConvertible::operator=(IConvertible&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IConvertible::operator==(const IConvertible& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IConvertible::operator!=(const IConvertible& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IComparable::IComparable(decltype(nullptr))
	{
	}
	
	IComparable::IComparable(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IComparable::IComparable(const IComparable& other)
		: IComparable(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IComparable::IComparable(IComparable&& other)
		: IComparable(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IComparable::~IComparable()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IComparable& IComparable::operator=(const IComparable& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IComparable& IComparable::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IComparable& IComparable::operator=(IComparable&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IComparable::operator==(const IComparable& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IComparable::operator!=(const IComparable& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IEquatable_1<System::Boolean>::IEquatable_1(decltype(nullptr))
	{
	}
	
	IEquatable_1<System::Boolean>::IEquatable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IEquatable_1<System::Boolean>::IEquatable_1(const IEquatable_1<System::Boolean>& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IEquatable_1<System::Boolean>::IEquatable_1(IEquatable_1<System::Boolean>&& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IEquatable_1<System::Boolean>::~IEquatable_1<System::Boolean>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IEquatable_1<System::Boolean>& IEquatable_1<System::Boolean>::operator=(const IEquatable_1<System::Boolean>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IEquatable_1<System::Boolean>& IEquatable_1<System::Boolean>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IEquatable_1<System::Boolean>& IEquatable_1<System::Boolean>::operator=(IEquatable_1<System::Boolean>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IEquatable_1<System::Boolean>::operator==(const IEquatable_1<System::Boolean>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IEquatable_1<System::Boolean>::operator!=(const IEquatable_1<System::Boolean>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IEquatable_1<System::Char>::IEquatable_1(decltype(nullptr))
	{
	}
	
	IEquatable_1<System::Char>::IEquatable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IEquatable_1<System::Char>::IEquatable_1(const IEquatable_1<System::Char>& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IEquatable_1<System::Char>::IEquatable_1(IEquatable_1<System::Char>&& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IEquatable_1<System::Char>::~IEquatable_1<System::Char>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IEquatable_1<System::Char>& IEquatable_1<System::Char>::operator=(const IEquatable_1<System::Char>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IEquatable_1<System::Char>& IEquatable_1<System::Char>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IEquatable_1<System::Char>& IEquatable_1<System::Char>::operator=(IEquatable_1<System::Char>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IEquatable_1<System::Char>::operator==(const IEquatable_1<System::Char>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IEquatable_1<System::Char>::operator!=(const IEquatable_1<System::Char>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IEquatable_1<System::SByte>::IEquatable_1(decltype(nullptr))
	{
	}
	
	IEquatable_1<System::SByte>::IEquatable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IEquatable_1<System::SByte>::IEquatable_1(const IEquatable_1<System::SByte>& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IEquatable_1<System::SByte>::IEquatable_1(IEquatable_1<System::SByte>&& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IEquatable_1<System::SByte>::~IEquatable_1<System::SByte>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IEquatable_1<System::SByte>& IEquatable_1<System::SByte>::operator=(const IEquatable_1<System::SByte>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IEquatable_1<System::SByte>& IEquatable_1<System::SByte>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IEquatable_1<System::SByte>& IEquatable_1<System::SByte>::operator=(IEquatable_1<System::SByte>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IEquatable_1<System::SByte>::operator==(const IEquatable_1<System::SByte>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IEquatable_1<System::SByte>::operator!=(const IEquatable_1<System::SByte>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IEquatable_1<System::Byte>::IEquatable_1(decltype(nullptr))
	{
	}
	
	IEquatable_1<System::Byte>::IEquatable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IEquatable_1<System::Byte>::IEquatable_1(const IEquatable_1<System::Byte>& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IEquatable_1<System::Byte>::IEquatable_1(IEquatable_1<System::Byte>&& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IEquatable_1<System::Byte>::~IEquatable_1<System::Byte>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IEquatable_1<System::Byte>& IEquatable_1<System::Byte>::operator=(const IEquatable_1<System::Byte>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IEquatable_1<System::Byte>& IEquatable_1<System::Byte>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IEquatable_1<System::Byte>& IEquatable_1<System::Byte>::operator=(IEquatable_1<System::Byte>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IEquatable_1<System::Byte>::operator==(const IEquatable_1<System::Byte>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IEquatable_1<System::Byte>::operator!=(const IEquatable_1<System::Byte>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IEquatable_1<System::Int16>::IEquatable_1(decltype(nullptr))
	{
	}
	
	IEquatable_1<System::Int16>::IEquatable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IEquatable_1<System::Int16>::IEquatable_1(const IEquatable_1<System::Int16>& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IEquatable_1<System::Int16>::IEquatable_1(IEquatable_1<System::Int16>&& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IEquatable_1<System::Int16>::~IEquatable_1<System::Int16>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IEquatable_1<System::Int16>& IEquatable_1<System::Int16>::operator=(const IEquatable_1<System::Int16>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IEquatable_1<System::Int16>& IEquatable_1<System::Int16>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IEquatable_1<System::Int16>& IEquatable_1<System::Int16>::operator=(IEquatable_1<System::Int16>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IEquatable_1<System::Int16>::operator==(const IEquatable_1<System::Int16>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IEquatable_1<System::Int16>::operator!=(const IEquatable_1<System::Int16>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IEquatable_1<System::UInt16>::IEquatable_1(decltype(nullptr))
	{
	}
	
	IEquatable_1<System::UInt16>::IEquatable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IEquatable_1<System::UInt16>::IEquatable_1(const IEquatable_1<System::UInt16>& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IEquatable_1<System::UInt16>::IEquatable_1(IEquatable_1<System::UInt16>&& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IEquatable_1<System::UInt16>::~IEquatable_1<System::UInt16>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IEquatable_1<System::UInt16>& IEquatable_1<System::UInt16>::operator=(const IEquatable_1<System::UInt16>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IEquatable_1<System::UInt16>& IEquatable_1<System::UInt16>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IEquatable_1<System::UInt16>& IEquatable_1<System::UInt16>::operator=(IEquatable_1<System::UInt16>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IEquatable_1<System::UInt16>::operator==(const IEquatable_1<System::UInt16>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IEquatable_1<System::UInt16>::operator!=(const IEquatable_1<System::UInt16>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IEquatable_1<System::Int32>::IEquatable_1(decltype(nullptr))
	{
	}
	
	IEquatable_1<System::Int32>::IEquatable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IEquatable_1<System::Int32>::IEquatable_1(const IEquatable_1<System::Int32>& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IEquatable_1<System::Int32>::IEquatable_1(IEquatable_1<System::Int32>&& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IEquatable_1<System::Int32>::~IEquatable_1<System::Int32>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IEquatable_1<System::Int32>& IEquatable_1<System::Int32>::operator=(const IEquatable_1<System::Int32>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IEquatable_1<System::Int32>& IEquatable_1<System::Int32>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IEquatable_1<System::Int32>& IEquatable_1<System::Int32>::operator=(IEquatable_1<System::Int32>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IEquatable_1<System::Int32>::operator==(const IEquatable_1<System::Int32>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IEquatable_1<System::Int32>::operator!=(const IEquatable_1<System::Int32>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IEquatable_1<System::UInt32>::IEquatable_1(decltype(nullptr))
	{
	}
	
	IEquatable_1<System::UInt32>::IEquatable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IEquatable_1<System::UInt32>::IEquatable_1(const IEquatable_1<System::UInt32>& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IEquatable_1<System::UInt32>::IEquatable_1(IEquatable_1<System::UInt32>&& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IEquatable_1<System::UInt32>::~IEquatable_1<System::UInt32>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IEquatable_1<System::UInt32>& IEquatable_1<System::UInt32>::operator=(const IEquatable_1<System::UInt32>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IEquatable_1<System::UInt32>& IEquatable_1<System::UInt32>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IEquatable_1<System::UInt32>& IEquatable_1<System::UInt32>::operator=(IEquatable_1<System::UInt32>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IEquatable_1<System::UInt32>::operator==(const IEquatable_1<System::UInt32>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IEquatable_1<System::UInt32>::operator!=(const IEquatable_1<System::UInt32>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IEquatable_1<System::Int64>::IEquatable_1(decltype(nullptr))
	{
	}
	
	IEquatable_1<System::Int64>::IEquatable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IEquatable_1<System::Int64>::IEquatable_1(const IEquatable_1<System::Int64>& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IEquatable_1<System::Int64>::IEquatable_1(IEquatable_1<System::Int64>&& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IEquatable_1<System::Int64>::~IEquatable_1<System::Int64>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IEquatable_1<System::Int64>& IEquatable_1<System::Int64>::operator=(const IEquatable_1<System::Int64>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IEquatable_1<System::Int64>& IEquatable_1<System::Int64>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IEquatable_1<System::Int64>& IEquatable_1<System::Int64>::operator=(IEquatable_1<System::Int64>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IEquatable_1<System::Int64>::operator==(const IEquatable_1<System::Int64>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IEquatable_1<System::Int64>::operator!=(const IEquatable_1<System::Int64>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IEquatable_1<System::UInt64>::IEquatable_1(decltype(nullptr))
	{
	}
	
	IEquatable_1<System::UInt64>::IEquatable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IEquatable_1<System::UInt64>::IEquatable_1(const IEquatable_1<System::UInt64>& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IEquatable_1<System::UInt64>::IEquatable_1(IEquatable_1<System::UInt64>&& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IEquatable_1<System::UInt64>::~IEquatable_1<System::UInt64>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IEquatable_1<System::UInt64>& IEquatable_1<System::UInt64>::operator=(const IEquatable_1<System::UInt64>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IEquatable_1<System::UInt64>& IEquatable_1<System::UInt64>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IEquatable_1<System::UInt64>& IEquatable_1<System::UInt64>::operator=(IEquatable_1<System::UInt64>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IEquatable_1<System::UInt64>::operator==(const IEquatable_1<System::UInt64>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IEquatable_1<System::UInt64>::operator!=(const IEquatable_1<System::UInt64>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IEquatable_1<System::Single>::IEquatable_1(decltype(nullptr))
	{
	}
	
	IEquatable_1<System::Single>::IEquatable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IEquatable_1<System::Single>::IEquatable_1(const IEquatable_1<System::Single>& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IEquatable_1<System::Single>::IEquatable_1(IEquatable_1<System::Single>&& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IEquatable_1<System::Single>::~IEquatable_1<System::Single>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IEquatable_1<System::Single>& IEquatable_1<System::Single>::operator=(const IEquatable_1<System::Single>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IEquatable_1<System::Single>& IEquatable_1<System::Single>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IEquatable_1<System::Single>& IEquatable_1<System::Single>::operator=(IEquatable_1<System::Single>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IEquatable_1<System::Single>::operator==(const IEquatable_1<System::Single>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IEquatable_1<System::Single>::operator!=(const IEquatable_1<System::Single>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IEquatable_1<System::Double>::IEquatable_1(decltype(nullptr))
	{
	}
	
	IEquatable_1<System::Double>::IEquatable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IEquatable_1<System::Double>::IEquatable_1(const IEquatable_1<System::Double>& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IEquatable_1<System::Double>::IEquatable_1(IEquatable_1<System::Double>&& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IEquatable_1<System::Double>::~IEquatable_1<System::Double>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IEquatable_1<System::Double>& IEquatable_1<System::Double>::operator=(const IEquatable_1<System::Double>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IEquatable_1<System::Double>& IEquatable_1<System::Double>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IEquatable_1<System::Double>& IEquatable_1<System::Double>::operator=(IEquatable_1<System::Double>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IEquatable_1<System::Double>::operator==(const IEquatable_1<System::Double>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IEquatable_1<System::Double>::operator!=(const IEquatable_1<System::Double>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IEquatable_1<System::Decimal>::IEquatable_1(decltype(nullptr))
	{
	}
	
	IEquatable_1<System::Decimal>::IEquatable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IEquatable_1<System::Decimal>::IEquatable_1(const IEquatable_1<System::Decimal>& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IEquatable_1<System::Decimal>::IEquatable_1(IEquatable_1<System::Decimal>&& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IEquatable_1<System::Decimal>::~IEquatable_1<System::Decimal>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IEquatable_1<System::Decimal>& IEquatable_1<System::Decimal>::operator=(const IEquatable_1<System::Decimal>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IEquatable_1<System::Decimal>& IEquatable_1<System::Decimal>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IEquatable_1<System::Decimal>& IEquatable_1<System::Decimal>::operator=(IEquatable_1<System::Decimal>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IEquatable_1<System::Decimal>::operator==(const IEquatable_1<System::Decimal>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IEquatable_1<System::Decimal>::operator!=(const IEquatable_1<System::Decimal>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IEquatable_1<UnityEngine::Vector3>::IEquatable_1(decltype(nullptr))
	{
	}
	
	IEquatable_1<UnityEngine::Vector3>::IEquatable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IEquatable_1<UnityEngine::Vector3>::IEquatable_1(const IEquatable_1<UnityEngine::Vector3>& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IEquatable_1<UnityEngine::Vector3>::IEquatable_1(IEquatable_1<UnityEngine::Vector3>&& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IEquatable_1<UnityEngine::Vector3>::~IEquatable_1<UnityEngine::Vector3>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IEquatable_1<UnityEngine::Vector3>& IEquatable_1<UnityEngine::Vector3>::operator=(const IEquatable_1<UnityEngine::Vector3>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IEquatable_1<UnityEngine::Vector3>& IEquatable_1<UnityEngine::Vector3>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IEquatable_1<UnityEngine::Vector3>& IEquatable_1<UnityEngine::Vector3>::operator=(IEquatable_1<UnityEngine::Vector3>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IEquatable_1<UnityEngine::Vector3>::operator==(const IEquatable_1<UnityEngine::Vector3>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IEquatable_1<UnityEngine::Vector3>::operator!=(const IEquatable_1<UnityEngine::Vector3>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IComparable_1<System::Boolean>::IComparable_1(decltype(nullptr))
	{
	}
	
	IComparable_1<System::Boolean>::IComparable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IComparable_1<System::Boolean>::IComparable_1(const IComparable_1<System::Boolean>& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IComparable_1<System::Boolean>::IComparable_1(IComparable_1<System::Boolean>&& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IComparable_1<System::Boolean>::~IComparable_1<System::Boolean>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IComparable_1<System::Boolean>& IComparable_1<System::Boolean>::operator=(const IComparable_1<System::Boolean>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IComparable_1<System::Boolean>& IComparable_1<System::Boolean>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IComparable_1<System::Boolean>& IComparable_1<System::Boolean>::operator=(IComparable_1<System::Boolean>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IComparable_1<System::Boolean>::operator==(const IComparable_1<System::Boolean>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IComparable_1<System::Boolean>::operator!=(const IComparable_1<System::Boolean>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IComparable_1<System::Char>::IComparable_1(decltype(nullptr))
	{
	}
	
	IComparable_1<System::Char>::IComparable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IComparable_1<System::Char>::IComparable_1(const IComparable_1<System::Char>& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IComparable_1<System::Char>::IComparable_1(IComparable_1<System::Char>&& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IComparable_1<System::Char>::~IComparable_1<System::Char>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IComparable_1<System::Char>& IComparable_1<System::Char>::operator=(const IComparable_1<System::Char>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IComparable_1<System::Char>& IComparable_1<System::Char>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IComparable_1<System::Char>& IComparable_1<System::Char>::operator=(IComparable_1<System::Char>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IComparable_1<System::Char>::operator==(const IComparable_1<System::Char>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IComparable_1<System::Char>::operator!=(const IComparable_1<System::Char>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IComparable_1<System::SByte>::IComparable_1(decltype(nullptr))
	{
	}
	
	IComparable_1<System::SByte>::IComparable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IComparable_1<System::SByte>::IComparable_1(const IComparable_1<System::SByte>& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IComparable_1<System::SByte>::IComparable_1(IComparable_1<System::SByte>&& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IComparable_1<System::SByte>::~IComparable_1<System::SByte>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IComparable_1<System::SByte>& IComparable_1<System::SByte>::operator=(const IComparable_1<System::SByte>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IComparable_1<System::SByte>& IComparable_1<System::SByte>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IComparable_1<System::SByte>& IComparable_1<System::SByte>::operator=(IComparable_1<System::SByte>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IComparable_1<System::SByte>::operator==(const IComparable_1<System::SByte>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IComparable_1<System::SByte>::operator!=(const IComparable_1<System::SByte>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IComparable_1<System::Byte>::IComparable_1(decltype(nullptr))
	{
	}
	
	IComparable_1<System::Byte>::IComparable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IComparable_1<System::Byte>::IComparable_1(const IComparable_1<System::Byte>& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IComparable_1<System::Byte>::IComparable_1(IComparable_1<System::Byte>&& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IComparable_1<System::Byte>::~IComparable_1<System::Byte>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IComparable_1<System::Byte>& IComparable_1<System::Byte>::operator=(const IComparable_1<System::Byte>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IComparable_1<System::Byte>& IComparable_1<System::Byte>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IComparable_1<System::Byte>& IComparable_1<System::Byte>::operator=(IComparable_1<System::Byte>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IComparable_1<System::Byte>::operator==(const IComparable_1<System::Byte>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IComparable_1<System::Byte>::operator!=(const IComparable_1<System::Byte>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IComparable_1<System::Int16>::IComparable_1(decltype(nullptr))
	{
	}
	
	IComparable_1<System::Int16>::IComparable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IComparable_1<System::Int16>::IComparable_1(const IComparable_1<System::Int16>& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IComparable_1<System::Int16>::IComparable_1(IComparable_1<System::Int16>&& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IComparable_1<System::Int16>::~IComparable_1<System::Int16>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IComparable_1<System::Int16>& IComparable_1<System::Int16>::operator=(const IComparable_1<System::Int16>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IComparable_1<System::Int16>& IComparable_1<System::Int16>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IComparable_1<System::Int16>& IComparable_1<System::Int16>::operator=(IComparable_1<System::Int16>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IComparable_1<System::Int16>::operator==(const IComparable_1<System::Int16>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IComparable_1<System::Int16>::operator!=(const IComparable_1<System::Int16>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IComparable_1<System::UInt16>::IComparable_1(decltype(nullptr))
	{
	}
	
	IComparable_1<System::UInt16>::IComparable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IComparable_1<System::UInt16>::IComparable_1(const IComparable_1<System::UInt16>& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IComparable_1<System::UInt16>::IComparable_1(IComparable_1<System::UInt16>&& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IComparable_1<System::UInt16>::~IComparable_1<System::UInt16>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IComparable_1<System::UInt16>& IComparable_1<System::UInt16>::operator=(const IComparable_1<System::UInt16>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IComparable_1<System::UInt16>& IComparable_1<System::UInt16>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IComparable_1<System::UInt16>& IComparable_1<System::UInt16>::operator=(IComparable_1<System::UInt16>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IComparable_1<System::UInt16>::operator==(const IComparable_1<System::UInt16>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IComparable_1<System::UInt16>::operator!=(const IComparable_1<System::UInt16>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IComparable_1<System::Int32>::IComparable_1(decltype(nullptr))
	{
	}
	
	IComparable_1<System::Int32>::IComparable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IComparable_1<System::Int32>::IComparable_1(const IComparable_1<System::Int32>& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IComparable_1<System::Int32>::IComparable_1(IComparable_1<System::Int32>&& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IComparable_1<System::Int32>::~IComparable_1<System::Int32>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IComparable_1<System::Int32>& IComparable_1<System::Int32>::operator=(const IComparable_1<System::Int32>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IComparable_1<System::Int32>& IComparable_1<System::Int32>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IComparable_1<System::Int32>& IComparable_1<System::Int32>::operator=(IComparable_1<System::Int32>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IComparable_1<System::Int32>::operator==(const IComparable_1<System::Int32>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IComparable_1<System::Int32>::operator!=(const IComparable_1<System::Int32>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IComparable_1<System::UInt32>::IComparable_1(decltype(nullptr))
	{
	}
	
	IComparable_1<System::UInt32>::IComparable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IComparable_1<System::UInt32>::IComparable_1(const IComparable_1<System::UInt32>& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IComparable_1<System::UInt32>::IComparable_1(IComparable_1<System::UInt32>&& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IComparable_1<System::UInt32>::~IComparable_1<System::UInt32>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IComparable_1<System::UInt32>& IComparable_1<System::UInt32>::operator=(const IComparable_1<System::UInt32>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IComparable_1<System::UInt32>& IComparable_1<System::UInt32>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IComparable_1<System::UInt32>& IComparable_1<System::UInt32>::operator=(IComparable_1<System::UInt32>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IComparable_1<System::UInt32>::operator==(const IComparable_1<System::UInt32>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IComparable_1<System::UInt32>::operator!=(const IComparable_1<System::UInt32>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IComparable_1<System::Int64>::IComparable_1(decltype(nullptr))
	{
	}
	
	IComparable_1<System::Int64>::IComparable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IComparable_1<System::Int64>::IComparable_1(const IComparable_1<System::Int64>& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IComparable_1<System::Int64>::IComparable_1(IComparable_1<System::Int64>&& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IComparable_1<System::Int64>::~IComparable_1<System::Int64>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IComparable_1<System::Int64>& IComparable_1<System::Int64>::operator=(const IComparable_1<System::Int64>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IComparable_1<System::Int64>& IComparable_1<System::Int64>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IComparable_1<System::Int64>& IComparable_1<System::Int64>::operator=(IComparable_1<System::Int64>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IComparable_1<System::Int64>::operator==(const IComparable_1<System::Int64>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IComparable_1<System::Int64>::operator!=(const IComparable_1<System::Int64>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IComparable_1<System::UInt64>::IComparable_1(decltype(nullptr))
	{
	}
	
	IComparable_1<System::UInt64>::IComparable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IComparable_1<System::UInt64>::IComparable_1(const IComparable_1<System::UInt64>& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IComparable_1<System::UInt64>::IComparable_1(IComparable_1<System::UInt64>&& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IComparable_1<System::UInt64>::~IComparable_1<System::UInt64>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IComparable_1<System::UInt64>& IComparable_1<System::UInt64>::operator=(const IComparable_1<System::UInt64>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IComparable_1<System::UInt64>& IComparable_1<System::UInt64>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IComparable_1<System::UInt64>& IComparable_1<System::UInt64>::operator=(IComparable_1<System::UInt64>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IComparable_1<System::UInt64>::operator==(const IComparable_1<System::UInt64>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IComparable_1<System::UInt64>::operator!=(const IComparable_1<System::UInt64>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IComparable_1<System::Single>::IComparable_1(decltype(nullptr))
	{
	}
	
	IComparable_1<System::Single>::IComparable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IComparable_1<System::Single>::IComparable_1(const IComparable_1<System::Single>& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IComparable_1<System::Single>::IComparable_1(IComparable_1<System::Single>&& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IComparable_1<System::Single>::~IComparable_1<System::Single>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IComparable_1<System::Single>& IComparable_1<System::Single>::operator=(const IComparable_1<System::Single>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IComparable_1<System::Single>& IComparable_1<System::Single>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IComparable_1<System::Single>& IComparable_1<System::Single>::operator=(IComparable_1<System::Single>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IComparable_1<System::Single>::operator==(const IComparable_1<System::Single>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IComparable_1<System::Single>::operator!=(const IComparable_1<System::Single>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IComparable_1<System::Double>::IComparable_1(decltype(nullptr))
	{
	}
	
	IComparable_1<System::Double>::IComparable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IComparable_1<System::Double>::IComparable_1(const IComparable_1<System::Double>& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IComparable_1<System::Double>::IComparable_1(IComparable_1<System::Double>&& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IComparable_1<System::Double>::~IComparable_1<System::Double>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IComparable_1<System::Double>& IComparable_1<System::Double>::operator=(const IComparable_1<System::Double>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IComparable_1<System::Double>& IComparable_1<System::Double>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IComparable_1<System::Double>& IComparable_1<System::Double>::operator=(IComparable_1<System::Double>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IComparable_1<System::Double>::operator==(const IComparable_1<System::Double>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IComparable_1<System::Double>::operator!=(const IComparable_1<System::Double>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IComparable_1<System::Decimal>::IComparable_1(decltype(nullptr))
	{
	}
	
	IComparable_1<System::Decimal>::IComparable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IComparable_1<System::Decimal>::IComparable_1(const IComparable_1<System::Decimal>& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IComparable_1<System::Decimal>::IComparable_1(IComparable_1<System::Decimal>&& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IComparable_1<System::Decimal>::~IComparable_1<System::Decimal>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IComparable_1<System::Decimal>& IComparable_1<System::Decimal>::operator=(const IComparable_1<System::Decimal>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IComparable_1<System::Decimal>& IComparable_1<System::Decimal>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IComparable_1<System::Decimal>& IComparable_1<System::Decimal>::operator=(IComparable_1<System::Decimal>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IComparable_1<System::Decimal>::operator==(const IComparable_1<System::Decimal>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IComparable_1<System::Decimal>::operator!=(const IComparable_1<System::Decimal>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	Decimal::Decimal(decltype(nullptr))
	{
	}
	
	Decimal::Decimal(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedSystemDecimal(Handle);
		}
	}
	
	Decimal::Decimal(const Decimal& other)
		: Decimal(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	Decimal::Decimal(Decimal&& other)
		: Decimal(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	Decimal::~Decimal()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedSystemDecimal(Handle);
			Handle = 0;
		}
	}
	
	Decimal& Decimal::operator=(const Decimal& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedSystemDecimal(Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedSystemDecimal(Handle);
		}
		return *this;
	}
	
	Decimal& Decimal::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedSystemDecimal(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	Decimal& Decimal::operator=(Decimal&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedSystemDecimal(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool Decimal::operator==(const Decimal& other) const
	{
		return Handle == other.Handle;
	}
	
	bool Decimal::operator!=(const Decimal& other) const
	{
		return Handle != other.Handle;
	}
	
	System::Decimal::Decimal(System::Double value)
	{
		auto returnValue = Plugin::SystemDecimalConstructorSystemDouble(value);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		Handle = returnValue;
		if (returnValue)
		{
			Plugin::ReferenceManagedSystemDecimal(Handle);
		}
	}
	
	System::Decimal::Decimal(System::UInt64 value)
	{
		auto returnValue = Plugin::SystemDecimalConstructorSystemUInt64(value);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		Handle = returnValue;
		if (returnValue)
		{
			Plugin::ReferenceManagedSystemDecimal(Handle);
		}
	}
	
	System::Decimal::operator System::ValueType()
	{
		int32_t handle = Plugin::BoxDecimal(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
			return System::ValueType(Plugin::InternalUse::Only, handle);
		}
		return nullptr;
	}
	
	System::Decimal::operator System::Object()
	{
		int32_t handle = Plugin::BoxDecimal(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
			return System::Object(Plugin::InternalUse::Only, handle);
		}
		return nullptr;
	}
	
	System::Decimal::operator System::IFormattable()
	{
		int32_t handle = Plugin::BoxDecimal(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
			return System::IFormattable(Plugin::InternalUse::Only, handle);
		}
		return nullptr;
	}
	
	System::Decimal::operator System::IConvertible()
	{
		int32_t handle = Plugin::BoxDecimal(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
			return System::IConvertible(Plugin::InternalUse::Only, handle);
		}
		return nullptr;
	}
	
	System::Decimal::operator System::IComparable()
	{
		int32_t handle = Plugin::BoxDecimal(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
			return System::IComparable(Plugin::InternalUse::Only, handle);
		}
		return nullptr;
	}
	
	System::Decimal::operator System::IComparable_1<System::Decimal>()
	{
		int32_t handle = Plugin::BoxDecimal(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
			return System::IComparable_1<System::Decimal>(Plugin::InternalUse::Only, handle);
		}
		return nullptr;
	}
	
	System::Decimal::operator System::IEquatable_1<System::Decimal>()
	{
		int32_t handle = Plugin::BoxDecimal(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
			return System::IEquatable_1<System::Decimal>(Plugin::InternalUse::Only, handle);
		}
		return nullptr;
	}
}

namespace System
{
	System::Object::operator System::Decimal()
	{
		System::Decimal returnVal(Plugin::InternalUse::Only, Plugin::UnboxDecimal(Handle));
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnVal;
	}
}

namespace UnityEngine
{
	Vector3::Vector3()
	{
	}
	
	UnityEngine::Vector3::Vector3(System::Single x, System::Single y, System::Single z)
	{
		auto returnValue = Plugin::UnityEngineVector3ConstructorSystemSingle_SystemSingle_SystemSingle(x, y, z);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		*this = returnValue;
	}
	
	System::Single UnityEngine::Vector3::GetMagnitude()
	{
		auto returnValue = Plugin::UnityEngineVector3PropertyGetMagnitude(this);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnValue;
	}
	
	UnityEngine::Vector3 UnityEngine::Vector3::operator+(UnityEngine::Vector3& a)
	{
		auto returnValue = Plugin::UnityEngineVector3Methodop_AdditionUnityEngineVector3_UnityEngineVector3(*this, a);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnValue;
	}
	
	UnityEngine::Vector3 UnityEngine::Vector3::operator-(UnityEngine::Vector3& a)
	{
		auto returnValue = Plugin::UnityEngineVector3Methodop_SubtractionUnityEngineVector3_UnityEngineVector3(*this, a);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnValue;
	}
	
	UnityEngine::Vector3 UnityEngine::Vector3::Normalize(UnityEngine::Vector3& value)
	{
		auto returnValue = Plugin::UnityEngineVector3MethodNormalizeUnityEngineVector3(value);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnValue;
	}
	
	System::Single UnityEngine::Vector3::Dot(UnityEngine::Vector3& lhs, UnityEngine::Vector3& rhs)
	{
		auto returnValue = Plugin::UnityEngineVector3MethodDotUnityEngineVector3_UnityEngineVector3(lhs, rhs);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnValue;
	}
	
	UnityEngine::Vector3 UnityEngine::Vector3::Cross(UnityEngine::Vector3& lhs, UnityEngine::Vector3& rhs)
	{
		auto returnValue = Plugin::UnityEngineVector3MethodCrossUnityEngineVector3_UnityEngineVector3(lhs, rhs);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnValue;
	}
	
	System::Single UnityEngine::Vector3::Distance(UnityEngine::Vector3& a, UnityEngine::Vector3& b)
	{
		auto returnValue = Plugin::UnityEngineVector3MethodDistanceUnityEngineVector3_UnityEngineVector3(a, b);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnValue;
	}
	
	UnityEngine::Vector3::operator System::ValueType()
	{
		int32_t handle = Plugin::BoxVector3(*this);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
			return System::ValueType(Plugin::InternalUse::Only, handle);
		}
		return nullptr;
	}
	
	UnityEngine::Vector3::operator System::Object()
	{
		int32_t handle = Plugin::BoxVector3(*this);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
			return System::Object(Plugin::InternalUse::Only, handle);
		}
		return nullptr;
	}
}

namespace System
{
	System::Object::operator UnityEngine::Vector3()
	{
		UnityEngine::Vector3 returnVal(Plugin::UnboxVector3(Handle));
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnVal;
	}
}

namespace UnityEngine
{
	Object::Object(decltype(nullptr))
	{
	}
	
	Object::Object(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	Object::Object(const Object& other)
		: Object(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	Object::Object(Object&& other)
		: Object(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	Object::~Object()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	Object& Object::operator=(const Object& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	Object& Object::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	Object& Object::operator=(Object&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool Object::operator==(const Object& other) const
	{
		return Handle == other.Handle;
	}
	
	bool Object::operator!=(const Object& other) const
	{
		return Handle != other.Handle;
	}
	
	System::String UnityEngine::Object::GetName()
	{
		auto returnValue = Plugin::UnityEngineObjectPropertyGetName(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return System::String(Plugin::InternalUse::Only, returnValue);
	}
	
	void UnityEngine::Object::SetName(System::String& value)
	{
		Plugin::UnityEngineObjectPropertySetName(Handle, value.Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
	}
	
	void UnityEngine::Object::Destroy(UnityEngine::Object& obj)
	{
		Plugin::UnityEngineObjectMethodDestroyUnityEngineObject(obj.Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
	}
}

namespace UnityEngine
{
	Component::Component(decltype(nullptr))
		: UnityEngine::Object(nullptr)
	{
	}
	
	Component::Component(Plugin::InternalUse, int32_t handle)
		: UnityEngine::Object(nullptr)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	Component::Component(const Component& other)
		: Component(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	Component::Component(Component&& other)
		: Component(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	Component::~Component()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	Component& Component::operator=(const Component& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	Component& Component::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	Component& Component::operator=(Component&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool Component::operator==(const Component& other) const
	{
		return Handle == other.Handle;
	}
	
	bool Component::operator!=(const Component& other) const
	{
		return Handle != other.Handle;
	}
	
	UnityEngine::Transform UnityEngine::Component::GetTransform()
	{
		auto returnValue = Plugin::UnityEngineComponentPropertyGetTransform(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return UnityEngine::Transform(Plugin::InternalUse::Only, returnValue);
	}
	
	UnityEngine::GameObject UnityEngine::Component::GetGameObject()
	{
		auto returnValue = Plugin::UnityEngineComponentPropertyGetGameObject(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return UnityEngine::GameObject(Plugin::InternalUse::Only, returnValue);
	}
}

namespace UnityEngine
{
	Transform::Transform(decltype(nullptr))
		: UnityEngine::Object(nullptr)
		, UnityEngine::Component(nullptr)
		, System::Collections::IEnumerable(nullptr)
	{
	}
	
	Transform::Transform(Plugin::InternalUse, int32_t handle)
		: UnityEngine::Object(nullptr)
		, UnityEngine::Component(nullptr)
		, System::Collections::IEnumerable(nullptr)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	Transform::Transform(const Transform& other)
		: Transform(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	Transform::Transform(Transform&& other)
		: Transform(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	Transform::~Transform()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	Transform& Transform::operator=(const Transform& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	Transform& Transform::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	Transform& Transform::operator=(Transform&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool Transform::operator==(const Transform& other) const
	{
		return Handle == other.Handle;
	}
	
	bool Transform::operator!=(const Transform& other) const
	{
		return Handle != other.Handle;
	}
	
	UnityEngine::Vector3 UnityEngine::Transform::GetPosition()
	{
		auto returnValue = Plugin::UnityEngineTransformPropertyGetPosition(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnValue;
	}
	
	void UnityEngine::Transform::SetPosition(UnityEngine::Vector3& value)
	{
		Plugin::UnityEngineTransformPropertySetPosition(Handle, value);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
	}
}

namespace System
{
	namespace Collections
	{
		IEnumerator::IEnumerator(decltype(nullptr))
		{
		}
		
		IEnumerator::IEnumerator(Plugin::InternalUse, int32_t handle)
		{
			Handle = handle;
			if (handle)
			{
				Plugin::ReferenceManagedClass(handle);
			}
		}
		
		IEnumerator::IEnumerator(const IEnumerator& other)
			: IEnumerator(Plugin::InternalUse::Only, other.Handle)
		{
		}
		
		IEnumerator::IEnumerator(IEnumerator&& other)
			: IEnumerator(Plugin::InternalUse::Only, other.Handle)
		{
			other.Handle = 0;
		}
		
		IEnumerator::~IEnumerator()
		{
			if (Handle)
			{
				Plugin::DereferenceManagedClass(Handle);
				Handle = 0;
			}
		}
		
		IEnumerator& IEnumerator::operator=(const IEnumerator& other)
		{
			if (this->Handle)
			{
				Plugin::DereferenceManagedClass(this->Handle);
			}
			this->Handle = other.Handle;
			if (this->Handle)
			{
				Plugin::ReferenceManagedClass(this->Handle);
			}
			return *this;
		}
		
		IEnumerator& IEnumerator::operator=(decltype(nullptr))
		{
			if (Handle)
			{
				Plugin::DereferenceManagedClass(Handle);
				Handle = 0;
			}
			return *this;
		}
		
		IEnumerator& IEnumerator::operator=(IEnumerator&& other)
		{
			if (Handle)
			{
				Plugin::DereferenceManagedClass(Handle);
			}
			Handle = other.Handle;
			other.Handle = 0;
			return *this;
		}
		
		bool IEnumerator::operator==(const IEnumerator& other) const
		{
			return Handle == other.Handle;
		}
		
		bool IEnumerator::operator!=(const IEnumerator& other) const
		{
			return Handle != other.Handle;
		}
		
		System::Object System::Collections::IEnumerator::GetCurrent()
		{
			auto returnValue = Plugin::SystemCollectionsIEnumeratorPropertyGetCurrent(Handle);
			if (Plugin::unhandledCsharpException)
			{
				System::Exception* ex = Plugin::unhandledCsharpException;
				Plugin::unhandledCsharpException = nullptr;
				ex->ThrowReferenceToThis();
				delete ex;
			}
			return System::Object(Plugin::InternalUse::Only, returnValue);
		}
		
		System::Boolean System::Collections::IEnumerator::MoveNext()
		{
			auto returnValue = Plugin::SystemCollectionsIEnumeratorMethodMoveNext(Handle);
			if (Plugin::unhandledCsharpException)
			{
				System::Exception* ex = Plugin::unhandledCsharpException;
				Plugin::unhandledCsharpException = nullptr;
				ex->ThrowReferenceToThis();
				delete ex;
			}
			return returnValue;
		}
	}
}

namespace System
{
	namespace Runtime
	{
		namespace Serialization
		{
			ISerializable::ISerializable(decltype(nullptr))
			{
			}
			
			ISerializable::ISerializable(Plugin::InternalUse, int32_t handle)
			{
				Handle = handle;
				if (handle)
				{
					Plugin::ReferenceManagedClass(handle);
				}
			}
			
			ISerializable::ISerializable(const ISerializable& other)
				: ISerializable(Plugin::InternalUse::Only, other.Handle)
			{
			}
			
			ISerializable::ISerializable(ISerializable&& other)
				: ISerializable(Plugin::InternalUse::Only, other.Handle)
			{
				other.Handle = 0;
			}
			
			ISerializable::~ISerializable()
			{
				if (Handle)
				{
					Plugin::DereferenceManagedClass(Handle);
					Handle = 0;
				}
			}
			
			ISerializable& ISerializable::operator=(const ISerializable& other)
			{
				if (this->Handle)
				{
					Plugin::DereferenceManagedClass(this->Handle);
				}
				this->Handle = other.Handle;
				if (this->Handle)
				{
					Plugin::ReferenceManagedClass(this->Handle);
				}
				return *this;
			}
			
			ISerializable& ISerializable::operator=(decltype(nullptr))
			{
				if (Handle)
				{
					Plugin::DereferenceManagedClass(Handle);
					Handle = 0;
				}
				return *this;
			}
			
			ISerializable& ISerializable::operator=(ISerializable&& other)
			{
				if (Handle)
				{
					Plugin::DereferenceManagedClass(Handle);
				}
				Handle = other.Handle;
				other.Handle = 0;
				return *this;
			}
			
			bool ISerializable::operator==(const ISerializable& other) const
			{
				return Handle == other.Handle;
			}
			
			bool ISerializable::operator!=(const ISerializable& other) const
			{
				return Handle != other.Handle;
			}
		}
	}
}

namespace System
{
	namespace Runtime
	{
		namespace InteropServices
		{
			_Exception::_Exception(decltype(nullptr))
			{
			}
			
			_Exception::_Exception(Plugin::InternalUse, int32_t handle)
			{
				Handle = handle;
				if (handle)
				{
					Plugin::ReferenceManagedClass(handle);
				}
			}
			
			_Exception::_Exception(const _Exception& other)
				: _Exception(Plugin::InternalUse::Only, other.Handle)
			{
			}
			
			_Exception::_Exception(_Exception&& other)
				: _Exception(Plugin::InternalUse::Only, other.Handle)
			{
				other.Handle = 0;
			}
			
			_Exception::~_Exception()
			{
				if (Handle)
				{
					Plugin::DereferenceManagedClass(Handle);
					Handle = 0;
				}
			}
			
			_Exception& _Exception::operator=(const _Exception& other)
			{
				if (this->Handle)
				{
					Plugin::DereferenceManagedClass(this->Handle);
				}
				this->Handle = other.Handle;
				if (this->Handle)
				{
					Plugin::ReferenceManagedClass(this->Handle);
				}
				return *this;
			}
			
			_Exception& _Exception::operator=(decltype(nullptr))
			{
				if (Handle)
				{
					Plugin::DereferenceManagedClass(Handle);
					Handle = 0;
				}
				return *this;
			}
			
			_Exception& _Exception::operator=(_Exception&& other)
			{
				if (Handle)
				{
					Plugin::DereferenceManagedClass(Handle);
				}
				Handle = other.Handle;
				other.Handle = 0;
				return *this;
			}
			
			bool _Exception::operator==(const _Exception& other) const
			{
				return Handle == other.Handle;
			}
			
			bool _Exception::operator!=(const _Exception& other) const
			{
				return Handle != other.Handle;
			}
		}
	}
}

namespace UnityEngine
{
	Behaviour::Behaviour(decltype(nullptr))
		: UnityEngine::Object(nullptr)
		, UnityEngine::Component(nullptr)
	{
	}
	
	Behaviour::Behaviour(Plugin::InternalUse, int32_t handle)
		: UnityEngine::Object(nullptr)
		, UnityEngine::Component(nullptr)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	Behaviour::Behaviour(const Behaviour& other)
		: Behaviour(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	Behaviour::Behaviour(Behaviour&& other)
		: Behaviour(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	Behaviour::~Behaviour()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	Behaviour& Behaviour::operator=(const Behaviour& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	Behaviour& Behaviour::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	Behaviour& Behaviour::operator=(Behaviour&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool Behaviour::operator==(const Behaviour& other) const
	{
		return Handle == other.Handle;
	}
	
	bool Behaviour::operator!=(const Behaviour& other) const
	{
		return Handle != other.Handle;
	}
}

namespace UnityEngine
{
	Bounds::Bounds(decltype(nullptr))
	{
	}
	
	Bounds::Bounds(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedUnityEngineBounds(Handle);
		}
	}
	
	Bounds::Bounds(const Bounds& other)
		: Bounds(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	Bounds::Bounds(Bounds&& other)
		: Bounds(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	Bounds::~Bounds()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedUnityEngineBounds(Handle);
			Handle = 0;
		}
	}
	
	Bounds& Bounds::operator=(const Bounds& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedUnityEngineBounds(Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedUnityEngineBounds(Handle);
		}
		return *this;
	}
	
	Bounds& Bounds::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedUnityEngineBounds(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	Bounds& Bounds::operator=(Bounds&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedUnityEngineBounds(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool Bounds::operator==(const Bounds& other) const
	{
		return Handle == other.Handle;
	}
	
	bool Bounds::operator!=(const Bounds& other) const
	{
		return Handle != other.Handle;
	}
	
	UnityEngine::Vector3 UnityEngine::Bounds::GetMax()
	{
		auto returnValue = Plugin::UnityEngineBoundsPropertyGetMax(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnValue;
	}
	
	void UnityEngine::Bounds::SetMax(UnityEngine::Vector3& value)
	{
		Plugin::UnityEngineBoundsPropertySetMax(Handle, value);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
	}
	
	UnityEngine::Vector3 UnityEngine::Bounds::GetMin()
	{
		auto returnValue = Plugin::UnityEngineBoundsPropertyGetMin(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnValue;
	}
	
	void UnityEngine::Bounds::SetMin(UnityEngine::Vector3& value)
	{
		Plugin::UnityEngineBoundsPropertySetMin(Handle, value);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
	}
	
	System::Boolean UnityEngine::Bounds::Intersects(UnityEngine::Bounds& bounds)
	{
		auto returnValue = Plugin::UnityEngineBoundsMethodIntersectsUnityEngineBounds(Handle, bounds.Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnValue;
	}
	
	UnityEngine::Bounds::operator System::ValueType()
	{
		int32_t handle = Plugin::BoxBounds(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
			return System::ValueType(Plugin::InternalUse::Only, handle);
		}
		return nullptr;
	}
	
	UnityEngine::Bounds::operator System::Object()
	{
		int32_t handle = Plugin::BoxBounds(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
			return System::Object(Plugin::InternalUse::Only, handle);
		}
		return nullptr;
	}
}

namespace System
{
	System::Object::operator UnityEngine::Bounds()
	{
		UnityEngine::Bounds returnVal(Plugin::InternalUse::Only, Plugin::UnboxBounds(Handle));
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnVal;
	}
}

namespace UnityEngine
{
	GameObject::GameObject(decltype(nullptr))
		: UnityEngine::Object(nullptr)
	{
	}
	
	GameObject::GameObject(Plugin::InternalUse, int32_t handle)
		: UnityEngine::Object(nullptr)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	GameObject::GameObject(const GameObject& other)
		: GameObject(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	GameObject::GameObject(GameObject&& other)
		: GameObject(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	GameObject::~GameObject()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	GameObject& GameObject::operator=(const GameObject& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	GameObject& GameObject::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	GameObject& GameObject::operator=(GameObject&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool GameObject::operator==(const GameObject& other) const
	{
		return Handle == other.Handle;
	}
	
	bool GameObject::operator!=(const GameObject& other) const
	{
		return Handle != other.Handle;
	}
	
	UnityEngine::GameObject::GameObject()
		: UnityEngine::Object(nullptr)
	{
		auto returnValue = Plugin::UnityEngineGameObjectConstructor();
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		Handle = returnValue;
		if (returnValue)
		{
			Plugin::ReferenceManagedClass(returnValue);
		}
	}
	
	UnityEngine::GameObject::GameObject(System::String& name)
		: UnityEngine::Object(nullptr)
	{
		auto returnValue = Plugin::UnityEngineGameObjectConstructorSystemString(name.Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		Handle = returnValue;
		if (returnValue)
		{
			Plugin::ReferenceManagedClass(returnValue);
		}
	}
	
	UnityEngine::Transform UnityEngine::GameObject::GetTransform()
	{
		auto returnValue = Plugin::UnityEngineGameObjectPropertyGetTransform(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return UnityEngine::Transform(Plugin::InternalUse::Only, returnValue);
	}
	
	System::String UnityEngine::GameObject::GetTag()
	{
		auto returnValue = Plugin::UnityEngineGameObjectPropertyGetTag(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return System::String(Plugin::InternalUse::Only, returnValue);
	}
	
	void UnityEngine::GameObject::SetTag(System::String& value)
	{
		Plugin::UnityEngineGameObjectPropertySetTag(Handle, value.Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
	}
	
	template<> MyGame::BaseGameScript UnityEngine::GameObject::AddComponent<MyGame::BaseGameScript>()
	{
		auto returnValue = Plugin::UnityEngineGameObjectMethodAddComponentMyGameBaseGameScript(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return MyGame::BaseGameScript(Plugin::InternalUse::Only, returnValue);
	}
	
	template<> UnityEngine::SpriteRenderer UnityEngine::GameObject::AddComponent<UnityEngine::SpriteRenderer>()
	{
		auto returnValue = Plugin::UnityEngineGameObjectMethodAddComponentUnityEngineSpriteRenderer(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return UnityEngine::SpriteRenderer(Plugin::InternalUse::Only, returnValue);
	}
	
	template<> UnityEngine::AudioSource UnityEngine::GameObject::AddComponent<UnityEngine::AudioSource>()
	{
		auto returnValue = Plugin::UnityEngineGameObjectMethodAddComponentUnityEngineAudioSource(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return UnityEngine::AudioSource(Plugin::InternalUse::Only, returnValue);
	}
	
	template<> UnityEngine::SpriteRenderer UnityEngine::GameObject::GetComponent<UnityEngine::SpriteRenderer>()
	{
		auto returnValue = Plugin::UnityEngineGameObjectMethodGetComponentUnityEngineSpriteRenderer(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return UnityEngine::SpriteRenderer(Plugin::InternalUse::Only, returnValue);
	}
	
	template<> UnityEngine::AudioSource UnityEngine::GameObject::GetComponent<UnityEngine::AudioSource>()
	{
		auto returnValue = Plugin::UnityEngineGameObjectMethodGetComponentUnityEngineAudioSource(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return UnityEngine::AudioSource(Plugin::InternalUse::Only, returnValue);
	}
	
	System::Boolean UnityEngine::GameObject::CompareTag(System::String& tag)
	{
		auto returnValue = Plugin::UnityEngineGameObjectMethodCompareTagSystemString(Handle, tag.Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnValue;
	}
	
	UnityEngine::GameObject UnityEngine::GameObject::CreatePrimitive(UnityEngine::PrimitiveType type)
	{
		auto returnValue = Plugin::UnityEngineGameObjectMethodCreatePrimitiveUnityEnginePrimitiveType(type);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return UnityEngine::GameObject(Plugin::InternalUse::Only, returnValue);
	}
}

namespace UnityEngine
{
	Debug::Debug(decltype(nullptr))
	{
	}
	
	Debug::Debug(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	Debug::Debug(const Debug& other)
		: Debug(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	Debug::Debug(Debug&& other)
		: Debug(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	Debug::~Debug()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	Debug& Debug::operator=(const Debug& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	Debug& Debug::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	Debug& Debug::operator=(Debug&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool Debug::operator==(const Debug& other) const
	{
		return Handle == other.Handle;
	}
	
	bool Debug::operator!=(const Debug& other) const
	{
		return Handle != other.Handle;
	}
	
	void UnityEngine::Debug::Log(System::Object& message)
	{
		Plugin::UnityEngineDebugMethodLogSystemObject(message.Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
	}
}

namespace UnityEngine
{
	AudioClip::AudioClip(decltype(nullptr))
		: UnityEngine::Object(nullptr)
	{
	}
	
	AudioClip::AudioClip(Plugin::InternalUse, int32_t handle)
		: UnityEngine::Object(nullptr)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	AudioClip::AudioClip(const AudioClip& other)
		: AudioClip(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	AudioClip::AudioClip(AudioClip&& other)
		: AudioClip(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	AudioClip::~AudioClip()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	AudioClip& AudioClip::operator=(const AudioClip& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	AudioClip& AudioClip::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	AudioClip& AudioClip::operator=(AudioClip&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool AudioClip::operator==(const AudioClip& other) const
	{
		return Handle == other.Handle;
	}
	
	bool AudioClip::operator!=(const AudioClip& other) const
	{
		return Handle != other.Handle;
	}
	
	UnityEngine::AudioClip::AudioClip()
		: UnityEngine::Object(nullptr)
	{
		auto returnValue = Plugin::UnityEngineAudioClipConstructor();
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		Handle = returnValue;
		if (returnValue)
		{
			Plugin::ReferenceManagedClass(returnValue);
		}
	}
}

namespace UnityEngine
{
	AudioSource::AudioSource(decltype(nullptr))
		: UnityEngine::Object(nullptr)
		, UnityEngine::Component(nullptr)
		, UnityEngine::Behaviour(nullptr)
	{
	}
	
	AudioSource::AudioSource(Plugin::InternalUse, int32_t handle)
		: UnityEngine::Object(nullptr)
		, UnityEngine::Component(nullptr)
		, UnityEngine::Behaviour(nullptr)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	AudioSource::AudioSource(const AudioSource& other)
		: AudioSource(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	AudioSource::AudioSource(AudioSource&& other)
		: AudioSource(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	AudioSource::~AudioSource()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	AudioSource& AudioSource::operator=(const AudioSource& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	AudioSource& AudioSource::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	AudioSource& AudioSource::operator=(AudioSource&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool AudioSource::operator==(const AudioSource& other) const
	{
		return Handle == other.Handle;
	}
	
	bool AudioSource::operator!=(const AudioSource& other) const
	{
		return Handle != other.Handle;
	}
	
	System::Boolean UnityEngine::AudioSource::GetLoop()
	{
		auto returnValue = Plugin::UnityEngineAudioSourcePropertyGetLoop(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnValue;
	}
	
	void UnityEngine::AudioSource::SetLoop(System::Boolean value)
	{
		Plugin::UnityEngineAudioSourcePropertySetLoop(Handle, value);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
	}
	
	UnityEngine::AudioClip UnityEngine::AudioSource::GetClip()
	{
		auto returnValue = Plugin::UnityEngineAudioSourcePropertyGetClip(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return UnityEngine::AudioClip(Plugin::InternalUse::Only, returnValue);
	}
	
	void UnityEngine::AudioSource::SetClip(UnityEngine::AudioClip& value)
	{
		Plugin::UnityEngineAudioSourcePropertySetClip(Handle, value.Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
	}
	
	void UnityEngine::AudioSource::PlayOneShot(UnityEngine::AudioClip& clip)
	{
		Plugin::UnityEngineAudioSourceMethodPlayOneShotUnityEngineAudioClip(Handle, clip.Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
	}
	
	void UnityEngine::AudioSource::Play()
	{
		Plugin::UnityEngineAudioSourceMethodPlay(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
	}
	
	void UnityEngine::AudioSource::Stop()
	{
		Plugin::UnityEngineAudioSourceMethodStop(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
	}
}

namespace UnityEngine
{
	Input::Input(decltype(nullptr))
	{
	}
	
	Input::Input(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	Input::Input(const Input& other)
		: Input(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	Input::Input(Input&& other)
		: Input(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	Input::~Input()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	Input& Input::operator=(const Input& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	Input& Input::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	Input& Input::operator=(Input&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool Input::operator==(const Input& other) const
	{
		return Handle == other.Handle;
	}
	
	bool Input::operator!=(const Input& other) const
	{
		return Handle != other.Handle;
	}
	
	System::Single UnityEngine::Input::GetAxis(System::String& axisName)
	{
		auto returnValue = Plugin::UnityEngineInputMethodGetAxisSystemString(axisName.Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnValue;
	}
	
	System::Single UnityEngine::Input::GetAxisRaw(System::String& axisName)
	{
		auto returnValue = Plugin::UnityEngineInputMethodGetAxisRawSystemString(axisName.Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnValue;
	}
	
	System::Boolean UnityEngine::Input::GetKey(System::String& name)
	{
		auto returnValue = Plugin::UnityEngineInputMethodGetKeySystemString(name.Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnValue;
	}
	
	System::Boolean UnityEngine::Input::GetKeyUp(System::String& name)
	{
		auto returnValue = Plugin::UnityEngineInputMethodGetKeyUpSystemString(name.Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnValue;
	}
	
	System::Boolean UnityEngine::Input::GetKeyDown(System::String& name)
	{
		auto returnValue = Plugin::UnityEngineInputMethodGetKeyDownSystemString(name.Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnValue;
	}
}

namespace UnityEngine
{
	Resources::Resources(decltype(nullptr))
	{
	}
	
	Resources::Resources(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	Resources::Resources(const Resources& other)
		: Resources(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	Resources::Resources(Resources&& other)
		: Resources(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	Resources::~Resources()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	Resources& Resources::operator=(const Resources& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	Resources& Resources::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	Resources& Resources::operator=(Resources&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool Resources::operator==(const Resources& other) const
	{
		return Handle == other.Handle;
	}
	
	bool Resources::operator!=(const Resources& other) const
	{
		return Handle != other.Handle;
	}
	
	template<> UnityEngine::Sprite UnityEngine::Resources::Load<UnityEngine::Sprite>(System::String& path)
	{
		auto returnValue = Plugin::UnityEngineResourcesMethodLoadUnityEngineSpriteSystemString(path.Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return UnityEngine::Sprite(Plugin::InternalUse::Only, returnValue);
	}
	
	template<> UnityEngine::AudioClip UnityEngine::Resources::Load<UnityEngine::AudioClip>(System::String& path)
	{
		auto returnValue = Plugin::UnityEngineResourcesMethodLoadUnityEngineAudioClipSystemString(path.Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return UnityEngine::AudioClip(Plugin::InternalUse::Only, returnValue);
	}
}

namespace UnityEngine
{
	MonoBehaviour::MonoBehaviour(decltype(nullptr))
		: UnityEngine::Object(nullptr)
		, UnityEngine::Component(nullptr)
		, UnityEngine::Behaviour(nullptr)
	{
	}
	
	MonoBehaviour::MonoBehaviour(Plugin::InternalUse, int32_t handle)
		: UnityEngine::Object(nullptr)
		, UnityEngine::Component(nullptr)
		, UnityEngine::Behaviour(nullptr)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	MonoBehaviour::MonoBehaviour(const MonoBehaviour& other)
		: MonoBehaviour(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	MonoBehaviour::MonoBehaviour(MonoBehaviour&& other)
		: MonoBehaviour(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	MonoBehaviour::~MonoBehaviour()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	MonoBehaviour& MonoBehaviour::operator=(const MonoBehaviour& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	MonoBehaviour& MonoBehaviour::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	MonoBehaviour& MonoBehaviour::operator=(MonoBehaviour&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool MonoBehaviour::operator==(const MonoBehaviour& other) const
	{
		return Handle == other.Handle;
	}
	
	bool MonoBehaviour::operator!=(const MonoBehaviour& other) const
	{
		return Handle != other.Handle;
	}
	
	UnityEngine::Transform UnityEngine::MonoBehaviour::GetTransform()
	{
		auto returnValue = Plugin::UnityEngineMonoBehaviourPropertyGetTransform(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return UnityEngine::Transform(Plugin::InternalUse::Only, returnValue);
	}
}

namespace System
{
	Exception::Exception(decltype(nullptr))
		: System::Runtime::InteropServices::_Exception(nullptr)
		, System::Runtime::Serialization::ISerializable(nullptr)
	{
	}
	
	Exception::Exception(Plugin::InternalUse, int32_t handle)
		: System::Runtime::InteropServices::_Exception(nullptr)
		, System::Runtime::Serialization::ISerializable(nullptr)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	Exception::Exception(const Exception& other)
		: Exception(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	Exception::Exception(Exception&& other)
		: Exception(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	Exception::~Exception()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	Exception& Exception::operator=(const Exception& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	Exception& Exception::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	Exception& Exception::operator=(Exception&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool Exception::operator==(const Exception& other) const
	{
		return Handle == other.Handle;
	}
	
	bool Exception::operator!=(const Exception& other) const
	{
		return Handle != other.Handle;
	}
	
	System::Exception::Exception(System::String& message)
		: System::Runtime::InteropServices::_Exception(nullptr)
		, System::Runtime::Serialization::ISerializable(nullptr)
	{
		auto returnValue = Plugin::SystemExceptionConstructorSystemString(message.Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		Handle = returnValue;
		if (returnValue)
		{
			Plugin::ReferenceManagedClass(returnValue);
		}
	}
}

namespace System
{
	SystemException::SystemException(decltype(nullptr))
		: System::Runtime::InteropServices::_Exception(nullptr)
		, System::Runtime::Serialization::ISerializable(nullptr)
		, System::Exception(nullptr)
	{
	}
	
	SystemException::SystemException(Plugin::InternalUse, int32_t handle)
		: System::Runtime::InteropServices::_Exception(nullptr)
		, System::Runtime::Serialization::ISerializable(nullptr)
		, System::Exception(nullptr)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	SystemException::SystemException(const SystemException& other)
		: SystemException(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	SystemException::SystemException(SystemException&& other)
		: SystemException(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	SystemException::~SystemException()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	SystemException& SystemException::operator=(const SystemException& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	SystemException& SystemException::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	SystemException& SystemException::operator=(SystemException&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool SystemException::operator==(const SystemException& other) const
	{
		return Handle == other.Handle;
	}
	
	bool SystemException::operator!=(const SystemException& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	NullReferenceException::NullReferenceException(decltype(nullptr))
		: System::Runtime::InteropServices::_Exception(nullptr)
		, System::Runtime::Serialization::ISerializable(nullptr)
		, System::Exception(nullptr)
		, System::SystemException(nullptr)
	{
	}
	
	NullReferenceException::NullReferenceException(Plugin::InternalUse, int32_t handle)
		: System::Runtime::InteropServices::_Exception(nullptr)
		, System::Runtime::Serialization::ISerializable(nullptr)
		, System::Exception(nullptr)
		, System::SystemException(nullptr)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	NullReferenceException::NullReferenceException(const NullReferenceException& other)
		: NullReferenceException(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	NullReferenceException::NullReferenceException(NullReferenceException&& other)
		: NullReferenceException(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	NullReferenceException::~NullReferenceException()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	NullReferenceException& NullReferenceException::operator=(const NullReferenceException& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	NullReferenceException& NullReferenceException::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	NullReferenceException& NullReferenceException::operator=(NullReferenceException&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool NullReferenceException::operator==(const NullReferenceException& other) const
	{
		return Handle == other.Handle;
	}
	
	bool NullReferenceException::operator!=(const NullReferenceException& other) const
	{
		return Handle != other.Handle;
	}
}

namespace UnityEngine
{
	PrimitiveType::PrimitiveType(int32_t value)
		: Value(value)
	{
	}
	
	UnityEngine::PrimitiveType::operator int32_t() const
	{
		return Value;
	}
	
	bool UnityEngine::PrimitiveType::operator==(PrimitiveType other)
	{
		return Value == other.Value;
	}
	
	bool UnityEngine::PrimitiveType::operator!=(PrimitiveType other)
	{
		return Value != other.Value;
	}
	
	UnityEngine::PrimitiveType::operator System::Enum()
	{
		int32_t handle = Plugin::BoxPrimitiveType(*this);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
			return System::Enum(Plugin::InternalUse::Only, handle);
		}
		return nullptr;
	}
	
	UnityEngine::PrimitiveType::operator System::ValueType()
	{
		int32_t handle = Plugin::BoxPrimitiveType(*this);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
			return System::ValueType(Plugin::InternalUse::Only, handle);
		}
		return nullptr;
	}
	
	UnityEngine::PrimitiveType::operator System::Object()
	{
		int32_t handle = Plugin::BoxPrimitiveType(*this);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
			return System::Object(Plugin::InternalUse::Only, handle);
		}
		return nullptr;
	}
	
	UnityEngine::PrimitiveType::operator System::IFormattable()
	{
		int32_t handle = Plugin::BoxPrimitiveType(*this);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
			return System::IFormattable(Plugin::InternalUse::Only, handle);
		}
		return nullptr;
	}
	
	UnityEngine::PrimitiveType::operator System::IConvertible()
	{
		int32_t handle = Plugin::BoxPrimitiveType(*this);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
			return System::IConvertible(Plugin::InternalUse::Only, handle);
		}
		return nullptr;
	}
	
	UnityEngine::PrimitiveType::operator System::IComparable()
	{
		int32_t handle = Plugin::BoxPrimitiveType(*this);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
			return System::IComparable(Plugin::InternalUse::Only, handle);
		}
		return nullptr;
	}
	
}
const UnityEngine::PrimitiveType UnityEngine::PrimitiveType::Sphere(0);
const UnityEngine::PrimitiveType UnityEngine::PrimitiveType::Capsule(1);
const UnityEngine::PrimitiveType UnityEngine::PrimitiveType::Cylinder(2);
const UnityEngine::PrimitiveType UnityEngine::PrimitiveType::Cube(3);
const UnityEngine::PrimitiveType UnityEngine::PrimitiveType::Plane(4);
const UnityEngine::PrimitiveType UnityEngine::PrimitiveType::Quad(5);

namespace System
{
	System::Object::operator UnityEngine::PrimitiveType()
	{
		UnityEngine::PrimitiveType returnVal(Plugin::UnboxPrimitiveType(Handle));
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnVal;
	}
}

namespace UnityEngine
{
	Renderer::Renderer(decltype(nullptr))
		: UnityEngine::Object(nullptr)
		, UnityEngine::Component(nullptr)
	{
	}
	
	Renderer::Renderer(Plugin::InternalUse, int32_t handle)
		: UnityEngine::Object(nullptr)
		, UnityEngine::Component(nullptr)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	Renderer::Renderer(const Renderer& other)
		: Renderer(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	Renderer::Renderer(Renderer&& other)
		: Renderer(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	Renderer::~Renderer()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	Renderer& Renderer::operator=(const Renderer& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	Renderer& Renderer::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	Renderer& Renderer::operator=(Renderer&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool Renderer::operator==(const Renderer& other) const
	{
		return Handle == other.Handle;
	}
	
	bool Renderer::operator!=(const Renderer& other) const
	{
		return Handle != other.Handle;
	}
}

namespace UnityEngine
{
	Sprite::Sprite(decltype(nullptr))
		: UnityEngine::Object(nullptr)
	{
	}
	
	Sprite::Sprite(Plugin::InternalUse, int32_t handle)
		: UnityEngine::Object(nullptr)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	Sprite::Sprite(const Sprite& other)
		: Sprite(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	Sprite::Sprite(Sprite&& other)
		: Sprite(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	Sprite::~Sprite()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	Sprite& Sprite::operator=(const Sprite& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	Sprite& Sprite::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	Sprite& Sprite::operator=(Sprite&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool Sprite::operator==(const Sprite& other) const
	{
		return Handle == other.Handle;
	}
	
	bool Sprite::operator!=(const Sprite& other) const
	{
		return Handle != other.Handle;
	}
	
	UnityEngine::Sprite::Sprite()
		: UnityEngine::Object(nullptr)
	{
		auto returnValue = Plugin::UnityEngineSpriteConstructor();
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		Handle = returnValue;
		if (returnValue)
		{
			Plugin::ReferenceManagedClass(returnValue);
		}
	}
	
	UnityEngine::Bounds UnityEngine::Sprite::GetBounds()
	{
		auto returnValue = Plugin::UnityEngineSpritePropertyGetBounds(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return UnityEngine::Bounds(Plugin::InternalUse::Only, returnValue);
	}
}

namespace UnityEngine
{
	SpriteRenderer::SpriteRenderer(decltype(nullptr))
		: UnityEngine::Object(nullptr)
		, UnityEngine::Component(nullptr)
		, UnityEngine::Renderer(nullptr)
	{
	}
	
	SpriteRenderer::SpriteRenderer(Plugin::InternalUse, int32_t handle)
		: UnityEngine::Object(nullptr)
		, UnityEngine::Component(nullptr)
		, UnityEngine::Renderer(nullptr)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	SpriteRenderer::SpriteRenderer(const SpriteRenderer& other)
		: SpriteRenderer(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	SpriteRenderer::SpriteRenderer(SpriteRenderer&& other)
		: SpriteRenderer(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	SpriteRenderer::~SpriteRenderer()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	SpriteRenderer& SpriteRenderer::operator=(const SpriteRenderer& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	SpriteRenderer& SpriteRenderer::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	SpriteRenderer& SpriteRenderer::operator=(SpriteRenderer&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool SpriteRenderer::operator==(const SpriteRenderer& other) const
	{
		return Handle == other.Handle;
	}
	
	bool SpriteRenderer::operator!=(const SpriteRenderer& other) const
	{
		return Handle != other.Handle;
	}
	
	UnityEngine::Sprite UnityEngine::SpriteRenderer::GetSprite()
	{
		auto returnValue = Plugin::UnityEngineSpriteRendererPropertyGetSprite(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return UnityEngine::Sprite(Plugin::InternalUse::Only, returnValue);
	}
	
	void UnityEngine::SpriteRenderer::SetSprite(UnityEngine::Sprite& value)
	{
		Plugin::UnityEngineSpriteRendererPropertySetSprite(Handle, value.Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
	}
	
	UnityEngine::Bounds UnityEngine::SpriteRenderer::GetBounds()
	{
		auto returnValue = Plugin::UnityEngineSpriteRendererPropertyGetBounds(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return UnityEngine::Bounds(Plugin::InternalUse::Only, returnValue);
	}
}

namespace UnityEngine
{
	Time::Time(decltype(nullptr))
	{
	}
	
	Time::Time(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	Time::Time(const Time& other)
		: Time(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	Time::Time(Time&& other)
		: Time(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	Time::~Time()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	Time& Time::operator=(const Time& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	Time& Time::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	Time& Time::operator=(Time&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool Time::operator==(const Time& other) const
	{
		return Handle == other.Handle;
	}
	
	bool Time::operator!=(const Time& other) const
	{
		return Handle != other.Handle;
	}
	
	System::Single UnityEngine::Time::GetDeltaTime()
	{
		auto returnValue = Plugin::UnityEngineTimePropertyGetDeltaTime();
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnValue;
	}
}

namespace MyGame
{
	AbstractBaseGameScript::AbstractBaseGameScript(decltype(nullptr))
		: UnityEngine::Object(nullptr)
		, UnityEngine::Component(nullptr)
		, UnityEngine::Behaviour(nullptr)
		, UnityEngine::MonoBehaviour(nullptr)
	{
	}
	
	AbstractBaseGameScript::AbstractBaseGameScript(Plugin::InternalUse, int32_t handle)
		: UnityEngine::Object(nullptr)
		, UnityEngine::Component(nullptr)
		, UnityEngine::Behaviour(nullptr)
		, UnityEngine::MonoBehaviour(nullptr)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	AbstractBaseGameScript::AbstractBaseGameScript(const AbstractBaseGameScript& other)
		: AbstractBaseGameScript(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	AbstractBaseGameScript::AbstractBaseGameScript(AbstractBaseGameScript&& other)
		: AbstractBaseGameScript(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	AbstractBaseGameScript::~AbstractBaseGameScript()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	AbstractBaseGameScript& AbstractBaseGameScript::operator=(const AbstractBaseGameScript& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	AbstractBaseGameScript& AbstractBaseGameScript::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	AbstractBaseGameScript& AbstractBaseGameScript::operator=(AbstractBaseGameScript&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool AbstractBaseGameScript::operator==(const AbstractBaseGameScript& other) const
	{
		return Handle == other.Handle;
	}
	
	bool AbstractBaseGameScript::operator!=(const AbstractBaseGameScript& other) const
	{
		return Handle != other.Handle;
	}
}

namespace MyGame
{
	MyGame::BaseGameScript::BaseGameScript()
		: UnityEngine::Object(nullptr)
		, UnityEngine::Component(nullptr)
		, UnityEngine::Behaviour(nullptr)
		, UnityEngine::MonoBehaviour(nullptr)
		, MyGame::AbstractBaseGameScript(nullptr)
	{
		CppHandle = Plugin::StoreBaseGameScript(this);
		System::Int32* handle = (System::Int32*)&Handle;
		int32_t cppHandle = CppHandle;
		Plugin::BaseGameScriptConstructor(cppHandle, &handle->Value);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		if (Handle)
		{
			Plugin::ReferenceManagedClass(Handle);
		}
		else
		{
			Plugin::RemoveBaseGameScript(CppHandle);
			CppHandle = 0;
		}
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
	}
	
	BaseGameScript::BaseGameScript(decltype(nullptr))
		: UnityEngine::Object(nullptr)
		, UnityEngine::Component(nullptr)
		, UnityEngine::Behaviour(nullptr)
		, UnityEngine::MonoBehaviour(nullptr)
		, MyGame::AbstractBaseGameScript(nullptr)
	{
		CppHandle = Plugin::StoreBaseGameScript(this);
	}
	
	MyGame::BaseGameScript::BaseGameScript(const MyGame::BaseGameScript& other)
		: UnityEngine::Object(nullptr)
		, UnityEngine::Component(nullptr)
		, UnityEngine::Behaviour(nullptr)
		, UnityEngine::MonoBehaviour(nullptr)
		, MyGame::AbstractBaseGameScript(nullptr)
	{
		Handle = other.Handle;
		CppHandle = Plugin::StoreBaseGameScript(this);
		if (Handle)
		{
			Plugin::ReferenceManagedClass(Handle);
		}
	}
	
	MyGame::BaseGameScript::BaseGameScript(MyGame::BaseGameScript&& other)
		: UnityEngine::Object(nullptr)
		, UnityEngine::Component(nullptr)
		, UnityEngine::Behaviour(nullptr)
		, UnityEngine::MonoBehaviour(nullptr)
		, MyGame::AbstractBaseGameScript(nullptr)
	{
		Handle = other.Handle;
		CppHandle = other.CppHandle;
		other.Handle = 0;
		other.CppHandle = 0;
	}
	
	MyGame::BaseGameScript::BaseGameScript(Plugin::InternalUse, int32_t handle)
		: UnityEngine::Object(nullptr)
		, UnityEngine::Component(nullptr)
		, UnityEngine::Behaviour(nullptr)
		, UnityEngine::MonoBehaviour(nullptr)
		, MyGame::AbstractBaseGameScript(nullptr)
	{
		Handle = handle;
		CppHandle = Plugin::StoreBaseGameScript(this);
		if (Handle)
		{
			Plugin::ReferenceManagedClass(Handle);
		}
	}
	
	MyGame::BaseGameScript::~BaseGameScript()
	{
		Plugin::RemoveWholeBaseGameScript(this);
		Plugin::RemoveBaseGameScript(CppHandle);
		CppHandle = 0;
		if (Handle)
		{
			int32_t handle = Handle;
			Handle = 0;
			if (Plugin::DereferenceManagedClassNoRelease(handle))
			{
				Plugin::ReleaseBaseGameScript(handle);
				if (Plugin::unhandledCsharpException)
				{
					System::Exception* ex = Plugin::unhandledCsharpException;
					Plugin::unhandledCsharpException = nullptr;
					ex->ThrowReferenceToThis();
					delete ex;
				}
			}
		}
	}
	
	MyGame::BaseGameScript& MyGame::BaseGameScript::operator=(const MyGame::BaseGameScript& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	MyGame::BaseGameScript& MyGame::BaseGameScript::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			int32_t handle = Handle;
			Handle = 0;
			if (Plugin::DereferenceManagedClassNoRelease(handle))
			{
				Plugin::ReleaseBaseGameScript(handle);
				if (Plugin::unhandledCsharpException)
				{
					System::Exception* ex = Plugin::unhandledCsharpException;
					Plugin::unhandledCsharpException = nullptr;
					ex->ThrowReferenceToThis();
					delete ex;
				}
			}
		}
		Handle = 0;
		return *this;
	}
	
	MyGame::BaseGameScript& MyGame::BaseGameScript::operator=(MyGame::BaseGameScript&& other)
	{
		Plugin::RemoveBaseGameScript(CppHandle);
		CppHandle = 0;
		if (Handle)
		{
			int32_t handle = Handle;
			Handle = 0;
			if (Plugin::DereferenceManagedClassNoRelease(handle))
			{
				Plugin::ReleaseBaseGameScript(handle);
				if (Plugin::unhandledCsharpException)
				{
					System::Exception* ex = Plugin::unhandledCsharpException;
					Plugin::unhandledCsharpException = nullptr;
					ex->ThrowReferenceToThis();
					delete ex;
				}
			}
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool MyGame::BaseGameScript::operator==(const MyGame::BaseGameScript& other) const
	{
		return Handle == other.Handle;
	}
	
	bool MyGame::BaseGameScript::operator!=(const MyGame::BaseGameScript& other) const
	{
		return Handle != other.Handle;
	}
	
	DLLEXPORT int32_t NewBaseGameScript(int32_t handle)
	{
		MyGame::BaseGameScript* memory = Plugin::StoreWholeBaseGameScript();
		MyGame::GameScript* thiz = new (memory) MyGame::GameScript(Plugin::InternalUse::Only, handle);
		return thiz->CppHandle;
	}

	DLLEXPORT void DestroyBaseGameScript(int32_t cppHandle)
	{
		MyGame::BaseGameScript* instance = Plugin::GetBaseGameScript(cppHandle);
		instance->~BaseGameScript();
	}

	void MyGame::BaseGameScript::Update()
	{
	}
	
	DLLEXPORT void MyGameAbstractBaseGameScriptUpdate(int32_t cppHandle)
	{
		try
		{
			Plugin::GetBaseGameScript(cppHandle)->Update();
		}
		catch (System::Exception ex)
		{
			Plugin::SetException(ex.Handle);
		}
		catch (...)
		{
			System::String msg = "Unhandled exception invoking MyGame::AbstractBaseGameScript";
			System::Exception ex(msg);
			Plugin::SetException(ex.Handle);
		}
	}
}

namespace System
{
	System::Object::operator System::Boolean()
	{
		System::Boolean returnVal(Plugin::UnboxBoolean(Handle));
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnVal;
	}
}

namespace System
{
	System::Object::operator System::SByte()
	{
		System::SByte returnVal(Plugin::UnboxSByte(Handle));
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnVal;
	}
}

namespace System
{
	System::Object::operator System::Byte()
	{
		System::Byte returnVal(Plugin::UnboxByte(Handle));
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnVal;
	}
}

namespace System
{
	System::Object::operator System::Int16()
	{
		System::Int16 returnVal(Plugin::UnboxInt16(Handle));
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnVal;
	}
}

namespace System
{
	System::Object::operator System::UInt16()
	{
		System::UInt16 returnVal(Plugin::UnboxUInt16(Handle));
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnVal;
	}
}

namespace System
{
	System::Object::operator System::Int32()
	{
		System::Int32 returnVal(Plugin::UnboxInt32(Handle));
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnVal;
	}
}

namespace System
{
	System::Object::operator System::UInt32()
	{
		System::UInt32 returnVal(Plugin::UnboxUInt32(Handle));
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnVal;
	}
}

namespace System
{
	System::Object::operator System::Int64()
	{
		System::Int64 returnVal(Plugin::UnboxInt64(Handle));
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnVal;
	}
}

namespace System
{
	System::Object::operator System::UInt64()
	{
		System::UInt64 returnVal(Plugin::UnboxUInt64(Handle));
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnVal;
	}
}

namespace System
{
	System::Object::operator System::Char()
	{
		System::Char returnVal(Plugin::UnboxChar(Handle));
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnVal;
	}
}

namespace System
{
	System::Object::operator System::Single()
	{
		System::Single returnVal(Plugin::UnboxSingle(Handle));
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnVal;
	}
}

namespace System
{
	System::Object::operator System::Double()
	{
		System::Double returnVal(Plugin::UnboxDouble(Handle));
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnVal;
	}
}

namespace System
{
	struct NullReferenceExceptionThrower : System::NullReferenceException
	{
		NullReferenceExceptionThrower(int32_t handle)
			: System::Runtime::InteropServices::_Exception(nullptr)
			, System::Runtime::Serialization::ISerializable(nullptr)
			, System::Exception(nullptr)
			, System::SystemException(nullptr)
			, System::NullReferenceException(Plugin::InternalUse::Only, handle)
		{
		}
	
		virtual void ThrowReferenceToThis()
		{
			throw *this;
		}
	};
}

DLLEXPORT void SetCsharpExceptionSystemNullReferenceException(int32_t handle)
{
	delete Plugin::unhandledCsharpException;
	Plugin::unhandledCsharpException = new System::NullReferenceExceptionThrower(handle);
}
/*END METHOD DEFINITIONS*/

////////////////////////////////////////////////////////////////
// App-specific functions for this file to call
////////////////////////////////////////////////////////////////

// Called when the plugin is initialized
extern void PluginMain(
	void* memory,
	int32_t memorySize,
	bool isFirstBoot);

////////////////////////////////////////////////////////////////
// C++ functions for C# to call
////////////////////////////////////////////////////////////////

enum class InitMode : uint8_t
{
	FirstBoot,
	Reload
};

// Init the plugin
DLLEXPORT void Init(
	uint8_t* memory,
	int32_t memorySize,
	InitMode initMode)
{
	uint8_t* curMemory = memory;
	
	// Read fixed parameters
	Plugin::ReleaseObject = *(void (**)(int32_t handle))curMemory;
	curMemory += sizeof(Plugin::ReleaseObject);
	Plugin::StringNew = *(int32_t (**)(const char*))curMemory;
	curMemory += sizeof(Plugin::StringNew);
	Plugin::SetException = *(void (**)(int32_t))curMemory;
	curMemory += sizeof(Plugin::SetException);
	Plugin::ArrayGetLength = *(int32_t (**)(int32_t))curMemory;
	curMemory += sizeof(Plugin::ArrayGetLength);
	Plugin::EnumerableGetEnumerator = *(int32_t (**)(int32_t))curMemory;
	curMemory += sizeof(Plugin::EnumerableGetEnumerator);
	
	// Read generated parameters
	int32_t maxManagedObjects = *(int32_t*)curMemory;
	curMemory += sizeof(int32_t);
	/*BEGIN INIT BODY PARAMETER READS*/
	Plugin::ReleaseSystemDecimal = *(void (**)(int32_t handle))curMemory;
	curMemory += sizeof(Plugin::ReleaseSystemDecimal);
	Plugin::SystemDecimalConstructorSystemDouble = *(int32_t (**)(double value))curMemory;
	curMemory += sizeof(Plugin::SystemDecimalConstructorSystemDouble);
	Plugin::SystemDecimalConstructorSystemUInt64 = *(int32_t (**)(uint64_t value))curMemory;
	curMemory += sizeof(Plugin::SystemDecimalConstructorSystemUInt64);
	Plugin::BoxDecimal = *(int32_t (**)(int32_t valHandle))curMemory;
	curMemory += sizeof(Plugin::BoxDecimal);
	Plugin::UnboxDecimal = *(int32_t (**)(int32_t valHandle))curMemory;
	curMemory += sizeof(Plugin::UnboxDecimal);
	Plugin::UnityEngineVector3ConstructorSystemSingle_SystemSingle_SystemSingle = *(UnityEngine::Vector3 (**)(float x, float y, float z))curMemory;
	curMemory += sizeof(Plugin::UnityEngineVector3ConstructorSystemSingle_SystemSingle_SystemSingle);
	Plugin::UnityEngineVector3PropertyGetMagnitude = *(System::Single (**)(UnityEngine::Vector3* thiz))curMemory;
	curMemory += sizeof(Plugin::UnityEngineVector3PropertyGetMagnitude);
	Plugin::UnityEngineVector3Methodop_AdditionUnityEngineVector3_UnityEngineVector3 = *(UnityEngine::Vector3 (**)(UnityEngine::Vector3& a, UnityEngine::Vector3& b))curMemory;
	curMemory += sizeof(Plugin::UnityEngineVector3Methodop_AdditionUnityEngineVector3_UnityEngineVector3);
	Plugin::UnityEngineVector3Methodop_SubtractionUnityEngineVector3_UnityEngineVector3 = *(UnityEngine::Vector3 (**)(UnityEngine::Vector3& a, UnityEngine::Vector3& b))curMemory;
	curMemory += sizeof(Plugin::UnityEngineVector3Methodop_SubtractionUnityEngineVector3_UnityEngineVector3);
	Plugin::UnityEngineVector3MethodNormalizeUnityEngineVector3 = *(UnityEngine::Vector3 (**)(UnityEngine::Vector3& value))curMemory;
	curMemory += sizeof(Plugin::UnityEngineVector3MethodNormalizeUnityEngineVector3);
	Plugin::UnityEngineVector3MethodDotUnityEngineVector3_UnityEngineVector3 = *(System::Single (**)(UnityEngine::Vector3& lhs, UnityEngine::Vector3& rhs))curMemory;
	curMemory += sizeof(Plugin::UnityEngineVector3MethodDotUnityEngineVector3_UnityEngineVector3);
	Plugin::UnityEngineVector3MethodCrossUnityEngineVector3_UnityEngineVector3 = *(UnityEngine::Vector3 (**)(UnityEngine::Vector3& lhs, UnityEngine::Vector3& rhs))curMemory;
	curMemory += sizeof(Plugin::UnityEngineVector3MethodCrossUnityEngineVector3_UnityEngineVector3);
	Plugin::UnityEngineVector3MethodDistanceUnityEngineVector3_UnityEngineVector3 = *(System::Single (**)(UnityEngine::Vector3& a, UnityEngine::Vector3& b))curMemory;
	curMemory += sizeof(Plugin::UnityEngineVector3MethodDistanceUnityEngineVector3_UnityEngineVector3);
	Plugin::BoxVector3 = *(int32_t (**)(UnityEngine::Vector3& val))curMemory;
	curMemory += sizeof(Plugin::BoxVector3);
	Plugin::UnboxVector3 = *(UnityEngine::Vector3 (**)(int32_t valHandle))curMemory;
	curMemory += sizeof(Plugin::UnboxVector3);
	Plugin::UnityEngineObjectPropertyGetName = *(int32_t (**)(int32_t thisHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineObjectPropertyGetName);
	Plugin::UnityEngineObjectPropertySetName = *(void (**)(int32_t thisHandle, int32_t valueHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineObjectPropertySetName);
	Plugin::UnityEngineObjectMethodDestroyUnityEngineObject = *(void (**)(int32_t objHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineObjectMethodDestroyUnityEngineObject);
	Plugin::UnityEngineComponentPropertyGetTransform = *(int32_t (**)(int32_t thisHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineComponentPropertyGetTransform);
	Plugin::UnityEngineComponentPropertyGetGameObject = *(int32_t (**)(int32_t thisHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineComponentPropertyGetGameObject);
	Plugin::UnityEngineTransformPropertyGetPosition = *(UnityEngine::Vector3 (**)(int32_t thisHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineTransformPropertyGetPosition);
	Plugin::UnityEngineTransformPropertySetPosition = *(void (**)(int32_t thisHandle, UnityEngine::Vector3& value))curMemory;
	curMemory += sizeof(Plugin::UnityEngineTransformPropertySetPosition);
	Plugin::SystemCollectionsIEnumeratorPropertyGetCurrent = *(int32_t (**)(int32_t thisHandle))curMemory;
	curMemory += sizeof(Plugin::SystemCollectionsIEnumeratorPropertyGetCurrent);
	Plugin::SystemCollectionsIEnumeratorMethodMoveNext = *(int32_t (**)(int32_t thisHandle))curMemory;
	curMemory += sizeof(Plugin::SystemCollectionsIEnumeratorMethodMoveNext);
	Plugin::ReleaseUnityEngineBounds = *(void (**)(int32_t handle))curMemory;
	curMemory += sizeof(Plugin::ReleaseUnityEngineBounds);
	Plugin::UnityEngineBoundsPropertyGetMax = *(UnityEngine::Vector3 (**)(int32_t thisHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineBoundsPropertyGetMax);
	Plugin::UnityEngineBoundsPropertySetMax = *(void (**)(int32_t thisHandle, UnityEngine::Vector3& value))curMemory;
	curMemory += sizeof(Plugin::UnityEngineBoundsPropertySetMax);
	Plugin::UnityEngineBoundsPropertyGetMin = *(UnityEngine::Vector3 (**)(int32_t thisHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineBoundsPropertyGetMin);
	Plugin::UnityEngineBoundsPropertySetMin = *(void (**)(int32_t thisHandle, UnityEngine::Vector3& value))curMemory;
	curMemory += sizeof(Plugin::UnityEngineBoundsPropertySetMin);
	Plugin::UnityEngineBoundsMethodIntersectsUnityEngineBounds = *(int32_t (**)(int32_t thisHandle, int32_t boundsHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineBoundsMethodIntersectsUnityEngineBounds);
	Plugin::BoxBounds = *(int32_t (**)(int32_t valHandle))curMemory;
	curMemory += sizeof(Plugin::BoxBounds);
	Plugin::UnboxBounds = *(int32_t (**)(int32_t valHandle))curMemory;
	curMemory += sizeof(Plugin::UnboxBounds);
	Plugin::UnityEngineGameObjectConstructor = *(int32_t (**)())curMemory;
	curMemory += sizeof(Plugin::UnityEngineGameObjectConstructor);
	Plugin::UnityEngineGameObjectConstructorSystemString = *(int32_t (**)(int32_t nameHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineGameObjectConstructorSystemString);
	Plugin::UnityEngineGameObjectPropertyGetTransform = *(int32_t (**)(int32_t thisHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineGameObjectPropertyGetTransform);
	Plugin::UnityEngineGameObjectPropertyGetTag = *(int32_t (**)(int32_t thisHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineGameObjectPropertyGetTag);
	Plugin::UnityEngineGameObjectPropertySetTag = *(void (**)(int32_t thisHandle, int32_t valueHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineGameObjectPropertySetTag);
	Plugin::UnityEngineGameObjectMethodAddComponentMyGameBaseGameScript = *(int32_t (**)(int32_t thisHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineGameObjectMethodAddComponentMyGameBaseGameScript);
	Plugin::UnityEngineGameObjectMethodAddComponentUnityEngineSpriteRenderer = *(int32_t (**)(int32_t thisHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineGameObjectMethodAddComponentUnityEngineSpriteRenderer);
	Plugin::UnityEngineGameObjectMethodAddComponentUnityEngineAudioSource = *(int32_t (**)(int32_t thisHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineGameObjectMethodAddComponentUnityEngineAudioSource);
	Plugin::UnityEngineGameObjectMethodGetComponentUnityEngineSpriteRenderer = *(int32_t (**)(int32_t thisHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineGameObjectMethodGetComponentUnityEngineSpriteRenderer);
	Plugin::UnityEngineGameObjectMethodGetComponentUnityEngineAudioSource = *(int32_t (**)(int32_t thisHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineGameObjectMethodGetComponentUnityEngineAudioSource);
	Plugin::UnityEngineGameObjectMethodCompareTagSystemString = *(int32_t (**)(int32_t thisHandle, int32_t tagHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineGameObjectMethodCompareTagSystemString);
	Plugin::UnityEngineGameObjectMethodCreatePrimitiveUnityEnginePrimitiveType = *(int32_t (**)(UnityEngine::PrimitiveType type))curMemory;
	curMemory += sizeof(Plugin::UnityEngineGameObjectMethodCreatePrimitiveUnityEnginePrimitiveType);
	Plugin::UnityEngineDebugMethodLogSystemObject = *(void (**)(int32_t messageHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineDebugMethodLogSystemObject);
	Plugin::UnityEngineAudioClipConstructor = *(int32_t (**)())curMemory;
	curMemory += sizeof(Plugin::UnityEngineAudioClipConstructor);
	Plugin::UnityEngineAudioSourcePropertyGetLoop = *(int32_t (**)(int32_t thisHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineAudioSourcePropertyGetLoop);
	Plugin::UnityEngineAudioSourcePropertySetLoop = *(void (**)(int32_t thisHandle, uint32_t value))curMemory;
	curMemory += sizeof(Plugin::UnityEngineAudioSourcePropertySetLoop);
	Plugin::UnityEngineAudioSourcePropertyGetClip = *(int32_t (**)(int32_t thisHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineAudioSourcePropertyGetClip);
	Plugin::UnityEngineAudioSourcePropertySetClip = *(void (**)(int32_t thisHandle, int32_t valueHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineAudioSourcePropertySetClip);
	Plugin::UnityEngineAudioSourceMethodPlayOneShotUnityEngineAudioClip = *(void (**)(int32_t thisHandle, int32_t clipHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineAudioSourceMethodPlayOneShotUnityEngineAudioClip);
	Plugin::UnityEngineAudioSourceMethodPlay = *(void (**)(int32_t thisHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineAudioSourceMethodPlay);
	Plugin::UnityEngineAudioSourceMethodStop = *(void (**)(int32_t thisHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineAudioSourceMethodStop);
	Plugin::UnityEngineInputMethodGetAxisSystemString = *(System::Single (**)(int32_t axisNameHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineInputMethodGetAxisSystemString);
	Plugin::UnityEngineInputMethodGetAxisRawSystemString = *(System::Single (**)(int32_t axisNameHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineInputMethodGetAxisRawSystemString);
	Plugin::UnityEngineInputMethodGetKeySystemString = *(int32_t (**)(int32_t nameHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineInputMethodGetKeySystemString);
	Plugin::UnityEngineInputMethodGetKeyUpSystemString = *(int32_t (**)(int32_t nameHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineInputMethodGetKeyUpSystemString);
	Plugin::UnityEngineInputMethodGetKeyDownSystemString = *(int32_t (**)(int32_t nameHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineInputMethodGetKeyDownSystemString);
	Plugin::UnityEngineResourcesMethodLoadUnityEngineSpriteSystemString = *(int32_t (**)(int32_t pathHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineResourcesMethodLoadUnityEngineSpriteSystemString);
	Plugin::UnityEngineResourcesMethodLoadUnityEngineAudioClipSystemString = *(int32_t (**)(int32_t pathHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineResourcesMethodLoadUnityEngineAudioClipSystemString);
	Plugin::UnityEngineMonoBehaviourPropertyGetTransform = *(int32_t (**)(int32_t thisHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineMonoBehaviourPropertyGetTransform);
	Plugin::SystemExceptionConstructorSystemString = *(int32_t (**)(int32_t messageHandle))curMemory;
	curMemory += sizeof(Plugin::SystemExceptionConstructorSystemString);
	Plugin::BoxPrimitiveType = *(int32_t (**)(UnityEngine::PrimitiveType val))curMemory;
	curMemory += sizeof(Plugin::BoxPrimitiveType);
	Plugin::UnboxPrimitiveType = *(UnityEngine::PrimitiveType (**)(int32_t valHandle))curMemory;
	curMemory += sizeof(Plugin::UnboxPrimitiveType);
	Plugin::UnityEngineSpriteConstructor = *(int32_t (**)())curMemory;
	curMemory += sizeof(Plugin::UnityEngineSpriteConstructor);
	Plugin::UnityEngineSpritePropertyGetBounds = *(int32_t (**)(int32_t thisHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineSpritePropertyGetBounds);
	Plugin::UnityEngineSpriteRendererPropertyGetSprite = *(int32_t (**)(int32_t thisHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineSpriteRendererPropertyGetSprite);
	Plugin::UnityEngineSpriteRendererPropertySetSprite = *(void (**)(int32_t thisHandle, int32_t valueHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineSpriteRendererPropertySetSprite);
	Plugin::UnityEngineSpriteRendererPropertyGetBounds = *(int32_t (**)(int32_t thisHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineSpriteRendererPropertyGetBounds);
	Plugin::UnityEngineTimePropertyGetDeltaTime = *(System::Single (**)())curMemory;
	curMemory += sizeof(Plugin::UnityEngineTimePropertyGetDeltaTime);
	Plugin::ReleaseBaseGameScript = *(void (**)(int32_t handle))curMemory;
	curMemory += sizeof(Plugin::ReleaseBaseGameScript);
	Plugin::BaseGameScriptConstructor = *(void (**)(int32_t cppHandle, int32_t* handle))curMemory;
	curMemory += sizeof(Plugin::BaseGameScriptConstructor);
	Plugin::BoxBoolean = *(int32_t (**)(uint32_t val))curMemory;
	curMemory += sizeof(Plugin::BoxBoolean);
	Plugin::UnboxBoolean = *(int32_t (**)(int32_t valHandle))curMemory;
	curMemory += sizeof(Plugin::UnboxBoolean);
	Plugin::BoxSByte = *(int32_t (**)(int8_t val))curMemory;
	curMemory += sizeof(Plugin::BoxSByte);
	Plugin::UnboxSByte = *(System::SByte (**)(int32_t valHandle))curMemory;
	curMemory += sizeof(Plugin::UnboxSByte);
	Plugin::BoxByte = *(int32_t (**)(uint8_t val))curMemory;
	curMemory += sizeof(Plugin::BoxByte);
	Plugin::UnboxByte = *(System::Byte (**)(int32_t valHandle))curMemory;
	curMemory += sizeof(Plugin::UnboxByte);
	Plugin::BoxInt16 = *(int32_t (**)(int16_t val))curMemory;
	curMemory += sizeof(Plugin::BoxInt16);
	Plugin::UnboxInt16 = *(System::Int16 (**)(int32_t valHandle))curMemory;
	curMemory += sizeof(Plugin::UnboxInt16);
	Plugin::BoxUInt16 = *(int32_t (**)(uint16_t val))curMemory;
	curMemory += sizeof(Plugin::BoxUInt16);
	Plugin::UnboxUInt16 = *(System::UInt16 (**)(int32_t valHandle))curMemory;
	curMemory += sizeof(Plugin::UnboxUInt16);
	Plugin::BoxInt32 = *(int32_t (**)(int32_t val))curMemory;
	curMemory += sizeof(Plugin::BoxInt32);
	Plugin::UnboxInt32 = *(System::Int32 (**)(int32_t valHandle))curMemory;
	curMemory += sizeof(Plugin::UnboxInt32);
	Plugin::BoxUInt32 = *(int32_t (**)(uint32_t val))curMemory;
	curMemory += sizeof(Plugin::BoxUInt32);
	Plugin::UnboxUInt32 = *(System::UInt32 (**)(int32_t valHandle))curMemory;
	curMemory += sizeof(Plugin::UnboxUInt32);
	Plugin::BoxInt64 = *(int32_t (**)(int64_t val))curMemory;
	curMemory += sizeof(Plugin::BoxInt64);
	Plugin::UnboxInt64 = *(System::Int64 (**)(int32_t valHandle))curMemory;
	curMemory += sizeof(Plugin::UnboxInt64);
	Plugin::BoxUInt64 = *(int32_t (**)(uint64_t val))curMemory;
	curMemory += sizeof(Plugin::BoxUInt64);
	Plugin::UnboxUInt64 = *(System::UInt64 (**)(int32_t valHandle))curMemory;
	curMemory += sizeof(Plugin::UnboxUInt64);
	Plugin::BoxChar = *(int32_t (**)(uint16_t val))curMemory;
	curMemory += sizeof(Plugin::BoxChar);
	Plugin::UnboxChar = *(int16_t (**)(int32_t valHandle))curMemory;
	curMemory += sizeof(Plugin::UnboxChar);
	Plugin::BoxSingle = *(int32_t (**)(float val))curMemory;
	curMemory += sizeof(Plugin::BoxSingle);
	Plugin::UnboxSingle = *(System::Single (**)(int32_t valHandle))curMemory;
	curMemory += sizeof(Plugin::UnboxSingle);
	Plugin::BoxDouble = *(int32_t (**)(double val))curMemory;
	curMemory += sizeof(Plugin::BoxDouble);
	Plugin::UnboxDouble = *(System::Double (**)(int32_t valHandle))curMemory;
	curMemory += sizeof(Plugin::UnboxDouble);
	/*END INIT BODY PARAMETER READS*/
	
	// Init managed object ref counting
	Plugin::RefCountsLenClass = maxManagedObjects;
	Plugin::RefCountsClass = (int32_t*)curMemory;
	curMemory += maxManagedObjects * sizeof(int32_t);
	
	/*BEGIN INIT BODY ARRAYS*/
	Plugin::RefCountsSystemDecimal = (int32_t*)curMemory;
	curMemory += 1000 * sizeof(int32_t);
	Plugin::RefCountsLenSystemDecimal = 1000;
	
	Plugin::RefCountsUnityEngineBounds = (int32_t*)curMemory;
	curMemory += 1000 * sizeof(int32_t);
	Plugin::RefCountsLenUnityEngineBounds = 1000;
	
	Plugin::BaseGameScriptFreeListSize = 1000;
	Plugin::BaseGameScriptFreeList = (MyGame::BaseGameScript**)curMemory;
	curMemory += 1000 * sizeof(MyGame::BaseGameScript*);
	
	Plugin::BaseGameScriptFreeWholeListSize = 1000;
	Plugin::BaseGameScriptFreeWholeList = (Plugin::BaseGameScriptFreeWholeListEntry*)curMemory;
	curMemory += 1000 * sizeof(Plugin::BaseGameScriptFreeWholeListEntry);
	/*END INIT BODY ARRAYS*/
	
	// Make sure there was enough memory
	int32_t usedMemory = (int32_t)(curMemory - (uint8_t*)memory);
	if (usedMemory > memorySize)
	{
		System::String msg = "Plugin memory size is too low";
		System::Exception ex(msg);
		Plugin::SetException(ex.Handle);
		return;
	}
	
	if (initMode == InitMode::FirstBoot)
	{
		// Clear memory
		memset(memory, 0, memorySize);
		
		/*BEGIN INIT BODY FIRST BOOT*/
		for (int32_t i = 0, end = Plugin::BaseGameScriptFreeListSize - 1; i < end; ++i)
		{
			Plugin::BaseGameScriptFreeList[i] = (MyGame::BaseGameScript*)(Plugin::BaseGameScriptFreeList + i + 1);
		}
		Plugin::BaseGameScriptFreeList[Plugin::BaseGameScriptFreeListSize - 1] = nullptr;
		Plugin::NextFreeBaseGameScript = Plugin::BaseGameScriptFreeList + 1;
		
		for (int32_t i = 0, end = Plugin::BaseGameScriptFreeWholeListSize - 1; i < end; ++i)
		{
			Plugin::BaseGameScriptFreeWholeList[i].Next = Plugin::BaseGameScriptFreeWholeList + i + 1;
		}
		Plugin::BaseGameScriptFreeWholeList[Plugin::BaseGameScriptFreeWholeListSize - 1].Next = nullptr;
		Plugin::NextFreeWholeBaseGameScript = Plugin::BaseGameScriptFreeWholeList + 1;
		/*END INIT BODY FIRST BOOT*/
	}
	
	try
	{
		PluginMain(
			curMemory,
			(int32_t)(memorySize - usedMemory),
			initMode == InitMode::FirstBoot);
	}
	catch (System::Exception ex)
	{
		Plugin::SetException(ex.Handle);
	}
	catch (...)
	{
		System::String msg = "Unhandled exception in PluginMain";
		System::Exception ex(msg);
		Plugin::SetException(ex.Handle);
	}
}

// Receive an unhandled exception from C#
DLLEXPORT void SetCsharpException(int32_t handle)
{
	Plugin::unhandledCsharpException = new System::Exception(
		Plugin::InternalUse::Only,
		handle);
}

