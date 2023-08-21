#pragma once

#include <memory>

namespace VulkanCore {

	void InitializeCore();
	void ShutdownCore();
}

#ifndef ANT_PLATFORM_WINDOWS
	#error Ant only supports Windows!
#endif

#define BIT(x) (1u << x)

#define ANT_BIND_EVENT_FN(fn) std::bind(&##fn, this, std::placeholders::_1)

#ifdef ANT_PLATFORM_WINDOWS
#define ANT_FORCE_INLINE __forceinline
#else
// TODO: other platforms
#define ANT_FORCE_INLINE inline
#endif

namespace Ant {

	// Pointer wrappers
	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	using byte = uint8_t;
}
