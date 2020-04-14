#pragma once
#include <array>

template<typename Enum>
using EnumSize = typename Enum::EnumCount;

template<typename EnumKey, typename ValueType>
using EnumKeyArrayMap = std::array<ValueType, static_cast<std::size_t>(EnumKey::EnumCount)>;
